#include "PreCompile.h"
#include "EngineWindow.h"
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineAPICore.h>

HINSTANCE UEngineWindow::hInstance = nullptr;
std::map<std::string, WNDCLASSEXA> UEngineWindow::WindowClasses;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int WindowCount = 0;

UEngineWindow::UEngineWindow()
{
}

UEngineWindow::~UEngineWindow()
{
	if (nullptr != WindowImage)
	{
		delete WindowImage;
		WindowImage = nullptr;
	}
	if (nullptr != BackBufferImage)
	{
		delete BackBufferImage;
		BackBufferImage = nullptr;
	}
	if (nullptr != WindowHandle)
	{
		DestroyWindow(WindowHandle);
		WindowHandle = nullptr;
	}
}

void UEngineWindow::EngineWindowInit(HINSTANCE _Instance)
{
	hInstance = _Instance;

	WNDCLASSEXA wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW; // 윈도우 스타일 설정
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "Default";
	wcex.hIconSm = nullptr;

	CreateWindowClass(wcex);
}

void UEngineWindow::CreateWindowClass(const WNDCLASSEXA& _Class)
{
	// 이미 등록된 클래스인지 확인
	std::map<std::string, WNDCLASSEXA>::iterator EndIter = WindowClasses.end();
	std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasses.find(std::string(_Class.lpszClassName));
	if (EndIter != FindIter)
	{
		MSGASSERT(std::string(_Class.lpszClassName) + "같은 이름의 윈도우 클래스를 2번 등록했습니다");
		return;
	}
	//	윈도우클래스 등록
	RegisterClassExA(&_Class);
	WindowClasses.insert(std::pair{ _Class.lpszClassName, _Class });
}


int UEngineWindow::WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction)
{
	MSG msg = MSG();
	if (nullptr != _StartFunction) {

		_StartFunction();
	}
	while (0 != WindowCount)
	{
		if (0 != PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (nullptr != _FrameFunction)
		{
			_FrameFunction();
		}
	}
	return (int)msg.wParam;
}

void UEngineWindow::Open(std::string_view _TitleName)
{
	if (0 == WindowHandle)
	{
		Create(_TitleName);
		//	예외처리	
		if (0 == WindowHandle) { return; }
	}
	// 윈도우 창 표시
	ShowWindow(WindowHandle, SW_SHOW);
	UpdateWindow(WindowHandle);
	++WindowCount;
}
FVector2D UEngineWindow::GetMousePos()
{
	POINT MousePoint;
	GetCursorPos(&MousePoint);
	// 윈도우창 위치기준으로 마우스 포지션
	ScreenToClient(WindowHandle, &MousePoint);
	return FVector2D(MousePoint.x, MousePoint.y);
}
void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{
	//	예외처리
	if (false == WindowClasses.contains(_ClassName.data()))
	{
		MSGASSERT(std::string(_ClassName) + "등록하지 않은 클래스로 윈도우창을 만들려고 했습니다");
		return;
	}
	//	등록된 윈도우 클래스로 윈도우핸들 생성
	WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW, 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	//	예외처리
	if (!WindowHandle)
	{
		MSGASSERT(std::string(_TitleName) + "윈도우 생성에 실패했습니다.");
		return;
	}
	//	현재윈도우핸들로부터 DC얻어오기
	HDC WindowMainDC = GetDC(WindowHandle);
	//	UEngineWinImage객체 생성 
	WindowImage = new UEngineWinImage();
	//	얻어온 DC로 WindowImage의 HDC생성
	WindowImage->Create(WindowMainDC);
}

void UEngineWindow::SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale)
{
	//	백버퍼를 생성하려면 무조건 윈도우의 크기를 설정해야함
	if (false == WindowSize.EqualToInt(_Scale))
	{
		// 기존 백버퍼 delete
		if (nullptr != BackBufferImage)
		{
			delete BackBufferImage;
			BackBufferImage = nullptr;
		}
		//	새로운 BackBuffer
		BackBufferImage = new UEngineWinImage();
		BackBufferImage->Create(WindowImage, _Scale);
	}
	//	새로운 (조정된)윈도우사이즈
	WindowSize = _Scale;
	RECT Rc = { 0, 0, _Scale.iX(), _Scale.iY() };
	AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);
	::SetWindowPos(WindowHandle, nullptr, _Pos.iX(), _Pos.iY(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}






LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		--WindowCount;
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
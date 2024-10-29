#include "PreCompile.h"
#include "EngineWindow.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDebug.h>

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
}

void UEngineWindow::EngineWindowInit(HINSTANCE _Instance)
{
	hInstance = _Instance;

	WNDCLASSEXA wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
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
	std::map<std::string, WNDCLASSEXA>::iterator EndIter = WindowClasses.end();
	std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasses.find(std::string(_Class.lpszClassName));
	if (EndIter != FindIter)
	{
		MSGASSERT(std::string(_Class.lpszClassName) + "같은 이름의 윈도우 클래스를 2번 등록했습니다");
		return;
	}
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
	}
	if (0 == WindowHandle)
	{
		return;
	}
	ShowWindow(WindowHandle, SW_SHOW);
	UpdateWindow(WindowHandle);
	++WindowCount;
}

void UEngineWindow::SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale)
{
	// 이전의 크기와 달라졌을때만 백버퍼를 새로 만든 것이다.
	if (false == WindowSize.EqualToInt(_Scale))
	{
		// 화면의 크기와 전히 동일한 크기여야 한다.
		// 여러번 호출하면 기존에 만들었던 녀석이 Leck이 되므로
		// 화면크기를 조정할 때마다 삭제해줘야 한다.
		if (nullptr != BackBufferImage)
		{
			// 기존 백버퍼는 지워버리고
			delete BackBufferImage;
			BackBufferImage = nullptr;
		}

		BackBufferImage = new UEngineWinImage();
		BackBufferImage->Create(WindowImage, _Scale);
	}

	WindowSize = _Scale;

	RECT Rc = { 0, 0, _Scale.iX(), _Scale.iY() };

	// 이게 그 계산해주는 함수이다.
	// 타이틀바 크기까지 합쳐진 크기로 준다.
	// 윈도우 입장
	// 현재 윈도우의 스타일을 넣어줘야 한다.

	// 그러면 또 이녀석은 
	// 윈도우에서 가져야할 위치를 포함한 크기를 주게 된다.
	AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

	::SetWindowPos(WindowHandle, nullptr, _Pos.iX(), _Pos.iY(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}

void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{
	if (false == WindowClasses.contains(_ClassName.data()))
	{
		MSGASSERT(std::string(_ClassName) + "등록하지 않은 클래스로 윈도우창을 만들려고 했습니다");
		return;
	}

	WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW, 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!WindowHandle)
	{
		MSGASSERT(std::string(_TitleName) + "윈도우 생성에 실패했습니다.");
		return;
	}
	// 윈도우가 만들어지면 hdc를 여기서 얻어올 겁니다.
	HDC WindowMainDC = GetDC(WindowHandle);

	// BackBufferImage.Copy({ 100,100 }, {50, 50}, PlayerImage);

	WindowImage = new UEngineWinImage();

	// 이건 만든다는 개념이 아니다.
	WindowImage->Create(WindowMainDC);
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
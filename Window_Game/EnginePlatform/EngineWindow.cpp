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
	// �������ϴ� ������ ������� ������ ����
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
	//	����ó��
	std::map<std::string, WNDCLASSEXA>::iterator EndIter = WindowClasses.end();
	std::map<std::string, WNDCLASSEXA>::iterator FindIter = WindowClasses.find(std::string(_Class.lpszClassName));
	if (EndIter != FindIter)
	{
		MSGASSERT(std::string(_Class.lpszClassName) + "���� �̸��� ������ Ŭ������ 2�� ����߽��ϴ�");
		return;
	}
	//	������Ŭ���� ���
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
		//	����ó��	
		if (0 == WindowHandle) { return; }
	}
	//	������â ����
	ShowWindow(WindowHandle, SW_SHOW);
	UpdateWindow(WindowHandle);
	++WindowCount;
}
void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{
	//	����ó��
	if (false == WindowClasses.contains(_ClassName.data()))
	{
		MSGASSERT(std::string(_ClassName) + "������� ���� Ŭ������ ������â�� ������� �߽��ϴ�");
		return;
	}
	//	��ϵ� ������ Ŭ������ �������ڵ� ����
	WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW, 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	//	����ó��
	if (!WindowHandle)
	{
		MSGASSERT(std::string(_TitleName) + "������ ������ �����߽��ϴ�.");
		return;
	}
	//	�����������ڵ�κ��� DC������
	HDC WindowMainDC = GetDC(WindowHandle);
	//	UEngineWinImage��ü ���� 
	WindowImage = new UEngineWinImage();
	//	���� DC�� WindowImage�� HDC����
	WindowImage->Create(WindowMainDC);
}

void UEngineWindow::SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale)
{
	//	����۸� �����Ϸ��� ������ �������� ũ�⸦ �����ؾ���
	if (false == WindowSize.EqualToInt(_Scale))
	{
		// ���� ����� delete
		if (nullptr != BackBufferImage)
		{
			delete BackBufferImage;
			BackBufferImage = nullptr;
		}
		//	���ο� BackBuffer
		BackBufferImage = new UEngineWinImage();
		BackBufferImage->Create(WindowImage, _Scale);
	}
	//	���ο� (������)�����������
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
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
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
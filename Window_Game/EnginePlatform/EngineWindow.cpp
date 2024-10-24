#include "PreCompile.h"
#include "EngineWindow.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDebug.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

HINSTANCE UEngineWindow::hInstance = nullptr;
std::map<std::string, WNDCLASSEXA> UEngineWindow::WindowClasses;
int WindowCount = 0;

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
		MSGASSERT(std::string(_Class.lpszClassName) + "���� �̸��� ������ Ŭ������ 2�� ����߽��ϴ�");
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

void UEngineWindow::Create(std::string_view _TitleName, std::string_view _ClassName)
{
	if (false == WindowClasses.contains(_ClassName.data()))
	{
		MSGASSERT(std::string(_ClassName) + "������� ���� Ŭ������ ������â�� ������� �߽��ϴ�");
		return;
	}

	WindowHandle = CreateWindowA(_ClassName.data(), _TitleName.data(), WS_OVERLAPPEDWINDOW, 0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!WindowHandle)
	{
		MSGASSERT(std::string(_TitleName) + "������ ������ �����߽��ϴ�.");
		return;
	}
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
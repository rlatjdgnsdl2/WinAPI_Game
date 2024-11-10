#pragma once
#include "EngineWinImage.h"


//	����: ��������� Ŭ����
class UEngineWindow
{
public:
	// constrcuter destructer
	UEngineWindow();
	~UEngineWindow();
	// delete Function
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;

	// �⺻ ������ Ŭ���� ����ü ���� �� ��� �Լ�
	static void EngineWindowInit(HINSTANCE _Instance);
	// ����� ���� ������ Ŭ���� ��� �Լ�
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	// ���� ���� �Լ� (������ �޽��� ������ ������ �Լ� ����)
	static int WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);

	//	Get, Set
	HDC GetWindowMainDC() const { return WindowImage->GetDC(); }
	FVector2D GetWindowSize() const {return WindowSize; }
	UEngineWinImage* GetWindowImage() const {return WindowImage; }
	UEngineWinImage* GetBackBuffer() const { return BackBufferImage; }
	void SetWindowTitle(std::string_view Text) { SetWindowTextA(WindowHandle, Text.data()); }
	void SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale);

	//	�������ڵ� ������ WindowImage HDC�����Լ�
	void Create(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	// ������ â�� ǥ���ϴ� �Լ�
	void Open(std::string_view _TitleName = "Window");

	FVector2D GetMousePos();


private:
	static HINSTANCE hInstance;
	HWND WindowHandle = nullptr;

	FVector2D WindowSize;

	//	��ϵ� WindowClass map 
	static std::map<std::string, WNDCLASSEXA> WindowClasses;
	//	FrontBuffer (ȭ�� ��¿� ����)
	UEngineWinImage* WindowImage = nullptr;
	//	BackBuffer (ȭ�� �غ�� ����)
	UEngineWinImage* BackBufferImage = nullptr;

};


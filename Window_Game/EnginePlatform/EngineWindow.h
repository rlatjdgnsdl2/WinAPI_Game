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

	//	Default ������ Ŭ��������ü ������ ���
	static void EngineWindowInit(HINSTANCE _Instance);
	//	Custom ������ Ŭ���� ���
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	//	Game Roop�Լ� 
	static int WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);

	//	Get, Set
	inline HDC GetWindowMainDC() const 
	{ 
		return WindowImage->GetDC(); 
	}
	inline FVector2D GetWindowSize() const 
	{
		return WindowSize; 
	}
	inline UEngineWinImage* GetWindowImage() const 
	{
		return WindowImage; 
	}
	inline UEngineWinImage* GetBackBuffer() const 
	{ 
		return BackBufferImage; 
	}
	inline void SetWindowTitle(std::string_view Text) 
	{ 
		SetWindowTextA(WindowHandle, Text.data()); 
	}

	//	������âũ�� �����Լ�
	void SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale);

	//	�������ڵ� ������ WindowImage HDC�����Լ�
	void Create(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	//	������â Show�Լ�
	void Open(std::string_view _TitleName = "Window");


private:
	static HINSTANCE hInstance;
	HWND WindowHandle = nullptr;

	FVector2D WindowSize;

	//	��ϵ� WindowClass map
	static std::map<std::string, WNDCLASSEXA> WindowClasses;
	//	FrontBuffer
	UEngineWinImage* WindowImage = nullptr;
	//	BackBuffer
	UEngineWinImage* BackBufferImage = nullptr;

};


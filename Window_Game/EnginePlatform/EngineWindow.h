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

	//	static �Լ�
	static void EngineWindowInit(HINSTANCE _Instance);															
	static void CreateWindowClass(const WNDCLASSEXA& _Class);													
	static int  WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);	

	// ��� �Լ�
	void Create(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	void Open(std::string_view _TitleName = "Window");

	inline HDC GetWindowMainDC()
	{
		return WindowImage->GetDC();
	}

	inline void SetWindowTitle(std::string_view Text) {
		SetWindowTextA(WindowHandle, Text.data());
	}
	void SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale);


private:
	// static ����
	static inline HINSTANCE hInstance = nullptr;
	static inline std::map<std::string, WNDCLASSEXA> WindowClasses;

	UEngineWinImage* BackBufferImage = nullptr;

	// ������ �̹����� ���εǾ���.
	UEngineWinImage* WindowImage = nullptr;

	HWND WindowHandle = nullptr;


};


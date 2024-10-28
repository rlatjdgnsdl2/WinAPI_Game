#pragma once

#include "EngineWinImage.h"


//	설명: 윈도우관련 클래스
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

	//	static 함수
	static void EngineWindowInit(HINSTANCE _Instance);															
	static void CreateWindowClass(const WNDCLASSEXA& _Class);													
	static int  WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);	

	// 멤버 함수
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
	// static 변수
	static inline HINSTANCE hInstance = nullptr;
	static inline std::map<std::string, WNDCLASSEXA> WindowClasses;

	UEngineWinImage* BackBufferImage = nullptr;

	// 윈도우 이미지로 랩핑되었다.
	UEngineWinImage* WindowImage = nullptr;

	HWND WindowHandle = nullptr;


};


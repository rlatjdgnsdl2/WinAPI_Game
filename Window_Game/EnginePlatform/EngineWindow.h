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

	//	Default 윈도우 클래스 등록
	static void EngineWindowInit(HINSTANCE _Instance);
	//	Custom 윈도우 클래스 등록
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	//	Game Roop함수 
	static int WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);

	void Create(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	void Open(std::string_view _TitleName = "Window");

	inline HDC GetWindowMainDC() const					{ return WindowImage->GetDC(); }
	inline FVector2D GetWindowSize() const				{ return WindowSize; }
	inline UEngineWinImage* GetWindowImage() const		{ return WindowImage; }
	inline UEngineWinImage* GetBackBuffer() const		{ return BackBufferImage; }
	inline void SetWindowTitle(std::string_view Text)	{ SetWindowTextA(WindowHandle, Text.data()); }

	//	윈도우창크기 설정함수
	void SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale);


private:
	static HINSTANCE hInstance;
	//	등록된 WindowClass map
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	UEngineWinImage* BackBufferImage = nullptr;
	//	EngineWindowImage로 랩핑
	UEngineWinImage* WindowImage = nullptr;

	HWND WindowHandle = nullptr;
	FVector2D WindowSize;


};


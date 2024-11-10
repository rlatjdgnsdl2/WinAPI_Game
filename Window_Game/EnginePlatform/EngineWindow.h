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

	// 기본 윈도우 클래스 구조체 생성 및 등록 함수
	static void EngineWindowInit(HINSTANCE _Instance);
	// 사용자 지정 윈도우 클래스 등록 함수
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	// 게임 루프 함수 (윈도우 메시지 루프와 프레임 함수 실행)
	static int WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);

	//	Get, Set
	HDC GetWindowMainDC() const { return WindowImage->GetDC(); }
	FVector2D GetWindowSize() const {return WindowSize; }
	UEngineWinImage* GetWindowImage() const {return WindowImage; }
	UEngineWinImage* GetBackBuffer() const { return BackBufferImage; }
	void SetWindowTitle(std::string_view Text) { SetWindowTextA(WindowHandle, Text.data()); }
	void SetWindowPosAndScale(FVector2D _Pos, FVector2D _Scale);

	//	윈도우핸들 생성및 WindowImage HDC설정함수
	void Create(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	// 윈도우 창을 표시하는 함수
	void Open(std::string_view _TitleName = "Window");

	FVector2D GetMousePos();


private:
	static HINSTANCE hInstance;
	HWND WindowHandle = nullptr;

	FVector2D WindowSize;

	//	등록된 WindowClass map 
	static std::map<std::string, WNDCLASSEXA> WindowClasses;
	//	FrontBuffer (화면 출력용 버퍼)
	UEngineWinImage* WindowImage = nullptr;
	//	BackBuffer (화면 준비용 버퍼)
	UEngineWinImage* BackBufferImage = nullptr;

};


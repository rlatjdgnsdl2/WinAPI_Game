#pragma once

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
	static void EngineWindowInit(HINSTANCE _Instance);																//	기본 윈도우클래스생성
	static void CreateWindowClass(const WNDCLASSEXA& _Class);														//	윈도우 생성 클래스 등록 함수
	static int  WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);		//	윈도우 게임 메시지 루프 함수
	
	// 멤버 함수
	void Create(std::string_view _TitleName="Window", std::string_view _ClassName = "Default");
	void Open(std::string_view _TitleName = "Window");
	
	inline HDC GetBackBuffer()
	{
		return BackBuffer;
	}


protected:

private:
	// static 변수
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	// 일반 멤버변수
	HWND WindowHandle = nullptr;	//	윈도우 다루는 핸들
	HDC BackBuffer = nullptr;

	

};


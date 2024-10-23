#pragma once
#include <EngineBase/EngineDelegate.h>

//	윈도우관련 클래스
class UEngineWindow
{
public:
	//	static 함수
	static void EngineWindowInit(HINSTANCE _Instance, std::string_view _ClassName = "Default");			//	기본 윈도우클래스생성
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	static int  WindowMessageLoop(EngineDelegate _FrameFuntion);		
	
	// 멤버 함수
	void Open(std::string_view _TitleName = "Window", std::string_view _ClassName = "Default");
	void Create(std::string_view _TitleName="Window", std::string_view _ClassName = "Default");

	// constrcuter destructer
	UEngineWindow();
	~UEngineWindow();
	// delete Function
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;
protected:

private:
	// static 멤버변수
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	// 일반 멤버변수
	HWND WindowHandle = nullptr;

	// 일반 멤버함수
	

};


#pragma once
#include <Windows.h>
#include <string>
#include <map>

//	윈도우관련 클래스
class UEngineWindow
{
public:
	//	static 함수
	static void EngineWindowInit(HINSTANCE _Instance);			//	기본 윈도우클래스생성
	static bool IsWindowClass(const std::string_view _Text);
	static int  WindowMessageLoop();		
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	
	// 멤버 함수
	void Open(std::string_view _TitleName = "Window");
	void Create(std::string_view _TitleName, std::string_view _ClassName = "Default");

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
	void Create(std::string_view _ClassName = "Default");

};


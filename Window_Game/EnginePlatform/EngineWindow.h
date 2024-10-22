#pragma once
#include <Windows.h>


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

	
	static void EngineWindowInit(HINSTANCE _Instance);	//	hInstance 초기화
	static int WindowMessageLoop();						//	윈도우 메시지 루프함수
	void Open();										//	윈도우창 띄우기함수


protected:

private:
	static HINSTANCE hInstance;
	HWND WindowHandle = nullptr;

};


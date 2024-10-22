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

	
	static void EngineWindowInit(HINSTANCE _Instance);	//	hInstance �ʱ�ȭ
	static int WindowMessageLoop();						//	������ �޽��� �����Լ�
	void Open();										//	������â �����Լ�


protected:

private:
	static HINSTANCE hInstance;
	HWND WindowHandle = nullptr;

};


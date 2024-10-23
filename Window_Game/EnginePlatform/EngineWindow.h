#pragma once
#include <EngineBase/EngineDelegate.h>

//	��������� Ŭ����
class UEngineWindow
{
public:
	//	static �Լ�
	static void EngineWindowInit(HINSTANCE _Instance, std::string_view _ClassName = "Default");			//	�⺻ ������Ŭ��������
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	static int  WindowMessageLoop(EngineDelegate _FrameFuntion);		
	
	// ��� �Լ�
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
	// static �������
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	// �Ϲ� �������
	HWND WindowHandle = nullptr;

	// �Ϲ� ����Լ�
	

};


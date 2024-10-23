#pragma once
#include <Windows.h>
#include <string>
#include <map>

//	��������� Ŭ����
class UEngineWindow
{
public:
	//	static �Լ�
	static void EngineWindowInit(HINSTANCE _Instance);			//	�⺻ ������Ŭ��������
	static bool IsWindowClass(const std::string_view _Text);
	static int  WindowMessageLoop();		
	static void CreateWindowClass(const WNDCLASSEXA& _Class);
	
	// ��� �Լ�
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
	// static �������
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	// �Ϲ� �������
	HWND WindowHandle = nullptr;

	// �Ϲ� ����Լ�
	void Create(std::string_view _ClassName = "Default");

};


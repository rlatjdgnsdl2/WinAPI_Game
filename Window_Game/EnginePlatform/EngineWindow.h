#pragma once

//	����: ��������� Ŭ����
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

	//	static �Լ�
	static void EngineWindowInit(HINSTANCE _Instance);																//	�⺻ ������Ŭ��������
	static void CreateWindowClass(const WNDCLASSEXA& _Class);														//	������ ���� Ŭ���� ��� �Լ�
	static int  WindowMessageLoop(std::function<void()> _StartFunction, std::function<void()> _FrameFunction);		//	������ ���� �޽��� ���� �Լ�
	
	// ��� �Լ�
	void Create(std::string_view _TitleName="Window", std::string_view _ClassName = "Default");
	void Open(std::string_view _TitleName = "Window");
	
	inline HDC GetBackBuffer()
	{
		return BackBuffer;
	}


protected:

private:
	// static ����
	static HINSTANCE hInstance;
	static std::map<std::string, WNDCLASSEXA> WindowClasses;

	// �Ϲ� �������
	HWND WindowHandle = nullptr;	//	������ �ٷ�� �ڵ�
	HDC BackBuffer = nullptr;

	

};


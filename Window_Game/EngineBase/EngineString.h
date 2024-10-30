#pragma once
#include <string>

// ���� : ���ڿ��� �����ִ� ���� Ŭ����
class UEngineString
{
public:
	// constrcuter destructer
	~UEngineString();

	// delete Function
	UEngineString(const UEngineString& _Other) = delete;
	UEngineString(UEngineString&& _Other) noexcept = delete;
	UEngineString& operator=(const UEngineString& _Other) = delete;
	UEngineString& operator=(UEngineString&& _Other) noexcept = delete;

	//	���ڿ� �빮�ں�ȯ�Լ�
	static std::string ToUpper(std::string_view);
	//	ANSI -> �����ڵ� ��ȯ �Լ�
	static std::wstring AnsiToUnicode(std::string_view _Name);

private:
	UEngineString();
};


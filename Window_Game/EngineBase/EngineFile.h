#pragma once
#include "EnginePath.h"


const int MAXPATH = 256;

//	���� : File Ŭ����
class UEngineFile : public UEnginePath
{
	// �ϵ��ڵ� 
public:
	UEngineFile();
	// ����ü�� -> �θ� Ŭ�������� 
	UEngineFile(const std::string& _Path);
	UEngineFile(std::string_view _Path);
	UEngineFile(std::filesystem::path _Path);
	~UEngineFile();

	// Write
	void Write(class UEngineSerializer& _Ser);
	void Read(class UEngineSerializer& _Ser);

	void Write(const void* _Ptr, size_t _Size);
	void Read(void* _Ptr, size_t _Size);

	void FileOpen(const char* _Mode);
	void Close();

	int GetFileSize();

private:
	FILE* File = nullptr;
};


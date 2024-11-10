#pragma once
#include "EnginePath.h"


const int MAXPATH = 256;

//	설명 : File 클래스
class UEngineFile : public UEnginePath
{
	// 하드코딩 
public:
	UEngineFile();
	// 생성체인 -> 부모 클래스까지 
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


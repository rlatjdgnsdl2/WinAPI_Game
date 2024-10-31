#pragma once
#include "EnginePath.h"

const int MAXPATH = 256;

class UEngineFile : public UEnginePath
{

public:
	UEngineFile();
	// 생성체인
	UEngineFile(std::string_view _Path);
	UEngineFile(std::filesystem::path _Path);
	~UEngineFile();

	// Write
	void Write(const void* _Ptr, size_t _Size);
	void Read(void* _Ptr, size_t _Size);
	void FileOpen(const char* _Mode);
	bool IsExits();
	void Close();

	
private:
	char Path[MAXPATH] = "";
	FILE* File = nullptr;
};


#pragma once
#include "EnginePath.h"



// 설명 : Directory 클래스
class UEngineDirectory : public UEnginePath
{
public:
	// constrcuter destructer
	UEngineDirectory();
	UEngineDirectory(std::string_view _Path);
	UEngineDirectory(std::filesystem::path _Path);
	~UEngineDirectory();
	
	std::vector<class UEngineFile> GetAllFile(bool _IsRecursive = true /*재귀여부*/ );
	std::vector<class UEngineDirectory> GetAllDirectory();

protected:

private:
	void GetAllFileRecursive(std::filesystem::path _Path, std::vector<class UEngineFile>& _Result);

};


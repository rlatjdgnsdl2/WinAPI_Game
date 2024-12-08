#pragma once

// 설명 : Path 클래스
class UEnginePath
{
public:
	UEnginePath();
	//	string , path 둘다 지원
	UEnginePath(std::string_view _Path);
	UEnginePath(std::filesystem::path _Path);
	virtual ~UEnginePath();
	//	경로가 존재하면 true
	bool IsExist();
	//	부모폴더로 이동
	//	현재 path
	std::string GetPathToString();
	// 파일명 + 확장자 포함 
	std::string GetFileName();
	// 폴더명 
	std::string GetDirectoryName();
	// 확장자
	std::string GetExtension();

	//	현재 path부터 _Path가 나올때까지 반복하는 함수
	bool FindPath(std::string_view _Path);
	bool IsDirectory();
	bool IsFile();
	void Append(std::string_view _AppendName);

protected:
	std::filesystem::path Path;
private:
	void MoveParentDirectory();
};


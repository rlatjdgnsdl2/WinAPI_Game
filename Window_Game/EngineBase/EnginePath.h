#pragma once

// 설명 :
class UEnginePath
{
public:
	// constrcuter destructer
	UEnginePath();
	//	String , path 둘다 지원
	UEnginePath(std::string_view _Path);
	UEnginePath(std::filesystem::path _Path);

	virtual ~UEnginePath();


	//	경로가 존재하면 true
	bool IsExists();
	//	부모폴더로 이동
	void MoveParent();

	//	현재 path를 string으로 Get
	std::string GetPathToString();

	// 파일명 + 확장자 포함 Get
	std::string GetFileName();

	// 폴더명 Get
	std::string GetDirectoryName();

	// 확장자
	std::string GetExtension();

	//	현재 path부터 특정 디렉토리가 나올때까지 반복하는 함수
	bool MoveParentToDirectory(std::string_view _Path);

	bool IsDirectory();

	bool IsFile();

	void Append(std::string_view _AppendName);


protected:
	std::filesystem::path Path;

private:
};


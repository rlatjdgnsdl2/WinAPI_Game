#pragma once


// ���� :
class UEnginePath
{
public:
	// constrcuter destructer
	UEnginePath();
	UEnginePath(std::string_view _Path);
	UEnginePath(std::filesystem::path _Path);
	~UEnginePath();

	//// delete Function
	//UEnginePath(const UEnginePath& _Other) = delete;
	//UEnginePath(UEnginePath&& _Other) noexcept = delete;
	//UEnginePath& operator=(const UEnginePath& _Other) = delete;
	//UEnginePath& operator=(UEnginePath&& _Other) noexcept = delete;

	bool IsExists();
	void MoveParent();

	std::string GetPathToString();

	//	���ϸ� + Ȯ���� ����
	std::string GetFileName();

	//	Ȯ����
	std::string GetExtension();

	//	Ư�� ���丮�� ���ö����� MoveParent�� �ݺ��ϴ� �Լ�.
	bool MoveParentToDirectory(std::string_view _Path);

	bool IsDirectory();
	bool IsFile();


protected:
	std::filesystem::path Path;

private:
};


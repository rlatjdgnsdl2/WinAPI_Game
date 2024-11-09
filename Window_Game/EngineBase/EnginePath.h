#pragma once

// ���� :
class UEnginePath
{
public:
	// constrcuter destructer
	UEnginePath();
	//	String , path �Ѵ� ����
	UEnginePath(std::string_view _Path);
	UEnginePath(std::filesystem::path _Path);

	virtual ~UEnginePath();


	//	��ΰ� �����ϸ� true
	bool IsExists();
	//	�θ������� �̵�
	void MoveParent();

	//	���� path�� string���� Get
	std::string GetPathToString();

	// ���ϸ� + Ȯ���� ���� Get
	std::string GetFileName();

	// ������ Get
	std::string GetDirectoryName();

	// Ȯ����
	std::string GetExtension();

	//	���� path���� Ư�� ���丮�� ���ö����� �ݺ��ϴ� �Լ�
	bool MoveParentToDirectory(std::string_view _Path);

	bool IsDirectory();

	bool IsFile();

	void Append(std::string_view _AppendName);


protected:
	std::filesystem::path Path;

private:
};


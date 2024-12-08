#pragma once

// ���� : Path Ŭ����
class UEnginePath
{
public:
	UEnginePath();
	//	string , path �Ѵ� ����
	UEnginePath(std::string_view _Path);
	UEnginePath(std::filesystem::path _Path);
	virtual ~UEnginePath();
	//	��ΰ� �����ϸ� true
	bool IsExist();
	//	�θ������� �̵�
	//	���� path
	std::string GetPathToString();
	// ���ϸ� + Ȯ���� ���� 
	std::string GetFileName();
	// ������ 
	std::string GetDirectoryName();
	// Ȯ����
	std::string GetExtension();

	//	���� path���� _Path�� ���ö����� �ݺ��ϴ� �Լ�
	bool FindPath(std::string_view _Path);
	bool IsDirectory();
	bool IsFile();
	void Append(std::string_view _AppendName);

protected:
	std::filesystem::path Path;
private:
	void MoveParentDirectory();
};


#include "PreCompile.h"
#include "EnginePath.h"
#include "EngineDebug.h"

UEnginePath::UEnginePath()
	: Path(std::filesystem::current_path()) {}

UEnginePath::UEnginePath(std::string_view _Path)
	: Path(_Path) {}

UEnginePath::UEnginePath(std::filesystem::path _Path)
	: Path(_Path) {}

UEnginePath::~UEnginePath() {}

std::string UEnginePath::GetPathToString() {
	return Path.string();
}

std::string UEnginePath::GetFileName()
{
	if (IsDirectory()) {
		MSGASSERT(Path.string() + " _���� ��� �϶��� GetFileName�� ȣ���Ҽ� �ֽ��ϴ�.");
		return "";
	}
	return Path.filename().string();
}


std::string UEnginePath::GetDirectoryName()
{
	if (!IsDirectory()) {
		MSGASSERT(Path.string() + " _���丮 ��� �϶��� GetDirectoryName�� ȣ���Ҽ� �ֽ��ϴ�.");
		return "";
	}
	return Path.filename().string();
}

std::string UEnginePath::GetExtension()
{
	return Path.extension().string();
}


bool UEnginePath::IsExist()
{
	return std::filesystem::exists(Path);
}

bool UEnginePath::IsFile()
{
	return false == IsDirectory();
}

bool UEnginePath::IsDirectory()
{
	return std::filesystem::is_directory(Path);
}

void UEnginePath::MoveParentDirectory()
{
	Path = Path.parent_path();
}

void UEnginePath::Append(std::string_view _AppendName)
{
	Path.append(_AppendName);
}

bool UEnginePath::FindPath(std::string_view _Path)
{
	UEnginePath DummyPath = UEnginePath(Path);
	if (false == DummyPath.IsDirectory()) {
		MSGASSERT("���丮 ����϶��� MoveParentToDirectory �� ȣ���Ҽ� �ֽ��ϴ�");
		return false;
	}
	// ���� path�� ���丮��
	bool Result = false;
	std::filesystem::path CurPath = DummyPath.Path;
	std::filesystem::path Root = CurPath.root_path();
	while (true) {
		CurPath = DummyPath.Path;
		if (CurPath == Root) {
			break;
		}
		CurPath.append(_Path);
		if (true == std::filesystem::exists(CurPath)) {
			Result = true;
			Path = CurPath;
			break;
		}
		DummyPath.MoveParentDirectory();
	}
	return Result;
}




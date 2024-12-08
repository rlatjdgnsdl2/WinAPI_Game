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
		MSGASSERT(Path.string() + " _파일 경로 일때만 GetFileName을 호출할수 있습니다.");
		return "";
	}
	return Path.filename().string();
}


std::string UEnginePath::GetDirectoryName()
{
	if (!IsDirectory()) {
		MSGASSERT(Path.string() + " _디렉토리 경로 일때만 GetDirectoryName을 호출할수 있습니다.");
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
		MSGASSERT("디렉토리 경로일때만 MoveParentToDirectory 를 호출할수 있습니다");
		return false;
	}
	// 현재 path가 디렉토리면
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




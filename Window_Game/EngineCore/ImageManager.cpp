#include "PreCompile.h"
#include "ImageManager.h"

#include <EngineBase/EnginePath.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineString.h>
#include <EngineBase/EngineFile.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>

UImageManager::UImageManager()
{
}

UImageManager::~UImageManager()
{
	{
		std::map<std::string, UEngineWinImage*>::iterator StartIter = Images.begin();
		std::map<std::string, UEngineWinImage*>::iterator EndIter = Images.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			UEngineWinImage* CurRes = StartIter->second;
			if (nullptr != CurRes)
			{
				delete CurRes;
				CurRes = nullptr;
			}
		}
	}

	{
		std::map<std::string, UEngineSprite*>::iterator StartIter = Sprites.begin();
		std::map<std::string, UEngineSprite*>::iterator EndIter = Sprites.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			UEngineSprite* CurRes = StartIter->second;
			if (nullptr != CurRes)
			{
				delete CurRes;
				CurRes = nullptr;
			}
		}
	}
}


void UImageManager::Load(std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	std::string FileName = EnginePath.GetFileName();

	Load(FileName, Path);
}

void UImageManager::LoadFolder(std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	std::string DirName = EnginePath.GetDirectoryName();

	LoadFolder(DirName, Path);
}


void UImageManager::Load(std::string_view _KeyName, std::string_view Path)
{
	UEnginePath EnginePath = UEnginePath(Path);

	if (true == EnginePath.IsDirectory())
	{
		MSGASSERT(std::string(Path) + "_디렉토리는 로드할수 없습니다.");
		return;
	}

	if (false == EnginePath.IsExists())
	{
		MSGASSERT(std::string(Path) + "는 유효하지 않은 파일 경로 입니다.");
		return;
	}

	UEngineWinImage* WindowImage = UEngineAPICore::GetCore()->GetMainWindow().GetWindowImage();

	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (true == Images.contains(UpperName))
	{
		MSGASSERT(UpperName + "는 이미 로드된 Image입니다.");
		return;
	}

	if (true == Sprites.contains(UpperName))
	{
		MSGASSERT(UpperName + "는 이미 로드된 Sprite입니다.");
		return;
	}

	UEngineWinImage* NewImage = new UEngineWinImage();
	NewImage->Load(WindowImage, Path);
	NewImage->SetName(UpperName);
	Images.insert({ UpperName , NewImage });

	// 이미지를 자르는 기준이 되는 위치는 왼쪽 위
	UEngineSprite* NewSprite = new UEngineSprite();
	FTransform Trans;
	Trans.Location = { 0,0 };
	Trans.Scale = NewImage->GetImageScale();
	NewSprite->PushData(NewImage, Trans);
	NewSprite->SetName(UpperName);
	Sprites.insert({ UpperName , NewSprite });
}

void UImageManager::LoadFolder(std::string_view _KeyName, std::string_view _Path)
{
	UEnginePath EnginePath = UEnginePath(_Path);

	if (false == EnginePath.IsExists())
	{
		MSGASSERT(std::string(_Path) + "는 유효하지 않은 파일 경로 입니다.");
		return;
	}

	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (true == Sprites.contains(UpperName))
	{
		MSGASSERT(UpperName + "는 이미 로드된 Sprite입니다.");
		return;
	}


	UEngineSprite* NewSprite = new UEngineSprite();
	NewSprite->SetName(UpperName);
	Sprites.insert({ UpperName , NewSprite });

	// 로드하기 위해서 필요한 Window Main HDC
	UEngineWinImage* WindowImage = UEngineAPICore::GetCore()->GetMainWindow().GetWindowImage();

	UEngineDirectory Dir = _Path;
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		std::string UpperFileName = UEngineString::ToUpper(ImageFiles[i].GetFileName());

		UEngineWinImage* NewImage = FindImage(UpperFileName);
		if (nullptr == NewImage)
		{
			NewImage = new UEngineWinImage();
			NewImage->SetName(UpperFileName);
			NewImage->Load(WindowImage, FilePath);
		}
		Images.insert({ UpperFileName,  NewImage });

		FTransform Transform;
		Transform.Location = { 0, 0 };
		Transform.Scale = NewImage->GetImageScale();

		NewSprite->PushData(NewImage, Transform);
	}
}

void UImageManager::CuttingSprite(std::string_view _KeyName, int _X, int _Y)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT("존재하지 않은 " + std::string(_KeyName) + " 스프라이트를 자르려고 했습니다");
		return;
	}

	if (false == Images.contains(UpperName))
	{
		MSGASSERT("존재하지 않은 이미지를 기반으로 " + std::string(_KeyName) + " 스프라이트를 자르려고 했습니다");
		return;
	}

	UEngineSprite* Sprite = Sprites[UpperName];
	UEngineWinImage* Image = Images[UpperName];

	Sprite->ClearSpriteData();
	Sprite->SetName(UpperName);
	Image->SetName(UpperName);

	FVector2D Scale = Image->GetImageScale();

	Scale.X /= _X;
	Scale.Y /= _Y;

	CuttingSprite(_KeyName, Scale);
}

void UImageManager::CuttingSprite(std::string_view _KeyName, FVector2D _CuttingSize)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT("존재하지 않은 " + std::string(_KeyName) + " 스프라이트를 자르려고 했습니다");
		return;
	}

	if (false == Images.contains(UpperName))
	{
		MSGASSERT("존재하지 않은 이미지를 기반으로 " + std::string(_KeyName) + " 스프라이트를 자르려고 했습니다");
		return;
	}

	UEngineSprite* Sprite = Sprites[UpperName];
	UEngineWinImage* Image = Images[UpperName];

	Sprite->ClearSpriteData();
	Sprite->SetName(UpperName);
	Image->SetName(UpperName);

	if (0 != (Image->GetImageScale().iX() % _CuttingSize.iX()))
	{
		MSGASSERT(std::string(_KeyName)+ "스프라이트 컷팅에 x가 딱 떨어지지 않습니다.");
		return;
	}

	if (0 != (Image->GetImageScale().iY() % _CuttingSize.iY()))
	{
		MSGASSERT(std::string(_KeyName)+ "스프라이트 컷팅에 y가 딱 떨어지지 않습니다." );
		return;
	}

	int SpriteX = Image->GetImageScale().iX() / _CuttingSize.iX();
	int SpriteY = Image->GetImageScale().iY() / _CuttingSize.iY();

	FTransform CuttingTrans;

	CuttingTrans.Location = FVector2D::ZERO;
	CuttingTrans.Scale = _CuttingSize;

	for (size_t y = 0; y < SpriteY; ++y)
	{
		for (size_t x = 0; x < SpriteX; ++x)
		{
			Sprite->PushData(Image, CuttingTrans);
			CuttingTrans.Location.X += _CuttingSize.X;
		}
		CuttingTrans.Location.X = 0.0f;
		CuttingTrans.Location.Y += _CuttingSize.Y;
	}
}

bool UImageManager::IsLoadSprite(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);
	return Sprites.contains(UpperName);
}

UEngineSprite* UImageManager::FindSprite(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Sprites.contains(UpperName))
	{
		MSGASSERT(std::string(_KeyName) + "는 로드하지 않은 Sprite입니다.");
		return nullptr;
	}
	return Sprites[UpperName];
}

UEngineWinImage* UImageManager::FindImage(std::string_view _KeyName)
{
	std::string UpperName = UEngineString::ToUpper(_KeyName);

	if (false == Images.contains(UpperName))
	{
		MSGASSERT(std::string(_KeyName) + "는 로드하지 않은 Image입니다.");
		return nullptr;
	}
	return Images[UpperName];
}



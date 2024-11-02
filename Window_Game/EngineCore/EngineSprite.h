#pragma once

#include <EnginePlatform/EngineWinImage.h>
#include <EngineBase/EngineDebug.h>

// 설명 :
class UEngineSprite : public UObject
{
public:
	class USpriteData
	{
	public:
		// 사용하고자 하는 이미지
		UEngineWinImage* Image;
		// 그 이미지의 트랜스폼
		FTransform Transform;

	};

	// constrcuter destructer
	UEngineSprite();
	~UEngineSprite();

	// delete Function
	UEngineSprite(const UEngineSprite& _Other) = delete;
	UEngineSprite(UEngineSprite&& _Other) noexcept = delete;
	UEngineSprite& operator=(const UEngineSprite& _Other) = delete;
	UEngineSprite& operator=(UEngineSprite&& _Other) noexcept = delete;

	void PushData(UEngineWinImage* Image, const FTransform& _Trans);
	USpriteData GetSpriteData(int _Index = 0)
	{
		if (_Index >= Data.size())
		{
			MSGASSERT(GetName() + " Sprite의 Index를 오버하여 사용하려고 했습니다.");
		}
		return Data[_Index];
	}

	void ClearSpriteData()
	{
		Data.clear();
	}

protected:
	std::vector<USpriteData> Data;
};



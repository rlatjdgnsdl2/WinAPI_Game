#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>

#include <EnginePlatform/EngineWinImage.h>
#include "EngineSprite.h"

// 설명 :
class UImageManager
{
public:
	// constrcuter destructer
	~UImageManager();

	// delete Function
	UImageManager(const UImageManager& _Other) = delete;
	UImageManager(UImageManager&& _Other) noexcept = delete;
	UImageManager& operator=(const UImageManager& _Other) = delete;
	UImageManager& operator=(UImageManager&& _Other) noexcept = delete;

	static UImageManager& GetInst()
	{
		static UImageManager Inst;
		return Inst;
	}

	// 자동으로 파일명이 키네임
	void Load(std::string_view Path);
	void LoadFolder(std::string_view Path);
	// 실제 로드는 여기에서 처리
	void Load(std::string_view _KeyName, std::string_view Path);
	void LoadFolder(std::string_view _KeyName, std::string_view Path);


	//	이미지가 동일한 간격으로 있을때 행과 열 기준 컷팅
	void CuttingSprite(std::string_view _KeyName, int _X, int _Y);
	//	사용자 정의 컷팅
	void CuttingSprite(std::string_view _KeyName, FVector2D _CuttingSize);
	void CuttingSprite(std::string_view _NewSpriteName, std::string_view _Image, FVector2D _CuttingSize);

	bool IsLoadSprite(std::string_view _KeyName);

	UEngineSprite* FindSprite(std::string_view _KeyName);
	UEngineWinImage* FindImage(std::string_view _KeyName);

protected:

private:
	UImageManager();
	std::map<std::string, UEngineWinImage*> Images;
	std::map<std::string, UEngineSprite*> Sprites;

};


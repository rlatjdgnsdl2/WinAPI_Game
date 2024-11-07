#pragma once
#include <list>
#include <vector>
#include <map>
#include <string>

#include <EnginePlatform/EngineWinImage.h>
#include "EngineSprite.h"

// ���� :
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

	// �ڵ����� ���ϸ��� Ű����
	void Load(std::string_view Path);
	void LoadFolder(std::string_view Path);
	// ���� �ε�� ���⿡�� ó��
	void Load(std::string_view _KeyName, std::string_view Path);
	void LoadFolder(std::string_view _KeyName, std::string_view Path);


	//	�̹����� ������ �������� ������ ��� �� ���� ����
	void CuttingSprite(std::string_view _KeyName, int _X, int _Y);
	//	����� ���� ����
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


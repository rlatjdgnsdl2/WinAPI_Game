#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ACharacterSelect :public AActor
{
public:
	//	constrcuter, destructer
	ACharacterSelect();
	virtual ~ACharacterSelect();

	//	delete Function
	ACharacterSelect(const ACharacterSelect& _Other) = delete;
	ACharacterSelect(ACharacterSelect&& _Other) noexcept = delete;
	ACharacterSelect& operator=(const ACharacterSelect& _Other) = delete;
	ACharacterSelect& operator=(ACharacterSelect&& _Other) noexcept = delete;

	virtual void BeginPlay()override;

protected:

private:
	class USpriteRenderer* BorderUI;
	FVector2D ImageSize = { 120,120 };
	std::map<std::string,class USpriteRenderer*> CharacterImages;

};


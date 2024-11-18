#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ACharacterSelect :public AActor
{
public:
	enum class SelectType {
		Player,
		Partner
	};
	//	constrcuter, destructer
	ACharacterSelect();
	virtual ~ACharacterSelect();

	//	delete Function
	ACharacterSelect(const ACharacterSelect& _Other) = delete;
	ACharacterSelect(ACharacterSelect&& _Other) noexcept = delete;
	ACharacterSelect& operator=(const ACharacterSelect& _Other) = delete;
	ACharacterSelect& operator=(ACharacterSelect&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;

protected:

private:
	SelectType CurSelectType = SelectType::Player;
	class USpriteRenderer* BorderUI;
	class USpriteRenderer* BoxUI;
	FVector2D ImageSize = { 120,120 };
	std::unordered_map<std::string, class USpriteRenderer*> CharacterImages;
	std::unordered_map<std::string, class USpriteRenderer*> ::iterator CurIter;


};


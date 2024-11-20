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
	virtual void Tick(float _DeltaTime)override;

protected:

private:
	const FVector2D ImageSize = { 120,120 };
	std::unordered_map<std::string, class USpriteRenderer*> PlayerCharacterImages;
	std::unordered_map<std::string, class USpriteRenderer*> PartnerCharacterImages;
	std::unordered_map<std::string, class USpriteRenderer*> ::iterator CurIter;

	class ABox* CharacterTable;
	class AText* Mudkip_Text;
	class AText* Chikorita_Text;
	class AText* Pikachu_Text;

	class AText* ExplanationText01;
	class AText* ExplanationText02;



};


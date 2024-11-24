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
	virtual void LevelChangeStart()override;
	virtual void LevelChangeEnd()override;

protected:

private:
	const FVector2D ImageSize = { 120,120 };
	std::map<std::string, class USpriteRenderer*> PlayerCharacterImages;
	std::map<std::string, class USpriteRenderer*> ::iterator CurIter;
	class AFade* Fade = nullptr;
	float CurDuration = 0.0f;

	bool IsNextLevel = false;
	bool IsPlayerSelect = false;
	bool IsPartnerSelect = false;
	std::string PlayerName;
	std::string PartnerName;


	class ABox* CharacterTable = nullptr;
	class ABoxUI* CharacterName = nullptr;
	class ABoxUI* SelectPokemon = nullptr;
	

	class AText* ExplanationText01 = nullptr;
	class AText* ExplanationText02 = nullptr;



};


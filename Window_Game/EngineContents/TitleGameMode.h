#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineBase/EngineRandom.h>



//	Ό³Έν:
class ATitleGameMode :public AGameMode
{
public:
	//	constrcuter, destructer
	ATitleGameMode();
	virtual ~ATitleGameMode();

	//	delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd() override;

	void SpawnPetals();


protected:

private:
	UEngineRandom Random;
	float TitlePlayTime = 0.0f;
	float FadeTime = 0.0f;
	float CurDuration = 0.0f;
	class ATitleBackground* TitleBackGround;
	class ATitleAnim* TitleAnim;
	class ATitleLogo* TitleLogo;
	USoundPlayer BGMPlayer;
	bool IsNextLevel = false;
	class AFade* Fade = nullptr;

	bool IsPetals = false;

	std::vector<class ATitlePetal*> PetalList;


	FVector2D UpPower = FVector2D::ZERO;
};


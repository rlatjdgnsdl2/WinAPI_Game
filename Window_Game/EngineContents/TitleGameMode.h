#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>



//	����:
class ATitleGameMode:public AGameMode
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
	
	
protected:

private:
	float TitlePlayTime = 0.0f;
	class ATitleBackground* TitleBackGround;
	class ATitleAnim* TitleAnim;
	class ATitleLogo* TitleLogo;
	USoundPlayer BGMPlayer;

	FVector2D LeftAcceleration = FVector2D::LEFT;
	FVector2D UpAcceleration = FVector2D::UP;
};


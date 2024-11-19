#pragma once
#include <EngineCore/GameMode.h>

//	Ό³Έν:
class ACharacterSelectGameMode :public AGameMode
{
public:
	//	constrcuter, destructer
	ACharacterSelectGameMode();
	virtual ~ACharacterSelectGameMode();

	//	delete Function
	ACharacterSelectGameMode(const ACharacterSelectGameMode& _Other) = delete;
	ACharacterSelectGameMode(ACharacterSelectGameMode&& _Other) noexcept = delete;
	ACharacterSelectGameMode& operator=(const ACharacterSelectGameMode& _Other) = delete;
	ACharacterSelectGameMode& operator=(ACharacterSelectGameMode&& _Other) noexcept = delete;

	virtual void LevelChangeStart()override;
	virtual void LevelChangeEnd()override;



protected:

private:
	class USpriteRenderer* BackGround;
	
	


};


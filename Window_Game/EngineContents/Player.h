#pragma once
#include <EngineCore/Actor.h>

//	����:
class APlayer :public AActor
{
public:
	//	constrcuter, destructer
	APlayer();
	virtual ~APlayer();

	//	delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



protected:

private:
	class USpriteRenderer* SpriteRenderer;
	void InitSetting();
	void AnimationSetting();
	void KeySetting(float _DeltaTime);
	
	float CurTime = 0.0f;

	

};


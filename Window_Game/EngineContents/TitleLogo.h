#pragma once
#include <EngineCore/Actor.h>
//	Ό³Έν:
class ATitleLogo :public AActor
{
public:
	//	constrcuter, destructer
	ATitleLogo();
	virtual ~ATitleLogo();

	//	delete Function
	ATitleLogo(const ATitleLogo& _Other) = delete;
	ATitleLogo(ATitleLogo&& _Other) noexcept = delete;
	ATitleLogo& operator=(const ATitleLogo& _Other) = delete;
	ATitleLogo& operator=(ATitleLogo&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;

protected:

private:
	class USpriteRenderer* SpriteRenderer = nullptr;
	class AText* TitleText = nullptr;
	float CurDuration = 0.0f;

};


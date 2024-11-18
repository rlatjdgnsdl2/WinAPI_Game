#pragma once
#include <EngineCore/Actor.h>


//	Ό³Έν:
class ASpecialSkill : public AActor
{
public:
	//	constrcuter, destructer
	ASpecialSkill();
	virtual ~ASpecialSkill();

	//	delete Function
	ASpecialSkill(const ASpecialSkill& _Other) = delete;
	ASpecialSkill(ASpecialSkill&& _Other) noexcept = delete;
	ASpecialSkill& operator=(const ASpecialSkill& _Other) = delete;
	ASpecialSkill& operator=(ASpecialSkill&& _Other) noexcept = delete;

	
	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;

protected:
	class USpriteRenderer* SpriteRenderer;

private:

};


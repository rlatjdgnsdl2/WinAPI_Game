#pragma once
#include <EngineCore/Actor.h>


//	Ό³Έν:
class ASpecialSkill : public AActor
{
public:
	//	constrcuter, destructer
	ASpecialSkill(std::string_view _SkillName);
	virtual ~ASpecialSkill();
	

	//	delete Function
	ASpecialSkill(const ASpecialSkill& _Other) = delete;
	ASpecialSkill(ASpecialSkill&& _Other) noexcept = delete;
	ASpecialSkill& operator=(const ASpecialSkill& _Other) = delete;
	ASpecialSkill& operator=(ASpecialSkill&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;
	bool IsAttack();

protected:

private:
	std::string SkillName = "";
	class USpriteRenderer* SpriteRenderer = nullptr;
	class APlayer* Player = nullptr;
	class APokemon* Target = nullptr;
	
	
	


};


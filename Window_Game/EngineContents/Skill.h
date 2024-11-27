#pragma once
#include <EngineCore/Actor.h>

enum class SkillState {
	Ready,
	Start,
	Update,
	End
};

//	Ό³Έν:
class ASkill : public AActor
{
public:
	//	constrcuter, destructer
	ASkill(std::string_view _SkillName);
	virtual ~ASkill();

	//	delete Function
	ASkill(const ASkill& _Other) = delete;
	ASkill(ASkill&& _Other) noexcept = delete;
	ASkill& operator=(const ASkill& _Other) = delete;
	ASkill& operator=(ASkill&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;

	class USpriteRenderer* GetSpriteRenderer() { return SpriteRenderer; }
	void SetAttacker(class APokemon* _Attacker);
	void SetTarget(class APokemon* _Target) { Target = _Target; }

	
	virtual void StartSkill();
	virtual void UpdateSkill(float _DeltaTime);
	virtual void EndSkill();


	const FIntPoint GetTile() {
		return ((GetActorLocation().ConvertToPoint()) / 72);
	}
	const FVector2D GetTargetLocation() const {
		return TargetLocation;
	}
	const FIntPoint GetTargetTile() {
		return ((TargetLocation.ConvertToPoint()) / 72);
	}
	void SetTargetLocation(const FVector2D& _TargetLocation) {
		TargetLocation = _TargetLocation;
		StartLocation = GetActorLocation();
	}
	void SetTargetTile(const FIntPoint& _TargetTileIndex) {
		TargetLocation = _TargetTileIndex * 72.0f;
		StartLocation = GetActorLocation();
	}

	void SetSkillFunction(std::function<void()> _Function) {
		SkillFunction = _Function;
	}

	bool IsAttack() const {
		return IsAttackVal;
	}


	


protected:

private:
	std::string SkillName = "";
	SkillState CurState = SkillState::Start;

	bool IsAttackVal = false;

	class USpriteRenderer* SpriteRenderer = nullptr;
	class APokemon* SkillUser = nullptr;
	class APokemon* Target = nullptr;

	float CurDuration = 0.0f;
	FVector2D StartLocation = FVector2D::ZERO;
	FVector2D TargetLocation = FVector2D::ZERO;

	std::function<void()> SkillFunction = nullptr;






};


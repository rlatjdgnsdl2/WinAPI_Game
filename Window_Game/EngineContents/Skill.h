#pragma once
#include <EngineCore/Actor.h>

enum class SkillState {
	None,
	Start,
	Update,
	End
};

//	설명:
class ASkill : public AActor
{
public:
	//	constrcuter, destructer
	ASkill(std::string_view SkillName);
	virtual ~ASkill();

	//	delete Function
	ASkill(const ASkill& _Other) = delete;
	ASkill(ASkill&& _Other) noexcept = delete;
	ASkill& operator=(const ASkill& _Other) = delete;
	ASkill& operator=(ASkill&& _Other) noexcept = delete;

	void virtual Tick(float _DeltaTime)override;

	void SetUserPokemon(class APokemon* _UserPokemon);

	void SetTargetPokemon(class APokemon* _TargetPokemon) {
		TargetPokemon = _TargetPokemon;
	}
	void SetDir(DIR _Dir) {
		Dir = _Dir;
	}
	void SetTile(const FIntPoint& _CurTileIndex) {
		SetActorLocation(_CurTileIndex * 72.0f);
	}
	const FIntPoint GetTile() {
		return ((GetActorLocation().ConvertToPoint()) / 72);
	}

	//	이동관련
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
	void ResetCurDuration() {
		CurDuration = 0.0f;
	}
	




	void StartSkill();
	void UpdateSkill(float _DeltaTime);
	void EndSkill();
	bool IsAttack();

protected:

private:
	DIR Dir = DIR::Down;


	class USpriteRenderer* SpriteRenderer = nullptr;
	float CurDuration = 0.0f;

	SkillState CurSkillState =  SkillState::None;
	FVector2D StartLocation = FVector2D::ZERO;
	FVector2D TargetLocation = FVector2D::ZERO;

	class APokemon* UserPokemon = nullptr;
	class APokemon* TargetPokemon = nullptr;

};


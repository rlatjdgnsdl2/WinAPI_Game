#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform/EngineSound.h>
#include "PokemonAbility.h"

//	����:
class APokemon :public AActor
{
public:

	//	constrcuter, destructer
	APokemon();
	virtual ~APokemon();

	//	delete Function
	APokemon(const APokemon& _Other) = delete;
	APokemon(APokemon&& _Other) noexcept = delete;
	APokemon& operator=(const APokemon& _Other) = delete;
	APokemon& operator=(APokemon&& _Other) noexcept = delete;

	virtual void SetPokemon(std::string_view _PokemonName);
	virtual void AnimSet();
	virtual void Idle();
	virtual void Move(float _DeltaTime);
	virtual void Skill();
	virtual void Hurt();

	const CampType GetCamp() const { return Camp; }
	const DIR& GetDir() const { return Dir; }
	void SetCamp(CampType _CampType) { Camp = _CampType; }
	void SetDir(DIR _dir) { Dir = _dir; }
	//	�̵�
	void ResetCurDuration();
	const FVector2D& GetTargetLocation() const;
	const FIntPoint GetTargetTile();
	const FIntPoint GetTile();
	void SetTargetLocation(const FVector2D& _TargetLocation);
	void SetTargetTile(const FIntPoint& _TargetTileIndex);
	void SetTile(FIntPoint& _CurTileIndex);

	//	����
	const SkillType& GetSkillType() const;
	class APokemon* GetTargetPokemon() const;
	void SetSkillType(SkillType _SkillType);
	void SetTargetPokemon(class APokemon* _TargetPokemon);
	void StartAttack();
	virtual void EndAttack();
	bool IsAttack();
	void PlayHurtAnim();

	PokemonAbility& GetCurAbility() {
		return CurAbility;
	}

protected:
	class USpriteRenderer* SpriteRenderer;
	PokemonAbility CurAbility;
	UEngineSound BGMPlayer;

	bool IsAttackValue;
	bool IsHurtValue;
	//	�⺻
	CampType Camp;
	DIR Dir;
	//	�̵�����
	float CurDuration;
	FVector2D StartLocation;
	FVector2D TargetLocation;
	//	��������
	class APokemon* TargetPokemon;
	SkillType CurSkill;
private:




};


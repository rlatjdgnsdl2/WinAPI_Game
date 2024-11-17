#pragma once
#include "Pokemon.h"




//	Ό³Έν:
class APlayer :public APokemon
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

	virtual void BeginPlay()override;
	virtual void LevelChangeStart()override;
	virtual void Tick(float _DeltaTime)override;
	virtual void SetPokemon(std::string_view _PokemonName) override;
	//virtual void EndAttack()override;

	virtual void SetCamp(CampType _Camp) {
		Camp = _Camp;
	}
	virtual CampType GetCamp() {
		return Camp;
	}

protected:

private:
	std::map<std::string,class USpriteRenderer*> UIRenderers;
	CampType Camp = CampType::Player;

};


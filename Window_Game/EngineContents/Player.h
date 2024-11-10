#pragma once
#include "Pokemon.h"




//	����:
class APlayer :public APokemon
{
public:
	friend class ATurnManager;

	//	constrcuter, destructer
	APlayer();
	APlayer(std::string_view _CurPokemonName);
	virtual ~APlayer();

	//	delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void Tick(float _DeltaTime)override;
	void LevelChangeStart() override;

protected:

private:
	
	virtual void AnimationSetting() override;
	
};


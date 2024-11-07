#pragma once
#include "Pokemon.h"

//	Ό³Έν:
class AEnemy : public APokemon
{
public:
	//	constrcuter, destructer
	AEnemy();
	virtual ~AEnemy();

	//	delete Function
	AEnemy(const AEnemy& _Other) = delete;
	AEnemy(AEnemy&& _Other) noexcept = delete;
	AEnemy& operator=(const AEnemy& _Other) = delete;
	AEnemy& operator=(AEnemy&& _Other) noexcept = delete;

	virtual void LevelChangeStart();

protected:

private:
	virtual void AnimationSetting()=0;

};


#pragma once
#include "Pokemon.h"

//	Ό³Έν:
class Enemy : public APokemon
{
public:
	//	constrcuter, destructer
	Enemy();
	virtual ~Enemy();

	//	delete Function
	Enemy(const Enemy& _Other) = delete;
	Enemy(Enemy&& _Other) noexcept = delete;
	Enemy& operator=(const Enemy& _Other) = delete;
	Enemy& operator=(Enemy&& _Other) noexcept = delete;

	virtual void LevelChangeStart();

protected:

private:
	virtual void AnimationSetting()=0;

};


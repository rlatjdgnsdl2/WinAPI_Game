#pragma once
#include "Pokemon.h"

//	Ό³Έν:
class APartner : public APokemon
{
public:
	//	constrcuter, destructer
	APartner();
	virtual ~APartner();

	//	delete Function
	APartner(const APartner& _Other) = delete;
	APartner(APartner&& _Other) noexcept = delete;
	APartner& operator=(const APartner& _Other) = delete;
	APartner& operator=(APartner&& _Other) noexcept = delete;
	
	virtual void LevelChangeStart();


protected:

private:
	virtual void AnimationSetting() override;

};


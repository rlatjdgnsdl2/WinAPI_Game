#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class APartner : public AActor
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

protected:

private:

};


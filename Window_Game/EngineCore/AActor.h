#pragma once
#include <EngineBase/EngineMath.h>
class AActor
{
private:
	FIntPoint actorPos;
	
	
public:
	virtual void BeginPlay();
	virtual void Tick();

	FIntPoint GetActorPos() const;
	void SetActorPos(FIntPoint _pos);


	

};


#pragma once
#include <EngineCore/Actor.h>

//	����:
class APlayer :public AActor
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

	

protected:

private:
	class USpriteRenderer* SpriteRenderer;

};


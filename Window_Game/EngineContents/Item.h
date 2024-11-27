#pragma once
#include <EngineCore/Actor.h>
//	Ό³Έν:
class AItem :public AActor
{
public:
	//	constrcuter, destructer
	AItem(std::string_view _ItemName);
	virtual ~AItem();

	//	delete Function
	AItem(const AItem& _Other) = delete;
	AItem(AItem&& _Other) noexcept = delete;
	AItem& operator=(const AItem& _Other) = delete;
	AItem& operator=(AItem&& _Other) noexcept = delete;

	virtual void BeginPlay() override;
	virtual void Tick(float _DeltaTime) override;

	



protected:

private:
	class USpriteRenderer* ItemRenderer;	
	class APlayer* Player;
};


#pragma once
#include <EngineCore/Actor.h>
//	Ό³Έν:
class AItem :public AActor
{
public:
	//	constrcuter, destructer
	AItem();
	AItem(std::string_view _ItemName);
	virtual ~AItem();

	//	delete Function
	AItem(const AItem& _Other) = delete;
	AItem(AItem&& _Other) noexcept = delete;
	AItem& operator=(const AItem& _Other) = delete;
	AItem& operator=(AItem&& _Other) noexcept = delete;

	



protected:

private:
	class USpriteRenderer* ItemRenderer;	

};


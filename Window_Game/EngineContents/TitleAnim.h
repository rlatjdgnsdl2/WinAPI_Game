#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATitleAnim :public AActor
{
public:
	//	constrcuter, destructer
	ATitleAnim();
	virtual ~ATitleAnim();

	//	delete Function
	ATitleAnim(const ATitleAnim& _Other) = delete;
	ATitleAnim(ATitleAnim&& _Other) noexcept = delete;
	ATitleAnim& operator=(const ATitleAnim& _Other) = delete;
	ATitleAnim& operator=(ATitleAnim&& _Other) noexcept = delete;

	void LevelChangeStart() override;
	void PlayAnimation(float _DeltaTime);


protected:

private:
	class USpriteRenderer* SpriteRenderer;
	FVector2D MoveVec = FVector2D({ -1,1 });
	FVector2D UpPower = FVector2D::UP;
};


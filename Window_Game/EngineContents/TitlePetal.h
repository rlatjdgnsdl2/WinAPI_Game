#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/EngineRandom.h>
// Ό³Έν :
class ATitlePetal : public AActor
{
public:
	// constrcuter destructer
	ATitlePetal();
	ATitlePetal(FVector2D _Location);
	virtual ~ATitlePetal();

	// delete Function
	ATitlePetal(const ATitlePetal& _Other) = delete;
	ATitlePetal(ATitlePetal&& _Other) noexcept = delete;
	ATitlePetal& operator=(const ATitlePetal& _Other) = delete;
	ATitlePetal& operator=(ATitlePetal&& _Other) noexcept = delete;

	virtual void BeginPlay() override;
	virtual void Tick(float _DeltaTime) override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd() override;

	void SetSmall(bool _IsSmall) { IsSmall = _IsSmall; }	



protected:

private:
	UEngineRandom Random;
	int Speed;
	class USpriteRenderer* SpriteRenderer = nullptr;
	bool IsSmall = true;
	

};


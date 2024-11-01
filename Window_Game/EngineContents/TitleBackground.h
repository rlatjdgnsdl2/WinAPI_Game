#pragma once
#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATitleBackground : public AActor
{
public:
	//	constrcuter, destructer
	ATitleBackground();
	~ATitleBackground();

	//	delete Function
	ATitleBackground(const ATitleBackground& _Other) = delete;
	ATitleBackground(ATitleBackground&& _Other) noexcept = delete;
	ATitleBackground& operator=(const ATitleBackground& _Other) = delete;
	ATitleBackground& operator=(ATitleBackground&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
		
	
protected:

private:
	class USpriteRenderer* SpriteRenderer;
	
	
	
};


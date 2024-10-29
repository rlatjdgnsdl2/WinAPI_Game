#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class ATempPlayer : public AActor
{
public:
	//	constrcuter, destructer
	ATempPlayer();
	~ATempPlayer();

	//	delete Function
	ATempPlayer(const ATempPlayer& _Other) = delete;
	ATempPlayer(ATempPlayer&& _Other) noexcept = delete;
	ATempPlayer& operator=(const ATempPlayer& _Other) = delete;
	ATempPlayer& operator=(ATempPlayer&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void Render() override;
protected:

private:

};


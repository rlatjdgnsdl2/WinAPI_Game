#pragma once
#include <EngineCore/Actor.h>

//	����:
class ATempActor :public AActor
{
public:
	//	constrcuter, destructer
	ATempActor();
	~ATempActor();

	//	delete Function
	ATempActor(const ATempActor& _Other) = delete;
	ATempActor(ATempActor&& _Other) noexcept = delete;
	ATempActor& operator=(const ATempActor& _Other) = delete;
	ATempActor& operator=(ATempActor&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void Render() override;
protected:

private:
};


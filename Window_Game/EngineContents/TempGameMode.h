#pragma once
#include <EngineCore/GameMode.h>

//	Ό³Έν:
class ATempGameMode : public AGameMode
{
public:
	//	constrcuter, destructer
	ATempGameMode();
	~ATempGameMode();

	//	delete Function
	ATempGameMode(const ATempGameMode& _Other) = delete;
	ATempGameMode(ATempGameMode&& _Other) noexcept = delete;
	ATempGameMode& operator=(const ATempGameMode& _Other) = delete;
	ATempGameMode& operator=(ATempGameMode&& _Other) noexcept = delete;

protected:

private:

};


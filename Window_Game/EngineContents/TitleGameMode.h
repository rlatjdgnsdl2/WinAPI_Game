#pragma once
#include <EngineCore/GameMode.h>

//	Ό³Έν:
class ATitleGameMode:public AGameMode
{
public:
	//	constrcuter, destructer
	ATitleGameMode();
	virtual ~ATitleGameMode();

	//	delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd() override;
	
	float GetTitlePlayTime();
	void ResetTitlePlayTime();
	
protected:

private:
	float TitlePlayTime = 0.0f;
	class ATitleBackground* TitleBackGround;
	class ATitleAnim* TitleAnim;
};


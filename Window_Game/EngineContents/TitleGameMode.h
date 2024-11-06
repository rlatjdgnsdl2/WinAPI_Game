#pragma once
#include <EngineCore/GameMode.h>

//	����:
class ATitleGameMode:public AGameMode
{
public:
	//	constrcuter, destructer
	ATitleGameMode();
	~ATitleGameMode();

	//	delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd() override;
	
	static float GetTitlePlayTime();
	static void ResetTitlePlayTime();
	
protected:

private:
	static inline float TitlePlayTime = 0.0f;
};


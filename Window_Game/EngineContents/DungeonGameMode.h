#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>


//	����: �ϸŴ��� ���� ���
class ADungeonGameMode : public AGameMode
{
public:
	
	//	constrcuter, destructer
	ADungeonGameMode();
	virtual ~ADungeonGameMode();



	//	delete Function
	ADungeonGameMode(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode(ADungeonGameMode&& _Other) noexcept = delete;
	ADungeonGameMode& operator=(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode& operator=(ADungeonGameMode&& _Other) noexcept = delete;

	virtual void Tick(float _DeltaTime)override;
	virtual void BeginPlay() override;
	virtual void LevelChangeStart() override;
	virtual void LevelChangeEnd() override;
	

protected:

private:
	USoundPlayer BGMPlayer;

	
	




};


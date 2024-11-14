#pragma once
#include <EngineCore/GameMode.h>

//	설명: 던전 내 UI
class ADungeonUI :public AGameMode
{
public:
	
	//	constrcuter, destructer
	ADungeonUI();
	virtual ~ADungeonUI();

	//	delete Function
	ADungeonUI(const ADungeonUI& _Other) = delete;
	ADungeonUI(ADungeonUI&& _Other) noexcept = delete;
	ADungeonUI& operator=(const ADungeonUI& _Other) = delete;
	ADungeonUI& operator=(ADungeonUI&& _Other) noexcept = delete;

	virtual void LevelChangeStart() override;
	virtual void BeginPlay() override;



protected:


private:
	std::string TextSpriteName;
	FVector2D TextScale;
	std::vector<class USpriteRenderer*> Renders;
	




};


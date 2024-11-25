#include "PreCompile.h"
#include "UIManager.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "BoxUI.h"
#include "Player.h"


AUIManager::AUIManager() 
{

}

AUIManager::~AUIManager() 
{

}

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());

	MenuUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 200,350 }, { 25,50 }));
	MenuUI->CreateString("Skill");
	MenuUI->CreateString("Item");
	MenuUI->CreateString("Close");

	MyInfoUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 750.0f, 150.0f }, { 25, 400 }));
	MyInfoUI->CreateString("");
	MyInfoUI->CreateString("");

	SkillUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 400, 200 }, { 25, 50 }));
	SkillUI->CreateString("Fire_Bomb");
	SkillUI->CreateString("Lightning_Bomb");
	SkillUI->CreateString("Water_Bomb");
	SkillInfoUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 700, 120 }, { 25, 350 }));
	SkillInfoUI->CreateString("");

	ItemUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 400, 300 }, { 25, 50 }));

	CreateTopUI("UI_B", "DungeonFont_B.png");
	CreateTopUI("UI_FVal", "DungeonFont_0.png");
	CreateTopUI("UI_F", "DungeonFont_F.png", 10.0f);
	CreateTopUI("UI_Lv", "DungeonFont_Lv.png");
	CreateTopUI("UI_LvVal10", "DungeonFont_0.png");
	CreateTopUI("UI_LvVal01", "DungeonFont_0.png", 100.0f);
	CreateTopUI("UI_Hp", "DungeonFont_Hp.png");
	CreateTopUI("UI_CurHpVal10", "DungeonFont_0.png");
	CreateTopUI("UI_CurHpVal01", "DungeonFont_0.png");
	CreateTopUI("UI_Slash", "DungeonFont_Slash.png");
	CreateTopUI("UI_MaxHpVal10", "DungeonFont_0.png");
	CreateTopUI("UI_MaxHpVal01", "DungeonFont_0.png");

	for (int i = 0; i < HpBar.size(); i++)
	{
		HpBar[i] = CreateDefaultSubObject<USpriteRenderer>();
		HpBar[i]->SetSprite("Dungeon_HpBar.png");
		FVector2D HpBarScale = HpBar[i]->SetSpriteScale(1.0f);
		HpBar[i]->SetCameraEffect(false);
		HpBar[i]->SetComponentLocation(UIStartPos);
		UIStartPos.X += HpBarScale.X;
		HpBar[i]->SetOrder(ERenderOrder::UI_Basic);
		HpBar[i]->SetSpriteScale(0.0f);
	}
	DungeonNameUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 450.0f, 80.0f }, { 250, 100 }));
	DungeonNameUI->CreateString("");

	Q_NextFloorUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 500.0f, 100.0f }, { 100, 100 }));
	Q_NextFloorUI->CreateString("Do you Want to go Next Floor?");
	A_NextFloorUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 150.0f, 110.0f }, { 600, 100 }));
	A_NextFloorUI->CreateString("Yes");
	A_NextFloorUI->CreateString("No");
	A_NextFloorUI->ResetTextIter();

	LogBoxUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 700.0f, 150.0f }, { 50, 400 }));
	CurMenu = MenuType::None;
}

void AUIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	switch (CurMenu)
	{
	case MenuType::None:
		if (true == UEngineInput::GetInst().IsDown('Q')){
			CurMenu = MenuType::OpenMenu;		
		}
		break;
	case MenuType::OpenMenu:
		OpenMenu();
		break;
	case MenuType::ShowMenu:
		ShowMenu();
		break;
	case MenuType::CloseMenu:
		CloseMenu();
		break;



	case MenuType::OpenSkill:
		OpenSkill();
		break;
	case MenuType::ShowSkill:
		ShowSkill();
		break;
	case MenuType::CloseSkill:
		CloseSkill();
		break;
	case MenuType::OpenItem:
		break;
	default:
		break;
	}
	if (CurLevelName == "DungeonLevel")
	{
		int CurHp = Player->GetCurHP();
		int MaxHp = Player->GetMaxHP();
		TopUI["UI_LvVal10"]->SetSprite(std::format("DungeonFont_{}.png", Player->GetLevel() / 10));
		TopUI["UI_LvVal01"]->SetSprite(std::format("DungeonFont_{}.png", Player->GetLevel() % 10));
		TopUI["UI_CurHpVal10"]->SetSprite(std::format("DungeonFont_{}.png", CurHp / 10));
		TopUI["UI_CurHpVal01"]->SetSprite(std::format("DungeonFont_{}.png", CurHp % 10));
		TopUI["UI_MaxHpVal10"]->SetSprite(std::format("DungeonFont_{}.png", MaxHp / 10));
		TopUI["UI_MaxHpVal01"]->SetSprite(std::format("DungeonFont_{}.png", MaxHp % 10));
		for (int i = 0; i < MaxHp; i++) {
			if (i < CurHp) {
				HpBar[i]->SetSprite("Dungeon_HpBar.png");
				HpBar[i]->SetSpriteScale(1.0f);
			}
			else {
				HpBar[i]->SetSprite("Dungeon_DamageBar.png");
				HpBar[i]->SetSpriteScale(1.0f);
			}
		}
	}


}



void AUIManager::CreateTopUI(const std::string& key, const std::string& spriteName, float offsetX)
{
	USpriteRenderer* UIRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UIRenderer->SetSprite(spriteName);
	FVector2D UIScale = UIRenderer->SetSpriteScale();
	UIRenderer->SetCameraEffect(false);
	UIRenderer->SetComponentLocation(UIStartPos);
	UIStartPos.X += UIScale.X + offsetX;
	UIRenderer->SetOrder(ERenderOrder::UI_Basic);
	TopUI.insert({ key, UIRenderer });
}


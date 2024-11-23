#include "PreCompile.h"
#include "DungeonUI.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include "Player.h"
#include "BasicUI.h"

#include "DungeonGameMode.h"
#include "Dungeon_BSP.h"
#include "Box.h"
#include "Text.h"
#include "TurnManager.h"


#include "BoxUI.h"




ADungeonUI::ADungeonUI() :IsAskValue(false), IsNewLogValue(false)
{
	HpBar.resize(300, nullptr);

}

ADungeonUI::~ADungeonUI()
{

}

void ADungeonUI::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());
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

}

void ADungeonUI::LevelChangeStart()
{
	Super::LevelChangeStart();
	TopUI["UI_FVal"]->SetSprite(std::format("DungeonFont_{}.png", Dungeon->GetCurFloor()));
}

void ADungeonUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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
	//	던전이름UI
	if (BasicUI->GetCurMenuType() == MenuType::ShowMenu) {
		DungeonNameUI->SetString(0, std::format("      {}", Dungeon->GetName()));
		DungeonNameUI->SetStringColor(0, "Yellow");
		DungeonNameUI->ShowUI();
	}
	else {
		DungeonNameUI->HideUI();
	}
	if (IsAskValue == true) {
		AText* Text = *(A_NextFloorUI->GetCurTextIter());
		A_NextFloorUI->SetStringColor(Text, "Yellow");
		if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD8)) {
			A_NextFloorUI->SetStringColor(*(A_NextFloorUI->GetCurTextIter()), "White");
			A_NextFloorUI->PrevTextIter();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD2)) {
			A_NextFloorUI->SetStringColor(*(A_NextFloorUI->GetCurTextIter()), "White");
			A_NextFloorUI->NextTextIter();
		}


		if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
			if (Text->GetString() == "Yes") {
				HideNextFloorUI();
				Dungeon->NextFloor();
				UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
			}
			else if (Text->GetString() == "No") {
				HideNextFloorUI();
				TurnManager->ComeBackTurn();
			}
		}
	}

	if (IsNewLogValue == true) {
		LogBoxUI->ShowUI();
	}
	else {
		LogBoxUI->HideUI();
	}





}


void ADungeonUI::CreateTopUI(const std::string& key, const std::string& spriteName, float offsetX)
{
	USpriteRenderer* UIElement = CreateDefaultSubObject<USpriteRenderer>();
	UIElement->SetSprite(spriteName);
	FVector2D UIScale = UIElement->SetSpriteScale();
	UIElement->SetCameraEffect(false);
	UIElement->SetComponentLocation(UIStartPos);
	UIStartPos.X += UIScale.X + offsetX;
	UIElement->SetOrder(ERenderOrder::UI_Basic);
	TopUI.insert({ key, UIElement });
}





void ADungeonUI::NewLogMessage(const std::string_view _Message)
{
	LogBoxUI->NewMessage(_Message);
	IsNewLogValue = true;
}

void ADungeonUI::IsGoingNextFloor()
{
	Q_NextFloorUI->ShowUI();
	A_NextFloorUI->ShowUI();
	IsAskValue = true;
}

void ADungeonUI::HideNextFloorUI()
{
	Q_NextFloorUI->HideUI();
	A_NextFloorUI->HideUI();
	IsAskValue = false;
}







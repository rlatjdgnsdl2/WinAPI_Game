#include "PreCompile.h"
#include "DungeonUI.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>
#include "Player.h"
#include "BasicUI.h"

#include "AbilityController.h"
#include "DungeonGameMode.h"
#include "Dungeon_BSP.h"
#include "Box.h"
#include "Text.h"
#include "TurnManager.h"


#include "BoxUI.h"




ADungeonUI::ADungeonUI()
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
	UI_B = CreateDefaultSubObject<USpriteRenderer>();
	UI_B->SetSprite("DungeonFont_B.png");
	FVector2D UI_BScale = UI_B->SetSpriteScale();
	UI_B->SetCameraEffect(false);
	UI_B->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_BScale.X;
	UI_B->SetOrder(ERenderOrder::UI_BASIC);

	UI_FValue = CreateDefaultSubObject<USpriteRenderer>();
	UI_FValue->SetSprite("DungeonFont_0.png");
	FVector2D UI_FValueScale = UI_FValue->SetSpriteScale();
	UI_FValue->SetCameraEffect(false);
	UI_FValue->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_FValueScale.X;
	UI_FValue->SetOrder(ERenderOrder::UI_BASIC);

	UI_F = CreateDefaultSubObject<USpriteRenderer>();
	UI_F->SetSprite("DungeonFont_F.png");
	FVector2D UI_FScale = UI_F->SetSpriteScale();
	UI_F->SetCameraEffect(false);
	UI_F->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_FScale.X + 10;
	UI_F->SetOrder(ERenderOrder::UI_BASIC);

	UI_Lv = CreateDefaultSubObject<USpriteRenderer>();
	UI_Lv->SetSprite("DungeonFont_Lv.png");
	FVector2D UI_LvScale = UI_Lv->SetSpriteScale();
	UI_Lv->SetCameraEffect(false);
	UI_Lv->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_LvScale.X;
	UI_Lv->SetOrder(ERenderOrder::UI_BASIC);

	UI_LvValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_LvValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_LvValue10Scale = UI_LvValue10->SetSpriteScale();
	UI_LvValue10->SetCameraEffect(false);
	UI_LvValue10->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_LvValue10Scale.X;
	UI_LvValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_LvValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_LvValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_LvValue01Scale = UI_LvValue01->SetSpriteScale();
	UI_LvValue01->SetCameraEffect(false);
	UI_LvValue01->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_LvValue01Scale.X + 100;
	UI_LvValue01->SetOrder(ERenderOrder::UI_BASIC);

	UI_Hp = CreateDefaultSubObject<USpriteRenderer>();
	UI_Hp->SetSprite("DungeonFont_Hp.png");
	FVector2D UI_HpScale = UI_Hp->SetSpriteScale();
	UI_Hp->SetCameraEffect(false);
	UI_Hp->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_HpScale.X;
	UI_Hp->SetOrder(ERenderOrder::UI_BASIC);

	UI_CurHpValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_CurHpValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_CurHpValue10Scale = UI_CurHpValue10->SetSpriteScale();
	UI_CurHpValue10->SetCameraEffect(false);
	UI_CurHpValue10->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_CurHpValue10Scale.X;
	UI_CurHpValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_CurHpValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_CurHpValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_CurHpValue01Scale = UI_CurHpValue01->SetSpriteScale();
	UI_CurHpValue01->SetCameraEffect(false);
	UI_CurHpValue01->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_CurHpValue01Scale.X;
	UI_CurHpValue01->SetOrder(ERenderOrder::UI_BASIC);

	UI_Slash = CreateDefaultSubObject<USpriteRenderer>();
	UI_Slash->SetSprite("DungeonFont_Slash.png");
	FVector2D UI_SlashScale = UI_Slash->SetSpriteScale();
	UI_Slash->SetCameraEffect(false);
	UI_Slash->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_SlashScale.X;
	UI_Slash->SetOrder(ERenderOrder::UI_BASIC);

	UI_MaxHpValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_MaxHpValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_MaxHpValue10Scale = UI_MaxHpValue10->SetSpriteScale();
	UI_MaxHpValue10->SetCameraEffect(false);
	UI_MaxHpValue10->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_MaxHpValue10Scale.X;
	UI_MaxHpValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_MaxHpValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_MaxHpValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_MaxHpValue01Scale = UI_MaxHpValue01->SetSpriteScale();
	UI_MaxHpValue01->SetCameraEffect(false);
	UI_MaxHpValue01->SetComponentLocation(UIStartPos);
	UIStartPos.X += UI_MaxHpValue01Scale.X;
	UI_MaxHpValue01->SetOrder(ERenderOrder::UI_BASIC);

	for (int i = 0; i < HpBar.size(); i++)
	{
		HpBar[i] = CreateDefaultSubObject<USpriteRenderer>();
		HpBar[i]->SetSprite("Dungeon_HpBar.png");
		FVector2D HpBarScale = HpBar[i]->SetSpriteScale(1.0f);
		HpBar[i]->SetCameraEffect(false);
		HpBar[i]->SetComponentLocation(UIStartPos);
		UIStartPos.X += HpBarScale.X;
		HpBar[i]->SetOrder(ERenderOrder::UI_BASIC);
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
	LogBoxUI->CreateString("");
	LogBoxUI->CreateString("");
	LogBoxUI->CreateString("");
	
}

void ADungeonUI::LevelChangeStart()
{
	Super::LevelChangeStart();
	UI_FValue->SetSprite(std::format("DungeonFont_{}.png", Dungeon->GetCurFloor()));
}

void ADungeonUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	int CurHp = Player->GetCurAbility()->GetCurHP();
	int MaxHp = Player->GetCurAbility()->GetMaxHP();
	UI_LvValue10->SetSprite(std::format("DungeonFont_{}.png", Player->GetCurAbility()->GetLevel() / 10));
	UI_LvValue01->SetSprite(std::format("DungeonFont_{}.png", Player->GetCurAbility()->GetLevel() % 10));

	UI_CurHpValue10->SetSprite(std::format("DungeonFont_{}.png", CurHp / 10));
	UI_CurHpValue01->SetSprite(std::format("DungeonFont_{}.png", CurHp % 10));


	UI_MaxHpValue10->SetSprite(std::format("DungeonFont_{}.png", MaxHp / 10));
	UI_MaxHpValue01->SetSprite(std::format("DungeonFont_{}.png", MaxHp % 10));
	for (int i = 0; i < MaxHp; i++)
	{
		if (i < CurHp)
		{
			HpBar[i]->SetSprite("Dungeon_HpBar.png");
			HpBar[i]->SetSpriteScale(1.0f);
		}
		else
		{
			HpBar[i]->SetSprite("Dungeon_DamageBar.png");
			HpBar[i]->SetSpriteScale(1.0f);
		}
	}

	//	던전이름UI
	if (BasicUI->GetCurMenuType() == MenuType::Menu) {
		DungeonNameUI->SetString(0, std::format("      {}", Dungeon->GetName()));
		DungeonNameUI->SetStringColor(0, "Yellow");
		DungeonNameUI->ShowUI();
		
	}
	else {
		DungeonNameUI->HideUI();
	}
	if (IsAskValue==true)
	{
		AText* Text = *(A_NextFloorUI->GetCurTextIter());
		A_NextFloorUI->SetStringColor(Text, "Yellow");
		if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD8))
		{
			A_NextFloorUI->SetStringColor(*(A_NextFloorUI->GetCurTextIter()), "White");
			A_NextFloorUI->PrevTextIter();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD2))
		{
			A_NextFloorUI->SetStringColor(*(A_NextFloorUI->GetCurTextIter()), "White");
			A_NextFloorUI->NextTextIter();
		}


		if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
		{
			if (Text->GetString() == "Yes")
			{
				HideNextFloorUI();
				UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
				Dungeon->NextFloor();
			}
			else if(Text->GetString() == "No")
			{
				HideNextFloorUI();
				TurnManager->ComeBackTurn();
			}
		}
	}

	if (IsNewLogValue == true)
	{
		LogBoxUI->ShowUI();

	}
	else
	{
		LogBoxUI->HideUI();
	}


	
		

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







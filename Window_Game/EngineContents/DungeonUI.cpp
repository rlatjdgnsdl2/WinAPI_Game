#include "PreCompile.h"
#include "DungeonUI.h"

#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "AbilityController.h"
#include "Dungeon_BSP.h"



ADungeonUI::ADungeonUI()
{
	HpBar.resize(300,nullptr);
	ResultMessageBox_Text.resize(3,std::vector<USpriteRenderer*>(30,nullptr));
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
	UI_B->SetComponentLocation(UIPos);
	UIPos.X += UI_BScale.X;
	UI_B->SetOrder(ERenderOrder::UI_BASIC);

	UI_FValue = CreateDefaultSubObject<USpriteRenderer>();
	UI_FValue->SetSprite("DungeonFont_0.png");
	FVector2D UI_FValueScale = UI_FValue->SetSpriteScale();
	UI_FValue->SetCameraEffect(false);
	UI_FValue->SetComponentLocation(UIPos);
	UIPos.X += UI_FValueScale.X;
	UI_FValue->SetOrder(ERenderOrder::UI_BASIC);

	UI_F = CreateDefaultSubObject<USpriteRenderer>();
	UI_F->SetSprite("DungeonFont_F.png");
	FVector2D UI_FScale = UI_F->SetSpriteScale();
	UI_F->SetCameraEffect(false);
	UI_F->SetComponentLocation(UIPos);
	UIPos.X += UI_FScale.X + 10;
	UI_F->SetOrder(ERenderOrder::UI_BASIC);

	UI_Lv = CreateDefaultSubObject<USpriteRenderer>();
	UI_Lv->SetSprite("DungeonFont_Lv.png");
	FVector2D UI_LvScale = UI_Lv->SetSpriteScale();
	UI_Lv->SetCameraEffect(false);
	UI_Lv->SetComponentLocation(UIPos);
	UIPos.X += UI_LvScale.X;
	UI_Lv->SetOrder(ERenderOrder::UI_BASIC);

	UI_LvValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_LvValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_LvValue10Scale = UI_LvValue10->SetSpriteScale();
	UI_LvValue10->SetCameraEffect(false);
	UI_LvValue10->SetComponentLocation(UIPos);
	UIPos.X += UI_LvValue10Scale.X;
	UI_LvValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_LvValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_LvValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_LvValue01Scale = UI_LvValue01->SetSpriteScale();
	UI_LvValue01->SetCameraEffect(false);
	UI_LvValue01->SetComponentLocation(UIPos);
	UIPos.X += UI_LvValue01Scale.X + 100;
	UI_LvValue01->SetOrder(ERenderOrder::UI_BASIC);

	UI_Hp = CreateDefaultSubObject<USpriteRenderer>();
	UI_Hp->SetSprite("DungeonFont_Hp.png");
	FVector2D UI_HpScale = UI_Hp->SetSpriteScale();
	UI_Hp->SetCameraEffect(false);
	UI_Hp->SetComponentLocation(UIPos);
	UIPos.X += UI_HpScale.X;
	UI_Hp->SetOrder(ERenderOrder::UI_BASIC);

	UI_CurHpValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_CurHpValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_CurHpValue10Scale = UI_CurHpValue10->SetSpriteScale();
	UI_CurHpValue10->SetCameraEffect(false);
	UI_CurHpValue10->SetComponentLocation(UIPos);
	UIPos.X += UI_CurHpValue10Scale.X;
	UI_CurHpValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_CurHpValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_CurHpValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_CurHpValue01Scale = UI_CurHpValue01->SetSpriteScale();
	UI_CurHpValue01->SetCameraEffect(false);
	UI_CurHpValue01->SetComponentLocation(UIPos);
	UIPos.X += UI_CurHpValue01Scale.X;
	UI_CurHpValue01->SetOrder(ERenderOrder::UI_BASIC);

	UI_Slash = CreateDefaultSubObject<USpriteRenderer>();
	UI_Slash->SetSprite("DungeonFont_Slash.png");
	FVector2D UI_SlashScale = UI_Slash->SetSpriteScale();
	UI_Slash->SetCameraEffect(false);
	UI_Slash->SetComponentLocation(UIPos);
	UIPos.X += UI_SlashScale.X;
	UI_Slash->SetOrder(ERenderOrder::UI_BASIC);

	UI_MaxHpValue10 = CreateDefaultSubObject<USpriteRenderer>();
	UI_MaxHpValue10->SetSprite("DungeonFont_0.png");
	FVector2D UI_MaxHpValue10Scale = UI_MaxHpValue10->SetSpriteScale();
	UI_MaxHpValue10->SetCameraEffect(false);
	UI_MaxHpValue10->SetComponentLocation(UIPos);
	UIPos.X += UI_MaxHpValue10Scale.X;
	UI_MaxHpValue10->SetOrder(ERenderOrder::UI_BASIC);

	UI_MaxHpValue01 = CreateDefaultSubObject<USpriteRenderer>();
	UI_MaxHpValue01->SetSprite("DungeonFont_0.png");
	FVector2D UI_MaxHpValue01Scale = UI_MaxHpValue01->SetSpriteScale();
	UI_MaxHpValue01->SetCameraEffect(false);
	UI_MaxHpValue01->SetComponentLocation(UIPos);
	UIPos.X += UI_MaxHpValue01Scale.X;
	UI_MaxHpValue01->SetOrder(ERenderOrder::UI_BASIC);

	for (int i = 0; i < HpBar.size(); i++)
	{
		HpBar[i] = CreateDefaultSubObject<USpriteRenderer>();
		HpBar[i]->SetSprite("Dungeon_HpBar.png");
		FVector2D HpBarScale = HpBar[i]->SetSpriteScale(1.0f);
		HpBar[i]->SetCameraEffect(false);
		HpBar[i]->SetComponentLocation(UIPos);
		UIPos.X += HpBarScale.X;
		HpBar[i]->SetOrder(ERenderOrder::UI_BASIC);
		HpBar[i]->SetSpriteScale(0.0f);
	}

	ResultMessageBox_Border = CreateDefaultSubObject<USpriteRenderer>();
	ResultMessageBox_Border->SetSprite("MessageBox_Basic.png");
	ResultMessageBox_Border->SetSpriteScale(1.0f);
	ResultMessageBox_Border->SetCameraEffect(false);
	ResultMessageBox_Border->SetOrder(ERenderOrder::UI_BASIC);
	ResultMessageBox_Border->SetComponentLocation({375,500});

	ResultMessageBox_In = CreateDefaultSubObject<USpriteRenderer>();
	ResultMessageBox_In->SetSprite("MessageBox_Basic.bmp");
	ResultMessageBox_In->SetSpriteScale(1.0f);
	ResultMessageBox_In->SetAlphafloat(0.5f);
	ResultMessageBox_In->SetCameraEffect(false);
	ResultMessageBox_In->SetOrder(ERenderOrder::UI_BASIC);
	ResultMessageBox_In->SetComponentLocation({ 375,500 });

	for (int y = 0; y < Text_MaxCount.Y; y++)
	{
		for (int x = 0; x < Text_MaxCount.X; x++)
		{
			//USpriteRenderer* NewText = CreateDefaultSubObject<USpriteRenderer>();
			//NewText->SetSprite()
			//ResultMessageBox_Text[y][x] = NewText;
		}
	}


}

void ADungeonUI::LevelChangeStart()
{
	Super::LevelChangeStart();
	UI_FValue->SetSprite(std::format("DungeonFont_{}.png",Dungeon->GetCurFloor()));

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

	


}

void ADungeonUI::ResultMessage()
{

}




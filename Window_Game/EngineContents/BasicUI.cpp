#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "BoxUI.h"
#include "Partner.h"
#include "Text.h"
#include "TurnManager.h"




ABasicUI::ABasicUI()
{
}

ABasicUI::~ABasicUI()
{

}

void ABasicUI::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());

	MenuBoxUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 200,350 }, { 25,50 }));
	MenuBoxUI->CreateString("Skill");
	MenuBoxUI->CreateString("Item");
	MenuBoxUI->CreateString("Close");

	MyInfoBoxUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 750.0f, 150.0f }, { 25, 400 }));
	MyInfoBoxUI->CreateString("");
	MyInfoBoxUI->CreateString("");

	SkillUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 400, 200 }, { 25, 50 }));
	SkillUI->CreateString("Fire_Bomb");
	SkillUI->CreateString("Lightning_Bomb");
	SkillUI->CreateString("Water_Bomb");

	SkillInfoUI = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 700, 120 }, { 25, 350 }));
	SkillInfoUI->CreateString("");
	CurMenuType = MenuType::CloseMenu;


}

void ABasicUI::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void ABasicUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	switch (CurMenuType)
	{
	case MenuType::ShowMenu:
		OpenMenu();
		break;
	case MenuType::Skill:
		OpenSkill();
		break;
	case MenuType::Item:
		break;
	case MenuType::CloseMenu:
		if (true == UEngineInput::GetInst().IsDown('Q'))
		{
			ShowMenu();
		}
		break;
	default:
		break;
	}





}


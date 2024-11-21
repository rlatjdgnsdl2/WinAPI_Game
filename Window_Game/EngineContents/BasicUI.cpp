#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "AbilityController.h"
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
	MenuBoxUI->CreateString("Team");
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
	CurMenuType = MenuType::Close;


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
	case MenuType::Menu:
		OpenMenu();
		break;
	case MenuType::Skill:
		OpenSkill();
		break;
	case MenuType::Item:
		break;
	case MenuType::Team:
		break;
	case MenuType::Close:

		if (true == UEngineInput::GetInst().IsDown('Q'))
		{
			CurTurn = ATurnManager::GetCurTurn();
			if (CurTurn == TurnType::Open_Menu) {

				MenuBoxUI->ShowUI();
				MenuBoxUI->ResetTextIter();
				MyInfoBoxUI->SetString(0, std::format("{} -   CurHp   {} - {}", Player->GetName(), Player->GetCurAbility()->GetCurHP(), Player->GetCurAbility()->GetMaxHP()));
				MyInfoBoxUI->SetString(1, std::format("{} -   CurHp   {} - {}", Partner->GetName(), Player->GetCurAbility()->GetCurHP(), Player->GetCurAbility()->GetMaxHP()));
				MyInfoBoxUI->SetStringColor(0, 0, Player->GetName().size(), "Blue");
				MyInfoBoxUI->SetStringColor(1, 0, Partner->GetName().size(), "Blue");
				MyInfoBoxUI->ShowUI();
				CurMenuType = MenuType::Menu;
			}
		}

		break;
	default:
		break;
	}





}


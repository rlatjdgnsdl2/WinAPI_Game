#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "AbilityController.h"
#include "Box.h"
#include "Text.h"




ABasicUI::ABasicUI()
{
	MenuStringRenderer.resize(4);
}

ABasicUI::~ABasicUI()
{

}

void ABasicUI::BeginPlay()
{
	Super::BeginPlay();
	MenuBox = GetWorld()->SpawnActor<ABox>();
	MenuBox->SetActorLocation({ 25,50 });
	MenuBox->SetBoxSize({ 200.0f, 350.0f });
	MenuBox->SetActive(false);

	MyInfoBox = GetWorld()->SpawnActor<ABox>();
	MyInfoBox->SetActorLocation({ 25, 400 });
	MyInfoBox->SetBoxSize({ 750.0f, 150.0f });

	MenuString.push_back("Skill");
	MenuString.push_back("Item");
	MenuString.push_back("Team");
	MenuString.push_back("Close");

	for (int i = 0; i < MenuString.size(); i++) {
		AText* NewText = GetWorld()->SpawnActor<AText>();
		NewText->SetString(MenuString[i]);
		NewText->SetActorLocation({ 65.0f,78.0f * 20.0f * i });
		MenuStringRenderer[i] = NewText;
	}
	MenuIter = MenuStringRenderer.begin();

	PlayerName = GetWorld()->SpawnActor<AText>();
	PlayerName->SetActorLocation({ 80.0f, 430.0f });

	PlayerHp = GetWorld()->SpawnActor<AText>();
	PlayerHp->SetActorLocation({ 200.0f, 430.0f });


}

void ABasicUI::LevelChangeStart()
{
	Super::LevelChangeStart();
	MenuBox->SetActive(false);
	MyInfoBox->SetActive(false);
	for (int i = 0; i < MenuString.size(); i++)
	{
		MenuStringRenderer[i]->SetActive(false);
	}
	CurMenuType = MenuType::Close;
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());
	PlayerName->SetString(Player->GetName(),"Blue");
	PlayerName->SetActive(false);

}

void ABasicUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	switch (CurMenuType)
	{
	case MenuType::Close:
		if (true == UEngineInput::GetInst().IsDown('Q'))
		{
			MenuBox->SetActive(true);
			for (int i = 0; i < MenuStringRenderer.size(); i++)
			{
				MenuStringRenderer[i]->SetActive(true);
				MenuStringRenderer[i]->SetActorLocation({ 80.0f,60.0f + 25.0f * i });
			}
			MyInfoBox->SetActive(true);
			PlayerName->SetActive(true);
			PlayerHp->SetString("CurHP  "+ std::to_string(Player->GetCurAbility()->GetCurHP()-11)+" MaxHp  " + std::to_string(Player->GetCurAbility()->GetMaxHP() - 11));
			PlayerHp->SetActive(true);

			AText* Menu = *MenuIter;
			Menu->SetColor("Yellow");
			CurMenuType = MenuType::Menu;
		}
		break;
	case MenuType::Menu:
		OpenMenu();
		break;
	case MenuType::Skill:
		//OpenSkill();
		break;
	case MenuType::Item:
		OpenItem();
		break;
	case MenuType::Team:
		//OpenTeam();
		break;
	default:
		break;
	}


}


#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "Text.h"
#include "Box.h"


void ABasicUI::OpenMenu() {

	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		{
			AText* Menu = *MenuIter;
			Menu->SetColor("White");
		}
		if (MenuIter == MenuStringRenderer.begin()) {
			MenuIter = MenuStringRenderer.end();
		}
		MenuIter--;
		{
			AText* Menu = *MenuIter;
			Menu->SetColor("Yellow");
		}
	}
	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		{
			AText* Menu = *MenuIter;
			Menu->SetColor("White");
		}
		MenuIter++;
		if (MenuIter == MenuStringRenderer.end())
		{
			MenuIter = MenuStringRenderer.begin();
		}
		{
			AText* Menu = *MenuIter;
			Menu->SetColor("Yellow");
		}
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		MenuBox->SetActive(false);
		MyInfoBox->SetActive(false);
		PlayerName->SetActive(false);
		PlayerHp->SetActive(false);
		for (int i = 0; i < MenuStringRenderer.size(); i++)
		{
			MenuStringRenderer[i]->SetActive(false);
		}
		CurMenuType = MenuType::Close;
		return;
	}

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		AText* SelectMenu = *MenuIter;
		std::string MenuName = SelectMenu->GetString();
		if ("Skill" == MenuName) {
			MenuBox->SetActive(false);
			MyInfoBox->SetActive(false);
			PlayerName->SetActive(false);
			PlayerHp->SetActive(false);
	
			for (int i = 0; i < MenuStringRenderer.size(); i++)
			{
				MenuStringRenderer[i]->SetActive(false);
			}
			CurMenuType = MenuType::Skill;
			return;
		}
		else if ("Item" == MenuName) {
			MenuBox->SetActive(false);
			MyInfoBox->SetActive(false);
			PlayerName->SetActive(false);
			PlayerHp->SetActive(false);
			
			for (int i = 0; i < MenuStringRenderer.size(); i++)
			{
				MenuStringRenderer[i]->SetActive(false);
			}
			CurMenuType = MenuType::Item;
			return;
		}
		else if ("Team" == MenuName) {
			MenuBox->SetActive(false);
			MyInfoBox->SetActive(false);
			PlayerName->SetActive(false);
			PlayerHp->SetActive(false);
			
			for (int i = 0; i < MenuStringRenderer.size(); i++)
			{
				MenuStringRenderer[i]->SetActive(false);
			}
			CurMenuType = MenuType::Team;
			return;
		}
		
		else if ("Close" == MenuName) {
			MenuBox->SetActive(false);
			MyInfoBox->SetActive(false);
			PlayerName->SetActive(false);
			PlayerHp->SetActive(false);
			
			for (int i = 0; i < MenuStringRenderer.size(); i++)
			{
				MenuStringRenderer[i]->SetActive(false);
			}
			CurMenuType = MenuType::Close;
			return;


		}

	}
}
#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "Player.h"


#include "Partner.h"
#include "BoxUI.h"
#include "Text.h"


void ABasicUI::ShowMenu()
{
	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::Yellow);
	if (true == UEngineInput::GetInst().IsDown(VK_UP))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::White);
		MenuBoxUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::White);
		MenuBoxUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {

		CurMenu = MenuType::CloseMenu;
		return;
	}

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		AText* CurText = *(MenuBoxUI->GetCurTextIter());
		std::string CurTextString = CurText->GetString();
		if ("Skill" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::White);
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();


			CurMenu = MenuType::OpenSkill;
			return;
		}
		else if ("Item" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::White);
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenu = MenuType::OpenItem;
			return;

		}

		else if ("Close" == CurTextString) {
			CurMenu = MenuType::CloseMenu;
			return;
		}
	}
}

void ABasicUI::OpenMenu() {

	MenuBoxUI->ShowUI();
	MenuBoxUI->ResetTextIter();

	MyInfoBoxUI->SetString(
		{ Player->GetName(),std::format("    CurHP -  {} - {}",Player->GetCurHP(),Player->GetMaxHP()) },
		{ TextColor::Blue,TextColor::White },0);
	MyInfoBoxUI->ShowUI();
	CurMenu = MenuType::ShowMenu;
}


void ABasicUI::CloseMenu() {
	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), TextColor::White);
	MenuBoxUI->HideUI();
	MyInfoBoxUI->HideUI();
	CurMenu = MenuType::None;
}
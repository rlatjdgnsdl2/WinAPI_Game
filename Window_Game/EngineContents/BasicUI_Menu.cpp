#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "Player.h"


#include "Partner.h"
#include "BoxUI.h"
#include "Text.h"


void ABasicUI::ShowMenu()
{
	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "Yellow");
	if (true == UEngineInput::GetInst().IsDown(VK_UP))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
		MenuBoxUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
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
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			

			CurMenu = MenuType::OpenSkill;
			return;
		}
		else if ("Item" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
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

	MyInfoBoxUI->SetString(0, std::format("{} -   CurHp   {} - {}", Player->GetName(), Player->GetCurHP(), Player->GetMaxHP()));
	/*MyInfoBoxUI->SetString(1, std::format("{} -   CurHp   {} - {}", Partner->GetName(), Player->GetCurHP(), Player->GetMaxHP()));*/
	MyInfoBoxUI->SetStringParticialColor(0, 0, static_cast<int>(Player->GetName().size()), "Blue");
	/*MyInfoBoxUI->SetStringParticialColor(1, 0, static_cast<int>(Partner->GetName().size()), "Blue");*/
	MyInfoBoxUI->ShowUI();
	CurMenu = MenuType::ShowMenu;
}


void ABasicUI::CloseMenu() {
	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
	MenuBoxUI->HideUI();
	MyInfoBoxUI->HideUI();
	CurMenu = MenuType::None;
}
#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "Player.h"
#include "AbilityController.h"
#include "Partner.h"
#include "BoxUI.h"
#include "Text.h"


void ABasicUI::ShowMenu()
{
	MenuBoxUI->ShowUI();
	MenuBoxUI->ResetTextIter();
	MyInfoBoxUI->SetString(0, std::format("{} -   CurHp   {} - {}", Player->GetName(), Player->GetCurAbility()->GetCurHP(), Player->GetCurAbility()->GetMaxHP()));
	MyInfoBoxUI->SetString(1, std::format("{} -   CurHp   {} - {}", Partner->GetName(), Player->GetCurAbility()->GetCurHP(), Player->GetCurAbility()->GetMaxHP()));
	MyInfoBoxUI->SetStringColor(0, 0, static_cast<int>(Player->GetName().size()), "Blue");
	MyInfoBoxUI->SetStringColor(1, 0, static_cast<int>(Partner->GetName().size()), "Blue");
	MyInfoBoxUI->ShowUI();
	CurMenuType = MenuType::Menu;
}

void ABasicUI::OpenMenu() {

	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "Yellow");
	if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD8))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
		MenuBoxUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD2))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
		MenuBoxUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
		MenuBoxUI->HideUI();
		MyInfoBoxUI->HideUI();
		CurMenuType = MenuType::Close;
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
			SkillInfoUI->ShowUI();
			SkillInfoUI->ResetTextIter();
			SkillUI->ShowUI();
			SkillUI->ResetTextIter();
			
			CurMenuType = MenuType::Skill;
		}
		else if ("Item" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenuType = MenuType::Item;
		
		}
	
		else if ("Close" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetCurTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenuType = MenuType::Close;
		}


	}
}
#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"
#include "Text.h"


void ABasicUI::OpenMenu() {

	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "Yellow");
	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
		MenuBoxUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
		MenuBoxUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
		MenuBoxUI->HideUI();
		MyInfoBoxUI->HideUI();
		CurMenuType = MenuType::Close;
		return;
	}

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		AText* CurText = *(MenuBoxUI->GetTextIter());
		std::string CurTextString = CurText->GetString();
		if ("Skill" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			SkillInfoUI->ShowUI();
			SkillInfoUI->ResetTextIter();
			SkillUI->ShowUI();
			SkillUI->ResetTextIter();
			
			CurMenuType = MenuType::Skill;
		}
		else if ("Item" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenuType = MenuType::Item;
		
		}
		else if ("Team" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenuType = MenuType::Team;

		}
		else if ("Close" == CurTextString) {
			MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
			MenuBoxUI->HideUI();
			MyInfoBoxUI->HideUI();
			CurMenuType = MenuType::Close;
		}


	}
}
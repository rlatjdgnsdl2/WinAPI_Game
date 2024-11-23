#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"

#include "Player.h"
#include "Text.h"
#include "Box.h"

void ABasicUI::OpenSkill() {
	SkillInfoUI->ShowUI();
	SkillInfoUI->ResetTextIter();
	SkillUI->ShowUI();
	SkillUI->ResetTextIter();
	CurMenu = MenuType::ShowSkill;
	return;
}
void ABasicUI::ShowSkill() {
	SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "Yellow");
	if (true == UEngineInput::GetInst().IsDown(VK_UP))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		
		CurMenu = MenuType::CloseSkill;
		return;
	}
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		// 스킬선택
		// 플레이어한테 스킬해줘야함
		Player->SetCurSpecialSkillName((*(SkillUI->GetCurTextIter()))->GetString());
		CurMenu = MenuType::CloseSkill;
	}
}


void ABasicUI::CloseSkill() {
	SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
	SkillUI->HideUI();
	SkillInfoUI->HideUI();
	CurMenu = MenuType::None;
}
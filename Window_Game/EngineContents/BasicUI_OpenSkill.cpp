#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"

#include "Player.h"
#include "Text.h"
#include "Box.h"


void ABasicUI::OpenSkill() {
	SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "Yellow");
	

	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
		CurMenuType = MenuType::Close;
		return;
	}
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		// 스킬선택
		// 플레이어한테 스킬해줘야함
		Player->SetCurSpecialSkillName((*(SkillUI->GetCurTextIter()))->GetString());


		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
 		CurMenuType = MenuType::Close;
	}
}
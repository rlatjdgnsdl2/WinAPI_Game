#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"

#include "Player.h"
#include "Text.h"
#include "Box.h"


void ABasicUI::OpenSkill() {
	SkillUI->SetStringColor(*(SkillUI->GetTextIter()), "Yellow");
	

	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		SkillUI->SetStringColor(*(SkillUI->GetTextIter()), "White");
		SkillUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		SkillUI->SetStringColor(*(SkillUI->GetTextIter()), "White");
		SkillUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		SkillUI->SetStringColor(*(SkillUI->GetTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
		CurMenuType = MenuType::Close;
		return;
	}
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		// 스킬선택
		// 플레이어한테 스킬해줘야함
		Player->SetCurSpecialSkillName((*(SkillUI->GetTextIter()))->GetString());


		SkillUI->SetStringColor(*(SkillUI->GetTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
 		CurMenuType = MenuType::Close;
	}
}
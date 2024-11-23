#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"

#include "Player.h"
#include "Text.h"
#include "Box.h"


void ABasicUI::OpenSkill() {
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
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
		CurMenuType = MenuType::CloseMenu;
		return;
	}
	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		// ��ų����
		// �÷��̾����� ��ų�������
		Player->SetCurSpecialSkillName((*(SkillUI->GetCurTextIter()))->GetString());


		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), "White");
		SkillUI->HideUI();
		SkillInfoUI->HideUI();
 		CurMenuType = MenuType::CloseMenu;
	}
}
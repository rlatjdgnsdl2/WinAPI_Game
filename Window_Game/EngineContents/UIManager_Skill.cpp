#include "PreCompile.h"
#include "UIManager.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"
#include "GameDataManager.h"

#include "Player.h"
#include "Text.h"
#include "Box.h"

void AUIManager::OpenSkill() {
	SkillInfoUI->ShowUI();
	SkillUI->ShowUI();
	SkillUI->ResetTextIter();
	CurMenu = MenuType::ShowSkill;
	return;
}
void AUIManager::ShowSkill() {
	AText* SkillText = *(SkillUI->GetCurTextIter());
	SkillUI->SetStringColor(SkillText, Color::Yellow);
	std::string SkillName = SkillText->GetString();
	std::string SkillInfo = UGameDataManager::GetInst().GetSkillInfo(SkillName);
	SkillInfoUI->SetString(SkillInfo);
	SkillInfoUI->ShowUI();
	if (true == UEngineInput::GetInst().IsDown(VK_UP))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), Color::White);
		SkillUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
	{
		SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), Color::White);
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


void AUIManager::CloseSkill() {
	SkillUI->SetStringColor(*(SkillUI->GetCurTextIter()), Color::White);
	SkillUI->HideUI();
	SkillInfoUI->HideUI();
	CurMenu = MenuType::None;
}
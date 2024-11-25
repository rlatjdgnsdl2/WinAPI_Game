#include "PreCompile.h"
#include  "UIManager.h"

#include <EnginePlatform/EngineInput.h>

#include "BoxUI.h"
#include "Dungeon_BSP.h"
#include "Text.h"
#include "Player.h"
#include "Partner.h"


void AUIManager::OpenMenu() {

	MenuUI->ShowUI();
	MenuUI->ResetTextIter();

	MyInfoUI->SetString(
		{ "Lv ",std::to_string(Player->GetLevel())," " + Player->GetName(),std::format("    CurHP -  {} - {}",Player->GetCurHP(),Player->GetMaxHP()) },
		{ Color::White, Color::Yellow,Color::Blue,Color::White }, 0);
	MyInfoUI->SetString(
		{ "Lv ",std::to_string(Partner->GetLevel())," " + Partner->GetName(),std::format("    CurHP -  {} - {}",Player->GetCurHP(),Player->GetMaxHP()) },
		{ Color::White, Color::Yellow,Color::Blue,Color::White }, 1);
	MyInfoUI->ShowUI();
	if (CurLevelName == "DungeonLevel") {
		DungeonNameUI->SetString("      " + Dungeon->GetName());
		DungeonNameUI->SetStringColor(0, Color::Yellow);
		DungeonNameUI->ShowUI();
	}
	CurMenu = MenuType::ShowMenu;
}

void AUIManager::ShowMenu() {
	AText* Text = *(MenuUI->GetCurTextIter());
	MenuUI->SetStringColor(Text, Color::Yellow);
	if (true == UEngineInput::GetInst().IsDown(VK_UP)) {
		MenuUI->SetStringColor(Text, Color::White);
		MenuUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN)) {
		MenuUI->SetStringColor(Text, Color::White);
		MenuUI->NextTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown('Q')) {
		CurMenu = MenuType::CloseMenu;
		return;
	}

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{

		std::string CurTextString = Text->GetString();
		if ("Skill" == CurTextString) {
			MenuUI->SetStringColor(Text, Color::White);
			MenuUI->HideUI();
			MyInfoUI->HideUI();
			if (CurLevelName == "DungeonLevel") {
				DungeonNameUI->HideUI();
			}
			CurMenu = MenuType::OpenSkill;
			return;
		}
		else if ("Item" == CurTextString) {
			MenuUI->SetStringColor(Text, Color::White);
			MenuUI->HideUI();
			MyInfoUI->HideUI();
			if (CurLevelName == "DungeonLevel") {
				DungeonNameUI->HideUI();
			}
			CurMenu = MenuType::OpenItem;
			return;
		}
		else if ("Close" == CurTextString) {
			CurMenu = MenuType::CloseMenu;
			return;
		}
	}
}
void AUIManager::CloseMenu() {
	if (CurLevelName == "DungeonLevel") {
		DungeonNameUI->HideUI();
	}
	MenuUI->SetStringColor(*(MenuUI->GetCurTextIter()), Color::White);
	MenuUI->HideUI();
	MyInfoUI->HideUI();
	CurMenu = MenuType::None;

}


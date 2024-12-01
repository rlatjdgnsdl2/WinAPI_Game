#include "PreCompile.h"
#include "UIManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "Dungeon_BSP.h"
#include "BoxUI.h"
#include "Text.h"


void AUIManager::OpenNextFloor() {
	Q_NextFloorUI->ShowUI();
	A_AnswerUI->ShowUI();
	CurMenu = MenuType::ShowNextFloor;

}

void AUIManager::ShowNextFloor() {
	AText* Text = *(A_AnswerUI->GetCurTextIter());
	A_AnswerUI->SetStringColor(Text, Color::Yellow);
	if (true == UEngineInput::GetInst().IsDown(VK_UP)) {
		UEngineSound::Play("DirSound.wav");
		A_AnswerUI->SetStringColor(Text, Color::White);
		A_AnswerUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN)) {
		UEngineSound::Play("DirSound.wav");
		A_AnswerUI->SetStringColor(Text, Color::White);
		A_AnswerUI->NextTextIter();
	}


	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		if (Text->GetString() == "Yes") {
			Q_NextFloorUI->HideUI();
			Dungeon->NextFloor();
			CurMenu = MenuType::CloseNextFloor;
			UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");

			return;
		}
		else if (Text->GetString() == "No") {
			Q_NextFloorUI->HideUI();
			A_AnswerUI->HideUI();
			CurMenu = MenuType::CloseNextFloor;
		}
	}
}
void AUIManager::CloseNextFloor() {
	Q_NextFloorUI->HideUI();
	A_AnswerUI->HideUI();
	CurMenu = MenuType::None;
}
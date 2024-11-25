#include "PreCompile.h"
#include "UIManager.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "BoxUI.h"
#include "Text.h"


void AUIManager::OpenNextFloor() {
	Q_NextFloorUI->ShowUI();
	A_NextFloorUI->ShowUI();
}

void AUIManager::ShowNextFloor() {
	AText* Text = *(A_NextFloorUI->GetCurTextIter());
	A_NextFloorUI->SetStringColor(Text, Color::Yellow);
	if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD8)) {
		A_NextFloorUI->SetStringColor(Text, Color::White);
		A_NextFloorUI->PrevTextIter();
	}
	if (true == UEngineInput::GetInst().IsDown(VK_NUMPAD2)) {
		A_NextFloorUI->SetStringColor(Text, Color::White);
		A_NextFloorUI->NextTextIter();
	}


	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		if (Text->GetString() == "Yes") {
			Q_NextFloorUI->HideUI();
			A_NextFloorUI->HideUI();
			UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");
			return;
		}
		else if (Text->GetString() == "No") {
			Q_NextFloorUI->HideUI();
			A_NextFloorUI->HideUI();
		}
	}
}
void AUIManager::CloseNextFloor() {

}
#include "PreCompile.h"
#include "BasicUI.h"

#include <EnginePlatform/EngineInput.h>
#include "BoxUI.h"


void ABasicUI::OpenMenu() {

	MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "Yellow");
	if (true == UEngineInput::GetInst().IsDown('W'))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
		MenuBoxUI->TextIterPrev();
	}
	if (true == UEngineInput::GetInst().IsDown('S'))
	{
		MenuBoxUI->SetStringColor(*(MenuBoxUI->GetTextIter()), "White");
		MenuBoxUI->TextIterNext();
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
		

	}
}
#include "PreCompile.h"
#include "UIManager.h"

#include <EnginePlatform/EngineInput.h>
#include "GameDataManager.h"
#include "BoxUI.h"
#include "Text.h"

void AUIManager::OpenItem() {

	std::list<std::string> ItemList = UGameDataManager::GetInst().GetPlayerInventory();
	ItemInfoUI->ShowUI();
	ItemUI->ResetTextIter();
	//ItemUI->ShowPage(ItemList, CurPage, 8);
	ItemUI->ShowUI();
	CurMenu = MenuType::ShowItem;
	return;
}

bool IsAskUseItem = false;

void AUIManager::ShowItem() {
	AText* ItemText = *(ItemUI->GetCurTextIter());
	ItemUI->SetStringColor(ItemText, Color::Yellow);
	std::string ItemName = ItemText->GetString();
	std::string ItemInfo = UGameDataManager::GetInst().GetItemInfo(ItemName);
	ItemInfoUI->SetString(ItemInfo);
	ItemInfoUI->ShowUI();
	if (!IsAskUseItem) {
		if (true == UEngineInput::GetInst().IsDown(VK_UP))
		{
			ItemUI->SetStringColor(*(ItemUI->GetCurTextIter()), Color::White);
			ItemUI->PrevTextIter();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
		{
			ItemUI->SetStringColor(*(ItemUI->GetCurTextIter()), Color::White);
			ItemUI->NextTextIter();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_LEFT))
		{
			ItemUI->SetStringColor(*(ItemUI->GetCurTextIter()), Color::White);
			for (int i = 0; i < 8; i++)
			{
				ItemUI->PrevTextIter();
			}
			CurPage--;
			if (CurPage < 0) {
				CurPage = MaxPage;
			}
			//ItemUI->ShowPage(UGameDataManager::GetInst().GetPlayerInventory(), CurPage, 8);
			ItemUI->ShowUI();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_RIGHT))
		{
			ItemUI->SetStringColor(*(ItemUI->GetCurTextIter()), Color::White);
			for (int i = 0; i < 8; i++)
			{
				ItemUI->NextTextIter();
			}
			CurPage++;
			if (CurPage > MaxPage) {
				CurPage = 0;
			}
			//ItemUI->ShowPage(UGameDataManager::GetInst().GetPlayerInventory(), CurPage, 8);
			ItemUI->ShowUI();
		}
		if (true == UEngineInput::GetInst().IsDown('Q')) {

			CurMenu = MenuType::CloseItem;
			return;
		}
		if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
			// 아이템 선택
			IsAskUseItem = true;
			A_AnswerUI->ShowUI();
			// 아이템 사용해야함
		}
	}
	else {
		AText* Text = *(A_AnswerUI->GetCurTextIter());
		A_AnswerUI->SetStringColor(Text, Color::Yellow);
		if (true == UEngineInput::GetInst().IsDown(VK_UP)) {
			A_AnswerUI->SetStringColor(Text, Color::White);
			A_AnswerUI->PrevTextIter();
		}
		if (true == UEngineInput::GetInst().IsDown(VK_DOWN)) {
			A_AnswerUI->SetStringColor(Text, Color::White);
			A_AnswerUI->NextTextIter();
		}

		if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
			if (Text->GetString() == "Yes") {
				A_AnswerUI->HideUI();
				CurMenu = MenuType::CloseItem;
			}
			else if (Text->GetString() == "No") {
				A_AnswerUI->HideUI();
				CurMenu = MenuType::CloseItem;
			}
		}

	}
}


void AUIManager::CloseItem() {
	ItemUI->SetStringColor(*(ItemUI->GetCurTextIter()), Color::White);
	ItemUI->HideUI();
	ItemInfoUI->HideUI();
	CurMenu = MenuType::None;
}
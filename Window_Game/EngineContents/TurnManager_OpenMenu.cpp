#include "PreCompile.h"
#include "TurnManager.h"
#include "UIManager.h"


void ATurnManager::OpenMenu() {

	MenuType CurMenu = UIManager->GetCurMenuType();
	if (CurMenu == MenuType::None) {
		CurTurn = PreTurn;
	}
}
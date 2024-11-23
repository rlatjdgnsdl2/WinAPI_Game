#include "PreCompile.h"
#include "TurnManager.h"
#include "DungeonUI.h"
#include "BasicUI.h"


void ATurnManager::OpenMenu() {

	MenuType CurMenu = BasicUI->GetCurMenuType();
	if (CurMenu == MenuType::None&&DungeonUI->IsAsk()==false) {
		CurTurn = PreTurn;
	}
}
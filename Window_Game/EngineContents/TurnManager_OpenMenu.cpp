#include "PreCompile.h"
#include "TurnManager.h"
#include "UIManager.h"


void ATurnManager::OpenMenu() {

	MenuType CurMenu = UIManager->GetCurMenuType();
	if (CurMenu == MenuType::None) {
		if (PreTurn == TurnType::Player_Move) {
			CurTurn = TurnType::AI_Skill_Start;
			return;
		}
		CurTurn = PreTurn;
		return;
	}
}
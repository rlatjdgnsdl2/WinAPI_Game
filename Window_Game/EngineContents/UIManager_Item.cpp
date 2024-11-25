#include "PreCompile.h"
#include "UIManager.h"




void AUIManager::OpenItem() {
	
	CurMenu = MenuType::ShowSkill;
	return;
}
void AUIManager::ShowItem() {
	
}


void AUIManager::CloseItem() {
	
	CurMenu = MenuType::None;
}
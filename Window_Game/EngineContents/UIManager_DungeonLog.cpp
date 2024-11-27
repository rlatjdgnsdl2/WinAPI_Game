#include "PreCompile.h"
#include "UIManager.h"

#include <EnginePlatform/EngineInput.h>

#include "DungeonLogBox.h"





void AUIManager::NewLogMessage(const std::string_view _Message, Color _Color){
	LogBoxUI->NewMessage(_Message, _Color);
	CurMenu = MenuType::OpenLog;
	return;
}

void AUIManager::NewLogMessage(const std::vector<std::string>& _Message, const std::vector<Color>& _Colors){
	LogBoxUI->NewMessage(_Message, _Colors);
	CurMenu = MenuType::OpenLog;
	return;
}


void AUIManager::OpenLog() {
	LogBoxUI->ShowUI();
	CurMenu = MenuType::ShowLog;
}
void AUIManager::ShowLog(float _DeltaTime) {
	CurDuration += _DeltaTime;
	if (true == UEngineInput::GetInst().IsDown('Q'))
	{
		CurDuration = 0.0f;
		LogBoxUI->HideUI();
		CurMenu = MenuType::OpenMenu;
		return;
	}
	if (CurDuration > 5.0f)
	{
		CurDuration = 0.0f;
		CurMenu = MenuType::CloseLog;
		return;
	}
}
void AUIManager::CloseLog() {
	LogBoxUI->HideUI();
	CurMenu = MenuType::None;
	return;
}


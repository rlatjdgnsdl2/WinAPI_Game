#include "PreCompile.h"
#include "TextManager.h"

#include <EngineCore/SpriteRenderer.h>
#include "Text.h"




ATextManager::ATextManager()
{
	
}
ATextManager::~ATextManager()
{

}


void ATextManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATextManager::PushDungeonLog(std::string_view _StringValue)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValue);
	DungeonLogRender.push_back(NewText);
}


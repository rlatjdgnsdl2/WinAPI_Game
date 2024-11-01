#include "PreCompile.h"
#include "TileMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

ATileMap::ATileMap() 
{
	TileMap.resize(40, std::vector<USpriteRenderer*>(60, nullptr));
	UImageManager::GetInst().CuttingSprite("BeachCave_Ground.png", 5, 10);
	UImageManager::GetInst().CuttingSprite("BeachCave_Wall.png", 5, 10);
	SetActorLocation({100,100});
}

ATileMap::~ATileMap() 
{

}

void ATileMap::Tick(float _DeltaTime)
{
	if (UEngineInput::GetInst().IsPress('A')) {
		SetTile(100,100);
	}
}

void ATileMap::SetTile(int _row, int _col)
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("BeachCave_Ground.png",0);
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	FVector2D TitleScale = SpriteRenderer->SetSpriteScale(1.0f,0);
	SpriteRenderer->SetComponentLocation(TitleScale.Half());
	TileMap[_row][_col] = SpriteRenderer;
}

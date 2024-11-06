#include "PreCompile.h"
#include "TileMap.h"

#include <EngineBase/EngineRandom.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineCoreDebug.h>

#include "ContentsEnum.h"
#include "DungeonGameMode.h"
#include "PMDContentsCore.h"



ATileMap::ATileMap()
{
	
	
}
ATileMap::~ATileMap()
{

}


void ATileMap::CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName)
{
	if (nullptr == Tiles[_y][_x].SpriteRenderer)
	{
		USpriteRenderer* NewSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		Tiles[_y][_x].SpriteRenderer = NewSpriteRenderer;
	}
	Tiles[_y][_x].SpriteRenderer->SetSprite(_SpriteName, 4);
	Tiles[_y][_x].SpriteRenderer->SetComponentLocation({ (_x)*_Scale.X,(_y)*_Scale.Y });
	Tiles[_y][_x].SpriteRenderer->SetSpriteScale(1.0f);
	Tiles[_y][_x].SpriteRenderer->SetOrder(ERenderOrder::BACKGROUND);
	FVector2D TileLocation = Tiles[_y][_x].SpriteRenderer->GetComponentLocation();
	Tiles[_y][_x].TileTrans = FTransform(_Scale, TileLocation);
}



void ATileMap::SetTile(int _col, int _row, std::string_view _SpriteName)
{
	Tiles[_row][_col].SpriteRenderer->SetSprite(_SpriteName.data(), 4);
}
















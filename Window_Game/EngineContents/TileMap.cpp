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
	Tiles.resize(Height, std::vector<DungeonTile>(Width));
	SetActorLocation({ 0,0 });
}
ATileMap::~ATileMap()
{

}

void ATileMap::CreateTile(int _x, int _y, FVector2D _Scale, std::string_view _SpriteName, int _Index)
{
	if (nullptr == Tiles[_y][_x].SpriteRenderer)
	{
		USpriteRenderer* NewSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		Tiles[_y][_x].SpriteRenderer = NewSpriteRenderer;
	}
	Tiles[_y][_x].SpriteRenderer->SetSprite(_SpriteName, _Index);
	Tiles[_y][_x].SpriteRenderer->SetComponentLocation({ (_x)*_Scale.X,(_y)*_Scale.Y });
	Tiles[_y][_x].SpriteRenderer->SetSpriteScale();
	Tiles[_y][_x].SpriteRenderer->SetOrder(ERenderOrder::BackGround);
	FVector2D TileLocation = Tiles[_y][_x].SpriteRenderer->GetComponentLocation();
	Tiles[_y][_x].TileTrans = FTransform(_Scale, TileLocation);
}



void ATileMap::SetTile(int _x, int _y, std::string_view _SpriteName, int _Index)
{
	Tiles[_y][_x].SpriteRenderer->SetSprite(_SpriteName.data(), _Index);
}




















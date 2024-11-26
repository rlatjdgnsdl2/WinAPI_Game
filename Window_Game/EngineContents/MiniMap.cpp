#include "PreCompile.h"
#include "MiniMap.h"

#include <EngineCore/SpriteRenderer.h>
#include "Dungeon_BSP.h"
#include "Player.h"


AMiniMap::AMiniMap() 
{
	MiniMapRenderers.resize(40, std::vector<USpriteRenderer*>(60));
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PlayerRenderer->SetSprite("Player.png");
	PlayerRenderer->SetSpriteScale();
	PlayerRenderer->SetOrder(ERenderOrder::UI_Image);
	PlayerRenderer->SetCameraEffect(false);

	PotalRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PotalRenderer->SetSprite("Potal.png");
	PotalRenderer->SetSpriteScale();
	PotalRenderer->SetOrder(ERenderOrder::UI_Image);
	PotalRenderer->SetCameraEffect(false);

	SetActorLocation({ 10,20 });
}

AMiniMap::~AMiniMap() 
{

}
void AMiniMap::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());
}
void AMiniMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FIntPoint PlayerPos = Player->GetTile();
	FVector2D PlayerLocation = { PlayerPos.X * 12, PlayerPos.Y * 12 };
	PlayerRenderer->SetComponentLocation(PlayerLocation);
}
void AMiniMap::SetMiniMap()
{
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (MiniMapRenderers[y][x] == nullptr) {
				USpriteRenderer* NewSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
				NewSpriteRenderer->SetSprite("Void.png");
				NewSpriteRenderer->SetComponentLocation({ (x) * 12,(y) * 12 });
				NewSpriteRenderer->SetSpriteScale();
				NewSpriteRenderer->SetCameraEffect(false);
				NewSpriteRenderer->SetOrder(ERenderOrder::UI_Image);
				MiniMapRenderers[y][x] = NewSpriteRenderer;
			}
		}
	}

	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			if (nullptr != MiniMapRenderers[y][x]) {
				// Ÿ�� ���� ����
				// ��� �˻� �� Ÿ�� ���� ����
				TileType CurTileType = Dungeon->GetTile(x,y).TileType;
				if (CurTileType == TileType::WALL) {
					MiniMapRenderers[y][x]->SetSprite("Void.png");
				}
				else if (CurTileType == TileType::WATER) {
					MiniMapRenderers[y][x]->SetSprite("Void.png");
				}
				else if (CurTileType == TileType::GROUND) {

					if (y > 0 && x > 0 && y < Height - 1 && x < Width - 1) {
						std::string FindKey;
						for (int i = -1; i <= 1; ++i) {
							for (int j = -1; j <= 1; ++j) {
								FindKey += (CurTileType == Dungeon->GetTile(x+j, y+i).TileType) ? "1" : "0";
							}
						}
						std::string SpriteName = Dungeon->GetMinimapSpriteName(FindKey);
						MiniMapRenderers[y][x]->SetSprite(SpriteName);
					}
				}
			}
		}
	}
	FVector2D PotalLocation = Dungeon->GetPotalLocation();
	PotalRenderer->SetComponentLocation({ PotalLocation.X / 6, PotalLocation.Y / 6 });
}


#include "PreCompile.h"
#include "DungeonGameMode.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineCore/ImageManager.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "TileMap.h"




std::vector<std::vector<FVector2D>> ADungeonGameMode::AllGrounds;
ADungeonGameMode::ADungeonGameMode()
{


}

ADungeonGameMode::~ADungeonGameMode()
{

}

void ADungeonGameMode::BeginPlay()
{
	Super::BeginPlay();


}
void ADungeonGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ADungeonGameMode::LevelChangeStart()
{
	Super::LevelChangeStart();
	if (nullptr == Dungeon) {

		Dungeon = GetWorld()->SpawnActor<ATileMap>();
	}
	GenerateDungeon();

}


void ADungeonGameMode::GenerateDungeon()
{
	SetAllWall();
	SetRandomHallWay();
	SetborderWall();
	CheckTile();
}

void ADungeonGameMode::SetAllWall()
{
	Dungeon->SetAllWall();
}

void ADungeonGameMode::SetRandomHallWay()
{
	UEngineRandom random;
	FIntPoint PreAnchor = FIntPoint(random.RandomInt(5, 54), random.RandomInt(5, 34));;

	for (int j = 0; j < 10; j++)
	{
		FIntPoint Anchor = FIntPoint(random.RandomInt(5, 54), random.RandomInt(5, 34));
		FIntPoint Distance = PreAnchor - Anchor;

		while (std::abs(Distance.X) < 4 || std::abs(Distance.Y) < 4)
		{
			Anchor = FIntPoint(random.RandomInt(5, 53), random.RandomInt(5, 33));
			Distance = PreAnchor - Anchor;
		}

		if (Distance.Y > 0) {
			for (int i = 0; i < Distance.Y; i++)
			{
				Dungeon->SetTile(Anchor.X, Anchor.Y + i, "_Ground.png");
			}
		}
		//	pre가 위에 있다면
		else if (Distance.Y < 0) {
			for (int i = 0; i > Distance.Y; i--)
			{
				Dungeon->SetTile(Anchor.X, Anchor.Y + i, "_Ground.png");
			}
		}
		//	pre가 오른쪽에 있다면
		if (Distance.X > 0) {
			for (int i = 0; i < Distance.X; i++)
			{
				Dungeon->SetTile(Anchor.X + i, Anchor.Y + Distance.Y, "_Ground.png");
			}
		}
		//	pre가 왼쪽에 있다면
		else if (Distance.X < 0) {
			for (int i = 0; i > Distance.X; i--)
			{
				Dungeon->SetTile(Anchor.X + i, Anchor.Y + Distance.Y, "_Ground.png");
			}
		}
		PreAnchor = Anchor;
	}
	FIntPoint DungeonSize = Dungeon->GetTileCount();
	for (int _y = 0; _y < DungeonSize.Y; _y++)
	{
		for (int _x = 0; _x < DungeonSize.X; _x++)
		{

			std::string SpriteName = Dungeon->GetSpriteRenderer(_x, _y)->GetCurSpriteName();
			int Index = SpriteName.find('_');
			std::string FindName = SpriteName.substr(Index);
			if ("_Ground.png" == FindName) {
				FVector2D GroundLocation = Dungeon->GetTileLocation(_x, _y);
				//AllGrounds.push_back(GroundLocation);
			}

		}
	}
}

void ADungeonGameMode::SetRandomSizeRoom()
{

}

void ADungeonGameMode::SetborderWall()
{
	FIntPoint DungeonSize = Dungeon->GetTileCount();
	for (int _y = 0; _y < DungeonSize.Y; _y++)
	{
		for (int _x = 0; _x < DungeonSize.X; _x++)
		{
			if (_y < 2 || _x < 2 || _y > 37 || _x > 57)
			{
				//	가장자리는 벽으로
				Dungeon->SetTile(_x, _y, "_Wall.png");
			}
		}
	}
}

void ADungeonGameMode::CheckTile()
{
	Dungeon->CheckTile();
}

void ADungeonGameMode::SetCurDungeonName(std::string_view _DungeonName)
{
}








#include "PreCompile.h"
#include "Dungeon.h"

#include <EngineBase/EngineRandom.h>
#include <EngineCore/SpriteRenderer.h>

#include "PMDContentsCore.h"





std::vector<FIntPoint>AllGround;
ADungeon::ADungeon()
{
	
	Tiles.resize(DungeonData.DungeonSize.Y, std::vector<Tile>(DungeonData.DungeonSize.X));
	DungeonData.TileTypes.resize(DungeonData.DungeonSize.Y, std::vector<TileType>(DungeonData.DungeonSize.X));
	SetActorLocation({ 0,0 });
}

ADungeon::~ADungeon()
{

}

void ADungeon::SetAllWall()
{
	for (int y = 0; y < DungeonData.DungeonSize.Y; y++)
	{
		for (int x = 0; x < DungeonData.DungeonSize.X; x++)
		{
			if (Tiles[y][x].SpriteRenderer == nullptr) {
				CreateTile(x, y, { 72,72 }, DungeonData.CurDungeonName + "_Wall.png",4);
			}
			SetTile(x, y, DungeonData.CurDungeonName + "_Wall.png",4);
		}
	}
}

void ADungeon::SliceDungeon()
{
	int SliceCountY = 3;
	int SliceCountX = 5;
	for (int y = 0; y < SliceCountY; y++)
	{
		for (int x = 0; x < SliceCountX; x++)
		{
			FTransform SlicedDungeonTrans;
			FVector2D SlicedDungeonScale = FVector2D(DungeonData.GenableDungeonSize.X / SliceCountX, DungeonData.GenableDungeonSize.Y / SliceCountY);
			SlicedDungeonTrans = FTransform(
				FVector2D(SlicedDungeonScale),
				FVector2D(SlicedDungeonScale.X * x + DungeonData.BoderSize
					, SlicedDungeonScale.Y * y + DungeonData.BoderSize));
			DungeonData.SlicedDungeons.push_back(SlicedDungeonTrans);
		}
	}
}

void ADungeon::SetRoom()
{
	UEngineRandom Random;
	//for (int i = 0; i < 7; i++) {
	//	FIntPoint RoomSize = FIntPoint(Random.RandomInt(3, 9), Random.RandomInt(3, 9));
	//	int maxValue = AllGround.size() - 1;
	//	int randomIndex = Random.RandomInt(0, maxValue);
	//	FIntPoint SelectPos = AllGround[randomIndex];

	//	// 방이 맵 경계 내에 있고 겹치지 않는지 확인
	//	if (SelectPos.X + RoomSize.X < 59 && SelectPos.Y + RoomSize.Y < 39 &&
	//		!IsRoomOverlap(FIntPoint(SelectPos), RoomSize, DungeonData.DungeonRooms)) {

	//		// 방 타일 배치
	//		for (int _y = 0; _y < RoomSize.Y; _y++) {
	//			for (int _x = 0; _x < RoomSize.X; _x++) {
	//				SetTile(_x + SelectPos.X, _y + SelectPos.Y, DungeonData.CurDungeonName + "_Ground.png");
	//			}
	//		}

	//		// 방 위치와 크기를 Rooms에 추가
	//		FTransform roomTransform;
	//		roomTransform.Location = FVector2D(SelectPos.X, SelectPos.Y);
	//		roomTransform.Scale = FVector2D(RoomSize.X, RoomSize.Y); // Scale을 방 크기로 저장
	//		DungeonData.DungeonRooms.push_back(roomTransform);
	//	}
	//}

	int SlicedRoomCount = DungeonData.SlicedDungeons.size();
	for (int i = 0; i < SlicedRoomCount; i++)
	{
		while (true)
		{
			Room NewRoom;
			FVector2D DungeonRoomSize = FVector2D(Random.RandomInt(3, DungeonData.SlicedDungeons[i].Scale.X), Random.RandomInt(3, DungeonData.SlicedDungeons[i].Scale.Y));
			FVector2D DungeonRoomPos = FVector2D(
				Random.RandomInt(DungeonData.SlicedDungeons[i].Location.X, DungeonData.SlicedDungeons[i].Location.X + DungeonData.SlicedDungeons[i].Scale.X - DungeonRoomSize.X),
				Random.RandomInt(DungeonData.SlicedDungeons[i].Location.Y, DungeonData.SlicedDungeons[i].Location.Y + DungeonData.SlicedDungeons[i].Scale.Y - DungeonRoomSize.Y));
			if (DungeonRoomPos.X + DungeonRoomSize.X <= DungeonData.SlicedDungeons[i].Location.X + DungeonData.SlicedDungeons[i].Scale.X
				&& DungeonRoomPos.Y + DungeonRoomSize.Y <= DungeonData.SlicedDungeons[i].Location.Y + DungeonData.SlicedDungeons[i].Scale.Y)
			{
				for (int y = 0; y < DungeonRoomSize.Y; y++) {
					for (int x = 0; x < DungeonRoomSize.X; x++) {
						SetTile(x + DungeonRoomPos.X, y + DungeonRoomPos.Y, DungeonData.CurDungeonName + "_Ground.png",4);
					}
				}
				NewRoom.RoomTrans = FTransform(DungeonRoomSize, DungeonRoomPos);
				DungeonData.Rooms.push_back(NewRoom);
				break;  // 경계를 넘지 않으면 방 생성 완료
			}
		}
	}
}

void ADungeon::SetHallWay()
{
	UEngineRandom random;


	

	FIntPoint PreAnchor = FIntPoint(random.RandomInt(DungeonData.BoderSize, DungeonData.DungeonSize.X - DungeonData.BoderSize - 1), random.RandomInt(DungeonData.BoderSize, DungeonData.DungeonSize.Y - DungeonData.BoderSize - 1));;
	AllGround.push_back(PreAnchor);

	for (int j = 0; j < 10; j++)
	{
		FIntPoint Anchor = FIntPoint(random.RandomInt(DungeonData.BoderSize, DungeonData.DungeonSize.X - DungeonData.BoderSize - 1), random.RandomInt(DungeonData.BoderSize, DungeonData.DungeonSize.Y - DungeonData.BoderSize - 1));
		AllGround.push_back(Anchor);
		FIntPoint Distance = PreAnchor - Anchor;

		if (Distance.Y > 0) {
			for (int i = 0; i < Distance.Y; i++)
			{
				SetTile(Anchor.X, Anchor.Y + i, DungeonData.CurDungeonName + "_Ground.png",4);

				AllGround.push_back(FIntPoint(Anchor.X, Anchor.Y + i));
			}
		}
		//	pre가 위에 있다면
		else if (Distance.Y < 0) {
			for (int i = 0; i > Distance.Y; i--)
			{
				SetTile(Anchor.X, Anchor.Y + i, DungeonData.CurDungeonName + "_Ground.png", 4);
				AllGround.push_back(FIntPoint(Anchor.X, Anchor.Y + i));
			}
		}
		//	pre가 오른쪽에 있다면
		if (Distance.X > 0) {
			for (int i = 0; i < Distance.X; i++)
			{
				SetTile(Anchor.X + i, Anchor.Y + Distance.Y, DungeonData.CurDungeonName + "_Ground.png", 4);
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y));
			}
		}
		//	pre가 왼쪽에 있다면
		else if (Distance.X < 0) {
			for (int i = 0; i > Distance.X; i--)
			{
				SetTile(Anchor.X + i, Anchor.Y + Distance.Y, DungeonData.CurDungeonName + "_Ground.png", 4);
				AllGround.push_back(FIntPoint(Anchor.X + i, Anchor.Y));
			}
		}
		PreAnchor = Anchor;
	}
}

void ADungeon::SetBorderWall()
{
	for (int y = 0; y < DungeonData.DungeonSize.Y; y++)
	{
		for (int x = 0; x < DungeonData.DungeonSize.X; x++)
		{
			if (y <= 2 || x <= 2 || y >= DungeonData.DungeonSize.Y - 3 || x >= DungeonData.DungeonSize.X - 3)
			{
				//	가장자리는 벽으로
				SetTile(x, y, DungeonData.CurDungeonName + "_Wall.png", 4);
			}
		}
	}
}

void ADungeon::SetNaturally()
{
	for (int y = 0; y < DungeonData.DungeonSize.Y; y++)
	{
		for (int x = 0; x < DungeonData.DungeonSize.X; x++)
		{
			if (nullptr != Tiles[y][x].SpriteRenderer)
			{
				//	현재타일이름
				std::string SpriteName = Tiles[y][x].SpriteRenderer->GetCurSpriteName();
				int FindIndex = SpriteName.find('_');
				std::string TypeName = SpriteName.substr(FindIndex);
				if ("_GROUND.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TileType::GROUND;
				}
				else if ("_WALL.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TileType::WALL;
				}
				else if ("_WATER.PNG" == TypeName)
				{
					DungeonData.TileTypes[y][x] = TileType::WATER;
				}

				if (y >= 1 && x >= 1 && y <= DungeonData.DungeonSize.Y - 2 && x <= DungeonData.DungeonSize.X - 2)
				{
					//	타일세팅
					std::string FindKey = "";
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (0 <= y + i && 0 <= x + j && DungeonData.DungeonSize.X > x + j && DungeonData.DungeonSize.Y > y + i)
							{
								//	주위타일과 타일이름을 비교해서 키값생성
								std::string CompareName = Tiles[y + i][x + j].SpriteRenderer->GetCurSpriteName();
								if (SpriteName == CompareName) {
									FindKey += "1";
								}
								else if (SpriteName != CompareName) {
									FindKey += "0";
								}
							}
						}
					}
					int SpriteIndex = PMDContentsCore::GetTileIndex(FindKey);
					Tiles[y][x].SpriteRenderer->SetSprite(SpriteName, SpriteIndex);
				}
			}
		}
	}
}

bool ADungeon::IsRoomOverlap(const FIntPoint& pos, const FIntPoint& size, const std::vector<FTransform>& rooms)
{
	const int padding = 3; // 최소 간격
	for (const auto& room : rooms) {
		FIntPoint roomPos(room.Location.X, room.Location.Y);
		FIntPoint roomSize(room.Scale.X, room.Scale.Y);

		// 각 방의 경계를 패딩만큼 확장
		if (!(pos.X + size.X + padding <= roomPos.X || pos.X >= roomPos.X + roomSize.X + padding ||
			pos.Y + size.Y + padding <= roomPos.Y || pos.Y >= roomPos.Y + roomSize.Y + padding)) {
			return true; // 겹침
		}
	}
	return false; // 겹치지 않음
}



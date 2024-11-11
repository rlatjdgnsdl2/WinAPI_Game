#include "PreCompile.h"
#include "TurnManager.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EnginePlatform/EngineInput.h>


#include "Player.h"
#include "Dungeon_BSP.h"
#include "Partner.h"



ATurnManager::ATurnManager()
{

}

ATurnManager::~ATurnManager()
{

}

void ATurnManager::LevelChangeStart()
{
	Super::LevelChangeStart();
	//	MainPawn 연결
	AActor* PlayerActor = GetWorld()->GetPawn();
	Player = dynamic_cast<APlayer*>(PlayerActor);
	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
	GetWorld()->SetCameraToMainPawn(true);

	//	Spawn위치 설정
	SetSpawnPos();
	//	초기화
	Player->SetStartLocation(Player->GetActorLocation());
	Player->SetTargetLocation(Player->GetActorLocation());
	//	캠프설정
	PlayerCamp.push_back(Player);
	PlayerCamp.push_back(Partner);

	CurTurnType = TurnType::Player_Select;

}

void ATurnManager::Tick(float _DeltaTime)
{

	Super::Tick(_DeltaTime);
	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("X : " + std::to_string(Player->GetActorLocation().X));
	UEngineDebug::CoreOutPutString("Y : " + std::to_string(Player->GetActorLocation().Y));
	UEngineDebug::CoreOutPutString("DebugMode : " + std::to_string(IsDebugMode));



	switch (CurTurnType)
	{
	case TurnType::Player_Select:
		PlayerSelect();
		break;
	case TurnType::Player_Select_Move:
		SelectMove(PlayerInput);
		break;
	case TurnType::Player_Select_Skill:
		SelectSkill(PlayerInput);
		break;
	case TurnType::Player_Move:
		PlayerMove(_DeltaTime);
		break;
	case TurnType::Player_Skill:
		PlayerSkill(_DeltaTime);
		break;
	case TurnType::Move_AI_Select:
		Move_AISelect(_DeltaTime);
		break;
	case TurnType::Skill_AI_Select:
		Skill_AISelect(_DeltaTime);
		break;
	case TurnType::AI_Move:
		AIMove(_DeltaTime);
		break;
	case TurnType::AI_Skill:
		AISkill(_DeltaTime);
		break;

	}
}



void ATurnManager::SetSpawnPos()
{
	UEngineRandom Random;
	// player pos
	int MaxSize = Dungeon->GetRoomLocations().size();
	int Index = Random.RandomInt(0, MaxSize - 1);
	FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
	Player->SetActorLocation(RoomLocation);


	std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
	std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsSpawnable = false;
		while (!IsSpawnable) {
			int Index = Random.RandomInt(0, MaxSize - 1);
			FVector2D RoomLocation = Dungeon->GetRoomLocations()[Index];
			if (RoomLocation != Player->GetActorLocation()) {
				CurPokemon->SetActorLocation(RoomLocation);
				IsSpawnable = true;
			}
		}
	}




	//// partner pos
	///*FVector2D PlayerPos = Player->GetActorLocation();
	//FVector2D PosIndex = PlayerPos / 72;
	//bool isSpawnPartner = false;
	//for (int y = -1; y <= 1; y++)
	//{
	//	for (int x = -1; x <= 1; x++)
	//	{
	//		TileType TileType = Dungeon->GetDungeonData()->TileTypes[PosIndex.iY() + y][PosIndex.iX()+x];
	//		if (TileType::GROUND == TileType && x != 0 && y != 0)
	//		{
	//			FVector2D PartnerPos = FVector2D(PlayerPos.X + x * 72, PlayerPos.Y + y * 72);
	//			Partner->SetActorLocation(PartnerPos);
	//			isSpawnPartner = true;
	//		}
	//	}
	//	if (isSpawnPartner)
	//	{
	//		break;
	//	}
	//*/}

	//// TestSpawn monster
	////TestEnemy->SetActorLocation(PlayerPos+FVector2D(144,144));


}









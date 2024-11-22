#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"
#include "DungeonUI.h"



void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);
	// 플레이어가 이동할때 MovePokemon에 있는 포켓몬 모두 동시에 이동함
	for (APokemon* CurPokemon : MovePokemon) {
		CurPokemon->Move(_DeltaTime);
	}
	// 플레이어가 도착했으면
	FVector2D CurPlayerLocation = Player->GetActorLocation();
	FVector2D PlayerTargetLocation = Player->GetTargetLocation();
	FVector2D NextPotalLocation = Dungeon->GetPotalLocation();
	if (CurPlayerLocation == PlayerTargetLocation)
	{
		// 포탈위치인지 확인
		if (CurPlayerLocation == NextPotalLocation)
		{
			//  다음층이 Max층이면
			//  Game Clear
			//	UI띠우고
			DungeonUI->IsGoingNextFloor();
			PreTurn = CurTurn;
			CurTurn = TurnType::Open_UI;
			return;
			
		}
		
		//	MovePokemon에 있는 포켓몬 모두 강제로 도착하게
		for (APokemon* CurPokemon : MovePokemon) {
			CurPokemon->Move(1.0f);
		}
		//	다 이동했으면 MovePokemon초기화
		MovePokemon.clear();

		CurTurn = TurnType::AI_Skill;
		return;
	}
}
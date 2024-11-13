#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"




void ATurnManager::PlayerMove(float _DeltaTime)
{
	//	Player move
	Player->Move(_DeltaTime);
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	//	 플레이어가 이동할때 MovePokemon에 있는 포켓몬 모두 이동함
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Move(_DeltaTime);
	}

	// 플레이어가 도착했으면
	if (Player->GetActorLocation() == Player->GetTargetLocation())	
	{
		//	MovePokemon에 있는 포켓몬 모두 강제로 도착하게
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			CurPokemon->Move(1.0f);
			CurPokemon->ResetCurDuration();
		}
		//	다 이동했으면 MovePokemon초기화
		MovePokemon.clear();
		//	다음단계
		CurTurnType = TurnType::AI_Move;
	}
}
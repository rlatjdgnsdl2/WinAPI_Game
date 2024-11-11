#include "PreCompile.h"
#include "TurnManager.h"


#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>

#include "Pokemon.h"
#include "Player.h"




void ATurnManager::PlayerMove(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	//	Player move
	Player->Move(_DeltaTime);

	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();

	// 플레이어가 이동할때 MoveVec에 있는 포켓몬 모두 이동함
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		CurPokemon->Move(_DeltaTime);
	}

	if (Player->GetActorLocation() == Player->GetTargetLocation())	//도착했으면
	{
		std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
		std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
		for (; StartIter != EndIter; StartIter++)
		{
			APokemon* CurPokemon = *StartIter;
			CurPokemon->Move(1.0f);
			CurPokemon->SetCurDuration(0.0f);
		}
		//	이동한 몬스터들 다 Vec에서 제거
		MovePokemon.clear();
		CurDuration = 0.0f;
		//	다음단계
		CurTurnType = TurnType::AI_Skill;
	}
}
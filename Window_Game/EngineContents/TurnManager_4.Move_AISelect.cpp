#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::Move_AISelect(float _DeltaTime)
{
	//	모든 AI포켓몬들
	std::vector<class APokemon*> ::iterator StartIter = IdleVec.begin();
	std::vector<class APokemon*> ::iterator EndIter = IdleVec.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		//	피아식별
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		CampType CurCamp = CurPokemon->GetCurCamp();
		//	주인공편일때
		if (CampType::Player == CurCamp)
		{
			bool IsFindTarget = false;
			//	적들이랑 위치비교
			std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
			std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				//	한칸내에 있으면
				if (Distance.X <= 72 && Distance.Y <= 72&& Distance.Y >= -72&&Distance.Y >= -72)
				{
					//	SkillVec에 넣어줌
					SkillVec.push_back(CurPokemon);
					//	타겟을 찾음
					IsFindTarget = true;
					
				}	
			}
			// 타겟못찾으면
			if (!IsFindTarget) 
			{
				//타겟로케이션 정해줘야함(플레이어 위치 기준)
				//	파트너만 위치 정해주는 임시코드 (길찾기 알고리즘 없으면 못함)
				CurPokemon->SetStartLocation(CurPokemon->GetActorLocation());
				CurPokemon->SetTargetLocation(Player->GetStartLocation());
				CurPokemon->SetCurDuration(0.0f);
				//MoveVec에 넣어줌
				MoveVec.push_back(CurPokemon);
			}
		}
		//	위와동일
		else if (CampType::Enemy == CurCamp)
		{
			bool IsFindTarget = false;
			std::vector<APokemon*>::iterator StartIter = PlayerCamp.begin();
			std::vector<APokemon*>::iterator EndIter = PlayerCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				if (Distance.X <= 72 && Distance.Y <= 72 && Distance.Y >= -72 && Distance.Y >= -72)
				{
					SkillVec.push_back(CurPokemon);
					IsFindTarget = true;
					
				}

			}
			if (!IsFindTarget)
			{
				//타겟로케이션 정해줘야함(플레이어 위치 기준)
				//	파트너만 위치 정해주는 임시코드 (길찾기 알고리즘 없으면 못함)
				CurPokemon->SetStartLocation(CurPokemon->GetActorLocation());
				CurPokemon->SetTargetLocation(CurPokemon->GetStartLocation() + FVector2D::UP * 72);
				CurPokemon->SetCurDuration(0.0f);

				MoveVec.push_back(CurPokemon);
			}
		}
		
	}


	// 다음단계
	CurTurnType = TurnType::Player_Move;
}
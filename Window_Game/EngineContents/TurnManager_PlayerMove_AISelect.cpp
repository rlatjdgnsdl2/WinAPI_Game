#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::PlayerMove_AISelect(float _DeltaTime)
{
	std::unordered_map<float, APokemon*>::iterator StartIter = IdleMaps.begin();
	std::unordered_map<float, APokemon*>::iterator EndIter = IdleMaps.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = StartIter->second;
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		CampType CurCamp = CurPokemon->GetCurCamp();
		if (CampType::Player == CurCamp)
		{
			bool IsFindTarget = false;
			std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
			std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				if (Distance <= FVector2D(72, 72))
				{
					SkillMaps.insert({ CurPokemon->GetSpeed(),CurPokemon });
					IsFindTarget = true;
					return;
				}
				
			}
			if (!IsFindTarget) 
			{
				MoveMaps.insert({ CurPokemon->GetSpeed(),CurPokemon });
			}
		}
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
				if (Distance <= FVector2D(72, 72))
				{
					SkillMaps.insert({ CurPokemon->GetSpeed(),CurPokemon });
					IsFindTarget = true;
					return;
				}

			}
			if (!IsFindTarget)
			{
				MoveMaps.insert({ CurPokemon->GetSpeed(),CurPokemon });
			}
		}
		
	}



	CurTurnType = TurnType::Player_Move;
}
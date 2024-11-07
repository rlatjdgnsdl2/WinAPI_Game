#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"

void ATurnManager::PlayerMove_AISelect(float _DeltaTime)
{
	std::map<float, APokemon*>::iterator StartIter = IdleMaps.begin();
	std::map<float, APokemon*>::iterator EndIter = IdleMaps.end();
	for (; StartIter!=EndIter; StartIter++) 
	{
		APokemon* CurPokemon = StartIter->second;
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		CampType CurCamp = CurPokemon->GetCurCamp();
		if (CampType::Player == CurCamp) 
		{
			std::vector<APokemon*>::iterator StartIter = EnemyCamp.begin();
			std::vector<APokemon*>::iterator EndIter = EnemyCamp.end();
			for (; StartIter != EndIter; StartIter++)
			{
				APokemon* ComparePokemon = *StartIter;
				FVector2D CompreLocation = ComparePokemon->GetActorLocation();
				FVector2D Distance = CompreLocation - CurPokemonLocation;
				if (Distance <= FVector2D(72, 72)) 
				{
					SkillMaps.insert({ 1.0f,CurPokemon });
				}

			}
		}
		
		
	}

	

	CurTurnType = TurnType::Player_Move;
}
#include "PreCompile.h"
#include "TurnManager.h"

#include "Player.h"
#include "Pokemon.h"


void ATurnManager::PlayerSkill(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	Player->Skill(Player->GetCurSkillType());
	APokemon* TargetPokemon = Player->GetTargetPokemon();
	if (TargetPokemon != nullptr) {
		//데미지받기
	}
	if (CurDuration > 0.51f) {
		CurTurnType = TurnType::Skill_AI_Select;
		CurDuration = 0.0f;
	}
}
#include "PreCompile.h"
#include "SkillManager.h"
#include "Pokemon.h"
#include "Dungeon_BSP.h"
#include "TurnManager.h"

ASkillManager::ASkillManager()
{
	SkillFunc["NormalAttack"] = [&](APokemon* _SkillUser, APokemon* _Target) {
		if (_SkillUser == nullptr || _Target == nullptr) {
			return;
		}
		int Damage = UContentsMath::DamageCalculation(_SkillUser->GetATK(), _Target->GetDEF());
		_Target->SetDamage(Damage);
		};

	
}

ASkillManager::~ASkillManager()
{
}


#include "PreCompile.h"
#include "TurnManager.h"

#include <EngineBase/EngineRandom.h>
#include "Pokemon.h"
#include "UIManager.h"
//#include "DungeonUI.h"

void ATurnManager::AISkillStart()
{
	if (SkillPokemon.empty()) {
		CurTurn = TurnType::Player_Select;
		return;
	}
	APokemon* CurPokemon = SkillPokemon.front();
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	// �������� Ÿ�����ϸ� ���ϱ�
	if (TargetPokemon == nullptr) {
		std::list<APokemon*>& CompareCamp = (CurPokemon->GetCamp() == CampType::Player) ? EnemyCamp : PlayerCamp;
		if (CompareCamp.empty()) {
			CurTurn = TurnType::Player_Select;
			return;
		}
		FIntPoint CurTile = CurPokemon->GetTile();
		for (APokemon* ComparePokemon : CompareCamp) {
			FIntPoint Distance = ComparePokemon->GetTargetTile() - CurTile;
			//	��ó�� ���� �ִٸ� �� Ÿ�ٰ��ɺ��Ϳ� Ǫ��
			if (std::abs(Distance.X) <= 1 && std::abs(Distance.Y) <= 1) {
				if (Distance.X == 0 && Distance.Y == 0) {
					continue;
				}
				CurPokemon->PushTargetablePokemon(ComparePokemon);
			}
		}
		//Ÿ�ٰ��� ���ϸ��߿� �Ѹ� �������� Ÿ�ټ���
		std::vector<APokemon*>& TargetablePokemons = CurPokemon->GetTargetablePokemons();
		if (TargetablePokemons.empty()) {
			CurTurn = TurnType::AI_Skill_End;
			return;
		}
		int RandomIndex = Random.RandomInt(0, static_cast<int>(CurPokemon->GetTargetablePokemons().size()) - 1);
		APokemon* SelectTargetPokemon = CurPokemon->GetTargetablePokemons()[RandomIndex];
		if (SelectTargetPokemon == nullptr) {
			CurTurn = TurnType::AI_Skill_End;
			return;
		}
		// Ÿ���� �� ����������
		CurPokemon->SetTargetPokemon(SelectTargetPokemon);
	}
	TargetPokemon = CurPokemon->GetTargetPokemon();
	FIntPoint TargetTile = TargetPokemon->GetTile();
	FIntPoint CurTile = CurPokemon->GetTile();
	FIntPoint TargetDir = TargetTile - CurTile;
	CurPokemon->SetDir(UContentsMath::FIntPoint_To_DIR(TargetDir));
	CurPokemon->SetSkill(SkillType::NormalAttack);
	CurPokemon->ResetTargetablePokemon();
	CurPokemon->StartAttack();
	int Damage = UContentsMath::DamageCalculation(CurPokemon->GetATK(), TargetPokemon->GetDEF());
	UIManager->NewLogMessage(
		{ CurPokemon->GetName()," damage to ", TargetPokemon->GetName()," for " ,std::to_string(Damage) },
		{ Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow });
	TargetPokemon->SetDamage(Damage);
	CurTurn = TurnType::AI_Skill;
}

void ATurnManager::AISkill()
{
	APokemon* CurPokemon = SkillPokemon.front();
	CurPokemon->Skill();
	if (CurPokemon->IsAttack()) {
		return;
	}
	CurTurn = TurnType::AI_Skill_End;
}

void ATurnManager::AISkillEnd()
{
	APokemon* CurPokemon = SkillPokemon.front();
	APokemon* TargetPokemon = CurPokemon->GetTargetPokemon();
	if (TargetPokemon != nullptr && TargetPokemon->IsDie()) {
		// ���� ���ϸ��� Player�����϶�
		if (TargetPokemon->GetCamp() == CampType::Player) {
			// ���ӿ���
		}
		else {
			// ���� ���ϸ��� ���϶�
			int Level = TargetPokemon->GetLevel();
			UIManager->NewLogMessage(
				{ TargetPokemon->GetName()," Die and ", "Player Party",  " Gain EXP ",std::to_string(TargetPokemon->GetLevel() * 100) }, { Color::Blue,Color::White,Color::Blue,Color::White,Color::Yellow });
			// ��Ƽ�� ���� ����ġ ȹ�� �� ������������
			for (APokemon* CurPokemon : PlayerCamp) {
				if (CurPokemon != nullptr && CurPokemon->GainExp(TargetPokemon->GetLevel() * 100)) {
					UIManager->NewLogMessage(
						{ CurPokemon->GetName()," Level Up!", }, { Color::Blue,Color::Yellow });
					UIManager->NewLogMessage(
						{ "All Ability ","+2" }, { Color::White,Color::Yellow });
				}
			}
			AllAIPokemon.remove(TargetPokemon);
			SkillPokemon.remove(TargetPokemon);
			MovePokemon.remove(TargetPokemon);
			EnemyCamp.remove(TargetPokemon);
			TargetPokemon->Destroy();
		}
	}
	CurPokemon->ResetTargetablePokemon();
	CurPokemon->SetTargetPokemon(nullptr);
	SkillPokemon.remove(CurPokemon);
	CurTurn = TurnType::AI_Skill_Start;
}



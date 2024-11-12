#include "PreCompile.h"
#include "TurnManager.h"
#include "Pokemon.h"
#include "Player.h"
#include "Dungeon_BSP.h"


bool SortFunc(APokemon* first, APokemon* second) {
	if (first->GetPokemonStat().Speed > second->GetPokemonStat().Speed) 
	{
		return true;
	}
	return false;
}




void ATurnManager::Move_AISelect(float _DeltaTime)
{
	// speed�� ����
	AllPokemon.sort(SortFunc);
	//	��� AI���ϸ��
	std::list<class APokemon*> ::iterator StartIter = AllPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsFindTarget = false;
		// ������ġ
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		//	���� ����
		CampType CurCamp = CurPokemon->GetCurCamp();

		// �������ϸ��
		std::list<class APokemon*> ::iterator CompareStartIter = AllPokemon.begin();
		std::list<class APokemon*> ::iterator CompareEndIter = AllPokemon.end();
		for (; CompareStartIter != CompareEndIter; CompareStartIter++)
		{
			//	�� �ڽ��̸� �ǳʶ�
			if (StartIter == CompareStartIter) {
				continue;
			}
			//	���� ���ϸ� 
			APokemon* ComparePokemon = *CompareStartIter;
			//	���� ���ϸ� ����
			CampType CompareCamp = ComparePokemon->GetCurCamp();
			//	���� �ٸ������̸�
			if (CurCamp != CompareCamp)
			{
				//	���� ���ϸ� ��ġ
				FVector2D CompareLocation = ComparePokemon->GetTargetLocation();
				//	�Ÿ�����
				FVector2D Distance = CompareLocation - CurPokemonLocation;
				//	���࿡ �ٷ� ���̰ų� �տ� �� �����̸�
				if (Distance.X <= 72 && Distance.Y <= 72 && Distance.Y >= -72 && Distance.Y >= -72)
				{
					//	SkillVec�� �־���
					IsFindTarget = true;
					//	Ÿ�ټ���
					CurPokemon->SetTargetPokemon(ComparePokemon);
					SkillPokemon.push_back(CurPokemon);
					//	Ÿ���� ã��
					if (true==IsFindTarget) {
						break;
					}

				}
				
			}
			if (false == IsFindTarget) {
				MovePokemon.push_back(CurPokemon);
			}
			int a = 0;

		}

	}

	// �����ܰ�
	CurTurnType = TurnType::Player_Move;
}

bool ATurnManager::IsMove(const FIntPoint& _Point)
{
	FIntPoint CheckPoint = _Point;
	// ���������� ������ false
	if (true == Dungeon->IsOver(CheckPoint)) {
		return false;
	}
	// ���� �ƴϸ� ture
	TileType CheckTileType = Dungeon->Tiles[CheckPoint.Y][CheckPoint.X].TileType;
	if (TileType::GROUND != CheckTileType) {
		return false;
	}

	// �ٸ����ϸ��� �̵��� ���̸�
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonTargetLocation = CurPokemon->GetTargetLocation();
		if (CurPokemonTargetLocation.ConvertToPoint() == CheckPoint * 72) {
			return false;
		}
	}
	return true;
}
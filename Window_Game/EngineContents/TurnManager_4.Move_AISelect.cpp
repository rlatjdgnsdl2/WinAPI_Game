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
	AllAIPokemon.sort(SortFunc);
	PlayerCamp.sort(SortFunc);
	EnemyCamp.sort(SortFunc);

	//	��� AI���ϸ��
	std::list<class APokemon*> ::iterator StartIter = AllAIPokemon.begin();
	std::list<class APokemon*> ::iterator EndIter = AllAIPokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		bool IsFindTarget = false;
		// ������ġ
		FVector2D CurPokemonLocation = CurPokemon->GetActorLocation();
		//	���� ����
		CampType CurCamp = CurPokemon->GetCurCamp();

		// �������ϸ��
		std::list<class APokemon*> ::iterator CompareStartIter = AllAIPokemon.begin();
		std::list<class APokemon*> ::iterator CompareEndIter = AllAIPokemon.end();
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
					if (true == IsFindTarget) {
						break;
					}

				}

			}


		}

		if (false == IsFindTarget) {
			FIntPoint StartIndex = CurPokemon->GetActorLocation().ConvertToPoint() / 72;
			FIntPoint TargetIndex = Player->GetTargetLocation().ConvertToPoint() / 72;
			std::list<FIntPoint> PathIndexList = PathFinder.PathFind(StartIndex, TargetIndex);
			std::list<FIntPoint>::iterator StartIter = PathIndexList.begin();
			if (PathIndexList.size() == 0) {

				CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
				CurPokemon->SetTargetLocation(CurPokemon->GetActorLocation());
			}
			else {
				StartIndex = *StartIter;
				StartIter++;
				TargetIndex = *StartIter;
				CurPokemon->SetStartLocation(FVector2D(StartIndex.X * 72.0f, StartIndex.Y * 72.0f));
				CurPokemon->SetTargetLocation(FVector2D(TargetIndex.X * 72.0f, TargetIndex.Y * 72.0f));

			}
			MovePokemon.push_back(CurPokemon);
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

	//�ٸ����ϸ��� �̵��� ���̸�
	std::vector<APokemon*>::iterator StartIter = MovePokemon.begin();
	std::vector<APokemon*>::iterator EndIter = MovePokemon.end();
	for (; StartIter != EndIter; StartIter++)
	{
		APokemon* CurPokemon = *StartIter;
		FVector2D CurPokemonTargetLocation = CurPokemon->GetTargetLocation();
		if (CurPokemonTargetLocation.ConvertToPoint() / 72 == CheckPoint) {
			return false;
		}
	}
	return true;
}
#include "PreCompile.h"
#include "Enemy.h"


AEnemy::AEnemy() 
{

}

AEnemy::~AEnemy() 
{

}

void AEnemy::LevelChangeStart()
{
	Super::LevelChangeStart();
	CurCamp = CampType::Enemy;
}


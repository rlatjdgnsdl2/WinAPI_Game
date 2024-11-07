#include "PreCompile.h"
#include "Enemy.h"


Enemy::Enemy() 
{

}

Enemy::~Enemy() 
{

}

void Enemy::LevelChangeStart()
{
	Super::LevelChangeStart();
	CurCamp = CampType::Enemy;
}


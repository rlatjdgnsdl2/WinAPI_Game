#include "PreCompile.h"
#include "TurnManager.h"
#include "Partner.h"
#include "Player.h"


void ATurnManager::InitPlayerAttack() 
{

}

void ATurnManager::PlayerAttack()
{
	Player->Attack();
	//Partner->Move();
}
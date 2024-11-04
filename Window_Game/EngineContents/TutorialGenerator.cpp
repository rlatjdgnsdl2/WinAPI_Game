#include "PreCompile.h"
#include "TutorialGenerator.h"
#include "TileMap.h"

#include <EngineBase/EngineRandom.h>
	


UTutorialGenerator::UTutorialGenerator() 
{

}
UTutorialGenerator::~UTutorialGenerator() 
{

}

void UTutorialGenerator::SetRandomHallWay()
{
	UEngineRandom random;
	FVector2D anchor = FVector2D(random.RandomInt(3,15), random.RandomInt(3,20));
	//GetDungeon()->SetTile(anchor.iX(), anchor.iY(), "_Ground.png");
}
void UTutorialGenerator::SetRandomSizeRoom()
{
	
}


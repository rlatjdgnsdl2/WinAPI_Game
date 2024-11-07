#include "PreCompile.h"
#include "2DCollision.h"

U2DCollision::U2DCollision()
{
}

U2DCollision::~U2DCollision()
{
}

void U2DCollision::BeginPlay()
{
	Super::BeginPlay();

	// 스프라이트 랜더러가 

	AActor* Actor = GetActor();
	ULevel* Level = Actor->GetWorld();

	Level->PushCollision(this);
}

void U2DCollision::ComponentTick(float _DeltaTime)
{
	Super::ComponentTick(_DeltaTime);

	// 디버그 모드가 on
	int a = 0;
}


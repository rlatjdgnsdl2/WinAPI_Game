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

	// ��������Ʈ �������� 

	AActor* Actor = GetActor();
	ULevel* Level = Actor->GetWorld();

	Level->PushCollision(this);
}

void U2DCollision::ComponentTick(float _DeltaTime)
{
	Super::ComponentTick(_DeltaTime);

	// ����� ��尡 on
	int a = 0;
}


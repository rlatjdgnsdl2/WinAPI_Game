#include "PreCompile.h"
#include "TitlePetal.h"
#include <EngineCore/SpriteRenderer.h>

ATitlePetal::ATitlePetal()
{
	

}

ATitlePetal::ATitlePetal(FVector2D _Location)
{
	SetActorLocation(_Location);
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite("Title_Petal.png");
	SpriteRenderer->SetSpriteScale(1.0f);
	
}

ATitlePetal::~ATitlePetal()
{

}

void ATitlePetal::BeginPlay()
{
	Super::BeginPlay();
	SpriteRenderer->CreateAnimation("Small_Petal", "Title_Petal.png", 0, 15, 0.1f, true);
	SpriteRenderer->CreateAnimation("Big_Petal", "Title_Petal.png", 16, 31, 0.1f, true);
	Speed = Random.RandomInt(800, 1500);
	
}

void ATitlePetal::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AddActorLocation(FVector2D::UP * Speed * _DeltaTime);
	AddActorLocation(FVector2D::LEFT * 500 * _DeltaTime);
	if (IsSmall) {
		SpriteRenderer->ChangeAnimation("Small_Petal");
	}
	else {
		SpriteRenderer->ChangeAnimation("Big_Petal");
	}
}

void ATitlePetal::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void ATitlePetal::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}


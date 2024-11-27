#include "PreCompile.h"
#include "Item.h"

#include <EngineCore/SpriteRenderer.h>
#include "Player.h"
#include "GameDataManager.h"

AItem::AItem() 
{
	
}

AItem::AItem(std::string_view _ItemName)
{
	SetName(_ItemName);
	ItemRenderer = CreateDefaultSubObject<USpriteRenderer>();
	ItemRenderer->SetSprite(GetName()+"_item.png");
	ItemRenderer->SetSpriteScale();
	ItemRenderer->SetOrder(ERenderOrder::Item);
}

AItem::~AItem() 
{

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetPawn());
	ItemRenderer->SetSpriteScale();
	ItemRenderer->SetOrder(ERenderOrder::Item);
}

void AItem::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Player != nullptr) {
		FVector2D PlayerPos = Player->GetActorLocation();
		FVector2D ItemPos = GetActorLocation();
		if (PlayerPos == ItemPos)
		{
			UGameDataManager::GetInst().PushInventory(GetName());
			Destroy();
		}
	}
}

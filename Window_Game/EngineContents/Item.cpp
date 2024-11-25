#include "PreCompile.h"
#include "Item.h"
#include <EngineCore/SpriteRenderer.h>

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

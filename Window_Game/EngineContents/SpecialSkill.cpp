#include "PreCompile.h"
#include "SpecialSkill.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"



ASpecialSkill::ASpecialSkill(std::string_view SkillName) :SpriteRenderer(nullptr)
{
	SetName(SkillName);
}

ASpecialSkill::~ASpecialSkill()
{

}

void ASpecialSkill::BeginPlay()
{
	Super::BeginPlay();
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite(GetName(), 0);
	FVector2D Scale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y / 3.0f * -1.0f });
	SpriteRenderer->SetOrder(ERenderOrder::AttacK_Player);
	int MaxCount = UGameDataManager::GetInst().GetSkillAnimCount(GetName());
	float Frame = 1.0f / MaxCount;
	SpriteRenderer->CreateAnimation(GetName(), GetName(), 0, MaxCount - 1, Frame, false);



}

void ASpecialSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SpriteRenderer->ChangeAnimation(GetName());
}

bool ASpecialSkill::IsAttack()
{
	return false == SpriteRenderer->IsCurAnimationEnd();
}





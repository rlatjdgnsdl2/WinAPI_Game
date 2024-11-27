#include "PreCompile.h"
#include "SpecialSkill.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"



ASpecialSkill::ASpecialSkill(std::string_view SkillName) :SpriteRenderer(nullptr), Player(nullptr), Target(nullptr)
{
	SetName(SkillName);
}

ASpecialSkill::~ASpecialSkill()
{

}

void ASpecialSkill::BeginPlay()
{
	Super::BeginPlay();
	SkillName = GetName();
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetSprite(SkillName, 0);
	FVector2D Scale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y / 3.0f * -1.0f });
	SpriteRenderer->SetOrder(ERenderOrder::AttacK_Player);
	if (SkillName != "NORMAL_ATTACK") {
		int MaxCount = UGameDataManager::GetInst().GetSkillAnimCount(SkillName);
		float Frame = 1.0f / MaxCount;
		SpriteRenderer->CreateAnimation(GetName(), GetName(), 0, MaxCount - 1, Frame, false);
		SpriteRenderer->ChangeAnimation(GetName());
	}
}

void ASpecialSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

bool ASpecialSkill::IsAttack()
{
	return false == SpriteRenderer->IsCurAnimationEnd();
}





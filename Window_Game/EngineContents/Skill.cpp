#include "PreCompile.h"
#include "Skill.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"
#include "Pokemon.h"


ASkill::ASkill(std::string_view SkillName) :SpriteRenderer(nullptr), TargetPokemon(nullptr), UserPokemon(nullptr)
{
	SetName(SkillName);
}

ASkill::~ASkill()
{

}

void ASkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	switch (CurSkillState)
	{
	case SkillState::None:

		break;
	case SkillState::Start:
		StartSkill();
		break;
	case SkillState::Update:
		UpdateSkill(_DeltaTime);
		break;
	case SkillState::End:
		EndSkill();
		break;
	default:
		break;
	}
}

void ASkill::SetUserPokemon(APokemon* _UserPokemon)
{
	UserPokemon = _UserPokemon;
	TargetPokemon = UserPokemon->GetTargetPokemon();
	StartLocation = UserPokemon->GetActorLocation();
	TargetLocation = UserPokemon->GetTargetLocation();
	Dir = UserPokemon->GetDir();
}

void ASkill::StartSkill()
{
	std::string SkillName = GetName();
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	int StartMaxCount = UGameDataManager::GetInst().GetSkillAnimCount(SkillName + "_Start");
	int EndMaxCount = UGameDataManager::GetInst().GetSkillAnimCount(SkillName + "_End");
	float StartFrame = 1.0f / StartMaxCount;
	float EndFrame = 1.0f / EndMaxCount;
	SpriteRenderer->CreateAnimation(SkillName + "_Start", SkillName + "_Start", 0, StartMaxCount - 1, StartFrame, false);
	SpriteRenderer->CreateAnimation(SkillName + "_End", SkillName + "_End", 0, EndMaxCount - 1, EndFrame, false);
	SpriteRenderer->SetOrder(ERenderOrder::AttacK_Player);

	SpriteRenderer->ChangeAnimation(SkillName + "_Start");
	FVector2D Scale = SpriteRenderer->SetSpriteScale();
	SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y / 3.0f * -1.0f });
}

void ASkill::UpdateSkill(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration);
	SetActorLocation(NewLocation);
	FVector2D SkillLocation = GetActorLocation();
	if (SkillLocation == TargetLocation)
	{
		SpriteRenderer->ChangeAnimation(GetName() + "_End");
		FVector2D Scale = SpriteRenderer->SetSpriteScale();
		SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y / 3.0f * -1.0f });
		if (TargetPokemon != nullptr)
		{
			DIR TargetDir = UContentsMath::ReverseDir(Dir);
			TargetPokemon->SetDir(TargetDir);
			TargetPokemon->Hurt();
		}

		CurSkillState = SkillState::End;
	}
}

void ASkill::EndSkill()
{
	if (SpriteRenderer->IsCurAnimationEnd())
	{
		//Destroy();
	}
}

bool ASkill::IsAttack()
{
	return false == SpriteRenderer->IsCurAnimationEnd();
}

#include "PreCompile.h"
#include "Skill.h"

#include <EngineCore/SpriteRenderer.h>
#include "Pokemon.h"
#include "GameDataManager.h"

ASkill::ASkill(std::string_view _SkillName)
{
	SkillName = _SkillName;
	SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
}

ASkill::~ASkill()
{

}

void ASkill::BeginPlay()
{
	Super::BeginPlay();
	SpriteRenderer->SetSprite("Void.png");
	FVector2D Scale = SpriteRenderer->SetSpriteScale();
	//SpriteRenderer->SetComponentLocation({ 0.0f,Scale.Y / 3.0f * -1.0f });
	SpriteRenderer->SetOrder(ERenderOrder::AttacK_Player);
	int StartMaxCount = UGameDataManager::GetInst().GetSkillAnimCount(SkillName+"_Start");
	int EndMaxCount = UGameDataManager::GetInst().GetSkillAnimCount(SkillName+ "_End");
	float StartFrame = 1.0f / StartMaxCount;
	float EndFrame = 1.0f / EndMaxCount;	
	SpriteRenderer->CreateAnimation(SkillName + "_START", SkillName +"_START", 0, StartMaxCount - 1, StartFrame, false);
	SpriteRenderer->CreateAnimation(SkillName + "_END", SkillName + "_END", 0, EndMaxCount - 1, EndFrame, false);
	CurState = SkillState::Ready;
}

void ASkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	switch (CurState)
	{
	case SkillState::Ready:
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
	}
}

void ASkill::SetAttacker(APokemon* _Attacker)
{
	SkillUser = _Attacker;
	Target = SkillUser->GetTargetPokemon();
	SetActorLocation(SkillUser->GetActorLocation());
	CurState = SkillState::Start;
}

void ASkill::StartSkill()
{
	// 스킬시작애니메이션
	SpriteRenderer->ChangeAnimation(SkillName + "_START");
	CurState = SkillState::Update;
}

void ASkill::UpdateSkill(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration * 4.0f);
	SetActorLocation(NewLocation);
	FVector2D CurLocation = GetActorLocation();
	if (CurLocation == TargetLocation)
	{
		CurState = SkillState::End;
		return;
	}
}

void ASkill::EndSkill()
{
	// 타겟위치에 도착했을때 애니메이션
	SpriteRenderer->ChangeAnimation(SkillName + "_END");
	if (SpriteRenderer->IsCurAnimationEnd()) {
		IsAttackVal = false;
	}
}





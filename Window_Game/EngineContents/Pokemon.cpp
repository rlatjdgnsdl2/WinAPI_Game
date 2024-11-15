#include "PreCompile.h"
#include "Pokemon.h"

#include <EngineCore/SpriteRenderer.h>
#include "GameDataManager.h"


APokemon::APokemon()
{
}

APokemon::~APokemon()
{

}

void APokemon::SetPokemon(std::string_view _PokemonName)
{
	if (SpriteRenderer == nullptr) {
		SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	}
	SetName(_PokemonName);
	//	��������Ʈ ����
	SpriteRenderer->SetSprite(GetName() + "_Idle.png");
	SpriteRenderer->SetSpriteScale();
	//	�ִϸ��̼� ����
	AnimSet();
	//	��������
	SpriteRenderer->SetOrder(ERenderOrder::PLAYER);
	//	�⺻
	TargetPokemon = nullptr;
	CurDuration = 0.0f;
	Dir = DIR::Down;
	SkillType CurSkillType = SkillType::NormalAttack;
}

void APokemon::Idle()
{
	SpriteRenderer->ChangeAnimation("IdleAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}






#pragma once
#include <EngineCore/GameMode.h>

enum class TurnType
{
	Player_Select,
	Select_Move,
	Select_Skill,
	Player_Move,
	Player_Skill,
	AI_Select,
	AI_Move,
	AI_Skill,
};

enum class SkillType
{
	NormalAttack,
	SpecialAttack,
	UseItem
};

//	설명:
class ATurnManager : public AGameMode
{
public:
	//	constrcuter, destructer
	ATurnManager();
	virtual ~ATurnManager();

	//	delete Function
	ATurnManager(const ATurnManager& _Other) = delete;
	ATurnManager(ATurnManager&& _Other) noexcept = delete;
	ATurnManager& operator=(const ATurnManager& _Other) = delete;
	ATurnManager& operator=(ATurnManager&& _Other) noexcept = delete;

	void LevelChangeStart() override;
	void Tick(float _DeltaTime) override;

	void SetSpawnPos();


	void SetDungeon(class ADungeon* _Dungeon) 
	{
		Dungeon = _Dungeon;
	}
	void SetPatner(class APartner* _Partner)
	{
		Partner = _Partner;
	}


protected:

private:
	class APlayer* Player;
	class APartner* Partner;
	class ADungeon* Dungeon;
	TurnType CurTurnType;
	float CurDuration = 0.0f;

	int PlayerInput;
	
	//	스피드가 빠른순으로 정렬해야댐 역정렬
	std::map<float, class APokemon*> MoveMaps;
	std::map<float, class APokemon*> SkillMaps;

	//	idle
	void PlayerSelect();
	//	Select Type
	void SelectMove(int _PlayerInput);
	//	AI Check
	void AISelect();
	//	Select Play
	void PlayerMove(float _DeltaTime);

	// AI Select Play
	void AIMove(float _DeltaTime);
	void AISkill();
	



	void SelectSkill()
	{
		CurTurnType = TurnType::Select_Skill;
	}

	void Select_Skill();
	
	void PlayerSkill();
	





	//	move
	void InitPlayerMove(DIR direction, FVector2D moveVector);
	void SetPartnerDir();

	//	attack
	void InitPlayerAttack();


};

#pragma once
#pragma once
#include <EngineCore/EngineContentsCore.h>
//	����:
class PMDContentsCore :public UEngineContentsCore
{
public:
	//	constrcuter, destructer
	PMDContentsCore();
	~PMDContentsCore();
	//	delete Function
	PMDContentsCore(const PMDContentsCore& _Other) = delete;
	PMDContentsCore(PMDContentsCore&& _Other) noexcept = delete;
	PMDContentsCore& operator=(const PMDContentsCore& _Other) = delete;
	PMDContentsCore& operator=(PMDContentsCore&& _Other) noexcept = delete;

	
	
	void BeginPlay() override;
	void Tick() override;



protected:
private:
	
	void RoadResources();
	void RoadPokemon(std::string_view _PokemonName, int _Attack, int _Hurt, int _Idle, int _Shoot, int _Walk);
	void RoadSkill(std::string_view _SkillName, int size);
	void RoadDungeon(std::string_view _DungeonName);


};


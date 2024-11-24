#pragma once
#include <EngineBase/Object.h>
#include <EngineBase/EngineRandom.h>




// 설명 : 게임데이터관련 클래스
class UGameDataManager : public UObject
{
public:
	// constrcuter destructer
	virtual ~UGameDataManager();

	// delete Function
	UGameDataManager(const UGameDataManager& _Other) = delete;
	UGameDataManager(UGameDataManager&& _Other) noexcept = delete;
	UGameDataManager& operator=(const UGameDataManager& _Other) = delete;
	UGameDataManager& operator=(UGameDataManager&& _Other) noexcept = delete;

	static UGameDataManager& GetInst()
	{
		static UGameDataManager Inst = UGameDataManager();
		return Inst;
	}

	//	PokemonInfo
	void InsertAnimInfo(std::string_view _PokemonName, const AnimInfo& _PokemonAnimationInfos) {
		Animations.insert({ _PokemonName.data(),_PokemonAnimationInfos });
	}
	const AnimInfo& GetAnimInfo(std::string_view _PokemonName) const {
		return Animations.find(_PokemonName.data())->second;
	}
	//	DungeonInfo
	void InsertDungeonInfo(std::string_view _DungeonName,const DungeonInfo& _DungeonInfo) {
		Dungeons.insert({ _DungeonName.data(),_DungeonInfo });
	}
	const DungeonInfo& GetDungeonInfo(std::string_view _DungeonName) const {
		return Dungeons.find(_DungeonName.data())->second;
	}
	const int GetDungeonMaxFloor(std::string_view _DungeonName) const {
		return Dungeons.find(_DungeonName.data())->second.MaxFloor;
	}
	const int GetDungeonMaxLevel(std::string_view _DungeonName) const {
		return Dungeons.find(_DungeonName.data())->second.MaxLevel;
	}
	const size_t GetPokemonInDungeonSize(std::string_view _DungeonName) const {
		return Dungeons.find(_DungeonName.data())->second.Pokemons_In_Dongeon.size();
	}
	const std::string GetPokemonInDungeon()  {
		
		int MaxSize = static_cast<int>(Dungeons.find(SelectDungeon)->second.Pokemons_In_Dongeon.size());
		int Index = Random.RandomInt(0, MaxSize - 1);
		std::string PokemonName = Dungeons.find(SelectDungeon)->second.Pokemons_In_Dongeon[Index];
		return PokemonName;
	}
	int GetEnemyPokemonLevel() {
		int Level = Random.RandomInt(max(1, GetDungeonMaxLevel(SelectDungeon)-3), GetDungeonMaxLevel(SelectDungeon));
		return Level;
	}

	
	//	PokemonAbility
	void InsertPokemonAbility(std::string_view _PokemonName, const PokemonInfo& _PokemonAbility) {
		Pokemons.insert({ _PokemonName.data(), _PokemonAbility });
	}
	const PokemonInfo& GetPokemonAbility(std::string_view _PokemonName) const {
		return Pokemons.find(_PokemonName.data())->second;
	}
	void InsertSkillAnimCount(std::string_view _SkillName, int _SkillAnimCount) {
		SkillAnimations.insert({ _SkillName.data(),_SkillAnimCount });
	}
	int GetSkillAnimCount(std::string_view _SkillName) const {
		return SkillAnimations.find(_SkillName.data())->second;
	}

	//	PlayerData
	void InsertPlayerData(std::string_view _PlayerName, const PlayerData& _PlayerData) {
		PlayerDatas.insert({ _PlayerName.data(),_PlayerData });
	}
	const PlayerData& GetPlayerData(std::string_view _PlayerName) const {
		return PlayerDatas.find(_PlayerName.data())->second;
	}
	void SetPlayerData(std::string_view _PlayerName, int _Level) {
		PlayerDatas.find(_PlayerName.data())->second = _Level;
	}





	std::string GetSelectDungeon() const{
		return SelectDungeon;
	}
	void SetSelectDungeon(std::string_view _SelectDungeon){
		 SelectDungeon = _SelectDungeon;
	}

	std::string GetSelectPlayer() const {
		return SelectPlayer;
	}
	void SetSelectPlayer(std::string_view _SelectPlayer) {
		SelectPlayer = _SelectPlayer;
	}
	std::string GetSelectPartner() const {
		return SelectPartner;
	}
	void SetSelectPartner(std::string_view _SelectPartner) {
		SelectPartner = _SelectPartner;
	}

	
protected:

private:
	UEngineRandom Random;
	UGameDataManager();
	std::string SelectPlayer;
	std::string SelectPartner;
	std::string SelectDungeon = "BeachCave";
	std::map<std::string, AnimInfo > Animations;
	std::map<std::string, int> SkillAnimations;
	std::map<std::string, PokemonInfo > Pokemons;
	std::map<std::string, DungeonInfo> Dungeons;

	std::map<std::string, PlayerData> PlayerDatas;
	
};


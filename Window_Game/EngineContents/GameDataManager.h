#pragma once

// 설명 : 게임데이터관련 클래스
class UGameDataManager
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

	//	PokemonAbility
	void InsertPokemonAbility(std::string_view _PokemonName, const PokemonInfo& _PokemonAbility) {
		Pokemons.insert({ _PokemonName.data(), _PokemonAbility });
	}
	PokemonInfo GetPokemonAbility(std::string_view _PokemonName) const {
		return Pokemons.find(_PokemonName.data())->second;
	}


	// PlayerAbility
	PokemonInfo GetPlayerAbility(std::string_view _PlayerName) {
		return PlayerAbilities.find(_PlayerName.data())->second;
	}

	void InsertPlayerAbility(std::string_view _PlayerName, PokemonInfo _PokemonAbility) {
		PlayerAbilities.insert({ _PlayerName.data(), _PokemonAbility });
	}




	std::string GetSelectDungeon() const{
		return SelectDungeon;
	}
	void SetSelectDungeon(std::string_view _SelectDungeon){
		 SelectDungeon = _SelectDungeon;
	}

	
protected:

private:
	UGameDataManager();
	std::string SelectDungeon = "BeachCave";
	std::map<std::string, AnimInfo > Animations;
	std::map<std::string, PokemonInfo > Pokemons;
	std::map<std::string, DungeonInfo> Dungeons;

	
	std::map<std::string, PokemonInfo> PlayerAbilities;

};


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
	void InsertPokemonAnimationInfo(std::string_view _PokemonName, PokemonAnimaionInfo _PokemonAnimationInfos) {
		PokemonAnimationInfos.insert({ _PokemonName.data(),_PokemonAnimationInfos });
	}
	const PokemonAnimaionInfo GetPokemonAnimationInfo(std::string_view _PokemonName) const {
		return PokemonAnimationInfos.find(_PokemonName.data())->second;
	}

	//	PokemonData
	void InsertPokemonAbility(std::string_view _PokemonName, PokemonAbility _PokemonAbility) {
		PokemonAbilities.insert({ _PokemonName.data(), _PokemonAbility });
	}
	const PokemonAbility GetPokemonAbility(std::string_view _PokemonName) const {
		return PokemonAbilities.find(_PokemonName.data())->second;
	}

	//	DungeonInfo
	void InsertDungeonInfo(std::string_view _DungeonName, DungeonInfo _DungeonInfo) {
		DungeonInfos.insert({ _DungeonName.data(),_DungeonInfo });
	}
	DungeonInfo GetDungeonInfo(std::string_view _DungeonName) const {
		return DungeonInfos.find(_DungeonName.data())->second;
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
	std::map<std::string, PokemonAnimaionInfo > PokemonAnimationInfos;
	std::map<std::string, PokemonAbility > PokemonAbilities;
	std::map<std::string, DungeonInfo> DungeonInfos;

	

};


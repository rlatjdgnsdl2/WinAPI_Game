#pragma once

// Ό³Έν :
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
	void InsertPokemonInfo(std::string_view _PokemonName, PokemonAnimaionInfo _PokemonInfo) {
		PokemonInfos.insert({ _PokemonName.data(),_PokemonInfo });
	}
	const PokemonAnimaionInfo GetPokemonInfo(std::string_view _PokemonName) const {
		return PokemonInfos.find(_PokemonName.data())->second;
	}

	//	PokemonData
	void InsertPokemonData(std::string_view _PokemonName, PokemonStat _PokemonData) {
		PokemonDatas.insert({ _PokemonName.data(),_PokemonData });
	}
	const PokemonStat GetPokemonData(std::string_view _PokemonName) const {
		return PokemonDatas.find(_PokemonName.data())->second;
	}

	//	DungeonInfo
	void InsertDungeonInfo(std::string_view _DungeonName, DungeonInfo _DungeonInfo) {
		DungeonInfos.insert({ _DungeonName.data(),_DungeonInfo });
	}
	DungeonInfo GetDungeonInfo(std::string_view _DungeonName) const {
		return DungeonInfos.find(_DungeonName.data())->second;
	}






	std::string GetSelectDungeon() const
	{
		return SelectDungeon;
	}
	void SetSelectDungeon(std::string_view _SelectDungeon)
	{
		 SelectDungeon = _SelectDungeon;
	}

	

protected:

private:
	UGameDataManager();
	std::string SelectDungeon = "BeachCave";
	std::map<std::string, PokemonAnimaionInfo > PokemonInfos;
	std::map<std::string, PokemonStat > PokemonDatas;
	std::map<std::string, DungeonInfo> DungeonInfos;

	

};


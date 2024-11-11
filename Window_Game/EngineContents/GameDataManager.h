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
	void InsertPokemonInfo(std::string_view _PokemonName, PokemonInfo _PokemonInfo) {
		PokemonInfos.insert({ _PokemonName.data(),_PokemonInfo });
	}
	const PokemonInfo GetPokemonInfo(std::string_view _PokemonName) const {
		return PokemonInfos.find(_PokemonName.data())->second;
	}
	//	PokemonData
	void InsertPokemonData(std::string_view _PokemonName, PokemonData _PokemonData) {
		PokemonDatas.insert({ _PokemonName.data(),_PokemonData });
	}
	const PokemonData GetPokemonData(std::string_view _PokemonName) const {
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
	std::map<std::string, PokemonInfo > PokemonInfos;
	std::map<std::string, PokemonData > PokemonDatas;
	std::map<std::string, DungeonInfo> DungeonInfos;
	std::string SelectDungeon;

	

};


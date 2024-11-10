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
	void InsertPokemonInfo(std::string_view _PokemonName, PokemonInfo _PokemonInfo) {
		PokemonInfos.insert({ _PokemonName.data(),_PokemonInfo });
	}
	PokemonInfo GetPokemonInfo(std::string_view _PokemonName) {
		return PokemonInfos.find(_PokemonName.data())->second;
	}

	PokemonData GetPokemonData(std::string_view _PokemonName) {
		return PokemonDatas.find(_PokemonName.data())->second;
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
	std::string SelectDungeon;

	

};


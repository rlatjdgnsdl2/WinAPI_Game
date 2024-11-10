#pragma once

// Ό³Έν :
class GameDataManager
{
public:
	// constrcuter destructer
	virtual ~GameDataManager();

	// delete Function
	GameDataManager(const GameDataManager& _Other) = delete;
	GameDataManager(GameDataManager&& _Other) noexcept = delete;
	GameDataManager& operator=(const GameDataManager& _Other) = delete;
	GameDataManager& operator=(GameDataManager&& _Other) noexcept = delete;

	static GameDataManager& GetInst()
	{
		static GameDataManager Inst = GameDataManager();
		return Inst;
	}
	Pokemon_Ability& GetPokemonAbility() {
		return PlayerAbility;
	}

protected:

private:
	GameDataManager();
	Pokemon_Ability PlayerAbility = {50,};

};


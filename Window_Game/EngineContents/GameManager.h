#pragma once

// Ό³Έν :
class GameManager
{
public:
	


	virtual ~GameManager();

	// delete Function
	GameManager(const GameManager& _Other) = delete;
	GameManager(GameManager&& _Other) noexcept = delete;
	GameManager& operator=(const GameManager& _Other) = delete;
	GameManager& operator=(GameManager&& _Other) noexcept = delete;

	static GameManager& GetInst()
	{
		static GameManager Inst;
		return Inst;
	}
	


protected:

private:
	GameManager();
	std::map<std::string, PokemonAbility> BasicAbilities;
	PokemonAbility PlayerAbility;

	
	

};


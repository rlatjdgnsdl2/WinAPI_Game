#pragma once
#include <EngineCore/ActorComponent.h>

//	Ό³Έν:
class UPokemonUtility : public UActorComponent 
{
public:
	class Pokem {
	public:
		PokemonType PokemonType;
		unsigned int Level;
		unsigned int Hp;
		unsigned int Attack;
		unsigned int Defense;
		unsigned int Special_Attack;
		unsigned int Special_Defense;
		unsigned int Speed;

		void LevelUp() {
			Level++;
		}
	};



	//	constrcuter, destructer
	UPokemonUtility();
	virtual ~UPokemonUtility();

	//	delete Function
	UPokemonUtility(const UPokemonUtility& _Other) = delete;
	UPokemonUtility(UPokemonUtility&& _Other) noexcept = delete;
	UPokemonUtility& operator=(const UPokemonUtility& _Other) = delete;
	UPokemonUtility& operator=(UPokemonUtility&& _Other) noexcept = delete;

	


protected:

private:
	PokemonAbility PokemonAbility;

};


#pragma once
#include <string>
#include "Dungeon.h"

#include <EngineCore/GameMode.h>
//	Ό³Έν:
class ADungeonGameMode : public AGameMode
{
public:
	//	constrcuter, destructer
	ADungeonGameMode();
	virtual ~ADungeonGameMode();

	//	delete Function
	ADungeonGameMode(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode(ADungeonGameMode&& _Other) noexcept = delete;
	ADungeonGameMode& operator=(const ADungeonGameMode& _Other) = delete;
	ADungeonGameMode& operator=(ADungeonGameMode&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime)override;
	void LevelChangeStart() override;
	void GenerateDungeon(std::string_view _DungeonName, std::string_view _GeneratorName);

	static void SetCurDungeonName(std::string_view _DungeonName);
	static void SetCurGeneratorName(std::string_view _GeneratorName);

protected:

private:
	static std::string CurGeneratorName;
	static std::string CurDungeonName;
	ADungeon* Dungeon = nullptr;

	std::map<std::string, class UDungeonGenerator* >  GeneratorMaps;
};


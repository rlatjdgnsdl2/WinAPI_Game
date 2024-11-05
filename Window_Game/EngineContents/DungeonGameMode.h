#pragma once
#include <string>


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
	


	void GenerateDungeon();
	void SetAllWall();
	void SetRandomHallWay();
	void SetRandomSizeRoom();
	void SetborderWall();
	void CheckTile();


	static void SetCurDungeonName(std::string_view _DungeonName);
	
	static std::string GetCurDungeonName() 
	{
		return CurDungeonName;
	};
	

protected:

private:
	class ATileMap* Dungeon;
	static inline std::string CurDungeonName = "BeachCave";
	static std::vector<std::vector<FVector2D>> AllGrounds;
	
	


};


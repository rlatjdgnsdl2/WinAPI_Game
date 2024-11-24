#include "PreCompile.h"
#include "PMDContentsCore.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include "GameDataManager.h"

#include "TitleGameMode.h"
#include "CharacterSelectGameMode.h"
#include "DungeonSelectGameMode.h"
#include "DungeonGameMode.h"

#include "TempPlayer.h"
#include "CharacterSelect.h"
#include "DungeonSelect.h"
#include "Player.h"



int ScaleRate = 3;

PMDContentsCore::PMDContentsCore() {}
PMDContentsCore::~PMDContentsCore() {}

void PMDContentsCore::BeginPlay()
{
	//	리소스로드
	RoadResources();

	//	게임타이틀 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Pokemon Mystery Dungeon : Explorers of Sky");
	//	윈도우 크기 설정
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 256 * ScaleRate, 192 * ScaleRate });
	//	Level생성
	//	타이틀레벨
	UEngineAPICore::GetCore()->CreateLevel<ATitleGameMode, ATempPlayer>("TitleLevel");
	//	캐릭터 선택레벨
	UEngineAPICore::GetCore()->CreateLevel<ACharacterSelectGameMode, ACharacterSelect>("CharacterSelectLevel");
	//	던전 선택레벨
	UEngineAPICore::GetCore()->CreateLevel<ADungeonSelectGameMode, ADungeonSelectActor>("DungeonSelectLevel");
	//	던전레벨
	UEngineAPICore::GetCore()->CreateLevel<ADungeonGameMode, APlayer>("DungeonLevel");


	//	처음 레벨 입장
	UEngineAPICore::GetCore()->OpenLevel("TitleLevel");
	//UEngineAPICore::GetCore()->OpenLevel("CharacterSelectLevel");
	//UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");
	//UEngineAPICore::GetCore()->OpenLevel("DungeonLevel");

}
void PMDContentsCore::Tick()
{
}



void PMDContentsCore::RoadResources()
{
	//	리소스 로드
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UImageManager::GetInst().Load(FilePath);
		}
	}
	// 사운드 로드
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Sound");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}
	RoadSkill("Fire_Bomb", 9);
	RoadSkill("Lightning_Bomb", 15);
	RoadSkill("Water_Bomb", 8);

	//	Font
	UImageManager::GetInst().CuttingSprite("Yellow_Text.png", 26, 4);
	UImageManager::GetInst().CuttingSprite("Blue_Text.png", 26, 4);
	UImageManager::GetInst().CuttingSprite("Green_Text.png", 26, 4);
	UImageManager::GetInst().CuttingSprite("White_Text.png", 26, 4);

	//	Title
	UImageManager::GetInst().CuttingSprite("Title_anim.png", 5, 3);

	//	player
	RoadPokemon("Bulbasaur", 11, 2, 3, 6, 6);
	UGameDataManager::GetInst().InsertPokemonAbility("Bulbasaur", PokemonInfo(22, 3, 4, 2, 3));
	RoadPokemon("Charmander", 11, 2, 4, 9, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Charmander", PokemonInfo(22, 3, 4, 3, 2));
	RoadPokemon("Chikorita", 10, 2, 6, 11, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Chikorita", PokemonInfo(30, 4, 4, 3, 3 ));
	RoadPokemon("Chimchar", 10, 2, 5, 12, 7);
	UGameDataManager::GetInst().InsertPokemonAbility("Chimchar", PokemonInfo(22, 4, 4, 3, 5));
	RoadPokemon("Cyndaquil", 10, 2, 2, 10, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Cyndaquil", PokemonInfo(25, 4, 4, 2, 2));
	RoadPokemon("Eevee", 11, 2, 2,8, 7);
	UGameDataManager::GetInst().InsertPokemonAbility("Eevee", PokemonInfo(25, 4, 3, 5, 5));
	RoadPokemon("Meowth", 10, 2, 4, 9, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Meowth", PokemonInfo(20, 2, 4, 4, 4));
	RoadPokemon("Mudkip", 10, 2, 7, 11, 6);
	UGameDataManager::GetInst().InsertPokemonAbility("Mudkip", PokemonInfo(26, 4, 4, 3, 3));
	RoadPokemon("Munchlax", 13, 2, 4, 12, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Munchlax", PokemonInfo(30, 5, 5, 3, 3));
	RoadPokemon("Phanpy", 13, 2, 4, 12, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Phanpy", PokemonInfo(22, 2, 3, 2, 3));
	RoadPokemon("Pikachu", 10, 2, 6, 11, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Pikachu", PokemonInfo(20, 3, 3, 3, 3));
	RoadPokemon("Piplup", 14, 2, 6, 12, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Piplup", PokemonInfo(23, 3, 4, 5, 4));
	RoadPokemon("Riolu", 15, 2, 4, 9, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Riolu", PokemonInfo(20, 3, 4, 2, 2));
	RoadPokemon("Shinx", 15, 2, 7, 12, 7);
	UGameDataManager::GetInst().InsertPokemonAbility("Shinx", PokemonInfo(21, 2, 2, 2, 2));
	RoadPokemon("Skitty", 11, 2, 4, 11, 7);
	UGameDataManager::GetInst().InsertPokemonAbility("Skitty", PokemonInfo(30, 4, 4, 3, 3));
	RoadPokemon("Squirtle", 10, 2, 8, 11, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Squirtle", PokemonInfo(30, 3, 3, 3, 3));
	RoadPokemon("Torchic", 11, 2, 5, 13, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Torchic", PokemonInfo(25, 4, 4, 3, 3));
	RoadPokemon("Totodile", 10, 2, 7, 14, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Totodile", PokemonInfo(25, 4, 4, 3, 3));
	RoadPokemon("Treecko", 10, 2, 3, 9, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Treecko", PokemonInfo(25, 3, 4, 3, 3));
	RoadPokemon("Turtwig", 11, 2, 4, 12, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Turtwig", PokemonInfo(20, 5, 5, 3, 3));
	RoadPokemon("Vulpix", 11, 2, 4, 13, 5);
	UGameDataManager::GetInst().InsertPokemonAbility("Vulpix", PokemonInfo(24, 4, 4, 4, 4));



	//	Dungeon
	//	BeachCave
	RoadDungeon("BeachCave");
	RoadPokemon("Kabuto", 11, 2, 3, 11, 4);
	RoadPokemon("Shellos", 13, 2, 3, 12, 6);
	RoadPokemon("Shellder", 10, 2, 4, 13, 6);
	RoadPokemon("Corsola", 10, 2, 3, 11, 4);
	UGameDataManager::GetInst().InsertPokemonAbility("Kabuto", PokemonInfo(20, 8, 6, 5, 5));
	UGameDataManager::GetInst().InsertPokemonAbility("Shellos", PokemonInfo(9, 4, 5, 4, 4)); 
	UGameDataManager::GetInst().InsertPokemonAbility("Shellder", PokemonInfo(10, 4, 5, 4, 5));
	UGameDataManager::GetInst().InsertPokemonAbility("Corsola", PokemonInfo(11, 4, 4, 3, 3));
	UGameDataManager::GetInst().InsertDungeonInfo("BeachCave", DungeonInfo(60, 40, 5,5, { "Kabuto","Shellos","Shellder","Corsola" }));

	//	AmpPlains
	RoadDungeon("AmpPlains");
	UGameDataManager::GetInst().InsertDungeonInfo("AmpPlains", DungeonInfo(60, 40, 5,5, { "Kabuto","Shellos","Shellder","Corsola" }));

	//	DeepDarkCrater
	RoadDungeon("DeepDarkCrater");
	UGameDataManager::GetInst().InsertDungeonInfo("DeepDarkCrater", DungeonInfo(60, 40, 5,5, { "Kabuto","Shellos","Shellder","Corsola" }));

	//	SurroundedSea
	RoadDungeon("SurroundedSea");
	UGameDataManager::GetInst().InsertDungeonInfo("SurroundedSea", DungeonInfo(60, 40, 5,5, { "Kabuto","Shellos","Shellder","Corsola" }));


	//	Item
	UImageManager::GetInst().CuttingSprite("Item.png", 3, 1);



}

void PMDContentsCore::RoadPokemon(std::string_view _PokemonName, int _Attack, int _Hurt, int _Idle, int _Shoot, int _Walk)
{
	UImageManager::GetInst().CuttingSprite(std::format("{}_Attack.png", _PokemonName), _Attack, 8);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Hurt.png", _PokemonName), _Hurt, 8);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Idle.png", _PokemonName), _Idle, 8);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Shoot.png", _PokemonName), _Shoot, 8);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Walk.png", _PokemonName), _Walk, 8);
	UGameDataManager::GetInst().InsertAnimInfo(_PokemonName, AnimInfo({ _Attack,_Hurt,_Idle,_Shoot,_Walk }));
}

void PMDContentsCore::RoadSkill(std::string_view _SkillName, int size)
{
	UEngineDirectory Skill;
	Skill.MoveParentToDirectory("Resources//Image//Skill");
	Skill.Append(_SkillName);
	UImageManager::GetInst().LoadFolder(Skill.GetPathToString());
	UGameDataManager::GetInst().InsertSkillAnimCount(_SkillName, size);
}

void PMDContentsCore::RoadDungeon(std::string_view _DungeonName)
{
	UImageManager::GetInst().CuttingSprite(std::format("{}_Ground.png", _DungeonName), 5, 10);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Wall.png", _DungeonName), 5, 10);
	UImageManager::GetInst().CuttingSprite(std::format("{}_Water.png", _DungeonName), 5, 10);
}



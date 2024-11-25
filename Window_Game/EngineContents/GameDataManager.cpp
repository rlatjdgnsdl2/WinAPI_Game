#include "PreCompile.h"
#include "GameDataManager.h"

UGameDataManager::UGameDataManager()
{
	ItemInfo.insert({"Apple","fill Hungry"});
	ItemInfo.insert({ "Oran","fill HP" });
	ItemInfo.insert({ "SkillDisk","learn a skill" });
	Items = { "Apple","Oran","SkillDisk" };
	SkillInfo.insert({ "Fire_Bomb","Fire_Bomb in front of you" });
	SkillInfo.insert({ "Lightning_Bomb","Lightning_Bomb in front of you" });
	SkillInfo.insert({ "Water_Bomb","Water_Bomb in front of you" });
}


UGameDataManager::~UGameDataManager()
{
}


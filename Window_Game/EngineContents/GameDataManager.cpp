#include "PreCompile.h"
#include "GameDataManager.h"

UGameDataManager::UGameDataManager()
{
	ItemInfo.insert({"Apple","fill Hungry"});
	ItemInfo.insert({ "Oran","fill HP" });
	ItemInfo.insert({ "SkillDisk","learn a skill" });
	Items = { "Apple","Oran","SkillDisk" };
}


UGameDataManager::~UGameDataManager()
{
}


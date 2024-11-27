#pragma once
#include "BoxUI.h"

//	Ό³Έν:
class AInventory :public ABoxUI
{
public:
	//	constrcuter, destructer
	AInventory();
	AInventory(FTransform _BoxTrans);
	virtual ~AInventory();

	//	delete Function
	AInventory(const AInventory& _Other) = delete;
	AInventory(AInventory&& _Other) noexcept = delete;
	AInventory& operator=(const AInventory& _Other) = delete;
	AInventory& operator=(AInventory&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void MovePage(int _dir);
	virtual void ShowUI(float _DeltaTime = 0.0f)override;

	void SetItemList(const std::list<std::string>& _ItemList) {
		ItemList = _ItemList;
	}


protected:

private:
	std::list<std::string> ItemList;
	std::list<std::string>::iterator ItemListIter;
	int CurPage = 0;
	int MaxPage = 3;

};


#include "PreCompile.h"
#include "Inventory.h"
#include "Box.h"
#include "Text.h"
#include "GameDataManager.h"


AInventory::AInventory()
{

}

AInventory::AInventory(FTransform _BoxTrans) :ABoxUI(_BoxTrans)
{
	
}

AInventory::~AInventory()
{

}

void AInventory::BeginPlay()
{
	Super::BeginPlay();
	Box = GetWorld()->SpawnActor<ABox>();
	Box->SetBoxSize(BoxTrans.Scale);
	Box->SetActive(false);
	SetTextsCount(8);
	ItemListIter = ItemList.begin();
}

void AInventory::MovePage(int _dir)
{
	SetItemList(UGameDataManager::GetInst().GetPlayerInventory());
	int Size = ItemList.size();
	ItemListIter = ItemList.begin();
	std::list<std::string>::iterator EndIter = ItemList.end();
	if (ItemListIter == EndIter)
	{
		return;
	}
	if (_dir == 1) {
		
		CurPage++;
		CurPage == MaxPage ? CurPage = 0 : CurPage;
		for (int i = 0; i < TextsCount * CurPage; i++)
		{
			if (ItemListIter == EndIter)
			{
				ItemListIter = ItemList.begin();
				CurPage = 0;
				break;
			}
			ItemListIter++;
		}
	}
	else if (_dir == -1) {
		CurPage--;
		CurPage < 0 ? CurPage = MaxPage : CurPage;
		for (int i = 0; i < TextsCount * CurPage; i++)
		{
			if (ItemListIter == EndIter)
			{
				ItemListIter = ItemList.begin();
				CurPage = 0;
				break;
			}
			ItemListIter++;
		}
	}
}

void AInventory::ShowUI(float _DeltaTime)
{
	Box->SetActive(true);
	SetItemList(UGameDataManager::GetInst().GetPlayerInventory());
	ItemListIter = ItemList.begin();
	std::list<std::string>::iterator EndIter = ItemList.end();
	for (int i = 0; i < TextsCount * CurPage; i++)
	{
		if (ItemListIter == EndIter)
		{
			ItemListIter = ItemList.begin();
			break;
		}
		ItemListIter++;
	}
	
	FVector2D Location = BoxTrans.Location;
	Box->SetActorLocation(Location);
	for (int i = 0; i < TextsCount; i++)
	{
		if (ItemListIter == EndIter) {
			SetString("", Color::White, i);
			continue;
		}
		else {
			SetString(*ItemListIter, Color::White, i);
		}
		ItemListIter++;
	}
	for (AText* CurText : Texts) {
		Location.Y += 30.0f;
		CurText->SetActive(true);
		CurText->ShowText(_DeltaTime);
		CurText->SetActorLocation(Location + FVector2D(40, 0));
	}
}



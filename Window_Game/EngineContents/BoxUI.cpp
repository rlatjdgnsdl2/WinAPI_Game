#include "PreCompile.h"
#include "BoxUI.h"

#include "Box.h"
#include "Text.h"


ABoxUI::ABoxUI()
{

}

ABoxUI::ABoxUI(FTransform _BoxTrans) :BoxTrans(_BoxTrans)
{
}

ABoxUI::~ABoxUI()
{

}

void ABoxUI::BeginPlay()
{
	Super::BeginPlay();
	Box = GetWorld()->SpawnActor<ABox>();
	Box->SetBoxSize(BoxTrans.Scale);
	Box->SetActive(false);
}

void ABoxUI::CreateString(std::string_view _StringValue, std::string_view _color, FVector2D _TextSize, float _Time)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValue, _color, _TextSize, _Time);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::SetString(int Index, std::string_view _StringValue)
{
	Texts[Index]->SetString(_StringValue);
}

void ABoxUI::SetStringColor(int Index, std::string_view _color)
{
	Texts[Index]->SetColor(_color);
}

void ABoxUI::SetStringColor(AText* Text, std::string_view _color)
{
	Text->SetColor(_color);
}

void ABoxUI::SetStringColor(int Index, int _TextStartIndex, int _TextEndIndex, std::string_view _color)
{
	Texts[Index]->SetColor(_TextStartIndex, _TextEndIndex, _color);
}

void ABoxUI::ShowUI(float _DeltaTime) {
	Box->SetActive(true);
	FVector2D Location = BoxTrans.Location;
	Box->SetActorLocation(Location);
	for (AText* Text : Texts)
	{
		Location.Y += 30.0f;
		Text->SetActive(true);
		Text->ShowText(_DeltaTime);
		Text->SetActorLocation(Location + FVector2D(40, 0));
	}
}

void ABoxUI::HideUI()
{
	Box->SetActive(false);
	for (AText* Text : Texts)
	{
		Text->SetActive(false);
	}
}


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

void ABoxUI::SetTextsCount(int _Count)
{
	for (int i = 0; i < _Count; i++)
	{
		CreateString("");
	}
}

void ABoxUI::CreateString(std::string_view _StringValue, Color _Color, float _Time)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValue, _Color, _Time);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::CreateString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, float _Time)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValues, _colors, _Time);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::SetString(std::string_view _StringValue, Color _Color, int Index, float _Time)
{
	if (Index < Texts.size()) {
		Texts[Index]->SetString(_StringValue, _Color, _Time);
	}
}

void ABoxUI::SetString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, int Index, float _Time)
{
	if (Index < Texts.size()) {
		Texts[Index]->SetString(_StringValues, _colors, _Time);
	}
}



void ABoxUI::SetStringColor(AText* Text, Color _Color)
{
	Text->SetColor(_Color);
}



void ABoxUI::SetStringColor(int Index, Color _Color)
{
	if (Index < Texts.size()) {

		Texts[Index]->SetColor(_Color);
	}
}



void ABoxUI::ShowUI(float _DeltaTime) {
	Box->SetActive(true);
	FVector2D Location = BoxTrans.Location;
	Box->SetActorLocation(Location);
	for (AText* Text : Texts) {
		Location.Y += 30.0f;
		Text->SetActive(true);
		Text->ShowText(_DeltaTime);
		Text->SetActorLocation(Location + FVector2D(40, 0));
	}
}

void ABoxUI::HideUI() {
	Box->SetActive(false);
	for (AText* Text : Texts) {
		Text->SetActive(false);
	}
}


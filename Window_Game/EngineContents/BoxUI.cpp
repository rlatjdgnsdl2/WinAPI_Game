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

void ABoxUI::CreateString(std::string_view _StringValue, TextColor _Color, FVector2D _TextSize, float _Time)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValue, _Color, _TextSize, _Time);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::CreateString(const std::vector<std::string>& _StringValues, const std::vector<TextColor>& _colors, const FVector2D& _TextSize, float _Time)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValues, _colors, _TextSize, _Time);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::SetString(std::string_view _StringValue, int Index, TextColor _Color, FVector2D _TextSize, float _Time)
{
	Texts[Index]->SetString(_StringValue, _Color, _TextSize, _Time);
}

void ABoxUI::SetString(const std::vector<std::string>& _StringValues, const std::vector<TextColor>& _colors, int Index, const FVector2D& _TextSize, float _Time)
{
	Texts[Index]->SetString(_StringValues, _colors, _TextSize, _Time);
}



void ABoxUI::SetStringColor(AText* Text, TextColor _Color)
{
	Text->SetColor(_Color);
}



void ABoxUI::SetStringColor(int Index, TextColor _Color)
{
	Texts[Index]->SetColor(_Color);
}


void ABoxUI::NewMessage(const std::string_view _Message)
{
	if (Texts.size() < 3) {
		CreateString(_Message);
	}

	else if (Texts.size() >= 3) {
		SetString(Texts[1]->GetString(), 0);
		SetString(Texts[2]->GetString(), 1);
		SetString(_Message, 2);
	}
}

void ABoxUI::NewMessage(const std::vector<std::string>& _Message, const std::vector<TextColor>& _colors)
{
	if (Texts.size() < 3) {
		CreateString(_Message, _colors);
	}
	else if (Texts.size() >= 3) {
		
		Texts[0]->SetString(Texts[1]);
		Texts[1]->SetString(Texts[2]);
		Texts[2]->SetString(_Message, _colors);
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


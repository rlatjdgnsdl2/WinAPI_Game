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

void ABoxUI::CreateString(std::string_view _StringValue, Color _Color, float _Time, FVector2D _TextSize)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValue, _Color, _Time, _TextSize);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::CreateString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, float _Time, const FVector2D& _TextSize)
{
	AText* NewText = GetWorld()->SpawnActor<AText>();
	NewText->SetString(_StringValues, _colors, _Time, _TextSize);
	NewText->SetActive(false);
	Texts.push_back(NewText);
}

void ABoxUI::SetString(std::string_view _StringValue, Color _Color, int Index, float _Time, FVector2D _TextSize)
{
	Texts[Index]->SetString(_StringValue, _Color, _Time, _TextSize);
}

void ABoxUI::SetString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, int Index, float _Time, const FVector2D& _TextSize)
{
	Texts[Index]->SetString(_StringValues, _colors, _Time, _TextSize);
}



void ABoxUI::SetStringColor(AText* Text, Color _Color)
{
	Text->SetColor(_Color);
}



void ABoxUI::SetStringColor(int Index, Color _Color)
{
	Texts[Index]->SetColor(_Color);
}


void ABoxUI::NewMessage(const std::string_view _Message, Color _Color, float _Time)
{
	if (Texts.size() < 3) {
		CreateString(_Message);
	}

	else if (Texts.size() >= 3) {
		SetString(Texts[1]->GetString(), _Color,0);
		SetString(Texts[2]->GetString(), _Color,1);
		SetString(_Message,_Color, 2, _Time);
	}
}

void ABoxUI::NewMessage(const std::vector<std::string>& _Message, const std::vector<Color>& _colors, float _Time)
{
	if (Texts.size() < 3) {
		CreateString(_Message, _colors);
	}
	else if (Texts.size() >= 3) {
		
		Texts[0]->SetString(Texts[1]);
		Texts[1]->SetString(Texts[2]);
		Texts[2]->SetString(_Message, _colors,_Time);
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


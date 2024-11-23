#include "PreCompile.h"
#include "Text.h"
#include <EngineCore/SpriteRenderer.h>


AText::AText()
{

}

AText::~AText()
{

}

void AText::Reserve(int _Count)
{
	// 기존에 있던 글자 제거
	for (size_t i = 0; i < TextRenderer.size(); i++)
	{
		TextRenderer[i]->SetActive(false);
	}
	TextRenderer.resize(_Count);
	for (size_t i = 0; i < TextRenderer.size(); i++)
	{
		USpriteRenderer* NewText = CreateDefaultSubObject<USpriteRenderer>();
		NewText->SetOrder(ERenderOrder::UI_Text);
		NewText->SetCameraEffect(false);
		TextRenderer[i] = NewText;
	}
}


void AText::ShowText(float _DeltaTime)
{
	int Size = static_cast<int>(StringValue.size());
	for (size_t i = 0; i < Size; i++) {
		TextRenderer[i]->SetActive(false);
	}

	if (Time == 0.0f) {
		CurCount = Size;
	}

	CurTime += _DeltaTime;

	if (CurTime > Time) {
		++CurCount;
		CurTime = 0.0f;
	}
	if (CurCount >= Size) {
		CurCount = Size;
	}

	for (size_t i = 0; i < CurCount; i++) {
		TextRenderer[i]->SetActive(true);
	}
}

void AText::SetString(std::string_view _StringValue, TextColor _color, const FVector2D& _TextSize, float _Time)
{
	TextSize = _TextSize;
	Time = _Time;
	StringValue = _StringValue;
	std::string Color;
	switch (_color)
	{
	case TextColor::White:
		Color = "White";
		break;
	case TextColor::Blue:
		Color = "Blue";
		break;
	case TextColor::Green:
		Color = "Green";
		break;
	case TextColor::Yellow:
		Color = "Yellow";
		break;
	}
	Reserve(static_cast<int>(StringValue.size()));
	CurCount = 0;
	for (size_t i = 0; i < StringValue.size(); i++)
	{
		char c = StringValue[i];
		int TextIndex = CharToTextIndex(c);
		TextRenderer[i]->SetSprite(Color + "_Text.png", TextIndex);
		TextRenderer[i]->SetSpriteScale();
		TextRenderer[i]->SetComponentLocation(FVector2D({ TextSize.X * i,TextSize.Y }));
		TextRenderer[i]->SetActive(false);
	}
}

void AText::SetString(const AText* _Text)
{
	StringValue = _Text->GetString();
	TextSize = _Text->TextSize;
	Time = _Text->Time;
	Reserve(static_cast<int>(StringValue.size()));

	CurCount = 0;
	for (size_t i = 0; i < StringValue.size(); i++)
	{
		char c = StringValue[i];
		int TextIndex = CharToTextIndex(c);
		TextRenderer[i]->SetSprite(_Text->TextRenderer[i]->GetCurSpriteName(), TextIndex);
		TextRenderer[i]->SetSpriteScale();
		TextRenderer[i]->SetComponentLocation(FVector2D({ TextSize.X * i,TextSize.Y }));
		TextRenderer[i]->SetActive(false);
	}
}

void AText::SetString(const std::vector<std::string>& _StringValues, const std::vector<TextColor>& _colors, const FVector2D& _TextSize, float _Time)
{
	if (_StringValues.size() != _colors.size())
	{
		return;
	}
	TextSize = _TextSize;
	Time = _Time;
	StringValue.clear(); // 기존 문자열 초기화
	for (const std::string& Str : _StringValues)
	{
		StringValue += Str;
	}
	Reserve(static_cast<int>(StringValue.size()));
	CurCount = 0;
	int Index = 0;
	for (size_t i = 0; i < _StringValues.size(); i++)
	{
		const std::string& _StringVal = _StringValues[i];
		std::string Color = UContentsMath::Color_To_String(_colors[i]);
		for (size_t j = 0; j < _StringVal.size(); j++)
		{
			char c = _StringVal[j];
			int TextIndex = CharToTextIndex(c);
			TextRenderer[Index]->SetSprite(Color + "_Text.png", TextIndex);
			TextRenderer[Index]->SetSpriteScale();
			TextRenderer[Index]->SetComponentLocation(FVector2D({ TextSize.X * Index, TextSize.Y }));
			TextRenderer[Index]->SetActive(false);
			Index++;
		}
	}
}

void AText::SetColor(TextColor _Color)
{
	std::string Color = UContentsMath::Color_To_String(_Color);
	for (size_t i = 0; i < StringValue.size(); i++)
	{
		char c = StringValue[i];
		int TextIndex = CharToTextIndex(c);
		TextRenderer[i]->SetSprite(Color + "_Text.png", TextIndex);
	}
}

int AText::CharToTextIndex(char _C)
{
	if (_C >= 'a' && _C <= 'z') {
		return (_C - 'a');
	}
	if (_C >= 'A' && _C <= 'Z') {
		return(_C - 'A' + 26);
	}
	if (_C >= '1' && _C <= '9') {
		return (_C - '1' + 52);
	}
	if (_C == '0') {
		return 61;
	}
	switch (_C) {
	case '!': return static_cast<int>(Text_Index::Exclamation);
	case '?': return static_cast<int>(Text_Index::Question);
	case',': return static_cast<int>(Text_Index::Comma);
	case '+': return static_cast<int>(Text_Index::Plus);
	case '-': return static_cast<int>(Text_Index::Minus);
	case '.': return static_cast<int>(Text_Index::Dot);
	default: return static_cast<int>(Text_Index::MAX);
	}
}



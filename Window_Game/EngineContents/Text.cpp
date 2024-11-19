#include "PreCompile.h"
#include "Text.h"

#include <EngineCore/SpriteRenderer.h>


AText::AText()
{
	TextRenderer.resize(300);
	for (size_t i = 0; i < TextRenderer.size(); i++)
	{
		USpriteRenderer* NewText = CreateDefaultSubObject<USpriteRenderer>();
		NewText->SetSprite("Text_White.png", static_cast<int>(Text_Index::MAX)+1);
		NewText->SetSpriteScale();
		NewText->SetComponentLocation(FVector2D({ TextSize.X * i,0.0f }));
		NewText->SetOrder(ERenderOrder::UI_Text);
		NewText->SetCameraEffect(false);
		TextRenderer[i] = NewText;
	}
	int a = 0;
}

AText::~AText()
{

}


void AText::SetString(std::string_view _StringValue)
{
	StringValue = _StringValue;
	const char* C_String = StringValue.c_str();
	for (size_t i = 0; i < StringValue.size(); i++)
	{
		char c = C_String[i];
		int TextIndex = CharToTextIndex(c);
		TextRenderer[i]->SetSprite("Text_White.png", TextIndex);
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
	if (_C >= '0' && _C <= '9') {
		return (_C - '0' + 52);
	}
	switch (_C) {
	case '!': return static_cast<int>(Text_Index::Exclamation);
	case '?': return static_cast<int>(Text_Index::Question);
	default: return static_cast<int>(Text_Index::MAX)+1;
	}
}



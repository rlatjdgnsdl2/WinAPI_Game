#include "PreCompile.h"
#include "DungeonLogBox.h"


#include "BoxUI.h"
#include "Box.h"
#include "Text.h"


ADungeonLogBox::ADungeonLogBox() 
{

}

ADungeonLogBox::ADungeonLogBox(FTransform _BoxTrans) :ABoxUI(_BoxTrans)
{

}

ADungeonLogBox::~ADungeonLogBox() 
{

}

void ADungeonLogBox::BeginPlay()
{
	Super::BeginPlay();
}

void ADungeonLogBox::NewMessage(const std::string_view _Message, Color _Color, float _Time)
{
	if (Texts.size() < 3) {
		CreateString(_Message);
	}
	else if (Texts.size() >= 3) {
		SetString(Texts[1]->GetString(), _Color, 0);
		SetString(Texts[2]->GetString(), _Color, 1);
		SetString(_Message, _Color, 2, _Time);
	}
}

void ADungeonLogBox::NewMessage(const std::vector<std::string>& _Message, const std::vector<Color>& _colors, float _Time)
{
	if (Texts.size() < 3) {
		CreateString(_Message, _colors);
	}
	else if (Texts.size() >= 3) {

		Texts[0]->SetString(Texts[1]);
		Texts[1]->SetString(Texts[2]);
		Texts[2]->SetString(_Message, _colors, _Time);
	}
}

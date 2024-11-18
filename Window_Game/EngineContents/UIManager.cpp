#include "PreCompile.h"
#include "UIManager.h"

#include <EngineCore/SpriteRenderer.h>




UIManager::UIManager()
{
	SetActorLocation({ 0,0 });
}
UIManager::~UIManager()
{

}
void UIManager::CreateMessageBox(FIntPoint _Text_MaxCount)
{
	MessageBox_Text.resize(_Text_MaxCount.Y, std::vector<USpriteRenderer*>(_Text_MaxCount.X));
	for (int y = 0; y < _Text_MaxCount.Y; y++)
	{
		for (int x = 0; x < _Text_MaxCount.X; x++)
		{
			USpriteRenderer* NewText = CreateDefaultSubObject<USpriteRenderer>();
			NewText->SetSprite("Text_White.png",static_cast<int>(Text_Index::MAX));
			NewText->SetSpriteScale();
			NewText->SetCameraEffect(false);
			NewText->SetComponentLocation({ x * 21, y * 34 });
			NewText->SetOrder(ERenderOrder::UI_Text);
			MessageBox_Text[y][x] = NewText;
		}
	}
}

void UIManager::ShowMessageBox_Bottom(std::string_view _Message,FVector2D _Location)
{
	CreateMessageBox(BottomMessageCount);
	std::string Message = _Message.data();
    const char* MessageChar = Message.c_str();
	for (int y = 0; y < BottomMessageCount.Y; y++)
	{
		for (int x = 0; x <BottomMessageCount.X; x++)
		{
			int index = y * BottomMessageCount.X + x;
			if (index < Message.size()) {
				Text_Index textIndex = CharToTextIndex(MessageChar[index]);
				MessageBox_Text[y][x]->SetSprite("Text_White.png", static_cast<int>(textIndex));
				MessageBox_Text[y][x]->SetComponentLocation(_Location + FVector2D({ x * 21, y * 34 }));
			}
			else {
				MessageBox_Text[y][x]->SetSprite("Text_White.png", static_cast<int>(Text_Index::MAX));
			}
		}
	}
}


Text_Index UIManager::CharToTextIndex(char c)
{
	if (c >= 'a' && c <= 'z') {
		return static_cast<Text_Index>(c - 'a');
	}
	if (c >= 'A' && c <= 'Z') {
		return static_cast<Text_Index>(c - 'A' + 26);
	}
	if (c >= '0' && c <= '9') {
		return static_cast<Text_Index>(c - '0' + 52);
	}
	switch (c) {
	case '!': return Text_Index::Exclamation;
	case '?': return Text_Index::Question;
	default: return Text_Index::MAX;
	}
}

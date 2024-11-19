#pragma once
#include <EngineCore/Actor.h>
enum class TextColor {
	White,
	Red,
	Blue,
	Green,
	Yellow,
	Black,
};
//	Ό³Έν:
class AText:public AActor
{
public:
	//	constrcuter, destructer
	AText();
	virtual ~AText();


	//	delete Function
	AText(const AText& _Other) = delete;
	AText(AText&& _Other) noexcept = delete;
	AText& operator=(const AText& _Other) = delete;
	AText& operator=(AText&& _Other) noexcept = delete;


	void SetString(std::string_view _StringValue,std::string_view _color="White");
	int CharToTextIndex(char c);


protected:

private:
	std::string StringValue;
	FVector2D TextSize = FVector2D({14.0f,20.0f});
	std::vector<class USpriteRenderer*> TextRenderer;

};


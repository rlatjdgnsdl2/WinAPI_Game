#pragma once
#include <EngineCore/Actor.h>

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


	void SetString(std::string_view _StringValue);
	int CharToTextIndex(char c);


protected:

private:
	std::string StringValue;
	FVector2D TextSize = FVector2D({15.0f,17.0f});
	FVector2D TextStartLocation;
	std::vector<class USpriteRenderer*> TextRenderer;

};


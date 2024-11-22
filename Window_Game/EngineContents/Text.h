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


	void Reserve(int _Count);

	void ShowText(float _DeltaTime);
	void SetString(std::string_view _StringValue, std::string_view _color = "White", FVector2D _TextSize = FVector2D({ 14.0f,20.0f }), float _Time=0.0f);
	void SetTime(float _Time) { Time = _Time; }

	std::string GetString() const { return StringValue; }	
	void SetColor(std::string_view _color);
	void SetParticialColor(int _StartIndex, int _EndIndex, std::string_view _color);
	
	int CharToTextIndex(char c);


protected:

private:
	std::string StringValue;
	std::string Color;
	FVector2D TextSize;
	std::vector<class USpriteRenderer*> TextRenderer;


	float CurTime = 0.0f;
	float Time = 0.0f;
	int CurCount = 1;

};


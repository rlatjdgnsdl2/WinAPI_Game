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
	void SetString(std::string_view _StringValue, TextColor _Color = TextColor::White, const FVector2D& _TextSize = FVector2D({ 14.0f,20.0f }), float _Time=0.0f);
	void SetString(const AText* _Text);
	void SetTime(float _Time) { Time = _Time; }

	void SetString(const std::vector<std::string>& _StringValues, const std::vector<TextColor>& _Colors, const FVector2D& _TextSize = FVector2D({ 14.0f,20.0f }), float _Time = 0.0f);

	std::string GetString() const { return StringValue; }	
	void SetColor(TextColor _Color);
	
	int CharToTextIndex(char c);


protected:

private:
	std::string StringValue;
	FVector2D TextSize;
	std::vector<class USpriteRenderer*> TextRenderer;


	float CurTime = 0.0f;
	float Time = 0.0f;
	int CurCount = 0;

};


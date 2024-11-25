#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class AText :public AActor
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
	void SetString(std::string_view _StringValue, Color _Color = Color::White, float _Time = 0.0f);
	void SetString(const AText* _Text);
	void SetTime(float _Time) { Time = _Time; }

	void SetString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _Colors, float _Time = 0.0f);

	std::string GetString() const { return StringValue; }
	void SetColor(Color _Color);

	int CharToTextIndex(char c);


protected:

private:
	std::string StringValue;
	const FVector2D TextSize = { 14.0f,20.0f };
	std::vector<class USpriteRenderer*> TextRenderer;


	float CurTime = 0.0f;
	float Time = 0.0f;
	int CurCount = 0;

};


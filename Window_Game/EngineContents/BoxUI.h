#pragma once
#include <EngineCore/Actor.h>


//	����:
class ABoxUI :public AActor
{
public:
	
	//	constrcuter, destructer
	ABoxUI();
	ABoxUI(FTransform _BoxTrans);
	virtual ~ABoxUI();

	//	delete Function
	ABoxUI(const ABoxUI& _Other) = delete;
	ABoxUI(ABoxUI&& _Other) noexcept = delete;
	ABoxUI& operator=(const ABoxUI& _Other) = delete;
	ABoxUI& operator=(ABoxUI&& _Other) noexcept = delete;

	virtual void BeginPlay()override;

	void SetTextsCount(int _Count);
	void CreateString(std::string_view _StringValue, Color _Color = Color::White, float _Time = 0.0f);
	void CreateString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, float _Time = 0.0f);

	void SetString(std::string_view _StringValue, Color _Color = Color::White, int Index = 0, float _Time = 0.0f);
	void SetString(const std::vector<std::string>& _StringValues, const std::vector<Color>& _colors, int Index = 0, float _Time = 0.0f);
	void SetStringColor(class AText* Text, Color _Color);
	void SetStringColor(int Index, Color _Color);

	std::vector<class AText*>::iterator GetCurTextIter() { 
		return TextIter; 
	}
	void ResetTextIter() { 
		TextIter = Texts.begin(); 
	}
	void NextTextIter() {
		++TextIter;
		if (TextIter == Texts.end()) {
			TextIter = Texts.begin();
		}
	}
	void PrevTextIter() {
		if (TextIter == Texts.begin()) {
			TextIter = Texts.end();
		}
		--TextIter;
	}

	virtual void ShowUI(float _DeltaTime = 0.0f);
	void HideUI();

protected:
	FTransform BoxTrans = FTransform(FVector2D::ZERO, FVector2D::ZERO);
	class ABox* Box = nullptr;
	int TextsCount = 0;	
	std::vector<class AText*> Texts;
	std::vector<class AText*>::iterator TextIter;
private:


};


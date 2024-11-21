#pragma once
#include <EngineCore/Actor.h>
 

//	Ό³Έν:
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

	void CreateString(std::string_view _StringValue, std::string_view _color= "White", FVector2D _TextSize = FVector2D({ 14.0f,20.0f }),float _Timee=0.0f);
	void CreateString(class AText* _Text);

	void SetString(int Index, std::string_view _StringValue);
	void SetString(int Index, class AText* _Text);
	void SetStringColor(int Index, std::string_view _color);

	void SetStringColor(class AText* Text, std::string_view _color);
	void SetStringColor(int _Index, int _TextStartIndex, int _TextEndIndex, std::string_view _color);

	
	std::vector<class AText*>::iterator GetTextIter() { return TextIter; }



	void ResetTextIter() { TextIter = Texts.begin(); }
	void NextTextIter() { 	
		++TextIter; 
		if (TextIter == Texts.end())
		{
			TextIter = Texts.begin();
		}
	}
	void PrevTextIter() {
		if (TextIter == Texts.begin())
		{
			TextIter = Texts.end();
		}
		--TextIter;
	}


	void ShowUI(float _DeltaTime=0.0f);
	void HideUI();

	
protected:

private:
	class ABox* Box;
	FTransform BoxTrans;
	std::vector<class AText*> Texts;
	std::vector<class AText*>::iterator TextIter;


};


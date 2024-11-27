#pragma once
#include "BoxUI.h"

//	Ό³Έν:
class ADungeonLogBox :public ABoxUI
{
public:
	//	constrcuter, destructer
	typedef ABoxUI Super;
	ADungeonLogBox();
	ADungeonLogBox(FTransform _BoxTrans);
	virtual ~ADungeonLogBox();

	//	delete Function
	ADungeonLogBox(const ADungeonLogBox& _Other) = delete;
	ADungeonLogBox(ADungeonLogBox&& _Other) noexcept = delete;
	ADungeonLogBox& operator=(const ADungeonLogBox& _Other) = delete;
	ADungeonLogBox& operator=(ADungeonLogBox&& _Other) noexcept = delete;
	virtual void BeginPlay()override;

	void NewMessage(const std::string_view _Message, Color _Color = Color::White, float _Time = 0.0f);
	void NewMessage(const std::vector<std::string>& _Message, const std::vector<Color>& _colors, float _Time = 0.0f);


protected:

private:

};


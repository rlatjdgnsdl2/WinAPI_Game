#pragma once
#include <EngineCore/GameMode.h>





//	Ό³Έν:
class UIManager :public AGameMode
{
public:

	//	constrcuter, destructer
	virtual ~UIManager();

	//	delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

	static UIManager* GetInst()
	{
		static UIManager Inst;
		return &Inst;
	}
	void CreateMessageBox(FIntPoint _Count);

	void ShowMessageBox_Bottom(std::string_view _Message, FVector2D _Location);


protected:

private:
	UIManager();
	Text_Index CharToTextIndex(char c);
	FIntPoint BottomMessageCount = FIntPoint({ 30,3 });
	std::vector<std::vector<class USpriteRenderer*>> MessageBox_Text;


};


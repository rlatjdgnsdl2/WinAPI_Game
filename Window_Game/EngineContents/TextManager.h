#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/Actor.h>>




//	Ό³Έν:
class ATextManager :public AGameMode
{
public:

	//	constrcuter, destructer
	ATextManager();
	virtual ~ATextManager();

	//	delete Function
	ATextManager(const ATextManager& _Other) = delete;
	ATextManager(ATextManager&& _Other) noexcept = delete;
	ATextManager& operator=(const ATextManager& _Other) = delete;
	ATextManager& operator=(ATextManager&& _Other) noexcept = delete;

	virtual void Tick(float _DeltaTime) override;

	void PushDungeonLog(std::string_view _StringValue);

	
	


protected:

private:
	std::list<class AText*> DungeonLogRender;
	


};


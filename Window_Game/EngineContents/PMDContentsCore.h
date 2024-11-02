#pragma once
#include <EngineCore/EngineContentsCore.h>
//	����:
class PMDContentsCore :public UEngineContentsCore
{
public:
	//	constrcuter, destructer
	PMDContentsCore();
	~PMDContentsCore();
	//	delete Function
	PMDContentsCore(const PMDContentsCore& _Other) = delete;
	PMDContentsCore(PMDContentsCore&& _Other) noexcept = delete;
	PMDContentsCore& operator=(const PMDContentsCore& _Other) = delete;
	PMDContentsCore& operator=(PMDContentsCore&& _Other) noexcept = delete;

	static std::map<std::string, int > TileIndexForKey;
	
	
	void BeginPlay() override;
	void Tick() override;


protected:
private:
	void InitKeySet();


};


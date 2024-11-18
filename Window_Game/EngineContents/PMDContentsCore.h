#pragma once
#pragma once
#include <EngineCore/EngineContentsCore.h>
//	Ό³Έν:
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

	
	
	void BeginPlay() override;
	void Tick() override;
	static int GetTileIndex(std::string_view _key);


protected:
private:
	static std::map<std::string, int > TileIndexForKey;
	void InitKeySet();
	void RoadResources();


};


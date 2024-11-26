#pragma once
#include <EngineCore/Actor.h>

//	Ό³Έν:
class AMiniMap : public AActor
{
public:
	
	//	constrcuter, destructer
	AMiniMap();
	virtual ~AMiniMap();

	//	delete Function
	AMiniMap(const AMiniMap& _Other) = delete;
	AMiniMap(AMiniMap&& _Other) noexcept = delete;
	AMiniMap& operator=(const AMiniMap& _Other) = delete;
	AMiniMap& operator=(AMiniMap&& _Other) noexcept = delete;

	virtual void BeginPlay()override;
	virtual void Tick(float _DeltaTime)override;	
		
	void SetMiniMap();
	void SetDungeon(class ADungeon_BSP* _Dungeon) { Dungeon = _Dungeon; }
	void SetPlayer(class APlayer* _Player) { Player = _Player; }



protected:

private:
	std::vector<std::vector<class USpriteRenderer*>> MiniMapRenderers;
	class USpriteRenderer* PlayerRenderer = nullptr;
	class USpriteRenderer* PotalRenderer = nullptr;	


	class ADungeon_BSP* Dungeon = nullptr;
	class APlayer* Player = nullptr;
	const FVector2D SpriteSize = { 8,8 };
	const int Width = 60;
	const int Height = 40;


};


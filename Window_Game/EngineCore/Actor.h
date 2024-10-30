#pragma once
#include <EngineBase/Object.h>
#include "EngineSprite.h"

//	����:
class AActor : public UObject
{
public:
	typedef AActor Super;

	//	Level�� Actor�� ���ٰ���
	friend class ULevel;

	//	constrcuter, destructer
	AActor();
	virtual ~AActor();

	//	delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

	//	virtual 
	virtual void BeginPlay() {}
	virtual void Tick(float _DeltaTime) {}
	virtual void Render();

	//	�Ϲ�
	class ULevel* GetWorld()					{ return World; }
	void SetActorLocation(FVector2D _Location)	{ Transform.Location = _Location; }
	void AddActorLocation(FVector2D _Direction) { Transform.Location += _Direction; }
	void SetActorScale(FVector2D _Scale)		{ Transform.Scale = _Scale; }
	FVector2D GetActorLocation()				{ return Transform.Location; }


	class UEngineSprite* Sprite = nullptr;
	void SetSprite(std::string_view _Name, int _CurIndex = 0);

protected:

private:
	//	Actor�� �����ִ� level
	class ULevel* World = nullptr;
	int CurIndex = 0;
	FTransform Transform;
};


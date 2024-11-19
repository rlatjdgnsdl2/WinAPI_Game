#pragma once
#include <EngineCore/Actor.h>

class BoxPiece {
public:
	class USpriteRenderer* SpriteRenderer;
	FVector2D BoxPieceSize;
};



//	Ό³Έν:
class ABox : public AActor
{
public:
	//	constrcuter, destructer
	ABox();
	virtual ~ABox();

	//	delete Function
	ABox(const ABox& _Other) = delete;
	ABox(ABox&& _Other) noexcept = delete;
	ABox& operator=(const ABox& _Other) = delete;
	ABox& operator=(ABox&& _Other) noexcept = delete;

	void SetBoxSize(FVector2D BoxSize);

	


protected:

private:
	std::vector<std::vector<BoxPiece>> BoxUI;

};


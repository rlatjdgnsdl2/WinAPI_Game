#include "PreCompile.h"
#include "Box.h"
#include <EngineCore/SpriteRenderer.h>


ABox::ABox()
{
	BoxUI.resize(3, std::vector<BoxPiece>(3));
	std::vector<std::string> Sprites = {
		"MessageBox_LeftTop.png", "MessageBox_Top.png", "MessageBox_RightTop.png",
		"MessageBox_Left.png", "MessageBox_Center.bmp", "MessageBox_Right.png",
		"MessageBox_LeftBottom.png", "MessageBox_Bottom.png", "MessageBox_RightBottom.png"
	};
	for (size_t y = 0; y < 3; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			USpriteRenderer* NewSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
			NewSpriteRenderer->SetSprite(Sprites[y * 3 + x]);
			NewSpriteRenderer->SetSpriteScale();
			NewSpriteRenderer->SetComponentScale(CornerSize);
			NewSpriteRenderer->SetCameraEffect(false);
			NewSpriteRenderer->SetComponentLocation(FVector2D({ CornerSize.X * x, CornerSize.Y * y }));
			NewSpriteRenderer->SetOrder(ERenderOrder::UI_BASIC);
			BoxUI[y][x].SpriteRenderer = NewSpriteRenderer;
			BoxUI[y][x].BoxPieceSize = CornerSize;
		}
	}
}

ABox::~ABox()
{

}



void ABox::SetBoxSize(FVector2D BoxSize)
{
	
	FVector2D Pivot = { 0.0f, 0.0f };

	// 상단 박스 설정
	
	Pivot += CornerSize.Half();
	BoxUI[0][0].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[0][0].SpriteRenderer->SetComponentScale(CornerSize);
	

	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[0][1].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[0][1].SpriteRenderer->SetComponentScale(FVector2D(BoxSize.X - CornerSize.X * 2.0f, CornerSize.Y));

	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[0][2].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[0][2].SpriteRenderer->SetComponentScale(CornerSize);

	Pivot = { 0.0f, 0.0f };

	// 중간 박스 설정
	Pivot += CornerSize.Half() + FVector2D(0.0f, (BoxSize.Y - CornerSize.Y * 2)).Half()/*FVector2D(2.0f,0.0f)*/;
	BoxUI[1][0].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[1][0].SpriteRenderer->SetComponentScale(FVector2D(24.0f, BoxSize.Y - CornerSize.Y * 2.0f));

	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[1][1].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[1][1].SpriteRenderer->SetComponentScale(FVector2D(BoxSize.X - CornerSize.X * 2.0f, BoxSize.Y - CornerSize.Y * 2.0f));
	BoxUI[1][1].SpriteRenderer->SetAlphafloat(0.3f);
	BoxUI[1][1].SpriteRenderer->SetOrder(ERenderOrder::UI_BACKGROUND);


	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[1][2].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[1][2].SpriteRenderer->SetComponentScale(FVector2D(24.0f, BoxSize.Y - CornerSize.Y * 2.0f));

	Pivot = { 0.0f, 0.0f };

	// 하단 박스 설정
	Pivot += CornerSize.Half() + FVector2D(0.0f, BoxSize.Y - CornerSize.Y * 2.0f);
	BoxUI[2][0].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[2][0].SpriteRenderer->SetComponentScale(CornerSize);

	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[2][1].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[2][1].SpriteRenderer->SetComponentScale(FVector2D(BoxSize.X - CornerSize.X * 2.0f, CornerSize.Y));

	Pivot += FVector2D((BoxSize.X - CornerSize.X * 2), 0.0f).Half();
	BoxUI[2][2].SpriteRenderer->SetComponentLocation(Pivot);
	BoxUI[2][2].SpriteRenderer->SetComponentScale(CornerSize);
}
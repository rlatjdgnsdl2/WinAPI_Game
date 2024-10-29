#include "PreCompile.h"
#include "EngineWinImage.h"
#include <EngineBase/EngineDebug.h>

UEngineWinImage::UEngineWinImage() 
{
	ZeroMemory(&Info, sizeof(BITMAP));
}

UEngineWinImage::~UEngineWinImage()
{
}

void UEngineWinImage::Create(UEngineWinImage* _TargetImage, FVector2D _Scale)
{
	if (nullptr == _TargetImage)
	{
		MSGASSERT("Main windowDC�� �����ʰ� �̹����� �����Ϸ��� �߽��ϴ�");
		return;
	}
	//	���ο�
	HBITMAP NewBitmap = static_cast<HBITMAP>(CreateCompatibleBitmap(_TargetImage->GetDC(), _Scale.iX(), _Scale.iY()));
	HDC NewImageDC = CreateCompatibleDC(_TargetImage->GetDC());

	// ���� BitMap delete ���� - OldBitMap 1, 1 ũ���� �̹���
	HBITMAP OldBitMap = static_cast<HBITMAP>(SelectObject(NewImageDC, NewBitmap));
	DeleteObject(OldBitMap);

	hBitMap = NewBitmap;
	ImageDC = NewImageDC;

	GetObject(hBitMap, sizeof(BITMAP), &Info);
}

void UEngineWinImage::CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans)
{
	if (nullptr == _TargetImage)
	{
		MSGASSERT("������� ����� �������� �ʽ��ϴ�");
	}

	HDC CopyDC = ImageDC;
	HDC TargetDC = _TargetImage->ImageDC;
	FVector2D LeftTop = _Trans.CenterLeftTop();
	FVector2D RightBot = _Trans.CenterRightBottom();

	BitBlt(
		TargetDC,
		LeftTop.iX(),
		LeftTop.iY(),
		_Trans.Scale.iX(),
		_Trans.Scale.iY(),
		CopyDC,
		0,
		0,
		SRCCOPY);

	
}

#include "PreCompile.h"
#include "EngineWinImage.h"
#include <EngineBase/EngineDebug.h>

UEngineWinImage::UEngineWinImage() :Info{}
{
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

	// HDC �ƹ��͵� ��������
	// HDC �־�޶�� �ϴµ� window HDC
	// int X; ������� �� �̹����� xũ��
	// int Y; ������� �� �̹����� yũ��

	// �ƹ��͵� ���°��� 
	// HDC hdc Ÿ�� �� �̹����� ���� �׸����� �ϴ� Ÿ��
	// int cx ������� �̹����� ũ��
	// int cy ������� �̹����� ũ��



	HBITMAP NewBitmap = static_cast<HBITMAP>(CreateCompatibleBitmap(_TargetImage->GetDC(), _Scale.iX(), _Scale.iY()));

	// �̹��� ����ü
	// �̹����� �����Ҽ� �ִ� ���� HDC
	// �̹����� ������ ���� HBITMAP
	// HDC<=>HBITMAP �� �������� �̹����� �̹����� �����ϴ� ������ ����Ǵ� ����

	// ��
	HDC NewImageDC = CreateCompatibleDC(_TargetImage->GetDC());

	// �����찡 ���ϱ⸦ �װ� ��ȭ���� �ѽ����� �ȿ����� ���׸�.
	// ���� ����⸸ �ص�  1, 1 �̹����� ������ ���´�. window 

	// �װ� ��ȭ���� �����ϴ� �۾��� ���ľ� �Ѵ�.
	HBITMAP OldBitMap = static_cast<HBITMAP>(SelectObject(NewImageDC, NewBitmap));
	// OldBitMap 1, 1 ũ���� �̹���
	// ������ �������θ� leck
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
	// CopyDC => TargetDC�� ī���ϰڴ�.
	// ������� �̷� HDC���� Copy�� ���ؼ� 
	// ī�ǿ� �Լ����� � �غ��߰� ���߿���
	// ���� �⺻���� �Լ��� �ٷ� Bitblt

	//HDC hdc, ī�� ���� ��� <= ���⿡�ٰ� �����ض�
	//int x, <= ��ġx
	//int y, <= ��ġy
	//int cx, <= ũ��x
	//int cy, <= ũ��x
	// HDC hdcSrc, ī���� �̹���
	// int x1, �̹��� ������ 0
	// int y1, 
	// rop => ī�� �ɼ�

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

	// SRCCOPY ī���Ҷ� 
}

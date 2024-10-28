#include "PreCompile.h"
#include "EngineWinImage.h"

UEngineWinImage::UEngineWinImage()
{
}

UEngineWinImage::~UEngineWinImage()
{
}

void UEngineWinImage::Create(FVector2D _Scale)
{
	// HDC �ƹ��͵� ��������
	// HDC �־�޶�� �ϴµ� window HDC
	// int X; ������� �� �̹����� xũ��
	// int Y; ������� �� �̹����� yũ��

	// ��ȭ�� 1280, 720
	HBITMAP NewBitmap = static_cast<HBITMAP>(CreateCompatibleBitmap(nullptr, _Scale.iX(), _Scale.iY()));

	// �̹��� ����ü
	// �̹����� �����Ҽ� �ִ� ���� HDC
	// �̹����� ������ ���� HBITMAP
	// HDC<=>HBITMAP �� �������� �̹����� �̹����� �����ϴ� ������ ����Ǵ� ����

	// ��
	HDC NewImageDC = CreateCompatibleDC(nullptr);

	// �����찡 ���ϱ⸦ �װ� ��ȭ���� �ѽ����� �ȿ����� ���׸�.
	// ���� ����⸸ �ص�  1, 1 �̹����� ������ ���´�. window 

	// �װ� ��ȭ���� �����ϴ� �۾��� ���ľ� �Ѵ�.
	HBITMAP OldBitMap = static_cast<HBITMAP>(SelectObject(NewImageDC, NewBitmap));
	// ������ �������θ� leck
	DeleteObject(OldBitMap);


	BitMap = NewBitmap;
	ImageDC = NewImageDC;


}
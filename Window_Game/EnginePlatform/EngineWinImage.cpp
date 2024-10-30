#include "PreCompile.h"
#include "EngineWinImage.h"
#include <EngineBase/EngineDebug.h>
#include <EngineBase/EnginePath.h>
#include <EngineBase/EngineString.h>

// GDI Plus �� ���
#include <objidl.h>
#include <gdiplus.h>

// $(WindowsSDK_LibraryPath_x64) <= ���� ��ξȿ� ����ִ� ���̺귯�� �Դϴ�.

// �̹����� window�⺻ ���̺귯���� 2������ �ֽ��ϴ�.
// BMP Ȯ��� ���̺귯��
#pragma comment(lib, "Msimg32.lib")

// PNG �� ���� window ����Ƽ�� �׷��� Ȯ��� ���̺귯��
#pragma comment(lib, "Gdiplus.lib")

UEngineWinImage::UEngineWinImage()
{
}

UEngineWinImage::~UEngineWinImage()
{
	// ������ ������� �޸𸮶� ���� �ȵǰ�����
	// �ظ��ϸ� ���� ��������� �����ִ°��� ��ȣ�մϴ�.
	if (nullptr != hBitMap)
	{
		DeleteObject(hBitMap);
		hBitMap = nullptr;
	}

	if (nullptr != ImageDC)
	{
		DeleteDC(ImageDC);
		ImageDC = nullptr;
	}

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

	// �̹��� 
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

void UEngineWinImage::CopyToTrans(UEngineWinImage* _TargetImage, const FTransform& _RenderTrans, const FTransform& _LTImageTrans, UColor _Color /*= UColor(255, 0, 255, 255)*/)
{
	// _RenderTrans ������ Ʈ������

	// _LTImageTrans �̹��� �ɰ� ũ�Ⱑ

	HDC CopyDC = ImageDC;
	HDC TargetDC = _TargetImage->ImageDC;

	//_In_ HDC hdcDest, ���⿡�ٰ� ī���ض�
	//_In_ int xoriginDest, �׷����� ��ġ
	//_In_ int yoriginDest, �׷����� ��ġ
	//_In_ int wDest, �׷����� ũ��
	//_In_ int hDest, �׷����� ũ��
	//_In_ HDC hdcSrc, ����� �̹��� => �����е��� �ε��� �̹���
	//_In_ int xoriginSrc, �̹��� �̺κ� 
	//_In_ int yoriginSrc, int X
	//_In_ int wSrc,
	//_In_ int hSrc,
	//_In_ UINT crTransparent

	FVector2D LeftTop = _RenderTrans.CenterLeftTop();

	TransparentBlt(
		TargetDC,
		LeftTop.iX(),
		LeftTop.iY(),
		_RenderTrans.Scale.iX(),
		_RenderTrans.Scale.iY(),
		CopyDC,
		_LTImageTrans.Location.iX(),
		_LTImageTrans.Location.iY(),
		_LTImageTrans.Scale.iX(),
		_LTImageTrans.Scale.iY(),
		_Color.Color
	);
}

void UEngineWinImage::Load(UEngineWinImage* _TargetImage, std::string_view _Path)
{
	// Png�� Bmp�϶� �ε��ϴ� ����� �޶�����.
	// Png�δ� �������� �⺻ �̹����� �ƴ϶�.
	// BMP�� ���� �ε������� PNG�� ���ݴ� �ڵ带 �ľ� �Ѵ�.
	// �׷��Ƚ��� �ᱹ WinApi

	// Png�� �ε��ؼ� Bmp�� ��ȯ�ϴ� ������ ��ġ�� ���信 ������.
	// ������ �ᱹ �ε��ϴ� �Լ��� �ٸ�������
	// �ε尡 �����ٸ� �ᱹ
	// class Color
	// {
	//    char R, G, B, 255;
	// }
	// Color Arr[??][??]

	// �ε尡 ������ window�� �����̴�. 

	// �𸮾��� �׷��� �մϴ�.
	// Window.png => WINDOW.PNG
	// WIndow.png
	// WIndow.Png
	// WIndow.pNg
	// WIndow.pnG

	UEnginePath Path = _Path;

	std::string UpperExt = UEngineString::ToUpper(Path.GetExtension());

	HBITMAP NewBitmap = nullptr;

	if (".PNG" == UpperExt)
	{
		// �ε������ GDI Plus�� �̿� �������� 
		// WInapi�Լ��� ����ϴ� �������� ����./

		// GDIPLus�� �ڵ��� ǥ���Ҷ� 
		ULONG_PTR gidplustoken = 0;

		// GDI plus�� ����ϱ� ���� ��ǲ
		Gdiplus::GdiplusStartupInput StartupInput;
		Gdiplus::GdiplusStartup(&gidplustoken, &StartupInput, nullptr);


		std::wstring WidePath = UEngineString::AnsiToUnicode(_Path);

		// ��� �־��ָ� �̹��� �ε����ִ� �Լ�
		Gdiplus::Image* pImage = Gdiplus::Image::FromFile(WidePath.c_str());

		// ���纻�� �����ϰ� �ű⿡�� bitmap �κ��� �̾Ƴ��� ���
		Gdiplus::Bitmap* pBitMap = reinterpret_cast<Gdiplus::Bitmap*>(pImage->Clone());

		Gdiplus::Status stat = pBitMap->GetHBITMAP(Gdiplus::Color(255, 255, 0, 255), &NewBitmap);

		if (Gdiplus::Status::Ok != stat)
		{
			MSGASSERT("Png �̹��� �ε忡 �����߽��ϴ�." + std::string(_Path));
			return;
		}

		// 
		delete pBitMap;
		delete pImage;


		// ���ο� �����ϴ� bitmap�� ������.
		// ������� �ᱹ ��� �̹����� bitmap���� ����.
		// Gdiplus::* pImage = Gdiplus::Image::FromFile(WidePath.c_str());

		int a = 0;

		// ���ڵ��� �ؾ� �մϴ�.



	}

	if (nullptr == NewBitmap)
	{
		MSGASSERT("�̹��� �ε��� �����߽��ϴ�");
		return;
	}

	// ��
	HDC NewImageDC = CreateCompatibleDC(_TargetImage->GetDC());

	HBITMAP OldBitMap = static_cast<HBITMAP>(SelectObject(NewImageDC, NewBitmap));
	DeleteObject(OldBitMap);

	hBitMap = NewBitmap;
	ImageDC = NewImageDC;

	GetObject(hBitMap, sizeof(BITMAP), &Info);
}
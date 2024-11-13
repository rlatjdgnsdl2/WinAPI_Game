#pragma once
#include <Windows.h>
#include <EngineBase/EngineMath.h>
#include <EngineBase/Object.h>


//	����: �̹���Ŭ����
class UEngineWinImage : public UObject
{
public:
	// constrcuter destructer
	UEngineWinImage();
	~UEngineWinImage();

	// delete Function
	UEngineWinImage(const UEngineWinImage& _Other) = delete;
	UEngineWinImage(UEngineWinImage&& _Other) noexcept = delete;
	UEngineWinImage& operator=(const UEngineWinImage& _Other) = delete;
	UEngineWinImage& operator=(UEngineWinImage&& _Other) noexcept = delete;


	HDC GetDC() { return ImageDC; }
	FVector2D GetImageScale() const { return { Info.bmWidth, Info.bmHeight }; }
	UColor GetColor(FVector2D _Point, UColor _DefaultColor = UColor::WHITE)
	{
		return GetColor(_Point.ConvertToPoint(), _DefaultColor);
	}

	UColor GetColor(FIntPoint _Point, UColor _DefaultColor);


	//	�̹� ������� DC�� �̹����� HDC�� ����
	void Create(HDC _DC) { ImageDC = _DC; }
	//	TargetImage�� DC�� �̹����� HDC�� ����
	void Create(UEngineWinImage* _TargetImage, FVector2D _Scale);

	//	BitBlt �Լ�
	void CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans);
	//	TransparentBlt �Լ�
	void CopyToTrans(UEngineWinImage* _TargetImage,
		const FTransform& _RenderTrans,
		const FTransform& _LTImageTrans,
		UColor _Color = UColor(255, 0, 255, 0));
	void CopyToAlpha(UEngineWinImage* _TargetImage,
		const FTransform& _RenderTrans,
		const FTransform& _LTImageTrans,
		unsigned char _Alpha);

	//	�̹��� �ε� �Լ� // PNG �ε�� GDI Plus�� �̿�
	void Load(UEngineWinImage* _TargetImage, std::string_view _Path);

	

protected:

private:
	//	�̹���
	HDC ImageDC = nullptr;
	HBITMAP hBitMap = nullptr;
	//	�̹��� ����
	BITMAP Info;

};


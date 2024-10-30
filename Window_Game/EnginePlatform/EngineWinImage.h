#pragma once
#include <Windows.h>
#include <EngineBase/EngineMath.h>
#include <EngineBase/Object.h>


//	설명: 이미지클래스
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

	//	이미 만들어진 DC를 이미지의 HDC로 설정
	void Create(HDC _DC) { ImageDC = _DC; }
	//	TargetImage의 DC를 이미지의 HDC로 설정
	void Create(UEngineWinImage* _TargetImage, FVector2D _Scale);

	//	BitBlt 함수
	void CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans);
	//	TransparentBlt 함수
	void CopyToTrans(UEngineWinImage* _TargetImage,
		const FTransform& _RenderTrans,
		const FTransform& _LTImageTrans,
		UColor _Color = UColor(255, 0, 255, 0));

	//	이미지 로드 함수 // PNG 로드는 GDI Plus를 이용
	void Load(UEngineWinImage* _TargetImage, std::string_view _Path);

	

protected:

private:
	//	이미지
	HDC ImageDC = nullptr;
	HBITMAP hBitMap = nullptr;
	//	이미지 정보
	BITMAP Info;

};


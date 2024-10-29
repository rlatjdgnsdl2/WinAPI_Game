#pragma once
#include <Windows.h>



// 설명 : API 랜더링 구조의 핵심 클래스 
class UEngineWinImage
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

	HDC GetDC() const { return ImageDC; }

	//	이미 만들어진 DC를 통해서 이미지를 만드는 함수
	void Create(HDC _DC) { ImageDC = _DC; }	
	//	 _Scale크기의 _TargetImage로 만들어진 DC를 통해서 이미지를 만드는 함수
	void Create(UEngineWinImage* _TargetImage, FVector2D _Scale);
	//	이 객체를 TargetImage의 _Trans지점에 복사
	void CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans);

protected:

private:
	//	DC+BitMap => 이미지 수정 가능
	//	이미지를 수정할수 있는 권한 - HDC
	HDC ImageDC = nullptr;		//	붓?
	//	이미지의 데이터 권한 - HBITMAP
	HBITMAP hBitMap = nullptr;	//	잉크?
	// 이미지정보
	BITMAP Info;

};


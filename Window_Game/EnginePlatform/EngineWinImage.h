#pragma once
#include <Windows.h>



// ���� : API ������ ������ �ٽ� Ŭ���� 
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

	//	�̹� ������� DC�� ���ؼ� �̹����� ����� �Լ�
	void Create(HDC _DC) { ImageDC = _DC; }	
	//	 _Scaleũ���� _TargetImage�� ������� DC�� ���ؼ� �̹����� ����� �Լ�
	void Create(UEngineWinImage* _TargetImage, FVector2D _Scale);
	//	�� ��ü�� TargetImage�� _Trans������ ����
	void CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans);

protected:

private:
	//	DC+BitMap => �̹��� ���� ����
	//	�̹����� �����Ҽ� �ִ� ���� - HDC
	HDC ImageDC = nullptr;		//	��?
	//	�̹����� ������ ���� - HBITMAP
	HBITMAP hBitMap = nullptr;	//	��ũ?
	// �̹�������
	BITMAP Info;

};


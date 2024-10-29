#pragma once
#include <Windows.h>

// �̳༮�� �̹��� ������ ����� �̴ϴ�.
// �̳༮�� �翬�� �ε嵵 �˴ϴ�.

// ���� : API �̹� ������ ������ �ٽ� Ŭ����
// 
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

	// void Load(std::string_view _Path);
	HDC GetDC() const { return ImageDC; }

	// �̹� ������� DC�� ���ؼ� �̹����� ����� Ÿ��
	void Create(HDC _DC) { ImageDC = _DC; }

	
	void Create(UEngineWinImage* _TargetImage, FVector2D _Scale);
	void CopyToBit(UEngineWinImage* _TargetImage, const FTransform& _Trans);

protected:

private:
	HDC ImageDC = nullptr;
	HBITMAP hBitMap = nullptr;
	BITMAP Info;

};


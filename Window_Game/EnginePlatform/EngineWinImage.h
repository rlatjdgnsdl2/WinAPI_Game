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
	HDC GetDC()
	{
		return ImageDC;
	}

	// �̹� ������� DC�� ���ؼ� �̹����� ����� Ÿ��
	void Create(HDC _DC)
	{
		ImageDC = _DC;
	}

	void Create(FVector2D _Scale);


protected:

private:
	// BMP �̹��� ���� �� ��ü����
	// FVector2D Size;
	HDC ImageDC = nullptr;
	HBITMAP BitMap = nullptr;

};


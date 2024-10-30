#include "PreCompile.h"
#include "Level.h"

#include "EngineAPICore.h"

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;
		if (nullptr != CurActor)
		{
			delete CurActor;
			CurActor = nullptr;
		}
	}
}

void ULevel::Tick(float _DeltaTime)
{
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		CurActor->Tick(_DeltaTime);
	}
}


void ULevel::Render()
{
	ScreenClear();
	// 액터를 기반으로 랜더링을 돌리는건 곧 지워질 겁니다.
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		CurActor->Render();
	}
	DoubleBuffering();
}

void ULevel::DoubleBuffering()
{
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();	//	메인윈도우
	UEngineWinImage* WindowImage = MainWindow.GetWindowImage();				//	FrontBuffer Image
	UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();			//	BackBuffer	Image
	FTransform Trans;
	Trans.Location = MainWindow.GetWindowSize().Half();
	Trans.Scale = MainWindow.GetWindowSize();
	BackBufferImage->CopyToBit(WindowImage, Trans);
}

void ULevel::ScreenClear()
{
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	UEngineWinImage* BackBufferImage = MainWindow.GetBackBuffer();
	FVector2D Size = MainWindow.GetWindowSize();
	Rectangle(BackBufferImage->GetDC(), -1, -1, Size.iX() + 2, Size.iY() + 2);
}





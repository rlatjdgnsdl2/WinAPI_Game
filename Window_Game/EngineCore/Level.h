#pragma once
#include "GameMode.h"

// ���� :
class ULevel
{
public:
	friend class USpriteRenderer;
	friend class UEngineAPICore;
	// constrcuter destructer
	ULevel();
	~ULevel();

	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);
	void Render(float _DeltaTime);

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();

		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		// ���� �� ���� �����̾�.
		ActorPtr->World = this;

		BeginPlayList.push_back(ActorPtr);
		// NewActor->BeginPlay();
		// AllActors.push_back(NewActor);
		return NewActor;
	}

	void SetCameraToMainPawn(bool _IsCameraToMainPawn)
	{
		IsCameraToMainPawn = _IsCameraToMainPawn;
	}

	void SetCameraPivot(FVector2D _Pivot)
	{
		CameraPivot = _Pivot;
	}

protected:

private:
	void ScreenClear();
	void DoubleBuffering();


	// ���ӷ����� �������� ���� ������ �غ��Ű�� �Լ��ε� �������.
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType();

		// ȭ���� �ٶ���ִ� ī�޶��� �����ϰ� ����ŵ� �˴ϴ�.
		MainPawn = new MainPawnType();

		// ���弼���� �����Ǵ°��� ������ �߿��ϴ�.
		MainPawn->World = this;
		GameMode->World = this;

		BeginPlayList.push_back(GameMode);
		BeginPlayList.push_back(MainPawn);

		//GameMode->BeginPlay();
		//MainPawn->BeginPlay();
		//AllActors.push_back(GameMode);
		//AllActors.push_back(MainPawn);
	}


	// �ƹ��� �Ժη� ȣ������ ���ϰ� �ϱ� ���ؼ� private �̾�� �Ѵ�.
	void PushRenderer(class USpriteRenderer* _Renderer);
	void ChangeRenderOrder(class USpriteRenderer* _Renderer, int _PrevOrder);

	// �밡���� ǥ���
	// �̸��� �������
	// �ɹ������� �̸��� �빮��
	// ��������������
	// dujumsaigury
	// �����ǹ̷� ���ֽø� �˴ϴ�.
	// �Ǿո� 
	class AGameMode* GameMode = nullptr;

	// ���ΰ�
	class AActor* MainPawn = nullptr;

	std::list<AActor*> AllActors;

	std::list<AActor*> BeginPlayList;

	bool IsCameraToMainPawn = true;
	// �Ʒ� ������ 2���� ī�޶�.
	FVector2D CameraPos;
	FVector2D CameraPivot;

	// �������� �Ұ��̴�.
	std::map<int, std::list<class USpriteRenderer*>> Renderers;
};


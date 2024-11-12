#pragma once
#include "GameMode.h"
class CollisionLinkData
{
public:
	union
	{
		struct
		{
			int Left;
			int Right;
		};
		__int64 Key;
	};
};
// 설명 :
class ULevel
{
public:
	friend class U2DCollision;
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
	void Collision(float _DeltaTime);
	void Release(float _DeltaTime);

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		ActorPtr->World = this;
		BeginPlayList.push_back(ActorPtr);
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
	void SetCameraPos(FVector2D _Pos)
	{
		CameraPos = _Pos;
	}
	FVector2D GetCameraPivot()
	{
		return CameraPivot;
	}

	FVector2D GetCameraPos()
	{
		return CameraPos;
	}
	AActor* GetPawn()
	{
		return MainPawn;
	}

	template<typename ConvertType>
	ConvertType* GetPawn()
	{
		return dynamic_cast<ConvertType*>(MainPawn);
	}
	AActor* GetGameMode()
	{
		return GameMode;
	}

	template<typename ConvertType>
	ConvertType* GetGameMode()
	{
		return dynamic_cast<ConvertType*>(GameMode);
	}

	void AddCameraPos(FVector2D _Value)
	{
		CameraPos += _Value;
	}

	template<typename LeftEnumType, typename RightEnumType>
	static void CollisionGroupLink(LeftEnumType _Left, RightEnumType _Right)
	{
		CollisionGroupLink(static_cast<int>(_Left), static_cast<int>(_Right));
	}

	static void CollisionGroupLink(int _Left, int _Right)
	{
		CollisionLinkData LinkData;
		LinkData.Left = _Left;
		LinkData.Right = _Right;

		for (size_t i = 0; i < CollisionLink.size(); i++)
		{
			// 조금 추하지만 vector
			if (CollisionLink[i].Key == _Right)
			{
				return;
			}
		}

		CollisionLink.push_back(LinkData);
	}


protected:

private:
	void ScreenClear();
	void DoubleBuffering();


	// 게임레벨과 메인폰 생성함수
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType();
		MainPawn = new MainPawnType();

		MainPawn->World = this;
		GameMode->World = this;

		BeginPlayList.push_back(GameMode);
		BeginPlayList.push_back(MainPawn);
	}

	void LevelChangeStart();
	void LevelChangeEnd();
	void PushRenderer(class USpriteRenderer* _Renderer);
	void ChangeRenderOrder(class USpriteRenderer* _Renderer, int _PrevOrder);
	void PushCollision(class U2DCollision* _Collision);
	void PushCheckCollision(class U2DCollision* _Collision);



	class AGameMode* GameMode = nullptr;

	// 주인공
	class AActor* MainPawn = nullptr;

	std::list<AActor*> AllActors;

	std::list<AActor*> BeginPlayList;

	bool IsCameraToMainPawn = true;
	// 아래 포지션 2개가 카메라.
	FVector2D CameraPos;
	FVector2D CameraPivot;

	std::map<int, std::list<class USpriteRenderer*>> Renderers;

	// 직접호출을 위해서 들고만 있는 용도
	std::map<int, std::list<class U2DCollision*>> Collisions;

	// 이벤트 체크방식을 위해서 어떤 그룹이 어떤 그룹과 충돌하지 기록해 놓은 자료구조
	static std::vector<CollisionLinkData> CollisionLink;

	// 프레임마다 충돌체크를 하는 콜리전들을 따로 모아 놓은 자료구조 => 이거 피하고 싶다.
	std::map<int, std::list<class U2DCollision*>> CheckCollisions;
};


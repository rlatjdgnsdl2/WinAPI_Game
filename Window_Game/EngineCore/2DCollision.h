#pragma once
#include "SceneComponent.h"

// �Ž� �浹. 


// ���� :
class U2DCollision : public USceneComponent
{
public:
	// constrcuter destructer
	U2DCollision();
	~U2DCollision();

	// delete Function
	U2DCollision(const U2DCollision& _Other) = delete;
	U2DCollision(U2DCollision&& _Other) noexcept = delete;
	U2DCollision& operator=(const U2DCollision& _Other) = delete;
	U2DCollision& operator=(U2DCollision&& _Other) noexcept = delete;

	void BeginPlay() override;

	void ComponentTick(float _DeltaTime) override;

	template<typename EnumType>
	EnumType GetGroup()
	{
		return static_cast<EnumType>(CollisionGroup);
	}

	int GetGroup()
	{
		return CollisionGroup;
	}

	// �浹ü���� �浹�׷��� ���������ִ°� �ǹ̰� ����.
	// �߰��� �浹 �׷��� �ٲ��� �Ǹ� �̾߱� ��Ź.
	template<typename EnumType>
	void SetCollisionGroup(EnumType _CollisionGroup)
	{
		SetCollisionGroup(static_cast<int>(_CollisionGroup));
	}

	void SetCollisionGroup(int _CollisionGroup)
	{
		CollisionGroup = _CollisionGroup;
	}

	template<typename EnumType>
	AActor* CollisionOnce(EnumType _OtherCollisionGroup, FVector2D _NextPos = FVector2D::ZERO)
	{
		// ��밡 100���̴�. 100�� 
		std::vector<AActor*> Result;
		Collision(static_cast<int>(_OtherCollisionGroup), Result, _NextPos, 1);

		if (true == Result.empty())
		{
			return nullptr;
		}

		return Result[0];
	}

	template<typename EnumType>
	std::vector<AActor*> CollisionAll(EnumType _OtherCollisionGroup)
	{
		// ��밡 100���̴�. 100�� 
		std::vector<AActor*> Result;
		Collision(static_cast<int>(_OtherCollisionGroup), Result, -1);

		return Result;
	}

	bool Collision(int _OtherCollisionGroup, std::vector<AActor*>& _Result, FVector2D _NextDir, unsigned int  _Limite);

	void SetCollisionType(ECollisionType _CollisionType)
	{
		CollisionType = _CollisionType;
	}

protected:

private:
	// �浹ü�� ������ �ణ �ǹ̰� �ٸ���.
	// -1 �浹 �׷��� ���������� �ʾҴ�
	// -1 �� ����ϸ� �ȵȴ�.
	// ����� �ȴ�.
	ECollisionType CollisionType = ECollisionType::CirCle;
	int CollisionGroup = -1;
};

// �����е��� ������ �ϴ� ���
// enum class ContentsCollision
// {
//     PlayerBody,
//     PlayerAttack,
//	   MonsterBody,
//     MonsterAttack,
// }

// ��κ��� �浹 �Լ����� �̿� ���� �����ִ� �Լ��� �����ϰų� 
// ���������� GUI�� ������ ��� �մϴ�.
// void SetCollisionGroupCheck(ContentsCollision::PlayerBody, ContentsCollision::MonsterAttack);


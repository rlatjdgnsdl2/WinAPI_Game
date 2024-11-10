#include "PreCompile.h"
#include "EngineMath.h"

const FVector2D FVector2D::ZERO = { 0, 0 };
const FVector2D FVector2D::LEFT = { -1, 0 };
const FVector2D FVector2D::RIGHT = { 1, 0 };
const FVector2D FVector2D::UP = { 0, -1 };
const FVector2D FVector2D::DOWN = { 0, 1 };

const FIntPoint FIntPoint::LEFT = { -1, 0 };
const FIntPoint FIntPoint::RIGHT = { 1, 0 };
const FIntPoint FIntPoint::UP = { 0, -1 };
const FIntPoint FIntPoint::DOWN = { 0, 1 };

const UColor UColor::WHITE = { 255, 255, 255, 0 };
const UColor UColor::BLACK = { 0, 0, 0, 0 };

FVector2D FVector2D::LerpClamp(FVector2D _StartLocation, FVector2D _TargetLocation, float _t)
{
	if (0.0f > _t) { _t = 0.0f; }
	if (1.0F < _t) { _t = 1.0f; }
	return FVector2D(
		_StartLocation.X + _t * (_TargetLocation.X - _StartLocation.X),
		_StartLocation.Y + _t * (_TargetLocation.Y - _StartLocation.Y));
}

FVector2D FVector2D::Normalize(FVector2D _Value)
{
	_Value.Normalize();
	return _Value;
}

void FVector2D::Normalize()
{
	float Len = Length();
	if (0.0f < Len && false == isnan(Len))
	{
		X = X / Len;
		Y = Y / Len;
	}
	return;
}

// FTransform Ŭ������ �浹 �Լ� �迭�� ����
std::function<bool(const FTransform&, const FTransform&)> FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::Max)][static_cast<int>(ECollisionType::Max)];

class CollisionFunctionInit
{
public:
	CollisionFunctionInit()
	{
		//CollisionFunctionInit ��ü�� �����ɶ� 
		FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::Rect)][static_cast<int>(ECollisionType::Rect)] = FTransform::IsRectToRect;
		FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::CirCle)][static_cast<int>(ECollisionType::CirCle)] = FTransform::IsCircleToCircle;
	}
};

// CollisionFunctionInit �ν��Ͻ� ���� (���� �ʱ�ȭ)
CollisionFunctionInit Inst = CollisionFunctionInit();


bool FTransform::IsCollision(ECollisionType _LeftType, const FTransform& _Left, ECollisionType _RightType, const FTransform& _Right)
{
	// �浹 �Լ� �迭���� ������ �Լ��� ȣ���Ͽ� ��� ��ȯ
	return FTransform::AllCollisionFunction[static_cast<int>(_LeftType)][static_cast<int>(_RightType)](_Left, _Right);
}


bool FTransform::IsCircleToCircle(const FTransform& _Left, const FTransform& _Right)
{
	FVector2D Len = _Left.Location - _Right.Location;
	// �� �������� �պ��� �߽� �Ÿ��� ª���� �浹
	if (Len.Length() < _Left.Scale.hX() + _Right.Scale.hX())
	{
		return true;
	}
	return false;
}

bool FTransform::IsRectToRect(const FTransform& _Left, const FTransform& _Right)
{
	// �� �簢���� �ٸ� �簢���� ��踦 ����� �浹���� ����
	if (_Left.CenterLeft() > _Right.CenterRight())
	{
		return false;
	}

	if (_Left.CenterRight() < _Right.CenterLeft())
	{
		return false;
	}

	if (_Left.CenterTop() > _Right.CenterBottom())
	{
		return false;
	}

	if (_Left.CenterBottom() < _Right.CenterTop())
	{
		return false;
	}
	// �� ������ ��� �������� ������ �浹
	return true;
}




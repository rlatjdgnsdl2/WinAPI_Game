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

std::function<bool(const FTransform&, const FTransform&)> FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::Max)][static_cast<int>(ECollisionType::Max)];

class CollisionFunctionInit
{
public:
	CollisionFunctionInit()
	{
		FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::Rect)][static_cast<int>(ECollisionType::Rect)] = FTransform::RectToRect;
		FTransform::AllCollisionFunction[static_cast<int>(ECollisionType::CirCle)][static_cast<int>(ECollisionType::CirCle)] = FTransform::CircleToCircle;
	}
};
//	데이터영역
CollisionFunctionInit Inst = CollisionFunctionInit();


bool FTransform::Collision(ECollisionType _LeftType, const FTransform& _Left, ECollisionType _RightType, const FTransform& _Right)
{
	return FTransform::AllCollisionFunction[static_cast<int>(_LeftType)][static_cast<int>(_RightType)](_Left, _Right);
}


bool FTransform::CircleToCircle(const FTransform& _Left, const FTransform& _Right)
{
	FVector2D Len = _Left.Location - _Right.Location;
	if (Len.Length() < _Left.Scale.hX() + _Right.Scale.hX())
	{
		return true;
	}

	return false;
}

bool FTransform::RectToRect(const FTransform& _Left, const FTransform& _Right)
{

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
	// 공식 만들면 된다.
	return true;
}




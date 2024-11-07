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

FVector2D FVector2D::LerpClamp(const FVector2D& _StartLocation, const FVector2D& _TargetLocation, float _t)
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




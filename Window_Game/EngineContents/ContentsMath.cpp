#include "PreCompile.h"
#include "ContentsMath.h"





DIR UContentsMath::FIntPoint_To_DIR(const FIntPoint& _FIntPoint) {
	if (_FIntPoint.X < 0 && _FIntPoint.Y == 0) {
		return DIR::Left;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y == 0) {
		return DIR::Right;
	}
	else if (_FIntPoint.X == 0 && _FIntPoint.Y < 0) {
		return  DIR::Up;
	}
	else if (_FIntPoint.X == 0 && _FIntPoint.Y > 0) {
		return DIR::Down;
	}
	else if (_FIntPoint.X < 0 && _FIntPoint.Y < 0) {
		return  DIR::Left_Up;
	}
	else if (_FIntPoint.X < 0 && _FIntPoint.Y > 0) {
		return  DIR::Left_Down;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y < 0) {
		return  DIR::Right_Up;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y > 0) {
		return  DIR::Right_Down;
	}
}
DIR UContentsMath::FVector2D_To_DIR(const FVector2D& _FVector2D) {
	if (_FVector2D.X < 0 && _FVector2D.Y == 0) {
		return DIR::Left;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y == 0) {
		return DIR::Right;
	}
	else if (_FVector2D.X == 0 && _FVector2D.Y < 0) {
		return  DIR::Up;
	}
	else if (_FVector2D.X == 0 && _FVector2D.Y > 0) {
		return DIR::Down;
	}
	else if (_FVector2D.X < 0 && _FVector2D.Y < 0) {
		return  DIR::Left_Up;
	}
	else if (_FVector2D.X < 0 && _FVector2D.Y > 0) {
		return  DIR::Left_Down;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y < 0) {
		return  DIR::Right_Up;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y > 0) {
		return  DIR::Right_Down;
	}
}

FVector2D UContentsMath::DIR_To_Vector2D(DIR _Dir) {
	switch (_Dir)
	{
	case DIR::Left_Down:
		return FVector2D::LEFT + FVector2D::DOWN;
		break;
	case DIR::Down:
		return FVector2D::DOWN;
		break;
	case DIR::Right_Down:
		return FVector2D::RIGHT + FVector2D::DOWN;
		break;
	case DIR::Left:
		return FVector2D::LEFT;
		break;
	case DIR::Right:
		return FVector2D::RIGHT;
		break;
	case DIR::Left_Up:
		return FVector2D::LEFT + FVector2D::UP;
		break;
	case DIR::Up:
		return FVector2D::UP;
		break;
	case DIR::Right_Up:
		return FVector2D::RIGHT + FVector2D::UP;
		break;
	default:
		return FVector2D::ZERO;
		break;
	}
}
FIntPoint UContentsMath::DIR_To_FIntPoint(DIR _Dir) {
	switch (_Dir)
	{
	case DIR::Left_Down:
		return FIntPoint::LEFT + FIntPoint::DOWN;
		break;
	case DIR::Down:
		return FIntPoint::DOWN;
		break;
	case DIR::Right_Down:
		return FIntPoint::RIGHT + FIntPoint::DOWN;
		break;
	case DIR::Left:
		return FIntPoint::LEFT;
		break;
	case DIR::Right:
		return FIntPoint::RIGHT;
		break;
	case DIR::Left_Up:
		return FIntPoint::LEFT + FIntPoint::UP;
		break;
	case DIR::Up:
		return FIntPoint::UP;
		break;
	case DIR::Right_Up:
		return FIntPoint::RIGHT + FIntPoint::UP;
		break;
	default:
		break;
	}
}

DIR UContentsMath::ReverseDir(DIR _Dir)
{
	switch (_Dir)
	{
	case DIR::Left_Down:
		return DIR::Right_Up;
		break;
	case DIR::Down:
		return DIR::Up;
		break;
	case DIR::Right_Down:
		return DIR::Left_Up;
		break;
	case DIR::Left:
		return DIR::Right;
		break;
	case DIR::Right:
		return DIR::Left;
		break;
	case DIR::Left_Up:
		return DIR::Right_Down;
		break;
	case DIR::Up:
		return DIR::Down;
		break;
	case DIR::Right_Up:
		return DIR::Left_Down;
		break;
	default:
		break;
	}
}

#include "PreCompile.h"
#include "ContentsMath.h"





DIR UContentsMath::FIntPoint_To_DIR(const FIntPoint& _FIntPoint) {
	DIR Dir = DIR::None;
	if (_FIntPoint.X < 0 && _FIntPoint.Y == 0) {
		Dir = DIR::Left;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y == 0) {
		Dir = DIR::Right;
	}
	else if (_FIntPoint.X == 0 && _FIntPoint.Y < 0) {
		Dir = DIR::Up;
	}
	else if (_FIntPoint.X == 0 && _FIntPoint.Y > 0) {
		Dir = DIR::Down;
	}
	else if (_FIntPoint.X < 0 && _FIntPoint.Y < 0) {
		Dir = DIR::Left_Up;
	}
	else if (_FIntPoint.X < 0 && _FIntPoint.Y > 0) {
		Dir = DIR::Left_Down;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y < 0) {
		Dir = DIR::Right_Up;
	}
	else if (_FIntPoint.X > 0 && _FIntPoint.Y > 0) {
		Dir = DIR::Right_Down;
	}
	return Dir;

}
DIR UContentsMath::FVector2D_To_DIR(const FVector2D& _FVector2D) {
	DIR Dir = DIR::None;
	if (_FVector2D.X < 0 && _FVector2D.Y == 0) {
		Dir = DIR::Left;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y == 0) {
		Dir = DIR::Right;
	}
	else if (_FVector2D.X == 0 && _FVector2D.Y < 0) {
		Dir = DIR::Up;
	}
	else if (_FVector2D.X == 0 && _FVector2D.Y > 0) {
		Dir = DIR::Down;
	}
	else if (_FVector2D.X < 0 && _FVector2D.Y < 0) {
		Dir = DIR::Left_Up;
	}
	else if (_FVector2D.X < 0 && _FVector2D.Y > 0) {
		Dir = DIR::Left_Down;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y < 0) {
		Dir = DIR::Right_Up;
	}
	else if (_FVector2D.X > 0 && _FVector2D.Y > 0) {
		Dir = DIR::Right_Down;
	}
	return Dir;
}

FVector2D UContentsMath::DIR_To_FVector2D(DIR _Dir) {
	FVector2D Dir = FVector2D::ZERO;
	switch (_Dir)
	{
	case DIR::Left_Down:
		Dir = FVector2D::LEFT + FVector2D::DOWN;
		break;
	case DIR::Down:
		Dir = FVector2D::DOWN;
		break;
	case DIR::Right_Down:
		Dir = FVector2D::RIGHT + FVector2D::DOWN;
		break;
	case DIR::Left:
		Dir = FVector2D::LEFT;
		break;
	case DIR::Right:
		Dir = FVector2D::RIGHT;
		break;
	case DIR::Left_Up:
		Dir = FVector2D::LEFT + FVector2D::UP;
		break;
	case DIR::Up:
		Dir = FVector2D::UP;
		break;
	case DIR::Right_Up:
		Dir = FVector2D::RIGHT + FVector2D::UP;
		break;
	default:
		break;
	}
	return Dir;
}
FIntPoint UContentsMath::DIR_To_FIntPoint(DIR _Dir) {
	FIntPoint Dir = FIntPoint::ZERO;
	switch (_Dir)
	{
	case DIR::Left_Down:
		Dir= FIntPoint::LEFT + FIntPoint::DOWN;
		break;
	case DIR::Down:
		Dir = FIntPoint::DOWN;
		break;
	case DIR::Right_Down:
		Dir = FIntPoint::RIGHT + FIntPoint::DOWN;
		break;
	case DIR::Left:
		Dir =  FIntPoint::LEFT;
		break;
	case DIR::Right:
		Dir = FIntPoint::RIGHT;
		break;
	case DIR::Left_Up:
		Dir = FIntPoint::LEFT + FIntPoint::UP;
		break;
	case DIR::Up:
		Dir = FIntPoint::UP;
		break;
	case DIR::Right_Up:
		Dir = FIntPoint::RIGHT + FIntPoint::UP;
		break;
	default:
		break;
	}
	return Dir;
}

DIR UContentsMath::ReverseDir(DIR _Dir)
{
	DIR Dir = DIR::None;
	switch (_Dir)
	{
	case DIR::Left_Down:
		Dir = DIR::Right_Up;
		break;
	case DIR::Down:
		Dir = DIR::Up;
		break;
	case DIR::Right_Down:
		Dir = DIR::Left_Up;
		break;
	case DIR::Left:
		Dir = DIR::Right;
		break;
	case DIR::Right:
		Dir = DIR::Left;
		break;
	case DIR::Left_Up:
		Dir = DIR::Right_Down;
		break;
	case DIR::Up:
		Dir = DIR::Down;
		break;
	case DIR::Right_Up:
		Dir = DIR::Left_Down;
		break;
	default:
		break;
	}
	return Dir;
}

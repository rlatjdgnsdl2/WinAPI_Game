#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>




void APokemon::Move(float _DeltaTime)
{
	CurDuration += _DeltaTime;
	FVector2D NewLocation = FVector2D::LerpClamp(StartLocation, TargetLocation, CurDuration / 0.5f);
	SetActorLocation(NewLocation);
	SpriteRenderer->ChangeAnimation("WalkAnim_" + std::to_string(static_cast<int>(Dir)));
	SpriteRenderer->SetSpriteScale();
}



void APokemon::ResetCurDuration() {
	CurDuration = 0.0f;
}
//	Target
const FVector2D& APokemon::GetTargetLocation() const {
	return TargetLocation;
}
const FIntPoint APokemon::GetTargetTile() {
	return ((TargetLocation.ConvertToPoint()) / 72);
}
void APokemon::SetTargetLocation(const FVector2D& _TargetLocation) {
	TargetLocation = _TargetLocation;
	StartLocation = GetActorLocation();
}
void APokemon::SetTargetTile(const FIntPoint& _TargetTileIndex) {
	TargetLocation = _TargetTileIndex * 72.0f;
	StartLocation = GetActorLocation();
}

//	ÇöÀç
const FIntPoint APokemon::GetTile() {
	return ((GetActorLocation().ConvertToPoint()) / 72);
}
void APokemon::SetTile(FIntPoint& _CurTileIndex) {
	SetActorLocation(_CurTileIndex * 72.0f);
}
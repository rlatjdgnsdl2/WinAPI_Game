#include "PreCompile.h"
#include "Pokemon.h"
#include <EngineCore/SpriteRenderer.h>







//	ÀÌµ¿
const FVector2D& APokemon::GetTargetLocation() const {
	return TargetLocation;
};
const FIntPoint& APokemon::GetTargetTile() {
	return ((TargetLocation.ConvertToPoint()) / 72);
};

void APokemon::SetTargetLocation(const FVector2D& _TargetLocation) {
	TargetLocation = _TargetLocation;
	StartLocation = GetActor()->GetActorLocation();
};
void APokemon::SetTargetTile(const FIntPoint& _TargetTileIndex) {
	TargetLocation = _TargetTileIndex * 72.0f;
	StartLocation = GetActor()->GetActorLocation();
};


void APokemon::ResetCurDuration() {
	CurDuration = 0.0f;
}
#include "PreCompile.h"
#include "TempGameMode.h"
#include "TempActor.h"


ATempGameMode::ATempGameMode() {}

ATempGameMode::~ATempGameMode() {}

void ATempGameMode::BeginPlay()
{
	ATempActor* TempActor = GetWorld()->SpawnActor<ATempActor>();
}

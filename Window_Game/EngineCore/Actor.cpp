#include "PreCompile.h"
#include "Actor.h"
#include <EngineCore/EngineAPICore.h>


AActor::AActor() {}

AActor::~AActor() {}

//	юс╫ц
void AActor::Render()
{

	
	//                  100 100  - 50 50 => 50 50
	FVector2D LeftTop = Location - Scale.Half();
	//                  100 100  + 50 50 => 150 150
	FVector2D RightBot = Location + Scale.Half();


	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();

	
}

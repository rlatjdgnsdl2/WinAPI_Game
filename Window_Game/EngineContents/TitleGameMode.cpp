#include "PreCompile.h"
#include "TitleGameMode.h"

#include "TitleAnimActor.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/ImageManager.h>



ATitleGameMode::ATitleGameMode()
{
	UEngineDirectory TItle;
	TItle.MoveParentToDirectory("Resources");
	TItle.Append("Title");
	UImageManager::GetInst().LoadFolder(TItle.GetPathToString());

	
}

ATitleGameMode::~ATitleGameMode()
{

}





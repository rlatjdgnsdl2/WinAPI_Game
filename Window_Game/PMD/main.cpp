#include "PreCompile.h"
#include <EngineContents/PMDContentsCore.h>


#include <EngineCore/EngineAPICore.h>

#pragma comment (lib, "EngineCore.lib")
#pragma comment (lib, "EngineContents.lib")


#include <EngineBase/EngineTimer.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	PMDContentsCore User;
	return UEngineAPICore::EngineStart(hInstance, &User);
}
#include "PreCompile.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineContents/YoshiContentsCore.h>

#pragma comment (lib, "EngineCore.lib")
#pragma comment (lib, "EngineContents.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	YoshiContentsCore User;
	return UEngineAPICore::EngineStart(hInstance,&User); //	클라이언트 담당이 작성한 컨텐츠 엔진에 전달
}
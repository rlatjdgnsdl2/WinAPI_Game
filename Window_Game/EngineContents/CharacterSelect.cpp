#include "PreCompile.h"
#include "CharacterSelect.h"

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>

#include "Box.h"
#include "Text.h"
#include "BoxUI.h"
#include "GameDataManager.h"




ACharacterSelect::ACharacterSelect()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WindowSize.Half());
	std::vector<std::string> PlayerNames = {
	"Bulbasaur","Charmander","Chikorita","Chimchar","Cyndaquil","Eevee","Meowth",
	"Mudkip","Munchlax","Phanpy","Pikachu","Piplup","Riolu","Shinx",
	"Skitty","Squirtle","Torchic","Totodile","Treecko","Turtwig","Vulpix"
	};

	std::vector<FVector2D> Locations = {
		{-300, -200}, {-200, -200}, {-100, -200}, {0, -200}, {100, -200}, {200, -200}, {300, -200},
		{-300, -100}, {-200, -100}, {-100, -100}, {0, -100}, {100, -100}, {200, -100}, {300, -100},
		{-300, 0}, {-200, 0}, {-100, 0}, {0, 0}, {100, 0}, {200, 0}, {300, 0}
	};

	for (size_t i = 0; i < PlayerNames.size(); ++i) {
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite(PlayerNames[i] + ".png");
		SpriteRenderer->SetSpriteScale(0.5);
		SpriteRenderer->SetComponentLocation(Locations[i]);
		SpriteRenderer->SetOrder(ERenderOrder::UI_Image);
		PlayerCharacterImages.insert({ PlayerNames[i], SpriteRenderer });
	}
}

ACharacterSelect::~ACharacterSelect()
{

}

void ACharacterSelect::BeginPlay()
{
	Super::BeginPlay();
	CharacterTable = GetWorld()->SpawnActor<ABox>();
	CharacterTable->SetBoxSize({ 760,410 });
	CharacterTable->SetActorLocation({ 10,20 });
	CurIter = PlayerCharacterImages.begin();
	CurIter->second->SetSpriteScale(1.0f);

	CharacterName = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 600,100 }, { 100,450 }));
	CharacterName->CreateString("             " + CurIter->first,Color::Blue);

	//  설명
	ExplanationText01 = GetWorld()->SpawnActor<AText>();
	ExplanationText01->SetString("Select Your Pokemon to push Left or Right ", Color::White);
	ExplanationText01->SetActorLocation({ 100, 340 });
	ExplanationText01->ShowText(0.0f);

	ExplanationText02 = GetWorld()->SpawnActor<AText>();
	ExplanationText02->SetString("And push SPACE_BAR ", Color::White);
	ExplanationText02->SetActorLocation({ 100, 370 });
	ExplanationText02->ShowText(0.0f);


	GetWorld()->SetCameraToMainPawn(false);
}

void ACharacterSelect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));

	if (true == UEngineInput::GetInst().IsDown(VK_RIGHT)) {
		CurIter->second->SetSpriteScale(0.5f);
		CurIter++;
		if (CurIter == PlayerCharacterImages.end()) {
			CurIter = PlayerCharacterImages.begin();
		}
		CurIter->second->SetSpriteScale(1.0f);
		CharacterName->SetString("             "+CurIter->first, Color::Blue);
		CharacterName->ShowUI(0.0f);
	}

	if (true == UEngineInput::GetInst().IsDown(VK_LEFT)) {
		CurIter->second->SetSpriteScale(0.5f);
		if (CurIter == PlayerCharacterImages.begin()) {
			CurIter = PlayerCharacterImages.end();
		}
		CurIter--;
		CurIter->second->SetSpriteScale(1.0f);
		CharacterName->SetString("             " + CurIter->first, Color::Blue);
		CharacterName->ShowUI(0.0f);
	}
	if (true == UEngineInput::GetInst().IsDown(VK_UP)) {
		CurIter->second->SetSpriteScale(0.5f);
		for (int i = 0; i < 7; ++i) {
			if (CurIter == PlayerCharacterImages.begin()) {
				CurIter = PlayerCharacterImages.end();
			}
			CurIter--;
		}
		CurIter->second->SetSpriteScale(1.0f);
		CharacterName->SetString("             " + CurIter->first, Color::Blue);
		CharacterName->ShowUI(0.0f);
	}
	if (true == UEngineInput::GetInst().IsDown(VK_DOWN)) {
		CurIter->second->SetSpriteScale(0.5f);
		for (int i = 0; i < 7; ++i) {
			CurIter++;
			if (CurIter == PlayerCharacterImages.end()) {
				CurIter = PlayerCharacterImages.begin();
			}
		}
		CurIter->second->SetSpriteScale(1.0f);
		CharacterName->SetString("             " + CurIter->first, Color::Blue);
		CharacterName->ShowUI(0.0f);
	}



	if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
		std::string PlayerName = CurIter->first;
		UGameDataManager::GetInst().SetSelectPlayer(PlayerName);
		UGameDataManager::GetInst().InsertPlayerData(PlayerName,PlayerData(5) );
		//	임시
		std::string PartnerName = "Vulpix";
		UGameDataManager::GetInst().InsertPlayerData(PartnerName, PlayerData(5));
		UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");

	}
}

void ACharacterSelect::LevelChangeStart()
{
	Super::LevelChangeStart();
	CharacterName->ShowUI(0.0f);
}










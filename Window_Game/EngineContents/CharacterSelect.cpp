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
#include "Fade.h"
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

	CharacterName = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 440,100 }, { 330,450 }));
	CharacterName->CreateString("  " + CurIter->first, Color::Blue);

	SelectPokemon = GetWorld()->SpawnActor<ABoxUI>(FTransform({ 300,130 }, { 20,450 }));
	SelectPokemon->CreateString("Your Pokemon", Color::White);
	SelectPokemon->CreateString("Your Partner", Color::White);


	//  Ό³Έν
	ExplanationText01 = GetWorld()->SpawnActor<AText>();
	ExplanationText01->SetString("Press the direction key to select Your Pokemon", Color::White);
	ExplanationText01->SetActorLocation({ 60, 340 });
	ExplanationText01->ShowText(0.0f);

	ExplanationText02 = GetWorld()->SpawnActor<AText>();
	ExplanationText02->SetString("And Press SPACE_BAR ", Color::White);
	ExplanationText02->SetActorLocation({ 60, 370 });
	ExplanationText02->ShowText(0.0f);


	GetWorld()->SetCameraToMainPawn(false);
}

void ACharacterSelect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	/*FVector2D MousePos = UEngineAPICore::GetCore()->GetMainWindow().GetMousePos();
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.X));
	UEngineDebug::CoreOutPutString(std::to_string(MousePos.Y));*/


	if (IsNextLevel)
	{
		CurDuration += _DeltaTime;
		if (CurDuration > 2.0f) {
			UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");
		}
		return;
	}
	if (IsPlayerSelect && IsPartnerSelect)
	{
		if (UEngineInput::GetInst().IsDown(VK_SPACE)) {
			IsNextLevel = true;
			Fade->FadeIn();
			return;
		}

	}

	if (IsPartnerSelect == false || IsPlayerSelect == false)
	{
		if (true == UEngineInput::GetInst().IsDown(VK_RIGHT)) {
			CurIter->second->SetSpriteScale(0.5f);
			CurIter++;
			if (CurIter == PlayerCharacterImages.end()) {
				CurIter = PlayerCharacterImages.begin();
			}
			CurIter->second->SetSpriteScale(1.0f);
			CharacterName->SetString("  " + CurIter->first, Color::Blue);
			CharacterName->ShowUI(0.0f);
			return;
		}

		if (true == UEngineInput::GetInst().IsDown(VK_LEFT)) {
			CurIter->second->SetSpriteScale(0.5f);
			if (CurIter == PlayerCharacterImages.begin()) {
				CurIter = PlayerCharacterImages.end();
			}
			CurIter--;
			CurIter->second->SetSpriteScale(1.0f);
			CharacterName->SetString("  " + CurIter->first, Color::Blue);
			CharacterName->ShowUI(0.0f);
			return;
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
			CharacterName->SetString("  " + CurIter->first, Color::Blue);
			CharacterName->ShowUI(0.0f);
			return;
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
			CharacterName->SetString("  " + CurIter->first, Color::Blue);
			CharacterName->ShowUI(0.0f);
			return;
		}
	}

	if (!IsPlayerSelect) {
		if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
			PlayerName = CurIter->first;
			SelectPokemon->SetString(PlayerName, Color::Green, 0);
			SelectPokemon->ShowUI();
			UGameDataManager::GetInst().SetSelectPlayer(PlayerName);
			UGameDataManager::GetInst().InsertPlayerData(PlayerName, PlayerData(5));
			IsPlayerSelect = true;
			return;
		}
	}
	else if (IsPlayerSelect)
	{
		if (true == UEngineInput::GetInst().IsDown(VK_SPACE)) {
			PartnerName = CurIter->first;
			if (PlayerName == PartnerName)
			{
				CharacterName->SetString("Pick a different Pokemon ", Color::Yellow);
				CharacterName->ShowUI();
				return;
			}
			SelectPokemon->SetString(PartnerName, Color::Green, 1);
			SelectPokemon->ShowUI();
			CharacterName->SetString("Press SpaceBar", Color::Blue);
			CharacterName->ShowUI();
			UGameDataManager::GetInst().SetSelectPlayer(PartnerName);
			UGameDataManager::GetInst().InsertPlayerData(PartnerName, PlayerData(5));
			IsPartnerSelect = true;
			return;
		}
	}



}

void ACharacterSelect::LevelChangeStart()
{
	Super::LevelChangeStart();
	{
		AFade* Actor = GetWorld()->SpawnActor<AFade>();
		Actor->FadeOut();
		Fade = Actor;
	}

	CharacterName->ShowUI(0.0f);
	SelectPokemon->ShowUI(0.0f);
}

void ACharacterSelect::LevelChangeEnd()
{
	Super::LevelChangeEnd();
	IsPlayerSelect = false;
	IsPartnerSelect = false;
	IsNextLevel = false;
	CurDuration = 0.0f;
}












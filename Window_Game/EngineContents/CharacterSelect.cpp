#include "PreCompile.h"
#include "CharacterSelect.h"

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineAPICore.h>

#include "Box.h"
#include "Text.h"
#include "GameDataManager.h"




ACharacterSelect::ACharacterSelect()
{
	FVector2D WindowSize = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	SetActorLocation(WindowSize.Half());
	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Mudkip.png");
		SpriteRenderer->SetSpriteScale(0.5f);
		SpriteRenderer->SetComponentLocation({ -250,-150 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_Image);
		PlayerCharacterImages.insert({ "Mudkip",SpriteRenderer });
	}

	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Chikorita.png");
		SpriteRenderer->SetSpriteScale(0.5f);
		SpriteRenderer->SetComponentLocation({ -100,-150 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_Image);
		PlayerCharacterImages.insert({ "Chikorita",SpriteRenderer });
	}

	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Pikachu.png");
		SpriteRenderer->SetSpriteScale(0.5f);
		SpriteRenderer->SetComponentLocation({ 50,-150 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_Image);
		PlayerCharacterImages.insert({ "Pikachu",SpriteRenderer });
	}
}

ACharacterSelect::~ACharacterSelect()
{

}

void ACharacterSelect::BeginPlay()
{
	Super::BeginPlay();
	CharacterTable = GetWorld()->SpawnActor<ABox>();
	CharacterTable->SetBoxSize({ 700,500 });
	CharacterTable->SetActorLocation({ 30,30 });

	Mudkip_Text = GetWorld()->SpawnActor<AText>();
	Mudkip_Text->SetString("Mudkip",TextColor::Blue);
	Mudkip_Text->SetActorLocation({ 100, 200 });
	Mudkip_Text->ShowText(0.0f);

	Chikorita_Text = GetWorld()->SpawnActor<AText>();
	Chikorita_Text->SetString("Chikorita", TextColor::Green);
	Chikorita_Text->SetActorLocation({ 230, 200 });
	Chikorita_Text->ShowText(0.0f);

	Pikachu_Text = GetWorld()->SpawnActor<AText>();
	Pikachu_Text->SetString("Pikachu",TextColor::Yellow);
	Pikachu_Text->SetActorLocation({ 400, 200 });
	Pikachu_Text->ShowText(0.0f);


	//  설명
	ExplanationText01 = GetWorld()->SpawnActor<AText>();
	ExplanationText01->SetString("Select Your Pokemon to push Left or Right ", TextColor::White);
	ExplanationText01->SetActorLocation({ 100, 440 });
	ExplanationText01->ShowText(0.0f);

	ExplanationText02 = GetWorld()->SpawnActor<AText>();
	ExplanationText02->SetString("And push SPACE_BAR ", TextColor::White);
	ExplanationText02->SetActorLocation({ 100, 470 });
	ExplanationText02->ShowText(0.0f);


	GetWorld()->SetCameraToMainPawn(false);
	CurIter = PlayerCharacterImages.begin();
	CurIter->second->SetSpriteScale(1.0f);
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
	}

	if (true == UEngineInput::GetInst().IsDown(VK_LEFT)) {
		CurIter->second->SetSpriteScale(0.5f);
		if (CurIter == PlayerCharacterImages.begin()) {
			CurIter = PlayerCharacterImages.end();
		}
		CurIter--;
		CurIter->second->SetSpriteScale(1.0f);
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










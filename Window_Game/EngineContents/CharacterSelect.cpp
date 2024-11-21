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
		SpriteRenderer->SetComponentLocation({ -200,0 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_IMAGE);
		PlayerCharacterImages.insert({ "Mudkip",SpriteRenderer });
	}

	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Chikorita.png");
		SpriteRenderer->SetSpriteScale(0.5f);
		SpriteRenderer->SetComponentLocation({ 0,0 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_IMAGE);
		PlayerCharacterImages.insert({ "Chikorita",SpriteRenderer });
	}

	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetSprite("Pikachu.png");
		SpriteRenderer->SetSpriteScale(0.5f);
		SpriteRenderer->SetComponentLocation({ 200,0 });
		SpriteRenderer->SetOrder(ERenderOrder::UI_IMAGE);
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
	CharacterTable->SetBoxSize({ 650,300 });
	CharacterTable->SetActorLocation({ 80,170 });

	Mudkip_Text = GetWorld()->SpawnActor<AText>();
	Mudkip_Text->SetString("Mudkip","Blue");
	Mudkip_Text->SetActorLocation({ 140, 350 });
	Mudkip_Text->ShowText(0.0f);

	Chikorita_Text = GetWorld()->SpawnActor<AText>();
	Chikorita_Text->SetString("Chikorita","Green");
	Chikorita_Text->SetActorLocation({ 340, 350 });
	Chikorita_Text->ShowText(0.0f);

	Pikachu_Text = GetWorld()->SpawnActor<AText>();
	Pikachu_Text->SetString("Pikachu","Yellow");
	Pikachu_Text->SetActorLocation({ 540, 350 });
	Pikachu_Text->ShowText(0.0f);

	ExplanationText01 = GetWorld()->SpawnActor<AText>();
	ExplanationText01->SetString("Select Your Pokemon to push A or D ", "White");
	ExplanationText01->SetActorLocation({ 140, 380 });
	ExplanationText01->ShowText(0.0f);

	ExplanationText02 = GetWorld()->SpawnActor<AText>();
	ExplanationText02->SetString("And push SPACE_BAR ", "White");
	ExplanationText02->SetActorLocation({ 140, 410 });
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


	if (true == UEngineInput::GetInst().IsDown('D')) {
		CurIter->second->SetSpriteScale(0.5f);
		CurIter++;
		if (CurIter == PlayerCharacterImages.end()) {
			CurIter = PlayerCharacterImages.begin();
		}
		CurIter->second->SetSpriteScale(1.0f);
	}

	if (true == UEngineInput::GetInst().IsDown('A')) {
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
		UGameDataManager::GetInst().InsertPlayerAbility(PlayerName, PokemonInfo( 5, 45, 20, 15));
		//	юс╫ц
		std::string PartnerName = "Vulpix";
		UGameDataManager::GetInst().InsertPlayerAbility(PartnerName, PokemonInfo( 5, 45, 20, 15));
		UEngineAPICore::GetCore()->OpenLevel("DungeonSelectLevel");

	}
}










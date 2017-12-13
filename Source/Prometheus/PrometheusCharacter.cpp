// Fill out your copyright notice in the Description page of Project Settings.

#include "PrometheusCharacter.h"

#include "MyGameStateBase.h"
#include "Torch.h"

#include "Components/PointLightComponent.h"
#include "Public/TimerManager.h"

// Sets default values
APrometheusCharacter::APrometheusCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrometheusLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PrometheusLight"));
	PrometheusLight->SetupAttachment(RootComponent);
	PrometheusLight->SetIntensity(MaxPrometheusLightLevel);
}

// Called when the game starts or when spawned
void APrometheusCharacter::BeginPlay()
{
	Super::BeginPlay();
	ResetLightTimer();
}

float APrometheusCharacter::GetLightPercent() {
	auto lightPercent = GetWorldTimerManager().GetTimerRemaining(PrometheusTimerHandle) / MaxLightTime;
	return (lightPercent > 0) ? lightPercent : 0.0f;
}

bool APrometheusCharacter::HasLightLeft() {
	return GetWorldTimerManager().GetTimerRemaining(PrometheusTimerHandle) > 0;
}

void APrometheusCharacter::TouchedTorch() {
	PrometheusLight->SetIntensity(MaxPrometheusLightLevel);
	ResetLightTimer();
}

void APrometheusCharacter::HitByMoth() {
	UE_LOG(LogTemp, Warning, TEXT("Hit moth!"))
	float timerRemaining = GetWorldTimerManager().GetTimerRemaining(PrometheusTimerHandle);
	const float damageAmountToTimer = 2.0f;
	if (timerRemaining <= damageAmountToTimer) {
		UE_LOG(LogTemp, Warning, TEXT("LOST ALL LIGHT"))
		GetWorldTimerManager().ClearTimer(PrometheusTimerHandle);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Losing light!  Was %f, is now %f"), timerRemaining, (timerRemaining - damageAmountToTimer))
		GetWorldTimerManager().SetTimer(PrometheusTimerHandle, this, &APrometheusCharacter::LightsOut, timerRemaining - damageAmountToTimer, false);
	}
}

bool APrometheusCharacter::HitByCrow() {
	UE_LOG(LogTemp, Warning, TEXT("Hit crow!"))
	float remainingLightPercent = GetLightPercent();
	UE_LOG(LogTemp, Warning, TEXT("Light remaining: %f"), remainingLightPercent)
	if (remainingLightPercent > .75) {
		return true;
	}
	else if (remainingLightPercent < 0.001) {
		TeleportPlayerToLastTouchedTorch();
	}
	return false;
}

// Called every frame
void APrometheusCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PrometheusLight) {
		float timerMultipler = GetWorldTimerManager().GetTimerRemaining(PrometheusTimerHandle) / MaxLightTime;
		if (timerMultipler < 0) timerMultipler = 0;
		float newIntensity = MaxPrometheusLightLevel * timerMultipler;
		PrometheusLight->SetIntensity(newIntensity);
		
	}
}

// Called to bind functionality to input
void APrometheusCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APrometheusCharacter::ResetLightTimer() {
	GetWorldTimerManager().SetTimer(PrometheusTimerHandle, this, &APrometheusCharacter::LightsOut, MaxLightTime, false);
}

void APrometheusCharacter::TeleportPlayerToLastTouchedTorch() {
	AMyGameStateBase* currentGameState = Cast<AMyGameStateBase>(GetWorld()->GetGameState());
	if (currentGameState) {
		TeleportTo(currentGameState->GetLastTorchTouched()->GetActorLocation(), FRotator(0,0,0));
		ResetLightTimer();
	} else {
		UE_LOG(LogTemp, Warning, TEXT("We have an unexpected game state or the game state is missing!"))
	}
}

void APrometheusCharacter::LightsOut() {
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "PrometheusCharacter.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Hit!"))
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

// Called every frame
void APrometheusCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("DamageAmount=%f, DamageToApply=%f"), DamageAmount, DamageToApply)
	//UE_LOG(LogTemp, Warning, TEXT("Ticking... "))
	if (PrometheusLight) {
		float timerMultipler = GetWorldTimerManager().GetTimerRemaining(PrometheusTimerHandle) / MaxLightTime;
		if (timerMultipler < 0) timerMultipler = 0;
		float newIntensity = MaxPrometheusLightLevel * timerMultipler;
		//UE_LOG(LogTemp, Warning, TEXT("timerMultipler=%f, intensity=%f"), timerMultipler, newIntensity)
		PrometheusLight->SetIntensity(newIntensity);
	}
	
}

// Called to bind functionality to input
void APrometheusCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APrometheusCharacter::ResetLightTimer() {
	//UE_LOG(LogTemp, Warning, TEXT("RESET LIGHT TIMER!"))
	GetWorldTimerManager().SetTimer(PrometheusTimerHandle, this, &APrometheusCharacter::LightsOut, MaxLightTime, false);
}

void APrometheusCharacter::LightsOut() {
}
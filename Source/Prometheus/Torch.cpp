// Fill out your copyright notice in the Description page of Project Settings.

#include "Torch.h"

#include "Components/PointLightComponent.h"

// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	PrometheusLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PrometheusLight"));
	PrometheusLight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATorch::BeginPlay()
{
	Super::BeginPlay();
	if (IsLit) {
		PrometheusLight->SetIntensity(MaxPrometheusLightLevel);
	}
	else {
		PrometheusLight->SetIntensity(0);
	}
}

bool ATorch::IsTorchLit() {
	return IsLit;
}

void ATorch::SetTorchLit(bool lit) {
	IsLit = lit;
	if (lit) {
		PrometheusLight->SetIntensity(MaxPrometheusLightLevel);
	}
	else {
		PrometheusLight->SetIntensity(0);
	}
}

//// Called every frame
//void ATorch::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}


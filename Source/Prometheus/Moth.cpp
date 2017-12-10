// Fill out your copyright notice in the Description page of Project Settings.

#include "Moth.h"

#include "PrometheusCharacter.h"

// Sets default values
AMoth::AMoth()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoth::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMoth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMoth::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void AMoth::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Calling..."))
//	if (OtherActor->IsA(APrometheusCharacter::StaticClass())) {
//		UE_LOG(LogTemp, Warning, TEXT("Ran into the player, trying to dock their light."))
//		APrometheusCharacter* player = Cast<APrometheusCharacter>(OtherActor);
//		if (player) {
//			player->HitByMoth();
//		}
//		else {
//			UE_LOG(LogTemp, Warning, TEXT("Something went very wrong.  Found the player but then was unable to access it."))
//		}
//	}
//	else {
//		UE_LOG(LogTemp, Warning, TEXT("Ran into something that isn't the player, ignoring."))
//	}
//}

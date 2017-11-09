// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PrometheusCharacter.generated.h"

UCLASS()
class PROMETHEUS_API APrometheusCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APrometheusCharacter();

	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	class UPointLightComponent* PrometheusLight;

	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	float MaxPrometheusLightLevel = 2500.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	float MaxLightTime = 10.0f;

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	float GetLightPercent();

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	bool HasLightLeft();

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	void TouchedTorch();

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	void ResetLightTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void LightsOut();

private:

	FTimerHandle PrometheusTimerHandle;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Torch.generated.h"

UCLASS()
class PROMETHEUS_API ATorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
//	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Prometheus")
	bool IsLit = false;

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	bool IsTorchLit();

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	void SetTorchLit(bool lit);

	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	float MaxPrometheusLightLevel = 2500.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	class UPointLightComponent* PrometheusLight;

};

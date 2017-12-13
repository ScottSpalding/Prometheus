// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PROMETHEUS_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	class ATorch* GetLastTorchTouched();
	UFUNCTION(BlueprintCallable, Category = "Prometheus")
	void SetLastTorchTouched(ATorch* torch);
	UPROPERTY(EditDefaultsOnly, Category = "Prometheus")
	ATorch* LastTorchTouched;
	
};

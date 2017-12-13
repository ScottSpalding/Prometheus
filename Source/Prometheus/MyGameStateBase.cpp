// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameStateBase.h"




class ATorch* AMyGameStateBase::GetLastTorchTouched() {
	return LastTorchTouched;
}


void AMyGameStateBase::SetLastTorchTouched(ATorch* torch) {
	LastTorchTouched = torch;
}
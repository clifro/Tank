// Fill out your copyright notice in the Description page of Project Settings.


#include "TAPlayerState.h"

void ATAPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	//Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATAPlayerState, Owner);
	DOREPLIFETIME(ATAPlayerState, PlayerScore);
}
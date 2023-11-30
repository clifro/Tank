// Fill out your copyright notice in the Description page of Project Settings.


#include "TAGameState.h"

void ATAGameState::UpdateScore(FName PlayerID)
{
	for (FScoreData data : PlayerScores)
	{
		if (data.PlayerID == PlayerID)
		{
			data.Score = data.Score + 1;
			return;
		}
	}

	FScoreData playerData{};
	playerData.PlayerID = PlayerID;
	playerData.Score = 0;
}
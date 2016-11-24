#pragma once;
#include "FBullCowGame.h";

//public methods
FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const
{ 
	return MyCurrentTry; 
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxtries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };
	return WordLengthToMaxtries[GetHiddenWordLength()];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!DoesLengthEqualsToHiddenWordLength(Guess))
	{
		return EGuessStatus::Wrong_Length;
	}
	if (!AreAllLettersLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	if (HasRepeatingLetters(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}

	return EGuessStatus::OK;
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "plane"; //has to be isogram and all lowercase

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	int32 WordLength = GetHiddenWordLength(); //assuming same length as guess

	FBullCowCount BullCowCount;

	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++) 
		{
			if (Guess[i] == MyHiddenWord[j]) 
			{
				if (i == j) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (WordLength == BullCowCount.Bulls)
	{
		bGameIsWon = true;
	}

	return BullCowCount;
}

//private methods
bool FBullCowGame::HasRepeatingLetters(FString Word) const
{
	TMap<char, bool> LetterSeen;
	
	for (char Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return true;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return false;
}

bool FBullCowGame::AreAllLettersLowercase(FString Word) const
{
	for (char Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}

bool FBullCowGame::DoesLengthEqualsToHiddenWordLength(FString Word) const
{
	return Word.length() == GetHiddenWordLength();
}

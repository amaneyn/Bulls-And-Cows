#pragma once;

#include <iostream>;
#include <string>;
#include "FBullCowGame.h";


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
FText GetUserInput();
void PrintBullCowCount(FBullCowCount);
void PrintGameSummary();
bool AskToPlayAgain();

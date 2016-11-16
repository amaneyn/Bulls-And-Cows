#pragma once
#include <string>

class FBullCowGame
{

public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsGuessValid(std::string);



private:
	int MyCurrentTry;
	int MyMaxTries = 3;
};
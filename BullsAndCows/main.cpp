#include "main.h";

FBullCowGame BCGame;

int main()
{
	do
	{
		system("cls");
		PrintIntro();
		PlayGame();
	}
	while(AskToPlayAgain());

	std::cout << "Bye bye!" << std::endl;

	return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		PrintBullCowCount(BullCowCount);
	}
	PrintGameSummary();

	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::Invalid;

	do
	{
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		Guess = GetUserInput();
		GuessStatus = BCGame.CheckGuessValidity(Guess);
		switch (GuessStatus)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Guess length must be " << BCGame.GetHiddenWordLength() << "." << std::endl << std::endl;
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Guess mustn't have repeating letters." << std::endl << std::endl;
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "All letters of the guess must be lowercase." << std::endl << std::endl;
				break;
			default:
				break;
		}
	}
	while (GuessStatus != EGuessStatus::OK);

	return Guess;
}

FText GetUserInput()
{
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintBullCowCount(FBullCowCount BullCowCount)
{
	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else
	{
		std::cout << "Better luck next time!" << std::endl;
	}

	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n) ";
	FText response = GetUserInput();

	bool WantsToPlayAgain = false;

	if (response[0] == 'y' || response[0] == 'Y')
	{
		WantsToPlayAgain = true;
	}

	return WantsToPlayAgain;
}

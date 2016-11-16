#include "main.h";
#include "FBullCowGame.h";

int main()
{
	do
	{
		system("cls");
		system("color 0A");
		PrintIntro();
		PlayGame();
	}
	while(AskToPlayAgain());

	PrintOutro();

	return 0;
}


void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	FBullCowGame BCGame;
	int MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;

	for (int i = 1; i <= MaxTries; i++)
	{
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
}

std::string GetGuess()
{
	std::cout << "Enter your guess: ";
	std::string Guess = GetUserInput();
	return Guess;
}

std::string GetUserInput()
{
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string response = GetUserInput();

	bool WantsToPlayAgain = false;

	if (response[0] == 'y' || response[0] == 'Y')
	{
		WantsToPlayAgain = true;
	}

	return WantsToPlayAgain;
}

void PrintOutro()
{
	std::cout << "Bye bye!" << std::endl;
	//std::cin.ignore();
}
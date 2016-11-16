#include <iostream>;
#include <string>;

using namespace std;

void PlayGame();
void PrintIntro();
string GetGuess();
string GetUserInput();
void PrintGuess(string Guess);

int main()
{
	PrintIntro();
	PlayGame();
	return 0;
}

void PlayGame()
{
	string Guess = "";
	constexpr int NUMBER_OF_TURNS = 5;

	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		Guess = GetGuess();
		PrintGuess(Guess);
	}
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game!" << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?" << endl;
	cout << endl;

	return;
}

string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = GetUserInput();
	return Guess;
}

string GetUserInput()
{
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

void PrintGuess(string Guess)
{
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return;
}
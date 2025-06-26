#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string playername;
char range, choice;
int random, guess, tries;
bool win = false;

void getrange();
void playgame();
int main() {
	srand(time(0));
	cout << "Welcome to the Random Number Guessing Game!" << endl;
	cout << "Enter your name: ";
	getline(cin, playername, '\n');
	cout << "Hello, " << playername << "! Let's start the game." << endl;
	do {
		getrange();
		cout << "Game Started! You have " << tries << " tries to guess the number." << endl;
		playgame();
		if (win == false)
		{
			cout << "Sorry, " << playername << ". You've used all your tries. The number was " << random << "." << endl;
		}
		if (win == true)
		{
			cout << "CONGRATULATIONS! \n";
			cout << playername << "! You guessed the number " << random << " correctly!" << endl;
		}
		cout << "Do you want to play again? (y/n): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	return 0;
}

void getrange()
{
	cout << "Enter the range for the game\n";
	cout << "1. 1-5  \n";
	cout << "2. 1 - 10\n";
	cout << "3. 1 - 50\n";
	cout << "4. 1 - 100\n";
	cin >> range;
	if (range == '1')
	{
		random = rand() % 5 + 1;
		tries = 3;
	}
	else if (range == '2')
	{
		random = rand() % 10 + 1;
		tries = 3;
	}
	else if (range == '3')
	{
		random = rand() % 50 + 1;
		tries = 5;
	}
	else if (range == '4')
	{
		random = rand() % 100 + 1;
		tries = 5;
	}
	else
	{
		cout << "Invalid range selected." << endl;
		cout << "Range selected from 1-100\n";
		random = rand() % 100 + 1;
		tries = 5;
	}
}
void playgame()
{
	win = false;
	while (tries > 0)
	{
		cout << "enter your guess: ";
		cin >> guess;
		if (guess > random)
		{
			cout << "guess too high........Try again\n";
		}
		else if (guess < random)
		{
			cout << "guess too low........Try again\n";
		}
		else if (guess == random)
		{
			win = true;
			break;
			return;
		}
		tries--;
		cout << "Number of tries left: " << tries << endl;
	}
	return;

}
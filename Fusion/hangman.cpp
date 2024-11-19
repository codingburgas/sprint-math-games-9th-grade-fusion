
#include "hangman.h"


#define MAX_ATTEMPTS 6 

using namespace std;


class HangmanGame {
public:
	// constructor to ini 
	HangmanGame()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		secretWord = getRandomWord();
		currentWord = string(secretWord.length(), '_');
		attemptsLeft = MAX_ATTEMPTS;
	}

	void play()
	{
		cout << "!!! Welcome to Hangman !!! " << endl;
		
		cout << "You have " << attemptsLeft
			<< " attempts to guess the word"
			<< endl;

	
		while (attemptsLeft > 0) {
			displayGameInfo();
			char guess;
			cout << "Guess a letter: ";
			cin >> guess;

			if (isalpha(guess)) {
				guess = tolower(guess);
				if (alreadyGuessed(guess)) {
					system("cls");
				drawHangman(attemptsLeft);
				}
				else {
					bool correctGuess
						= updateCurrentWord(guess);
					
					if (correctGuess) {
						cout << "Good guess!" << endl;
						system("cls");
						drawHangman(attemptsLeft);
						 
						if (currentWord == secretWord) {
							displayGameInfo();
							cout << "Congratulations! You "
								"guessed the word: "
								<< secretWord << endl;
							return;
						}
					}
					else {
						cout << "Incorrect guess." << endl;
						attemptsLeft--;
						system("cls");
						drawHangman(attemptsLeft);
					}
				}
			}
			else {
				cout << "Please enter a valid letter."
					<< endl;
			}
		}

		if (attemptsLeft == 0) {
			displayGameInfo();
			cout << "You've run out of attempts. The word "
				"was: "
				<< secretWord << endl;
			cout << endl;
		}
	}

private:
	string secretWord;
	string currentWord;
	int attemptsLeft;
	vector<char> guessedLetters;

	
	string getRandomWord()
	{
		vector<string> words
			= { "apple", "banana", "cherry", "grape","kiwi","apple", "book",  "case", "child", "company", "country", "day", "eye", "fact", "family", "group", "hand", "home", "job", "life", "lot", "man", "money", "month", "mother",  "night", "number", "part", "people", "place", "point", "problem", "program", "question", "right", "room", "school", "state", "story", "student", "study", "system", "thing", "time", "water", "way", "week", "woman", "word", "work", "world", "year"};
		int index = rand() % words.size();
		return words[index];
	}

	bool alreadyGuessed(char letter)
	{
		return find(guessedLetters.begin(),
			guessedLetters.end(), letter)
			!= guessedLetters.end();
	}

	bool updateCurrentWord(char letter)
	{
		bool correctGuess = false;
		for (int i = 0; i < secretWord.length(); i++) {
			if (secretWord[i] == letter) {
				currentWord[i] = letter;
				correctGuess = true;
				
			}
		}
		guessedLetters.push_back(letter);
		return correctGuess;
	}

	void displayGameInfo()
	{
		
		cout << "Word: " << currentWord << endl;
		cout << "Attempts left: " << attemptsLeft << endl;
		cout << "Guessed letters: ";
		for (char letter : guessedLetters) {
			cout << letter << " ";
		}
		cout << endl;
		
	}


	void drawHangman(int attemptsLeft)
	{
		if (attemptsLeft == 5) {
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			
		}
		
		else if (attemptsLeft == 4) {
			
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |	 |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			
		}
		else if (attemptsLeft == 3) {
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |      /|" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (attemptsLeft == 2) {
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |      /|\\" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (attemptsLeft == 1) {
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |      /|\\" << endl;
			cout << " |      /" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (attemptsLeft == 0) {
			cout << " __________" << endl;
			cout << " |	 |" << endl;
			cout << " |	 O" << endl;
			cout << " |      /|\\" << endl;
			cout << " |      / \\" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
	}
};

void hangman()
{
	char choice;
	do {
		HangmanGame game;
		game.play();
		cout << "Play again? (y/n): ";
		cin >> choice;
		system("cls");
	} while (choice == 'y' || choice == 'Y');
	system("cls");
}

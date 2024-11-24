#include "hangman.h"

#define MAX_ATTEMPTS 6

using namespace std;

// Class definition for Hangman Game
class HangmanGame {
public:
    HangmanGame() {
        srand(static_cast<unsigned int>(time(nullptr)));
        secretWord = getRandomWord();
        currentWord = string(secretWord.length(), '_');
        attemptsLeft = MAX_ATTEMPTS;
    }

    // Function to start the game
    void play() {
        printWithColor("!!! Welcome to Hangman !!!\n", "yellow");
        printWithColor("You have ", "yellow");
        cout << attemptsLeft;
        printWithColor(" attempts to guess the word\n", "yellow");

        while (attemptsLeft > 0) {
            displayGameInfo();
            char guess;
            printWithColor("Guess a letter: ", "green");
            cin >> guess;

            if (isalpha(guess)) {
                guess = tolower(guess);
                if (alreadyGuessed(guess)) {
                    system("cls");
                    drawHangman(attemptsLeft);
                }
                else {
                    bool correctGuess = updateCurrentWord(guess);
                    if (correctGuess) {
                        system("cls");
                        printWithColor("Good guess!", "green");
                        cout << "\n\n";
                        drawHangman(attemptsLeft);

                        if (currentWord == secretWord) {
                            displayGameInfo();
                            printWithColor("Congratulations! You guessed the word: ", "green");
                            typeEffect(secretWord);
                            cout << "\n";
                            return;
                        }
                    }
                    else {
                        system("cls");
                        printWithColor("Incorrect guess!\n", "red");
                        attemptsLeft--;
                        drawHangman(attemptsLeft);
                    }
                }
            }
        }

        if (attemptsLeft == 0) {
            displayGameInfo();
            printWithColor("You've run out of attempts. The word was: ", "red");
            typeEffect(secretWord);
            cout << endl;
        }
    }

private:
    string secretWord;
    string currentWord;
    int attemptsLeft;
    vector<char> guessedLetters;

    // Typing effect for text
    void typeEffect(const string& str, int delay = 100) {
        for (char c : str) {
            cout << c;
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
        cout << endl;
    }

    // Function to print colored text
    void printWithColor(const string& text, const string& color) {
        if (color == "green") {
            cout << "\033[1;32m" << text << "\033[0m";
        }
        else if (color == "red") {
            cout << "\033[1;31m" << text << "\033[0m";
        }
        else if (color == "yellow") {
            cout << "\033[1;33m" << text << "\033[0m";
        }
        else {
            cout << text;
        }
    }

    // Fetch a random word for the game
    string getRandomWord() {
        static const vector<string> words = {
            "apple", "banana", "cherry", "grape", "kiwi",
            "book", "case", "child", "company", "country",
            "day", "eye", "fact", "family", "group", "hand",
            "home", "job", "life", "lot", "man", "money",
            "month", "mother", "night", "number", "part",
            "people", "place", "point", "problem", "program",
            "question", "right", "room", "school", "state",
            "story", "student", "study", "system", "thing",
            "time", "water", "way", "week", "woman", "word",
            "work", "world", "year"
        };
        int index = rand() % words.size();
        return words[index];
    }

    // Check if a letter has already been guessed
    bool alreadyGuessed(char letter) {
        return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
    }

    // Update the current word with correctly guessed letters
    bool updateCurrentWord(char letter) {
        bool correctGuess = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                currentWord[i] = letter;
                correctGuess = true;
            }
        }
        guessedLetters.push_back(letter);
        return correctGuess;
    }

    // Display the current game information
    void displayGameInfo() {
        printWithColor("Word: ", "yellow");
        cout << currentWord << endl;
        printWithColor("Attempts left: ", "yellow");
        cout << attemptsLeft << endl;
        printWithColor("Guessed letters: ", "yellow");
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;
    }

    // Draw the hangman figure based on attempts left
    void drawHangman(int attemptsLeft) {
        switch (attemptsLeft) {
        case 5:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |\n"
                << " |\n"
                << " |\n"
                << " |\n";
            break;
        case 4:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |       |\n"
                << " |\n"
                << " |\n"
                << " |\n";
            break;
        case 3:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |      /|\n"
                << " |\n"
                << " |\n"
                << " |\n";
            break;
        case 2:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |      /|\\\n"
                << " |\n"
                << " |\n"
                << " |\n";
            break;
        case 1:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |      /|\\\n"
                << " |      /\n"
                << " |\n"
                << " |\n";
            break;
        case 0:
            cout << " __________\n"
                << " |       |\n"
                << " |       O\n"
                << " |      /|\\\n"
                << " |      / \\\n"
                << " |\n"
                << " |\n";
            break;
        }
    }
};

// Hangman game function
void hangman() {
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

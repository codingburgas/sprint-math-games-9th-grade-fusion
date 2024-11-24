#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

// Include game headers
#include "scramble.h"
#include "hangman.h"
#include "Tic-Tac-Toe.h"

using namespace std;

int main() {
    // Variable declarations
    int choice, game, goBack; // Menu and game selection variables
    bool gameState = true;    // Controls the overall program state
    bool menuState = true;    // Controls the main menu state

    // Main menu loop
    while (menuState) {
        // Display main menu options
        cout << "1 - Start" << endl;
        cout << "2 - About" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter your choice and press ENTER: ";
        cin >> choice;

        switch (choice) {
        case 1: // Start games menu
            system("cls");
            cout << "Choose a game!" << endl;
            cout << "1 - Hangman" << endl;
            cout << "2 - Tic-Tac-Toe" << endl;
            cout << "3 - Scramble" << endl;
            cout << "Enter your choice and press ENTER: ";
            cin >> game;
            system("cls");

            // Game selection logic
          switch (game) {
        case 1: // Hangman
            system("cls");
            hangman(); // Call the Hangman game
            break;

        case 2: // Tic-Tac-Toe
             system("cls");
            TicTacToe(choice); // Call the Tic-Tac-Toe game
            break;

        case 3: { // Scramble
            system("cls");
            cout << "You chose Scramble!" << endl;
            // List of words for the Scramble game
            vector<string> words = {
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
            ScrambleGame(words); // Call the Scramble game
            break;
            }

            default: // Invalid game choice
            system("cls");
            cout << "Invalid choice, returning to main menu." << endl;
            break;
            }

            break;

        case 2: // About section
            system("cls");
            cout << "Our Team : \n\n";
            cout << "Kaloyan Boychev - Scrum Trainer\n";
            cout << "Valeri Tenev - Frontend Developer\n";
            cout << "Aleksandr Toder - Backend Developer\n";
            cout << "Teodor Enev - Designer\n\n";
            cout << "1- Go back\n";
            cin >> goBack;
            if (goBack == 1) {
                system("cls");
            }
            break;

        case 3: // Exit
            gameState = false; // End the program
            return 0;

        default: // Invalid menu choice
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }

    return 0; // Exit the program
}

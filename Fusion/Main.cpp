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

// Function to display the "About" section of the program
void About() { 
    cout << "|=================================================|\n";
    cout << "|                       ABOUT                     |\n";
    cout << "|=================================================|\n";
    cout << "|Welcome to our project! This application is a    |\n";
    cout << "| collection of three entertaining games, designed|\n";
    cout << "| and developed by our school team.               |\n";
    cout << "|                                                 |\n";

    // Features section
    cout << "|**Features:**                                    |\n";
    cout << "|- A variety of games to suit different tastes.   |\n";
    cout << "|- Simple, intuitive menu for easy navigation.    |\n";
    cout << "|                                                 |\n";

    // Team credits
    cout << "|**Our Team:**                                    |\n";
    cout << "|- Kaloyan Boychev - Scrum Trainer                |\n";
    cout << "|- Valeri Tenev - Frontend Developer              |\n";
    cout << "|- Aleksandr Toder - Backend Developer            |\n";
    cout << "|- Teodor Enev - Designer                         |\n";
    cout << "|                                                 |\n";

    // Purpose of the project
    cout << "|We developed this project to practice and        |\n";
    cout << "|showcase our C++ programming skills, teamwork,   |\n";
    cout << "|and creativity.                                  |\n";
    cout << "|                                                 |\n";

    // Closing message
    cout << "|We hope you enjoy our games and have fun!        |\n";
    cout << "|Feel free to share your feedback with us.        |\n";
    cout << "|=================================================|\n";
}



int main() {
    // Variable declarations
    int choice, game, goBack;
    bool gameState = true; // Controls the overall program state

    // List of words for Scramble
    vector<string> words = { "example", "scramble", "project", "game" };

    // Main menu loop
    while (gameState) {
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
            cout << "4 - Return" << endl;
            cout << "Enter your choice and press ENTER: ";
            cin >> game;
            system("cls");

            // Game selection logic
            switch (game) {
            case 1:
                hangman(); // Call the Hangman game
                break;

            case 2:
                TicTacToe(choice); // Call the Tic-Tac-Toe game
                break;

            case 3:
                ScrambleGame(words); // Call the Scramble game
                break;

            case 4:
                system("cls");
                break; // Return to Main Menu

            default:
                cout << "Invalid choice, returning to main menu." << endl;
                break;
            }
            break;

        case 2: // About section
            system("cls");
            About();
            cout << "1- Go back\n";
            cin >> goBack;
            if (goBack == 1) // Return to Main Menu
                system("cls");
            break;

        case 3: // Exit
            gameState = false; // End the program
            break;

        default:
            cout << "Invalid choice, please try again." << endl;    
            break;
        }
    }

    return 0; // Exit the program
}
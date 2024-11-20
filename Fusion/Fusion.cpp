#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include "scramble.h"
#include "hangman.h"
#include "Tic-Tac-Toe.h"
using namespace std;


int main() {
   

    int choice, game;
    bool gameState = true;
    bool menuState = true;

    while (menuState) {
        cout << "1 - Start" << endl;
        cout << "2 - About" << endl;
        cout << "3 - Exit" << endl;
        cout << "Enter your choice and press ENTER: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "Choose a game!" << endl;
            cout << "1 - Hangman" << endl;
            cout << "2 - Tic-Tac-Toe" << endl;
            cout << "3 - Scramble" << endl;
            cout << "Enter your choice and press ENTER: ";
            cin >> game;
            system("cls");
            switch (game) {
            case 1:
                system("cls");
             
                hangman();
           
                
                break;
            case 2:
                system("cls");
                
                TicTacToe( choice);
                break;
            case 3:
                system("cls");
                cout << "You chose Scramble!" << endl;
                
                ScrambleGame(words, 4);
                break;
            default:
                system("cls");
                
                break;
            }
            break;

        case 2:
            cout << "About" << endl;
          
            break;

        case 3:
            
            gameState = false;
            return 0;
            break;

        default:
           
            break;
        }
    }

    return 0;
}

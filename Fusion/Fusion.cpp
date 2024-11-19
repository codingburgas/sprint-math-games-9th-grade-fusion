#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include "scramble.h"
#include "hangman.h"

using namespace std;


int main() {
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);  // Maximize the console window

    // Set console font size
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
    fontInfo.dwFontSize.X = 16;  // Font width
    fontInfo.dwFontSize.Y = 32;  // Font height
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);

    // Set console screen buffer size
    COORD coord;
    coord.X = 120;
    coord.Y = 300;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    int choice, game;
    bool gameState = true;
    bool menuState = true;

    while (menuState) {
        cout << "1 - Start." << endl;
        cout << "2 - Help." << endl;
        cout << "3 - Exit." << endl;
        cout << "Enter your choice and press ENTER: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "Choose a game!" << endl;
            cout << "1 - Hangman" << endl;
            cout << "2 - Pong" << endl;
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
            cout << "Help" << endl;
          
            break;

        case 3:
            cout << "Exiting program." << endl;
            gameState = false;
            break;

        default:
           
            break;
        }
    }

    return 0;
}

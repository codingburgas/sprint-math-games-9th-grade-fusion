#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include "scramble.h"
using namespace std;
int main()
{
	HWND console = GetConsoleWindow();

	// Maximize the console window (this forces it to full-screen on the primary monitor)
	ShowWindow(console, SW_MAXIMIZE);

	// Set console font size (larger font)
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);

	fontInfo.dwFontSize.X = 16; // Width of the font (increase for bigger text)
	fontInfo.dwFontSize.Y = 32; // Height of the font (increase for bigger text)

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);

	// Set console screen buffer size to match the screen size
	COORD coord;
	coord.X = 120; // Width of the buffer (adjust as needed)
	coord.Y = 300; // Height of the buffer (adjust as needed)
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);









	int choice, game;
	bool gameState = true;
	bool menuState = true;
	while (menuState != false) {
		cout << " 1 - Start." << endl;
		cout << " 2 - Help." << endl;
		cout << " 3 - Exit." << endl;
		cout << "Enter your choice and press ENTER: ";
		cin >> choice;
		//Add Menu
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Choose a game!" << endl;
			cout << "  1 - Hangman" << endl;
			cout << "  2 - Pong" << endl;
			cout << "  3 - Scramble" << endl;
			cout << "Enter your choice and press ENTER: ";
			cin >> game;
			system("cls");
				switch (game)
				{
				case 1:
					menuState = false;
					cout << "              *     *     *     *     *    *****   *     *     *     *     *" << endl;
					cout << "              *     *    * *    **    *   *     *  **   **    * *    **    *" << endl;
					cout << "              *     *   *   *   * *   *  *         * * * *   *   *   * *   *" << endl;
					cout << "              *******  *******  *  *  *  *   ****  *  *  *  *******  *  *  *" << endl;
					cout << "              *     *  *     *  *   * *  *     *   *     *  *     *  *   * *" << endl;
					cout << "              *     *  *     *  *    **   *     *  *     *  *     *  *    **" << endl;
					cout << "              *     *  *     *  *     *    *****   *     *  *     *  *     *" << endl;

					break;
				
				case 2:
					system("cls");
					cout << "You choose PONG" << endl;

					break;
				case 3:
					system("cls");
					cout << "You choose SCRAMBLE" << endl;

					ScrambleGame(words, 4);
					break;
				default:
					system("cls");
					cout << "Not a Valid Choice." << endl;
					cout << "Choose again." << endl;
					cout << "  1 - Hangman" << endl;
					cout << "  2 - Pong" << endl;
					cout << "  3 - Scramble" << endl;
					cout << "Enter your choice and press ENTER: ";
					cin >> game;
					break;
				}
			break;
		case 2:
			cout << "Help" << endl;

			break;
		case 3:
			cout << "End  Program." << endl;

			gameState = false;
			break;
		default:
			cout << "Not a Valid Choice." << endl;
			cout << "Choose again." << endl;
			cin >> choice;
			break;
		}

	}
	return 0;
}
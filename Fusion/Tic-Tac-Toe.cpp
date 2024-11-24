#include "Tic-Tac-Toe.h"
#include <cmath> 

#define Dimension 3

using namespace std;

class Player {
private:
    string name;

public:
    Player(string n) : name(n) {}

    string PlayerName() {
        return name;
    }
};

class Game {
private:
    char gameboard[Dimension][Dimension];
    int count;

public:
    Game() : count(0) {
        CreateBoard();
    }

    // Function to create a typing effect
    void typeEffect(const string& str, int delay = 100) {
        for (char c : str) {
            cout << c;
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
        cout << endl;
    }

    // Function for coloring output text
    void printWithColor(const string& text, const string& color) {
        if (color == "green") {
            cout << "\033[1;32m" << text << "\033[0m"; // Green text
        }
        else if (color == "red") {
            cout << "\033[1;31m" << text << "\033[0m"; // Red text
        }
        else if (color == "yellow") {
            cout << "\033[1;33m" << text << "\033[0m"; // Yellow text
        }
        else {
            cout << text; // Default color
        }
    }

    // Initialize the gameboard
    void CreateBoard() {
        for (int i = 0; i < Dimension; i++) {
            for (int j = 0; j < Dimension; j++) {
                gameboard[i][j] = ' ';
            }
        }
        showBoard();
    }

    // Display the gameboard
    void showBoard() {
        printf("\n\n");
        for (int i = 0; i < Dimension; i++) {
            cout << "\t\t\t";
            for (int j = 0; j < Dimension; j++) {
                cout << " | " << gameboard[i][j];
            }
            cout << " |\n\t\t\t----------------" << endl;
        }
    }

    // Handle a player's turn
    void PlayerTurn(Player& player) {
        int position;
        int row, col;

        while (true) {
            cout << player.PlayerName() << "'s turn:\n";
            printWithColor("Enter the position to be marked (1-9): ", "yellow");
            cin >> position;

            row = (position - 1) / Dimension;
            col = (position - 1) % Dimension;

            if (position < 1 || position > 9 || gameboard[row][col] != ' ') {
                printWithColor("Invalid position! Please try again.\n", "red");
            }
            else {
                gameboard[row][col] = (player.PlayerName() == "Player I") ? 'X' : 'O';
                printWithColor("Marked at position: ", "green");
                cout << position << endl;
                count++;
                break;
            }
        }
        showBoard();
    }

    // Handle the CPU's turn (for single-player mode)
    void CPUTurn() {
        int random_position, row, col;

        while (true) {
            random_position = rand() % (Dimension * Dimension) + 1;
            row = (random_position - 1) / Dimension;
            col = (random_position - 1) % Dimension;

            if (gameboard[row][col] == ' ') {
                gameboard[row][col] = 'O';
                printWithColor("CPU marked at position: ", "red");
                cout << random_position << endl;
                count++;
                break;
            }
        }
        showBoard();
    }

    // Check for a win condition or draw
    string CheckWin() {
        int r1, r2, c1, c2, d1 = 0, d2 = 0;

        for (int i = 0; i < Dimension; i++) {
            r1 = r2 = c1 = c2 = 0;

            for (int j = 0; j < Dimension; j++) {
                if (gameboard[i][j] == 'X') r1++;
                if (gameboard[i][j] == 'O') r2++;
                if (gameboard[j][i] == 'X') c1++;
                if (gameboard[j][i] == 'O') c2++;
            }

            if (r1 == Dimension || c1 == Dimension) return "Player I";
            if (r2 == Dimension || c2 == Dimension) return "Player II";

            if (gameboard[i][i] == 'X') d1++;
            if (gameboard[i][i] == 'O') d2++;
        }

        if (d1 == Dimension) return "Player I";
        if (d2 == Dimension) return "Player II";

        return (count == Dimension * Dimension) ? "Draw" : "";
    }
};

void TicTacToe(int choice) {
    Game game;

    cout << "Press 1 for single-player, 2 for two-player game: ";
    cin >> choice;

    if (choice == 1) {
        Player player1("Player I");
        string result;

        while (true) {
            game.PlayerTurn(player1);
            result = game.CheckWin();
            if (!result.empty()) break;

            game.CPUTurn();
            result = game.CheckWin();
            if (!result.empty()) break;
        }

        if (result == "Draw") {
            cout << "It's a draw!\n";
        }
        else {
            cout << result << " wins!\n";
        }
    }
    else if (choice == 2) {
        Player player1("Player I"), player2("Player II");
        string result;

        while (true) {
            game.PlayerTurn(player1);
            result = game.CheckWin();
            if (!result.empty()) break;

            game.PlayerTurn(player2);
            result = game.CheckWin();
            if (!result.empty()) break;
        }

        if (result == "Draw") {
            cout<<"It's a draw!\n";
        }
        else {
            cout << result << " wins!\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }

    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        system("cls");
        TicTacToe(choice);
    }
    else {
        system("cls");
    }
}


#include "Tic-Tac-Toe.h"

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

    void CreateBoard() {
        for (int i = 0; i < Dimension; i++) {
            for (int j = 0; j < Dimension; j++) {
                gameboard[i][j] = ' ';
            }
        }
        showBoard();
    }

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

    void PlayerTurn(Player& player) {
        int position;
        int row, col;

        while (true) {
            cout <<  player.PlayerName() <<"'s turn " << ":\n";
            cout << "Enter the position to be marked (1-9): ";
            cin >> position;

            row = static_cast<int>(ceil(static_cast<float>(position) / Dimension)) - 1;
            col = (position - 1) % Dimension;

            if (position < 1 || position > 9 || gameboard[row][col] != ' ') {
                cout << "Invalid position! Please try again.\n";
            }
            else {
                gameboard[row][col] = player.PlayerName() == "Player I" ? 'X' : 'O';
                cout << "Marked at position: " << position << endl;
                count++;
                break;
            }
        }
        showBoard();
    }

    void CPUTurn() {
        int random_position, row, col;

        while (true) {
            random_position = rand() % (Dimension * Dimension) + 1;
            row = static_cast<int>(ceil(static_cast<float>(random_position) / Dimension)) - 1;
            col = (random_position - 1) % Dimension;

            if (gameboard[row][col] == ' ') {
                gameboard[row][col] = 'O';
                cout << "CPU marked at position: " << random_position << endl;
                count++;
                break;
            }
        }
        showBoard();
    }

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
            if (r2 == Dimension || c2 == Dimension) return "Player 2";

            if (gameboard[i][i] == 'X') d1++;
            if (gameboard[i][i] == 'O') d2++;
        }

        if (d1 == Dimension) return "Player I";
        if (d2 == Dimension) return "Player 2";

        return count == Dimension * Dimension ? "Draw" : "";
    }
};
int choice;  
char choice2;

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

        cout << result << " wins!\n";
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

        cout << result << " wins!\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
   cout << "Play again? (y/n): ";
   cin >> choice2;
   if (choice2 == 'y' || choice2 == 'Y') {
       system("cls");
TicTacToe(choice);
   }
   else {
system("cls");
   }
   
        
       
        
        
    

}


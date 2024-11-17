#include "scramble.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
string WordForScramble(const string& word) {
    string scrambled = word;
    random_shuffle(scrambled.begin(), scrambled.end());
    return scrambled;
}

void ScrambleGame(const string* words, int wordNum) {
    bool keepPlaying = true;

    while (keepPlaying) {
        string selectedWord = words[rand() % wordNum];

        string ScrambledWord = WordForScramble(selectedWord);

        cout << "Guess the word: " << ScrambledWord << endl;

        string guess;
        cout << "Your guess: ";
        cin >> guess;

        if (guess == selectedWord) {
            cout << "Correct! The word was: " << selectedWord << endl;
        }
        else {
            cout << "Wrong! The correct word was: " << selectedWord << endl;
        }

        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        keepPlaying = (choice == 'y' || choice == 'Y');
    }

    cout << "Thanks for playing!" << endl;
    system("cls");
}
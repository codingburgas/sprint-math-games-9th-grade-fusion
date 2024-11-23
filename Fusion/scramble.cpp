#include "scramble.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Function to create a typing effect
void typeEffect(const string& str, int delay = 100) {
    for (char c : str) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay)); // Adjust delay to speed up or slow down typing effect
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

string WordForScramble(const string& word) {
    string scrambled = word;
    random_device rd;
    mt19937 rng(rd());  // Mersenne Twister random number generator
    shuffle(scrambled.begin(), scrambled.end(), rng);
    return scrambled;
}

void ScrambleGame(const vector<string>& words) {
    random_device rd;
    mt19937 rng(rd());  // Random number generator
    vector<string> shuffledWords = words;  // Copy to allow shuffling
    shuffle(shuffledWords.begin(), shuffledWords.end(), rng);

    bool keepPlaying = true;
    size_t wordIndex = 0;  // Track which word to pick next

    while (keepPlaying) {
        if (wordIndex >= shuffledWords.size()) {
            // Reshuffle when all words are used
            shuffle(shuffledWords.begin(), shuffledWords.end(), rng);
            wordIndex = 0;
        }

        string selectedWord = shuffledWords[wordIndex++];
        string scrambledWord = WordForScramble(selectedWord);

        printWithColor("Guess the word: ", "yellow");
        typeEffect(scrambledWord);  // Typing effect for the scrambled word

        string guess;
        printWithColor("Your guess: ", "green");
        cin >> guess;

        if (guess == selectedWord) {
            printWithColor("Correct! The word was: ", "green");
            typeEffect(selectedWord);
            printWithColor("Great job! Well done. ", "green");
        }
        else {
            printWithColor("Wrong! The correct word was: ", "red");
            typeEffect(selectedWord);
            printWithColor("Better luck next time! ", "red");
        }

        char choice;
        printWithColor("Play again? (y/n): ", "yellow");
        cin >> choice;
        keepPlaying = (choice == 'y' || choice == 'Y');
    }

    printWithColor("Thanks for playing!\n", "blue");
    this_thread::sleep_for(chrono::milliseconds(1000)); // Pause before closing
    system("cls");
}

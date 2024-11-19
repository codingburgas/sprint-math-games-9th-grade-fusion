#pragma once

#include <string>

using namespace std;

string WordForScramble(const string& word);

void ScrambleGame(const string* words, int wordNum);

static string words[] = { "apple", "banana", "cherry", "grape", "orange" , "pear" , "potato" , "watermelon"};
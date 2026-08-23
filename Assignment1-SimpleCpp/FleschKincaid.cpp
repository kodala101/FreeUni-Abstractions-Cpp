/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include  "simpio.h"
#include "TokenScanner.h"
#include <fstream>
#include <cctype>
using namespace std;

const double C0 = -15.59;
const double C1 = 0.39;
const double C2 = 11.8;

bool isVowel(char ch) {
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')  return true;
    return false;
}

int countSyllables(string word) {
    int n = 0;
    if (word.length() == 1) {
        if (isVowel(word[0])) return 1;
    }
    for (int i = 0; i < word.length() - 1; i++) {
        if (i == word.length() - 2 && isVowel(word[i]) && tolower(word[word.length() - 1]) == 'e') n++;
        if (isVowel(word[i]) && !isVowel(word[i + 1])) n++;
    }
    if (isVowel(word[word.length() - 1]) && tolower(word[word.length() - 1]) != 'e') n++;
    if (n == 0) return 1;
    return n;
}

int main() {
    while (true) {
        string file = getLine("Enter filename (type -1 to break the loop): ");
        if (file == "-1") break;
        ifstream infile;
        infile.open(file);
        if (infile.fail()) {
            cout << "Can't open the specified file!" << endl;
        }
        else {
            TokenScanner scanner(infile);
            scanner.ignoreWhitespace();
            scanner.addWordCharacters("'");
            int words = 0;
            int sentences = 0;
            int syllables = 0;
            while (scanner.hasMoreTokens()) {
                string word = scanner.nextToken();
                if (word[0] < 1 || word[0] > 255) continue;
                if (isalpha(word[0])) {
                    words++;
                    syllables += countSyllables(word);
                }
                if (word.find(".") != string::npos || word.find("?") != string::npos || word.find("!") != string::npos) {
                    sentences++;
                }
            }

            double grade = C0 + C1 * (1.0 * words / sentences) + C2 * (1.0 * syllables / words);

            cout << words << endl;
            cout << sentences << endl;
            cout << syllables << endl;
            cout << "Grade Level: " << grade << endl;
        }
        infile.close();
    }
    return 0;
}

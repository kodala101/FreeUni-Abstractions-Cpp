#include <iostream>
#include "console.h"
#include "vector.h"
#include "map.h"
#include "simpio.h"
#include <fstream>
#include "random.h"

using namespace std;

const int LENGTH_OF_TEXT = 2000;

//This function is for reading passed file and create map.
//Keys of the map are k-length substrings of the file and values are 
//vectors of chars coming after specific key in the file.
Map< string, Vector<char> > readFile(string fileName, int k) {
    Map< string, Vector<char> > kLengthSubStringsAndItsNextChars;
    ifstream infile;
    infile.open(fileName);
    string text = "";
    char ch;
    while (infile.get(ch)) text += ch;  //This while loop will write the whole file in one line.
    infile.close();
    for (int i = 0; i <= text.length() - k - 1; i++) {
        string kLength = text.substr(i, k);
        char nextChar = text[i + k];
        kLengthSubStringsAndItsNextChars[kLength].add(nextChar);  //If map doesn't contain key, it will create the pair automatically and if it does, it will add nextChar to its value.
    }
    return kLengthSubStringsAndItsNextChars;
}

//This function return the most common k-length substring from the file
//by iterating through the map and returning the key, value (vector) of which is the longest.
string generateFirstSymbols(Map< string, Vector<char> >& kLengthSubStringsAndItsNextChars) {
    string firstSymbols;
    int n = 0;
    foreach(string key in kLengthSubStringsAndItsNextChars) {
        if (kLengthSubStringsAndItsNextChars.get(key).size() >= n) {
            firstSymbols = key;
            n = kLengthSubStringsAndItsNextChars.get(key).size();
        }
    }
    return firstSymbols;
}

//This function generates text according to the frequency 
//of characters after the current k-length substring.
string generateText(Map< string, Vector<char> >& kLengthSubStringsAndItsNextChars, string firstSymbols, int k) {
    string text = firstSymbols;
    while (text.length() != LENGTH_OF_TEXT) {
        string current = text.substr(text.length() - k);
        Vector<char> vectOfChars = kLengthSubStringsAndItsNextChars.get(current);
        if (vectOfChars.isEmpty()) break;
        char next = vectOfChars[randomInteger(0, vectOfChars.size() - 1)];
        text += next;
    }
    return text;
}

//Main function asks user to enter filename and k until they are valid
//and then calls functions described above to print generated text in console.
int main() {
    string fileName;
    int k;
    while (true) {
        fileName = getLine("Enter name of the file: ");
        ifstream infile;
        infile.open(fileName);
        if (infile.fail()) {
            cout << "Name is incorrect" << endl;
            continue;
        }
        break;
    }
    while (true) {
        k = getInteger("Enter model number: ");
        if (k < 1 || k > 10) {
            cout << "Model number must be between 1 and 10" << endl;
            continue;
        }
        break;
    }
    
    Map<string, Vector<char> > kLengthSubStringsAndItsNextChars = readFile(fileName, k);
    cout << "Generated text: " << generateText(kLengthSubStringsAndItsNextChars, generateFirstSymbols(kLengthSubStringsAndItsNextChars), k) << endl;
    
    return 0;
}

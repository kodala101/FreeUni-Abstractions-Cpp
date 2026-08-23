#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"

using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence) {
    if (subsequence != "" && text == "") return false;

    if (subsequence == "") return true;
    if (text[0] == subsequence[0]) {
        return isSubsequence(text.substr(1), subsequence.substr(1));
    }
    else {
        return isSubsequence(text.substr(1), subsequence);
    }
}

int main() {
    string text = getLine("Enter text: ");
    string subsequence = getLine("Enter test: ");
    if (isSubsequence(text, subsequence)) {
        cout << "test is subsequence of text" << endl;
    }
    else {
        cout << "test is not subsequence of text" << endl;
    }
    return 0;
}

/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

string intToString(int n);
int stringToInt(string str);

bool sth = true;

int main() {
    cout << intToString(-431) << endl;
    cout << stringToInt("-432") << endl;
    return 0;
}

string intToString(int n) {
    if (n < 0) return "-" + intToString(-n);

    if (n / 10 == 0) {
        return string() + char(n + '0');
    }
    else {
        return intToString(n / 10) + (string() + char(n % 10 + '0'));
    }
}

int stringToInt(string str) {
    if (str[0] == '-') return -1 * stringToInt(str.substr(1));
    if (str.length() == 0) {
        return 0;
    }
    else {
        return stringToInt(str.substr(0, str.length() - 1)) * 10 + (str[str.length() - 1] - '0');
    }
}
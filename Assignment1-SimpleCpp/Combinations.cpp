/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
using namespace std;

int pascale(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    else {
        return pascale(n - 1, k - 1) + pascale (n - 1, k);
    }
}

int main() {
    cout << pascale(5, 4) << endl;
    return 0;
}

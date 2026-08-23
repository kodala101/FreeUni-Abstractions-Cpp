/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h";
#include "stack.h";
using namespace std;

void emptyStack(Stack<int>& stc) {
    while (!stc.isEmpty()) {
        stc.pop();
    }
}

int generate() {
    Stack<int> coins;
    int n = 0;
    while (true) {
        n++;
        if (randomInteger(0, 1) == 0) {
            cout << "trails" << endl;
            emptyStack(coins);
        }
        else {
            coins.push(1);
            cout << "heads" << endl;
            if (coins.size() == 3) break;
        }
    }
    return n;
}

int main() {
    cout << "It took " << generate() << " flips to get 3 consecutive heads." << endl;
    return 0;
}

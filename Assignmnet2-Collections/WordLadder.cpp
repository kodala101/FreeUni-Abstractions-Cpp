#include <iostream>
#include "console.h"
#include <vector>
#include "queue.h"
#include "set.h"
#include "simpio.h"
#include "lexicon.h"

using namespace std;

//This function creates a lexicon of words from the file.
//Then takes the last element from the vector, produces all words
//by changing one character in that element, checks if it's actually a word,
//checks in the set if it's already used and if it's not, adds it to the other set.
//Finally, function returns that set, consisting of the words which can be obtained by
//changing only one char in the last element of the strings' vector.
Set<string> addWordsFromLexicon(string word, Set<string>& usedWords) {
    Lexicon lex("EnglishWords.dat");
    string copy = word;
    Set<string> changedByOne;
    for (int i = 0; i < word.length(); i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            copy[i] = j;
            if (lex.contains(copy) && !usedWords.contains(copy)) changedByOne.add(copy);
            copy = word;
        }
    }
    return changedByOne;
}

//This function just follows the BFS model using addWordsFromLexicon function
//to produce new paths and add to the queue. (If there is no path for given words
//it returns an empty vector.
vector<string> shortestPath(string start, string destination) {
    Queue< vector<string> > paths;
    Set<string> usedWords;

    vector<string> first = { start };
    paths.enqueue(first);
    usedWords.add(start);

    while (!paths.isEmpty()) {
        vector<string> firstPath = paths.dequeue();
        string word = firstPath.back();
        if (word == destination) return firstPath;
        foreach(string changedWord in addWordsFromLexicon(word, usedWords)) {  //If there is no ladder, the set will be empty, there will be no strings in it, so enqueue won't happen
            usedWords.add(changedWord);                                        //That will cause path to become empty after several iterations (next dequeued vectors will also get
            vector<string> copy = firstPath;                                   //empty changedByOne-sets) and while loop will end. Function will return empty vector, which will be
            copy.push_back(changedWord);                                       //handled in the main function as a sign that there is no ladder between these two words.
            paths.enqueue(copy);
        }
    }
    vector<string> blank;
    return blank;
}

//In the main function, there is just one while loop
//where the user is asked to enter starting and destination words,
//and then calls shortestPath to print the output.
int main() {
    while (true) {
        string start = getLine("Enter start word (RETURN to quit) : ");
        if (start == "RETURN") break;
        string destination = getLine("Enter destination word: ");
        if (start.length() != destination.length()) {  //If the lengths of the words don't match, it's worthless to continue the programme.
            cout << "No ladder found." << endl;
            continue;
        }
        vector<string> ladder = shortestPath(start, destination);
        if (ladder.size() == 0) {
            cout << "No ladder found." << endl;
            continue;
        }
        cout << "Found ladder: ";
        for (int i = 0; i < ladder.size(); i++) cout << ladder[i] << " ";
        cout << endl;
    }
    return 0;
}

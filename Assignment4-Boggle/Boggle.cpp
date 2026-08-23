#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
#include "vector.h"
#include "set.h"
#include "queue.h"
#include "map.h"

using namespace std;

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;
const int NUM_ROWS = 4;
const int NUM_COLS = 4;
const int MIN_LENGTH_OF_WORDS = 4;

const string STANDARD_CUBES[16]  = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
    "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
    "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

void welcome();
void giveInstructions();
Grid<char> fillBoard(Vector<string>& playersCubes);
Map< string, Set<pair<int, int>> > allWords(Grid<char>& board, Lexicon& lex);
Vector<string> enterCubes();
void playersTurn(Map< string, Set<pair<int, int>> >& all, Set<string>& allPlayersWords);
void computersTurn(Map< string, Set<pair<int, int>> >& all);

int main() {
    while (true) {
        Lexicon lex("EnglishWords.dat");
        GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
        initGBoggle(gw);
        welcome();
        giveInstructions();
        drawBoard(NUM_ROWS, NUM_COLS);
        Vector<string> playersCubes = enterCubes();     //If player does not want to enter cubes, this vector will stay empty;
        Grid<char> board = fillBoard(playersCubes);
        Map< string, Set<pair<int, int>> > all = allWords(board, lex);
        Set<string> allPlayersWords;
        playersTurn(all, allPlayersWords);
        computersTurn(all);
        cout << "Type AGAIN, if you want to play one mor time." << endl;
        if (getLine() != "AGAIN") break;
    }
    return 0;
}

void welcome() {
    cout << "Welcome!  You're about to play an intense game ";
    cout << "of mind-numbing Boggle.  The good news is that ";
    cout << "you might improve your vocabulary a bit.  The ";
    cout << "bad news is that you're probably going to lose ";
    cout << "miserably to this little dictionary-toting hunk ";
    cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

void giveInstructions() {
    cout << endl;
    cout << "The boggle board is a grid onto which I ";
    cout << "I will randomly distribute cubes. These ";
    cout << "6-sided cubes have letters rather than ";
    cout << "numbers on the faces, creating a grid of ";
    cout << "letters on which you try to form words. ";
    cout << "You go first, entering all the words you can ";
    cout << "find that are formed by tracing adjoining ";
    cout << "letters. Two letters adjoin if they are next ";
    cout << "to each other horizontally, vertically, or ";
    cout << "diagonally. A letter can only be used once ";
    cout << "in each word. Words must be at least four ";
    cout << "letters long and can be counted only once. ";
    cout << "You score points based on word length: a ";
    cout << "4-letter word is worth 1 point, 5-letters ";
    cout << "earn 2 points, and so on. After your puny ";
    cout << "brain is exhausted, I, the supercomputer, ";
    cout << "will find all the remaining words and double ";
    cout << "or triple your paltry score." << endl << endl;
    cout << "Hit return when you're ready...";
    getLine();
}

Vector<string> enterCubes() {
    Vector<string> v;
    cout << "If you don't want to enter your own cubes, type NO, otherwise, type anything and enter your cubes." << endl;
    if (getLine() == "NO") return v;
    while (v.size() < NUM_ROWS * NUM_COLS) {
        cout << NUM_ROWS * NUM_COLS - v.size();
        v.add(getLine(" cubes left: "));
    }
    return v;
}

Grid<char> fillBoard(Vector<string>& playersCubes) {
    Vector< string > cubes;
    if (playersCubes.isEmpty()) {
        for (string cube : STANDARD_CUBES) cubes.add(cube);
    }
    else {
        for (string cube : playersCubes) cubes.add(cube);
    }
    for (int i = 0; i < cubes.size(); i++) {    //Randomizing the order of Vector of cubes.
        int change = randomInteger(i, cubes.size() - 1); //rato i dan?
        string change_th = cubes[change];
        cubes[change] = cubes[i];
        cubes[i] = change_th;
    }

    int indexInVec = 0;     //For filling the grid correctly.
    Grid<char> board(NUM_ROWS, NUM_COLS); 
    for (int i = 0; i < board.numRows(); i++) {     //Randomly chooses the side of the cubes and fill the grid.
        for (int j = 0; j < board.numCols(); j++) {
            int side = randomInteger(0, 5);
            char ch = cubes[indexInVec][side];
            board[i][j] = ch;
            labelCube(i, j, ch);
            indexInVec++;
        }
    }

    return board;
}

void allWordsFromSpecificCell(pair<int, int> start, Grid<char>& board, Lexicon& lex, Map< string, Set<pair<int, int>> >& all) {
    Set<pair<int, int>> used;
    Queue< tuple<   string, pair<int, int>, Set<pair<int, int>>   > > q;  //I am using BFS. This queue keeps the information about every single path as tuples.
    string firstStr = string() + board[start.first][start.second];        //That information consists of the string, the last cell with which the string was built and 
    used.add(start);                                                      //the set of cells used for building the string.
    q.enqueue( make_tuple(firstStr, start, used) );
    while (!q.isEmpty()) {
        tuple<   string, pair<int, int>, Set<pair<int, int>>   > path = q.dequeue();
        string curr = get<0>(path);
        if (lex.contains(curr) && curr.length() >= MIN_LENGTH_OF_WORDS) all.put(curr, get<2>(path));

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (board.inBounds(get<1>(path).first + i, get<1>(path).second + j)) {
                    pair<int, int> next(get<1>(path).first + i, get<1>(path).second + j);
                    string neww = curr + board[next.first][next.second];
                    Set<pair<int, int>> nextSet = get<2>(path);
                    if (!nextSet.contains(next) && lex.containsPrefix(neww)) {
                        nextSet.add(next);
                        q.enqueue(  make_tuple(neww, next, nextSet)  );
                    }
                }
            }
        }
    }
}

Map< string, Set<pair<int, int>> > allWords(Grid<char>& board, Lexicon& lex) {
    Map< string, Set<pair<int, int>> > all;
    for (int i = 0; i < board.numRows(); i++) {
        for (int j = 0; j < board.numCols(); j++) {
            pair<int, int> start(i, j);
            allWordsFromSpecificCell(start, board, lex, all);
        }
    }
    return all;
}

void toUpper(string& s) {
    for (char& c : s) c = toupper(c);
}

void unhighliteTheBoard() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++)  highlightCube(i, j, false);
    }
}

void playersTurn(Map< string, Set<pair<int, int>> >& all, Set<string>& allPlayersWords) {
    cout << "Enter words you have found on the board. If you can't think of any other, press ENTER." << endl;
    while (true) {
        string playersWord = getLine();
        toUpper(playersWord);
        if (playersWord == "") break;
        if (all.containsKey(playersWord) && !allPlayersWords.contains(playersWord)) {
            unhighliteTheBoard();
            allPlayersWords.add(playersWord);
            for (pair<int, int> p : all.get(playersWord)) {
                highlightCube(p.first, p.second, true);
            }
            recordWordForPlayer(playersWord, HUMAN);
            all.remove(playersWord);
        }
        else {
            cout << "Word is not valid." << endl;
        }
    }
}

void computersTurn(Map< string, Set<pair<int, int>> >& all) {
    for (string s : all)  recordWordForPlayer(s, COMPUTER);
}



#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"
#include "simpio.h"

using namespace std;

void generate(string protein, Map<char, Set<string> >& codons, string current, int index) {
    if (index == protein.size()) cout << current << endl;
    for (string s : codons.get(protein[index])) generate(protein, codons, current + s, index + 1);
}

void listAllRNAStrandsFor(string protein, Map<char, Set<string> >& codons) {
    generate(protein, codons, "", 0);
}

Map<char, Set<string> > loadCodonMap();

int main() {
    Map<char, Set<string> > codons = loadCodonMap();

    string protein = getLine("Enter protein: ");
    bool isLegit = true;
    for (int i = 0; i < protein.length(); i++) {
        if (islower(protein[i]) || !codons.containsKey(protein[i])) isLegit = false;
    }
    if (isLegit) {
        listAllRNAStrandsFor(protein, codons);
    }
    else {
        cout << "Protein does not exists" << endl;
    }

    return 0;
}

Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;

    string codon;
    char protein;

    while (input >> codon >> protein) {
        result[protein] += codon;
    }

    return result;
}

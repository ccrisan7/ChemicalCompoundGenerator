#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "atom.cpp"  // Including Atom class

using namespace std;

class CompoundSubstance {
private:
    vector<Atom*> atoms;
    unordered_map<string, int> atomCount;

    void clearAtoms();

public:
    CompoundSubstance(const vector<string> &atomSymbols);

    CompoundSubstance(const CompoundSubstance &other);

    CompoundSubstance& operator=(const CompoundSubstance &other);

    ~CompoundSubstance();

    void displayMolecularFormula() const;

    void display() const;
};

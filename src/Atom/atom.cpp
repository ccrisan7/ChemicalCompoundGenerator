#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "atom.hpp"

using namespace std;


void Atom::loadAtomicData() {
    ifstream file("../Data/atomic_data.txt");
    if (!file) {
        cerr << "Error: Could not open atomic_data.txt" << endl;
        return;
    }

    string symbol;
    int atomicNumber;
    double atomicMass;
    while (file >> symbol >> atomicNumber >> atomicMass) {
        atomicData[symbol] = {atomicNumber, atomicMass};
    }
    file.close();
    cout << "Atomic data loaded successfully" << endl;
}

void Atom::setAtomicProperties() {
    if (atomicData.empty()) {
        loadAtomicData();
    }

    auto it = atomicData.find(symbol);
    if (it != atomicData.end()) {
        atomicNumber = it->second.first;
        atomicMass = it->second.second;
    } else {
        cerr << "Unknown element symbol: " << symbol << endl;
        atomicNumber = 0;
        atomicMass = 0.0;
    }
    cout << "Atomic properties set successfully for " << symbol << endl;
}

Atom::Atom(const string &symbol) : symbol(symbol) {
    setAtomicProperties();
    cout << "Constructor for Atom: " << symbol << endl;
}

Atom::Atom(const Atom &other) : symbol(other.symbol), atomicNumber(other.atomicNumber), atomicMass(other.atomicMass) {
    cout << "Copy constructor for Atom: " << symbol << endl;
}

Atom& Atom::operator=(const Atom &other) {
    if (this != &other) {
        symbol = other.symbol;
        atomicNumber = other.atomicNumber;
        atomicMass = other.atomicMass;
        cout << "Assignment operator for Atom: " << symbol << endl;
    }
    return *this;
}

Atom::~Atom() {
    cout << "Destructor for Atom: " << symbol << endl;
}

string Atom::getSymbol() const { return symbol; }
int Atom::getAtomicNumber() const { return atomicNumber; }
double Atom::getAtomicMass() const { return atomicMass; }
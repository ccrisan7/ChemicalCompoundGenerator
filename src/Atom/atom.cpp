#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "atom.hpp"

using namespace std;

void Atom::loadAtomicData() {
    // Populate atomicData directly with the first 20 elements
    atomicData["H"] = {1, 1.008};
    atomicData["He"] = {2, 4.0026};
    atomicData["Li"] = {3, 6.94};
    atomicData["Be"] = {4, 9.0122};
    atomicData["B"] = {5, 10.81};
    atomicData["C"] = {6, 12.011};
    atomicData["N"] = {7, 14.007};
    atomicData["O"] = {8, 15.999};
    atomicData["F"] = {9, 18.998};
    atomicData["Ne"] = {10, 20.180};
    atomicData["Na"] = {11, 22.990};
    atomicData["Mg"] = {12, 24.305};
    atomicData["Al"] = {13, 26.982};
    atomicData["Si"] = {14, 28.085};
    atomicData["P"] = {15, 30.974};
    atomicData["S"] = {16, 32.06};
    atomicData["Cl"] = {17, 35.45};
    atomicData["Ar"] = {18, 39.948};
    atomicData["K"] = {19, 39.098};
    atomicData["Ca"] = {20, 40.078};

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
        cout << "!!Correct assignment operator for Atom: " << symbol << endl;
    }
    return *this;
}

Atom::~Atom() {
    cout << "Destructor for Atom: " << symbol << endl;
}

// Method to display the properties of the atom
void Atom::display() const {
    cout << "Symbol: " << symbol << endl;
    cout << "Atomic Number: " << atomicNumber << endl;
    cout << "Atomic Mass: " << atomicMass << " u" << endl;
}

// Method to set the symbol of the atom and update properties
void Atom::setSymbol(const std::string &newSymbol) {
    symbol = newSymbol;
    setAtomicProperties();
    cout << "Symbol set to " << symbol << " and properties updated" << endl;
}

// Initialize the static member
unordered_map<string, pair<int, double>> Atom::atomicData;


string Atom::getSymbol() const { return symbol; }
int Atom::getAtomicNumber() const { return atomicNumber; }
double Atom::getAtomicMass() const { return atomicMass; }

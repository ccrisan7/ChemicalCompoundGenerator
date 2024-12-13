#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "atom.hpp"

// Initialize static atomic data
std::unordered_map<std::string, std::pair<int, double>> Atom::atomicData;

// Load data for the first 20 elements
void Atom::loadAtomicData() {
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

    std::cout << "Atomic data loaded successfully." << std::endl;
}

// Set atomic properties based on the symbol
void Atom::setAtomicProperties() {
    if (atomicData.empty()) {
        loadAtomicData();
    }

    auto it = atomicData.find(symbol);
    if (it != atomicData.end()) {
        atomicNumber = it->second.first;
        atomicMass = it->second.second;
    } else {
        std::cerr << "Unknown element symbol: " << symbol << std::endl;
        atomicNumber = 0;
        atomicMass = 0.0;
    }
}

// Constructor for Atom
Atom::Atom(const std::string& symbol) : symbol(symbol) {
    setAtomicProperties();
}

// Copy constructor
Atom::Atom(const Atom& other) : symbol(other.symbol), atomicNumber(other.atomicNumber), atomicMass(other.atomicMass) {}

// Assignment operator
Atom& Atom::operator=(const Atom& other) {
    if (this != &other) {
        symbol = other.symbol;
        atomicNumber = other.atomicNumber;
        atomicMass = other.atomicMass;
    }
    std::cout << "\n!Confirmation of assignment operator successful!" << std::endl;
    return *this;
}

// Destructor
Atom::~Atom() {}

// Display atom details
void Atom::display() const {
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Atomic Number: " << atomicNumber << std::endl;
    std::cout << "Atomic Mass: " << atomicMass << " u" << std::endl;
}

// Update the symbol and set properties
void Atom::setSymbol(const std::string& newSymbol) {
    symbol = newSymbol;
    setAtomicProperties();
}

// Accessor methods
std::string Atom::getSymbol() const { return symbol; }
int Atom::getAtomicNumber() const { return atomicNumber; }
double Atom::getAtomicMass() const { return atomicMass; }

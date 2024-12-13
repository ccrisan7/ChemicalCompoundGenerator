#include "metal.hpp"
#include <iostream>

// Constructor implementation
Metal::Metal(const std::string& symbol, double atomicMass)
    : symbol(symbol), atomicNumber(0), atomicMass(atomicMass) {}

// Copy constructor
Metal::Metal(const Metal& other)
    : symbol(other.symbol), atomicNumber(other.atomicNumber), atomicMass(other.atomicMass) {}

// Assignment operator
Metal& Metal::operator=(const Metal& other) {
    if (this != &other) {
        symbol = other.symbol;
        atomicNumber = other.atomicNumber;
        atomicMass = other.atomicMass;
    }
    return *this;
}

// Destructor
Metal::~Metal() {}

// Accessor methods
std::string Metal::getSymbol() const { return symbol; }
int Metal::getAtomicNumber() const { return atomicNumber; }
double Metal::getAtomicMass() const { return atomicMass; }

// Display metal details
void Metal::display() const {
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Atomic Number: " << atomicNumber << std::endl;
    std::cout << "Atomic Mass: " << atomicMass << " u" << std::endl;
}
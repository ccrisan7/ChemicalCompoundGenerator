#ifndef METAL_HPP
#define METAL_HPP

#include <string>
#include <iostream>

// Forward declaration of Atom class to allow using shared pointers
class Atom;

// Metal class definition inheriting from Atom (or having a common base)
class Metal {
private:
    std::string symbol;
    int atomicNumber;
    double atomicMass;

public:
    // Constructor
    Metal(const std::string& symbol, double atomicMass);

    // Copy constructor
    Metal(const Metal& other);

    // Assignment operator
    Metal& operator=(const Metal& other);

    // Destructor
    ~Metal();

    // Accessor methods
    std::string getSymbol() const;
    int getAtomicNumber() const;
    double getAtomicMass() const;

    // Display metal details
    void display() const;
};

#endif // METAL_HPP
#ifndef ATOM_HPP
#define ATOM_HPP

#include <iostream>
#include <unordered_map>
#include <string>

class Atom {
private:
    std::string symbol;                 // Chemical symbol (e.g., H, He)
    int atomicNumber = 0;               // Atomic number
    double atomicMass = 0.0;            // Atomic mass (u)
    static std::unordered_map<std::string, std::pair<int, double>> atomicData; // Atomic data map

    // Load atomic data for the first 20 elements
    static void loadAtomicData();

    // Set atomic properties based on the symbol
    void setAtomicProperties();

public:
    // Constructor
    explicit Atom(const std::string& symbol);

    // Copy constructor
    Atom(const Atom& other);

    // Assignment operator
    Atom& operator=(const Atom& other);

    // Destructor
    virtual ~Atom();

    // Display atom details
    virtual void display() const;

    // Set the symbol and update properties
    void setSymbol(const std::string& newSymbol);

    // Accessor methods
    std::string getSymbol() const;
    int getAtomicNumber() const;
    double getAtomicMass() const;
};

#endif // ATOM_HPP
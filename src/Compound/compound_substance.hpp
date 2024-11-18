#ifndef COMPOUND_SUBSTANCE_HPP
#define COMPOUND_SUBSTANCE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "atom.hpp"  // Ensure you have a corresponding Atom class header file

class CompoundSubstance {
private:
    std::vector<Atom*> atoms;  // Stores pointers to Atom objects
    std::unordered_map<std::string, int> atomCount;  // Counts occurrences of each atom type

    void clearAtoms();  // Helper function to clear and deallocate atom pointers

public:
    // Constructors and Destructor
    CompoundSubstance();
    CompoundSubstance(const std::vector<std::string> &atomSymbols);
    CompoundSubstance(const CompoundSubstance &other);
    ~CompoundSubstance();

    // Assignment operator
    CompoundSubstance& operator=(const CompoundSubstance &other);

    // Member functions
    void displayMolecularFormula() const;
    void display() const;
    void addAtom(Atom atom);  // Adds an Atom pointer to the compound
    std::vector<Atom*> getAtoms() const;  // Returns a copy of the atoms vector
};

#endif // COMPOUND_SUBSTANCE_HPP
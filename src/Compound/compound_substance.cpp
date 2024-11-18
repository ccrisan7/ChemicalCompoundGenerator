#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "compound_substance.hpp"

using namespace std;

void CompoundSubstance::clearAtoms() {
    for (Atom* atom : atoms) {
        delete atom;
    }
    atoms.clear();
    atomCount.clear();
    cout << "Cleared atoms successfully" << endl;
}

CompoundSubstance::CompoundSubstance() {}

CompoundSubstance::CompoundSubstance(const vector<string> &atomSymbols) {
    for (const string &symbol : atomSymbols) {
        Atom* newAtom = new Atom(symbol);
        atoms.push_back(newAtom);
        atomCount[symbol]++;
    }
    cout << "CompoundSubstance created with " << atoms.size() << " atoms" << endl;
}

CompoundSubstance::CompoundSubstance(const CompoundSubstance &other) {
    for (const Atom* atom : other.atoms) {
        atoms.push_back(new Atom(*atom));
    }
    atomCount = other.atomCount;
    cout << "Copy constructor for CompoundSubstance" << endl;
}

CompoundSubstance& CompoundSubstance::operator=(const CompoundSubstance &other) {
    if (this != &other) {
        clearAtoms();
        for (const Atom* atom : other.atoms) {
            atoms.push_back(new Atom(*atom));
        }
        atomCount = other.atomCount;
        cout << "Assignment operator for CompoundSubstance" << endl;
    }
    return *this;
}

CompoundSubstance::~CompoundSubstance() {
    clearAtoms();
    cout << "Destructor for CompoundSubstance" << endl;
}

void CompoundSubstance::displayMolecularFormula() const {
    cout << "Molecular Formula: ";
    for (const auto &pair : atomCount) {
        cout << pair.first;
        if (pair.second > 1) {
            cout << pair.second;
        }
    }
    cout << endl;
    cout << "Molecular formula displayed successfully" << endl;
}

void CompoundSubstance::display() const {
    for (const Atom* atom : atoms) {
        cout << "Atom: " << atom->getSymbol()
             << ", Atomic number: " << atom->getAtomicNumber()
             << ", Atomic mass: " << atom->getAtomicMass() << endl;
    }
    cout << "Compound details displayed successfully" << endl;
}

void CompoundSubstance::addAtom(Atom atom) {
    Atom* newAtom = new Atom(atom);
    atoms.push_back(newAtom);
    atomCount[newAtom->getSymbol()]++;
    cout << "Atom " << newAtom->getSymbol() << " added successfully" << endl;
}

vector<Atom*> CompoundSubstance::getAtoms() const {
    return atoms;
}
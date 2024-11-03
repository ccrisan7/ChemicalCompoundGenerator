#ifndef ATOM_HPP
#define ATOM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

class Atom {
private:
    string symbol;
    int atomicNumber;
    double atomicMass;
    static unordered_map<string, pair<int, double>> atomicData;

    static void loadAtomicData();

    void setAtomicProperties();

public:
    Atom(const string &symbol);

    Atom(const Atom &other);

    Atom& operator=(const Atom &other);

    ~Atom();

    string getSymbol() const;
    int getAtomicNumber() const;
    double getAtomicMass() const;
};

// Initialize the static member
unordered_map<string, pair<int, double>> Atom::atomicData;

#endif

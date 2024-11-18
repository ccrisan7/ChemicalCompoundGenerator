#include <iostream>
#include "atom.hpp"  // Assuming the Atom class and methods are implemented in this file.
#include "compound_substance.hpp"  // Assuming this file contains the CompoundSubstance class and its methods.

int main() {
    // Create some Atom objects to test the methods
    Atom* atom1 = new Atom("H");
    Atom* atom2 = new Atom("O");
    Atom* atom3 = new Atom("C");

    // Ensure objects are initialized before use
    Atom* atom4 = new Atom("F");  // Default constructor
    *atom4 = *atom2; // Assignment operator (explicitly testing)

    // Display initial atoms
    std::cout << "Initial Atoms:" << std::endl;
    atom1->display();
    atom2->display();
    atom3->display();
    atom4->display();

    // Test the assignment operator thoroughly
    std::cout << "\nTesting Assignment Operator:" << std::endl;

    // Check if deep copy was performed correctly
    if (atom4->getSymbol() == atom2->getSymbol() && atom4->getAtomicNumber() == atom2->getAtomicNumber() && atom4->getAtomicMass() == atom2->getAtomicMass()) {
        std::cout << "Assignment operator successful: atom4 is correctly assigned from atom2." << std::endl;
    } else {
        std::cerr << "Error: Assignment operator failed to create an accurate copy of atom2." << std::endl;
    }

    atom4->display();

    // Modify atom4 and show that atom2 remains unchanged to confirm deep copy
    atom4->setSymbol("N");
    std::cout << "\nAfter modifying atom4:" << std::endl;
    atom4->display();
    std::cout << "atom2 should remain unchanged:" << std::endl;
    atom2->display();

    // Create CompoundSubstance objects
    CompoundSubstance* compound1 = new CompoundSubstance();
    compound1->addAtom(*atom1);
    compound1->addAtom(*atom2);

    CompoundSubstance* compound2 = new CompoundSubstance();
    compound2->addAtom(*atom3);
    compound2->addAtom(*atom2);

    // Display initial compounds
    std::cout << "\nInitial Compounds:" << std::endl;
    compound1->display();
    compound2->display();

    CompoundSubstance* compound3 = new CompoundSubstance();
    *compound3 = *compound1;
    compound3->addAtom(*atom3);
    std::cout << "\nAfter modifying compound3:" << std::endl;
    compound3->display();
    std::cout << "compound1 should remain unchanged:" << std::endl;
    compound1->display();

    delete atom1;
    delete atom2;
    delete atom3;
    delete atom4;

    delete compound1;
    delete compound2;
    delete compound3;

    return 0;
}
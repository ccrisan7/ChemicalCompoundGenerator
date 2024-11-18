#include <iostream>
#include "atom.cpp"  // Assuming the Atom class and methods are implemented in this file.
#include "compound_substance.hpp"  // Assuming this file contains the CompoundSubstance class and its methods.

int main() {
    // Create some Atom objects to test the methods
    Atom atom1("Hydrogen", 1, 1.008);
    Atom atom2("Oxygen", 8, 15.999);
    Atom atom3("Carbon", 6, 12.011);

    // Ensure objects are initialized before use
    Atom atom4;  // Default constructor
    atom4 = atom2; // Assignment operator (explicitly testing)

    // Display initial atoms
    std::cout << "Initial Atoms:" << std::endl;
    atom1.display();
    atom2.display();
    atom3.display();

    // Test the assignment operator thoroughly
    std::cout << "\nTesting Assignment Operator:" << std::endl;

    // Check if deep copy was performed correctly
    if (atom4.getName() == atom2.getName() && atom4.getAtomicNumber() == atom2.getAtomicNumber() && atom4.getAtomicWeight() == atom2.getAtomicWeight()) {
        std::cout << "Assignment operator successful: atom4 is correctly assigned from atom2." << std::endl;
    } else {
        std::cerr << "Error: Assignment operator failed to create an accurate copy of atom2." << std::endl;
    }

    atom4.display();

    // Modify atom4 and show that atom2 remains unchanged to confirm deep copy
    atom4.setName("Modified Oxygen");
    atom4.setAtomicWeight(16.5);
    std::cout << "\nAfter modifying atom4:" << std::endl;
    atom4.display();
    std::cout << "atom2 should remain unchanged:" << std::endl;
    atom2.display();

    // Create CompoundSubstance objects
    CompoundSubstance compound1;
    compound1.addAtom(atom1);
    compound1.addAtom(atom2);

    CompoundSubstance compound2;
    compound2.addAtom(atom3);
    compound2.addAtom(atom2);

    // Display initial compounds
    std::cout << "\nInitial Compounds:" << std::endl;
    compound1.display();
    compound2.display();

    // Test assignment operator for CompoundSubstance
    std::cout << "\nTesting Assignment Operator for CompoundSubstance:" << std::endl;
    CompoundSubstance compound3;
    compound3 = compound1;  // Test assignment operator explicitly

    // Verify the deep copy integrity
    if (compound3.getAtoms() == compound1.getAtoms()) {
        std::cout << "Assignment operator successful: compound3 is correctly assigned from compound1." << std::endl;
    } else {
        std::cerr << "Error: Assignment operator failed to create an accurate copy of compound1." << std::endl;
    }

    compound3.display();

    // Modify compound3 and show that compound1 remains unchanged
    compound3.addAtom(atom3);
    std::cout << "\nAfter modifying compound3:" << std::endl;
    compound3.display();
    std::cout << "compound1 should remain unchanged:" << std::endl;
    compound1.display();

    return 0;
}

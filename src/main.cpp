#include "compound_substance.cpp"
#include <vector>
#include <string>

using namespace std;

int main() {
    // 1. Testing Atom class methods
    cout << "Creating Atom for 'H'" << endl;
    Atom hydrogen("H");
    cout << "Symbol: " << hydrogen.getSymbol() << endl;
    cout << "Atomic Number: " << hydrogen.getAtomicNumber() << endl;
    cout << "Atomic Mass: " << hydrogen.getAtomicMass() << endl;

    cout << "\nCreating another Atom for 'O'" << endl;
    Atom oxygen("O");

    cout << "\nTesting Atom Copy Constructor" << endl;
    Atom copyOxygen(oxygen);

    cout << "\nTesting Atom Assignment Operator" << endl;
    Atom assignedAtom = hydrogen;

    // 2. Testing CompoundSubstance class methods
    cout << "\nCreating CompoundSubstance (H2O)" << endl;
    vector<string> atomSymbols = {"H", "H", "O"};
    CompoundSubstance water(atomSymbols);

    cout << "\nDisplaying CompoundSubstance details" << endl;
    water.display();

    cout << "\nDisplaying Molecular Formula of CompoundSubstance" << endl;
    water.displayMolecularFormula();

    cout << "\nTesting CompoundSubstance Copy Constructor" << endl;
    CompoundSubstance copyWater(water);
    copyWater.display();

    cout << "\nTesting CompoundSubstance Assignment Operator" << endl;
    CompoundSubstance assignedWater = water;
    assignedWater.display();

    // Exiting main will automatically invoke destructors for all objects
    cout << "\nExiting main, destructors will be called automatically." << endl;

    return 0;
}

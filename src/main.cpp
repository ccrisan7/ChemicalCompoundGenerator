#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include "atom.hpp"
#include "metal.hpp"

// Mutex to ensure thread-safe operations
std::mutex mtx;

// Function to display atom/metal data safely
void displayAtomData(const std::shared_ptr<Atom>& atom) {
    std::cout << "\nAtom:" << std::endl;
    std::lock_guard<std::mutex> lock(mtx);
    atom->display();
}

void displayMetalData(const std::shared_ptr<Metal>& metal) {
    std::cout << "\nMetal:" << std::endl;
    std::lock_guard<std::mutex> lock(mtx);
    metal->display();
}

int main() {
    // Normal variables for Atom objects
    Atom atom1("H");
    Atom atom2("O");
    Atom atom3("C");
    Atom atom4("F");

    std::cout << "Initial Atoms:" << std::endl;
    atom1.display();
    atom2.display();
    atom3.display();

    atom4 = atom2; // Assignment operator

    std::cout << "\nTesting Assignment Operator:" << std::endl;
    if (atom4.getSymbol() == atom2.getSymbol() && 
        atom4.getAtomicNumber() == atom2.getAtomicNumber() && 
        atom4.getAtomicMass() == atom2.getAtomicMass()) {
        std::cout << "Assignment operator successful: atom4 is correctly assigned from atom2." << std::endl;
    } else {
        std::cerr << "Error: Assignment operator failed." << std::endl;
    }
    atom4.display();

    // Using the copy constructor
    Atom atom5 = atom2; // Copy constructor
    std::cout << "\nTesting Copy Constructor:" << std::endl;
    atom5.display();

    // Using the move constructor
    Atom atom6 = std::move(atom4); // Move constructor
    std::cout << "\nTesting Move Constructor:" << std::endl;
    atom6.display();

    // Modify atom6 and ensure atom2 remains unchanged
    atom6.setSymbol("N");
    std::cout << "\nAfter modifying atom6:" << std::endl;
    atom6.display();
    std::cout << "atom2 should remain unchanged:" << std::endl;
    atom2.display();

    // Using unique_ptr for Atom objects
    std::unique_ptr<Atom> uptr_atom1 = std::make_unique<Atom>("H");
    std::unique_ptr<Atom> uptr_atom2 = std::make_unique<Atom>("O");
    std::unique_ptr<Atom> uptr_atom3 = std::make_unique<Atom>("C");

    std::cout << "\nTesting unique_ptr Atom objects:" << std::endl;
    uptr_atom1->display();
    uptr_atom2->display();
    uptr_atom3->display();

    std::unique_ptr<Atom> uptr_atom4 = std::make_unique<Atom>("F");
    *uptr_atom4 = *uptr_atom2; // Assignment operator with unique_ptr

    std::cout << "\nTesting unique_ptr Assignment Operator:" << std::endl;
    uptr_atom4->display();

    // Demonstrating shared pointers for Metal objects
    std::shared_ptr<Metal> copper = std::make_shared<Metal>("Cu", 63.55);
    std::shared_ptr<Metal> aluminum = std::make_shared<Metal>("Al", 26.98);

    // Thread-safe display using threads
    std::cout << "\nThread-safe displays:" << std::endl;

    // Convert unique_ptr to shared_ptr before passing to the thread
    std::shared_ptr<Atom> shared_atom1 = std::move(uptr_atom1);
    std::shared_ptr<Atom> shared_atom2 = std::move(uptr_atom2);
    std::shared_ptr<Atom> shared_atom3 = std::move(uptr_atom3);

    // Create threads with shared pointers
    std::vector<std::thread> threads;
    threads.emplace_back(displayAtomData, shared_atom1);
    threads.emplace_back(displayAtomData, shared_atom2);
    threads.emplace_back(displayAtomData, shared_atom3);
    threads.emplace_back(displayMetalData, copper);
    threads.emplace_back(displayMetalData, aluminum);

    // Join all threads
    for (auto& thread : threads) {
        if(thread.joinable()) {
            thread.join();
        }
    }

    return 0;
}
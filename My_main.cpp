#include <iostream>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <valgrind/valgrind.h>

#include "sources/Team.hpp" //no need for other includes

using namespace std;
using namespace std::chrono;
using namespace ariel;

/*
clang++-14 -g My_main.cpp -o My_main
valgrind --leak-check=full --error-exitcode=1 ./My_main


*/

int main() {
    Point a(32.3, 44), b(1.3, 3.5);

    Cowboy* cowboy1 = new Cowboy("Cowboy1", a);
    Cowboy* cowboy2 = new Cowboy("Cowboy2", b);
    Cowboy* cowboy3 = new Cowboy("Cowboy3", Point(10, 20));
    Cowboy* cowboy4 = new Cowboy("Cowboy4", Point(5, 5));

    cowboy4->hit(150); // Make Cowboy4 dead

    Team cowboys(cowboy1);
    cowboys.add(cowboy2);
    cowboys.add(cowboy3);
    cowboys.add(cowboy4); // Adding a dead Cowboy

    Team ninjas;

    // Create 10,000 ninjas
    for (int i = 0; i < 10000; ++i) {
        Point location(i, i);
        OldNinja* ninja = new OldNinja("Ninja" + to_string(i), location);
        ninjas.add(ninja);
    }

    // Measure the execution time of the 'attack' function
    auto start = high_resolution_clock::now();

    cowboys.attack(&ninjas);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Attack execution time: " << duration.count() << " milliseconds" << endl;

    // Perform actions and simulate battles
    while (cowboys.stillAlive() > 0 && ninjas.stillAlive() > 0) {
        cowboys.attack(&ninjas);
        ninjas.attack(&cowboys);
        cowboys.print();
        ninjas.print();
    }

    if (cowboys.stillAlive() > 0) {
        cout << "Winner is the Cowboys team!" << endl;
    } else {
        cout << "Winner is the Ninjas team!" << endl;
    }

    // Freeing memory
    delete cowboy1;
    delete cowboy2;
    delete cowboy3;
    delete cowboy4;
    cout << "Memory freed." << endl;

/*
    // Check for memory leaks using valgrind
    if (RUNNING_ON_VALGRIND) {
        cout << "Checking for memory leaks..." << endl;
        int result = system("valgrind --leak-check=full --error-exitcode=1 ./your_program");
        if (result == 0) {
            cout << "No memory leaks detected." << endl;
        } else {
            cout << "Memory leaks detected." << endl;
        }
    }
*/
    // Additional tests for shoot function
    Cowboy* cowboy5 = new Cowboy("Cowboy5", Point(50, 50));
    Cowboy* cowboy6 = new Cowboy("Cowboy6", Point(60, 60));
    OldNinja* ninja1 = new OldNinja("Ninja1", Point(70, 70));
    OldNinja* ninja2 = new OldNinja("Ninja2", Point(80, 80));

    cowboy5->shoot(cowboy6); // Cowboy5 shoots Cowboy6 (damage: 10)
    cowboy5->shoot(ninja1); // Cowboy5 shoots Ninja1 (damage: 10)
    cowboy6->shoot(cowboy5); // Cowboy6 shoots Cowboy5 (damage: 10)
    ninja1->slash(cowboy5); // Ninja1 slashes Cowboy5 (no damage)

    cout << "After shoot and slash actions:" << endl;
    cowboy5->print();
    cowboy6->print();
    ninja1->print();
    ninja2->print();

    // Freeing memory
    delete cowboy5;
    delete cowboy6;
    delete ninja1;
    delete ninja2;


    return 0;
}

/*
The error message you are getting is a linker error.
 It indicates that the linker (ld) is unable to find 
 the definitions for the functions and classes referenced in your code.
 */

#include <iostream>
#include "dictionary.hpp"

/**
 * Drives the program.
 */
int main() {
    string file = "../dictionary.txt";
    dictionary d(file);
    d.menu();
    return 0;
}
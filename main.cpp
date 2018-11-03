#include <iostream>
#include "dictionary.hpp"

int main() {
    string file = "../dictionary.txt";
    dictionary d(file);
    d.menu();
    return 0;
}
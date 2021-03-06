//
// Created by Iris L on 2018-11-02.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP
#include <map>
#include <iterator>
#include <string>

//Constants for switch case in menu function
#define PrintDictionary 1
#define FindWordDefinition 2
#define EnterNewWordAndDefinition 3
#define Exit 4

using namespace std;

/**
 * The dictionary class can print words and definitions,
 * search for the definition of a word,
 * and add new word and definition.
 * This is a prototype where instances and functions are declared.
 */
class dictionary {
private:
    string file;
    map<string, string> wordAndDef;
public:
    explicit dictionary(string filename);
    void menu();
    void print_dictionary();
    void find_wordDef();
    void new_wordAndDef();
    void update_dictionary();
};


#endif //LAB6_DICTIONARY_HPP

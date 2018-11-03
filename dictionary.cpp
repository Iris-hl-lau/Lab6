//
// Created by Iris L on 2018-11-02.
//

#include "dictionary.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

dictionary::dictionary(string filename) {
    file = filename;
    ifstream f_read;
    f_read.open(filename);
    string word;
    string def;

    while(f_read >> word) {
        getline(f_read, def);
        wordAndDef.insert(make_pair(word, def));
    }
    f_read.close();
}

void dictionary::menu(){
    int choice = 0;
    do {
        cout << "<<Menu>>" << endl;
        cout << "1 - Print dictionary" << endl;
        cout << "2 - Find word definition" << endl;
        cout << "3 - Enter new word and definition" << endl;
        cout << "4 - Exit" << endl;
        cin >> choice;

        switch(choice) {
            case PrintDictionary:
                print_dictionary();
                break;
            case FindWordDefinition:
                find_wordDef();
                break;
            case EnterNewWordAndDefinition:
                new_wordAndDef();
                break;
            case Exit:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid input.\n" << endl;
                break;
        }
    } while(choice != Exit);
}


void dictionary::print_dictionary() {
    auto itBegin = wordAndDef.begin();
    auto itEnd = wordAndDef.end();

    for (auto it = itBegin; it != itEnd; it++) {
        cout << "Word: " << it->first << endl;
        cout << " Definition: " << it->second << "\n" << endl;
    }
}

void dictionary::find_wordDef() {
    string word;
    cout << "Enter the word to be defined: " << endl;
    cin >> word;

    wordAndDef.begin();
    auto wordDef = wordAndDef.find(word);

    if(wordDef != wordAndDef.end()) {
        cout << "Definition: " ;
        cout << wordDef->second << endl;
    } else {
        cout << "The word " << word << " doesn't exist." << endl;
    }
}

void dictionary::new_wordAndDef(){
    wordAndDef.begin();
    string word, def;
    cout << "Enter a word: " << endl;
    cin >> word;
    auto wordDef = wordAndDef.find(word);

    while(wordDef != wordAndDef.end()) {
        cout << "The word " << word << " already exists." << endl;
        cout<< "Enter a new word." << endl;
        cin >> word;
        wordAndDef.begin();
        wordDef = wordAndDef.find(word);
    }
    cout << "Enter the definition: " << endl;
    cin.ignore();
    getline(cin, def);

    wordAndDef.insert(make_pair(word, def));
    update_dictionary();
    cout << "New word and definition has been added to the dictionary!" << endl;
}

void dictionary::update_dictionary() {
    ofstream f_write;
    f_write.open(file);
    auto itBegin = wordAndDef.begin();
    auto itEnd = wordAndDef.end();

    for (auto it = itBegin; it != itEnd; it++) {
        f_write << it->first << " " << it->second << "\n";
    }
    f_write.close();
}
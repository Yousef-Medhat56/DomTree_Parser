#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include "./dom_tree.h"
using namespace std;

class Interpreter
{
    // Load command: read html file and parse it DOM tree
    static void load(string filepath, DomTree *&tree);

    // Print command: print the DOM tree
    static void print(DomTree *&tree);

    // Selector command $(" "): Search for an element in the DOM tree
    static void search(string selector, DomTree *&tree);

    // Search for an element by it id attribute
    static void searchById(string selector, DomTree *&tree);

    // Help command: print the available commands in the program
    static void help();

public:
    // read the command that the user entered
    static void readCommand(DomTree *&tree);
};

#endif
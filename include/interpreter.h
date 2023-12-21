#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include "./dom_tree.h"
using namespace std;

class Interpreter
{
    static void load(string filepath, DomTree *&tree);
    static void print(DomTree *&tree);
    static void search(string selector, DomTree *&tree);

public:
    // read the command that the user entered
    static void readCommand(DomTree *&tree);
};

#endif
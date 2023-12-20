#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
using namespace std;

class Interpreter{
    static void load(string filepath);
    public:
    // read the command that the user entered
    static void readCommand();
};

#endif
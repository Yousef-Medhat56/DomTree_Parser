#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Console
{
public:
    // print success message
    static void success(string message);

    // print error message
    static void error(string message);
};

#endif
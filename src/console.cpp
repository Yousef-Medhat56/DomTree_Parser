#include "../include/console.h"

void Console::success(std::string message)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10); // change text color to green
    cout << message << endl;
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}

void Console::error(std::string message)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12); // change text color to red
    cout << message << endl;
    SetConsoleTextAttribute(hConsole, 15); // change text color to white
}

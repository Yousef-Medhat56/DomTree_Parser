#include "../include/interpreter.h"
#include "../include/string_utils.h"

void Interpreter::readCommand()
{
    // the command that the user will enter
    string command;

    while (true)
    {
        cout << "> ";

        //read the user input
        cin.clear();
        cin.sync();
        getline(cin, command);

        if (command == "print")
        {
            cout << "Print command" << endl;
        }
        else if (StringUtils::split(command, " ")[0] == "load")
        {
            cout << "Load command" << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Type 'help' to see the available commands." << endl;
        }
    }

    cout << "Exiting the program. Goodbye!" << std::endl;
}

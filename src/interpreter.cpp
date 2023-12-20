#include "../include/interpreter.h"
#include "../include/string_utils.h"
#include "../include/parser.h"
using namespace std;

void Interpreter::readCommand()
{
    // the command that the user will enter
    string command;

    while (true)
    {
        cout << "> ";

        // read the user input
        cin.clear();
        cin.sync();
        getline(cin, command);

        //trim whitespaces at start and end of the command
        command = StringUtils::trimSpaces(command);
        
        //split the command
        vector<string> command_splitted = StringUtils::split(command, " ");
        
        if (command == "print")
        {
            cout << "Print command" << endl;
        }
        else if (command_splitted[0] == "load")
        {
            // check that there is another parameter after the load command
            if (command_splitted.size() > 0)
            {
                // file path
                string filepath = command_splitted[command_splitted.size() - 1];
                load(filepath);
            }
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

void Interpreter::load(string filepath)
{
    // check if the filepath has quatations
    if (filepath[0] == '"' || filepath[0] == '\'')
        // trim the quatations
        filepath = StringUtils::trimFirstAndLastChar(filepath);

    // check that the file is a html file
    if (StringUtils::split(filepath, ".")[1] == "html")
    {
        try
        {
            // read the file content
            string plainHtml = Parser::readHtmlFile(filepath);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << endl;
        }
    }
    else
    {
        std::cerr << "Error: load html files only" << std::endl;
    }
}
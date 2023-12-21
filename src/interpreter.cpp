#include "../include/interpreter.h"
#include "../include/string_utils.h"
#include "../include/parser.h"
using namespace std;

void Interpreter::readCommand(DomTree *&tree)
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

        // trim whitespaces at start and end of the command
        command = StringUtils::trimSpaces(command);

        // split the command
        vector<string> command_splitted = StringUtils::split(command, " ");

        if (command == "print")
        {
            print(tree);
        }
        else if (command_splitted[0] == "load")
        {
            // check that there is another parameter after the load command
            if (command_splitted.size() > 0)
            {
                // file path
                string filepath = command_splitted[command_splitted.size() - 1];
                load(filepath, tree);
            }
        }
        // check if the user entered the selector command
        else if (StringUtils::startsWith(command, "$(") && command[command.size() - 1] == ')')
        {
            // extract the selector
            string selector = StringUtils::extract(command, "$(\"", "\")");

            search(selector, tree);
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

void Interpreter::load(string filepath, DomTree *&tree)
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

            tree = Parser::parseHTML(plainHtml);
            cout << "Success: file uploaded successfully" << endl;
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

void Interpreter::print(DomTree *&tree)
{
    // check that the tree pointer has a value
    if (tree)
        tree->display();
    else
        std::cerr << "Error: load html file first" << std::endl;
}

void Interpreter::search(string selector, DomTree *&tree)
{
    if (tree)
    {
        // check if the selector is for Id attribute
        if (selector[0] == '#')
        {
            // search for the tag by id
            searchById(selector, tree);
        }
        else
            std::cerr << "Error: syntax error" << std::endl;
    }
    else
        std::cerr << "Error: load html file first" << std::endl;
}

void Interpreter::searchById(string selector, DomTree *&tree)
{
    // trim the first char (#)
    selector = StringUtils::trimFirst(selector);

    // search for the tag element by id
    Node *tagNode = tree->getTagById(selector);

    if (tagNode)
        tagNode->display();
    else
        std::cerr << "Not Found" << std::endl;
}

#include <stack>
#include <iostream>
#include "../include/parser.h"
#include "./tree.cpp"
using namespace std;

string Parser::findTagName(const string &html)
{
    size_t closeTagStart = html.find('>'); //The index of the next close tag
    size_t nextSpaceStart = html.find(' '); //The index of the next whitespace
    string tagName;
    //check if the tag has attributes (the index of the close tag will be bigger than the index of the whitespace)
    if (closeTagStart > nextSpaceStart) 
        tagName = html.substr(1, nextSpaceStart - 1);
    else
        tagName = html.substr(1, closeTagStart - 1);
    return tagName;
}

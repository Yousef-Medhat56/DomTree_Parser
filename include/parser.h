#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>

#include "./tree.h"
using namespace std;

class Parser
{
    static string findTagName(const string& html);
    static bool isClosedTag(const string &html,const string &tagName);
    
};

#endif
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stack>

#include "./tree.h"
using namespace std;

class Parser
{
    static string findTagName(const string &html);
    static bool isSelfClosedTag(const string &html, const string &tagName);
    static void createTagNode(const string &tagName, stack<TagNode *> &nodeStack, Tree *&tree, const string &html);

};

#endif
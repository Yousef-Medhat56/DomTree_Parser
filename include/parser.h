#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "../src/stack.cpp"
#include "./dom_tree.h"
using namespace std;

class Parser
{
    static string findTagName(const string &html);
    static bool isSelfClosedTag(const string &html, const string &tagName);
    static void createTagNode(const string &tagName, stack<TagNode *> &nodeStack, DomTree *&tree, const string &html);
    static bool hasAttributes(const string &html);
    static void createAttrTags(const string html, stack<TagNode *> &nodeStack, DomTree *&tree);
    static string getTextContent(const string &html, const string &tagName);
    static void createTextNode(const string &textContent, stack<TagNode *> &nodeStack, DomTree *&tree);
    static void insertNodeToTree(Node *newNode, stack<TagNode *> &nodeStack, DomTree *&tree);

public:
    static DomTree *parseHTML(string plainHtml);
    static string readHtmlFile(string filepath);
};

#endif
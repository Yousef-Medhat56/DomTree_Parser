#include <stack>
#include <iostream>
#include "../include/parser.h"
#include "./tree.cpp"
using namespace std;

string Parser::findTagName(const string &html)
{
    size_t closeTagStart = html.find('>');  // The index of the next close tag
    size_t nextSpaceStart = html.find(' '); // The index of the next whitespace
    string tagName;
    // check if the tag has attributes (the index of the close tag will be bigger than the index of the whitespace)
    if (closeTagStart > nextSpaceStart)
        tagName = html.substr(1, nextSpaceStart - 1);
    else
        tagName = html.substr(1, closeTagStart - 1);
    return tagName;
}

// check if the tag is self closed
bool Parser::isSelfClosedTag(const string &html, const string &tagName)
{
    // search for the close tag
    size_t closeTag = html.find("</" + tagName + '>');
    if (closeTag != std::string::npos)
    {
        // The tag is not self closed
        return false;
    }
    // The tag is self closed
    return true;
}

void Parser::createTagNode(const string &tagName, stack<TagNode *> &nodeStack, Tree *&tree, const string &html)
{
    TagNode *tagNode = new TagNode(tagName);
    // if the nodes stack is empty, insert the root node
    if (nodeStack.empty())
        tree->insertChild(tagNode);
    else
    {
        // if the top node at the stack already has a child, insert the new node as a sibling
        if (nodeStack.top()->firstChild)
            tree->inserSibling(tagNode, nodeStack.top()->firstChild);
        else
            // insert a new child node
            tree->insertChild(tagNode, nodeStack.top());
    }
    if (!isSelfClosedTag(html, tagName))
        nodeStack.push(tagNode); // push the new node to the stack
}

Tree *Parser::parseHTML(string plainHtml)
{
    Tree *tree = new Tree();    // create the DOM tree
    stack<TagNode *> nodeStack; // TagNodes stack
    size_t pos = 0;             // position of the current character

    while (pos < plainHtml.size())
    {

        // Find the index of the first open tag character
        size_t openTagStart = plainHtml.find('<', pos);

        // check that the tag is not a closing tag or a comment
        if (plainHtml[openTagStart + 1] != '/' && plainHtml[openTagStart + 1] != '!')
        {
            // create substring of the plain html
            string subPlainHtml = plainHtml.substr(openTagStart);
            string tagName = findTagName(subPlainHtml);            // get the tag name
            createTagNode(tagName, nodeStack, tree, subPlainHtml); // create a new Tag node
        }

        //if the tag is a closing tag
        else if (plainHtml[openTagStart + 1] == '/')
            nodeStack.pop(); // pop the last tag node from the stack


        size_t closeTagStart = plainHtml.find('>', openTagStart);
        pos = closeTagStart + 1;
    }
    return tree;
}
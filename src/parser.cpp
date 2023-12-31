#include <iostream>
#include <fstream>
#include "../include/parser.h"
#include "./dom_tree.cpp"
#include "./string_utils.cpp"
using namespace std;

string Parser::readHtmlFile(string filepath)
{
    string plainHtml = "";

    ifstream htmlFile(filepath);
    if (htmlFile.is_open())
    {
        string line;
        while (getline(htmlFile, line))
        {
            plainHtml += line;
        }
        // Close the file
        htmlFile.close();
    }
    else
    {
        // Throw exception
        throw runtime_error("Error: Couldn't open file " + filepath);
    }
    return plainHtml;
}

string Parser::findTagName(const string &html)
{
    size_t closeTagStart = html.find('>');  // The index of the next close tag
    size_t nextSpaceStart = html.find(' '); // The index of the next whitespace
    string tagName;
    // check if the tag has attributes
    if (hasAttributes(html))
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

bool Parser::hasAttributes(const string &html)
{
    size_t closeTagStart = html.find('>');  // The index of the next close tag
    size_t nextSpaceStart = html.find(' '); // The index of the next whitespace

    // check if the tag has attributes (the index of the close tag will be bigger than the index of the whitespace)
    if (closeTagStart > nextSpaceStart + 3)
        return true;
    return false;
}

void Parser::createAttrTags(string htmlTag, stack<TagNode *> &nodeStack, DomTree *&tree)
{

    // the start of the attributes within the HTML tag
    size_t start = htmlTag.find(" \t");
    // the end of the tag
    size_t endOfTag = htmlTag.find(">");

    // the attributes plain text
    string attributesText = htmlTag.substr(start + 1, endOfTag - start - 1);

    // vector of attributes plain text
    vector<string> attrPairs = StringUtils::split(attributesText, " ");

    for (int i = 1; i < attrPairs.size(); i++)
    {
        // split the key and value of the attribute
        vector<string> tokens = StringUtils::split(attrPairs[i], "=");
        // if the tokens vector size is not even
        if (tokens.size() % 2)
            tokens.pop_back(); // remove the last element

        for (int i = 0; i < tokens.size(); i = i + 2)
        {
            string attrName = tokens[i];      // attribute name
            string attrValue = tokens[i + 1]; // attribute value

            // trim the quotations at the first and end of the attribute value
            attrValue = StringUtils::trimFirstAndLastChar(attrValue);
            // create attribute node
            AttributeNode *attrNode = new AttributeNode(attrName, attrValue);
            insertNodeToTree(attrNode, nodeStack, tree);
        }
    }
}

void Parser::createTagNode(const string &tagName, stack<TagNode *> &nodeStack, DomTree *&tree, const string &html)
{
    TagNode *tagNode = new TagNode(tagName);
    // if the nodes stack is empty, insert the root node
    if (nodeStack.empty())
        tree->insertChild(tagNode);
    else
    {
        insertNodeToTree(tagNode, nodeStack, tree);
    }
    nodeStack.push(tagNode); // push the new node to the stack
}

string Parser::getTextContent(const string &html, const string &tagName)
{
    string tagStart = ">";
    string tagEnd = "</" + tagName + ">";

    size_t start = html.find(tagStart);
    size_t end = html.find(tagEnd, start);

    // get the content inside the tag
    string tagContent = html.substr(start + 1, end - start - 1);

    // trim new lines and spaces from the tag content
    tagContent = StringUtils::trimNewline(tagContent);
    tagContent = StringUtils::trimSpaces(tagContent);

    // check that the tag content is text not another tag
    if (!StringUtils::startsWith(tagContent, "<") && !StringUtils::startsWith(tagContent, "</") && tagContent.length())
    {
        return tagContent;
    }
    return "";
}

void Parser::createTextNode(const string &textContent, stack<TagNode *> &nodeStack, DomTree *&tree)
{
    TextNode *textNode = new TextNode(textContent);
    insertNodeToTree(textNode, nodeStack, tree);
}

void Parser::insertNodeToTree(Node *newNode, stack<TagNode *> &nodeStack, DomTree *&tree)
{
    // set the parent node of the new node
    newNode->parent = nodeStack.top();

    // check if the parent node has a child already
    if (nodeStack.top()->firstChild)
        // insert the new node as a sibling to the child node
        tree->inserSibling(newNode, nodeStack.top()->firstChild);
    else
        // insert a new child node
        tree->insertChild(newNode, nodeStack.top());
}

DomTree *Parser::parseHTML(string plainHtml)
{
    DomTree *tree = new DomTree(); // create the DOM tree
    stack<TagNode *> nodeStack;    // TagNodes stack
    size_t pos = 0;                // position of the current character

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

            // check if the tag has attributes
            if (hasAttributes(subPlainHtml))
                createAttrTags(subPlainHtml, nodeStack, tree); // create attributes nodes and insert them to the tree

            // check if the tag is not self closed (may have text content)
            if (!isSelfClosedTag(subPlainHtml, tagName))
            {
                // get the text content of the tag
                string textContent = getTextContent(subPlainHtml, tagName);
                if (textContent.length())
                    createTextNode(textContent, nodeStack, tree);
            }
            else
                nodeStack.pop(); // remove it from the stack, because it will not have any text or tags children
        }

        // if the tag is a closing tag
        else if (plainHtml[openTagStart + 1] == '/')
            nodeStack.pop(); // pop the last tag node from the stack

        size_t closeTagStart = plainHtml.find('>', openTagStart);
        pos = closeTagStart + 1;
    }
    return tree;
}
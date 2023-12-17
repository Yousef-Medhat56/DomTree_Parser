#include <string>
#include <iostream>
#include "../include/node.h"
using namespace std;

Node::~Node()
{
    delete firstChild;
    delete nextSibling;
}

TagNode::TagNode() : tagName("")
{
    type = "tag";
    firstChild = nullptr;
    nextSibling = nullptr;
};

TagNode::TagNode(string tag) : tagName(tag)
{
    type = "tag";
    firstChild = nullptr;
    nextSibling = nullptr;
};

void TagNode::display() const
{
    cout << tagName << endl;
}

AttributeNode::AttributeNode() : attributeName(""), attributeValue("")
{
    type = "attr";
    firstChild = nullptr;
    nextSibling = nullptr;
};
AttributeNode::AttributeNode(string name, string value) : attributeName(name), attributeValue(value)
{
    type = "attr";
    firstChild = nullptr;
    nextSibling = nullptr;
};
void AttributeNode::display() const
{
    cout << attributeName << ": " << attributeValue << endl;
}

TextNode::TextNode() : text("")
{
    type = "text";
    firstChild = nullptr;
    nextSibling = nullptr;
};
TextNode::TextNode(string val) : text(val)
{
    type = "text";
    firstChild = nullptr;
    nextSibling = nullptr;
};

void TextNode::display() const
{
    cout << text << endl;
}
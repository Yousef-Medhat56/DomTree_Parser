#include <string>
#include <iostream>
#include "../include/node.h"
using namespace std;

Node::~Node()
{
    delete parent;
    delete firstChild;
    delete nextSibling;
}

string Node::getAttrName()
{
    return "";
}

string Node::getAttrVal()
{
    return "";
}

void Node::displayChildren()
{
    return;
}

TagNode::TagNode() : tagName("")
{
    type = "tag";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};

TagNode::TagNode(string tag) : tagName(tag)
{
    type = "tag";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};

void TagNode::display() const
{
    cout << tagName << endl;
}

void TagNode::displayChildren()
{
    // print the parent node
    this->display();
    cout << "|_____";

    // the first child
    Node *child = this->firstChild;
    
    // print the first child node
    child->display();
    
    //loop through the child siblings
    while (child->nextSibling)
    {
        child = child->nextSibling;
        cout << "|_____";
        // print the sibling node
        child->display();
    }
}

AttributeNode::AttributeNode() : attributeName(""), attributeValue("")
{
    type = "attr";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};
AttributeNode::AttributeNode(string name, string value) : attributeName(name), attributeValue(value)
{
    type = "attr";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};
void AttributeNode::display() const
{
    cout << attributeName << ": " << '"' << attributeValue << '"' << endl;
}

string AttributeNode::getAttrName()
{
    return attributeName;
}

string AttributeNode::getAttrVal()
{
    return attributeValue;
}

TextNode::TextNode() : text("")
{
    type = "text";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};
TextNode::TextNode(string val) : text(val)
{
    type = "text";
    parent = nullptr;
    firstChild = nullptr;
    nextSibling = nullptr;
};

void TextNode::display() const
{
    cout << '"' << text << '"' << endl;
}
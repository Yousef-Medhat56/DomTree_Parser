#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Node
{
    string type;
    Node *parent;
    Node *firstChild;
    Node *nextSibling;
    virtual void display() const = 0;
    virtual string getAttrName();
    virtual string getAttrVal();
    // display the direct children of the node
    virtual void displayChildren();
    virtual ~Node();
};

struct TagNode : Node
{
    string tagName;
    TagNode();
    TagNode(string tag);
    void display() const override;
    void displayChildren() override;
};

struct AttributeNode : Node
{
    string attributeName;
    string attributeValue;
    AttributeNode();
    AttributeNode(string name, string value);
    void display() const override;
    string getAttrName() override;
    string getAttrVal() override;
};

struct TextNode : Node
{
    string text;
    TextNode();
    TextNode(string val);
    void display() const override;
};

#endif // NODE_H
#include <iostream>
#include <string>
#include "./src/tree.cpp"
using namespace std;

int main()
{
    // Creating objects
    TagNode* tagNode = new TagNode("h1");
    AttributeNode* attributeNode = new AttributeNode("id", "myElm");
    TextNode textNode("Hello, World!");

    // Displaying information
    cout << "TagNode: ";
    tagNode->display();

    cout << "AttributeNode : ";
    attributeNode->display();

    cout << "TextNode : ";
    textNode.display();

    Tree tree;
    tree.insertChild(tagNode);
    tree.insertChild(attributeNode,tagNode);
    
    cout << "AttributeNode : ";
    tagNode->firstChild->display();
    return 0;
}
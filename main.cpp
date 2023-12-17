#include <iostream>
#include <string>
#include "./src/node.cpp"
using namespace std;

int main()
{
    // Creating objects
    TagNode tagNode("h1");
    AttributeNode attributeNode("id", "myElm");
    TextNode textNode("Hello, World!");

    // Displaying information
    cout << "TagNode: ";
    tagNode.display();

    cout << "AttributeNode : ";
    attributeNode.display();

    cout << "TextNode : ";
    textNode.display();

    return 0;
}
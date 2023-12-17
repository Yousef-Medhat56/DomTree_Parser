#include "../include/tree.h"
#include "./node.cpp"

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    delete root;
}

void Tree::insertChildRecursive(Node *newNode, Node *parent)
{
    // If the parent node has a child, traverse to the child
    if (parent->firstChild)
        insertChildRecursive(newNode, parent->firstChild);
    else
        // If the parent node does not have a child, insert the new node as its child
        parent->firstChild = newNode;
}

void Tree::insertChild(Node *newNode, Node *parent = nullptr)
{
    // Insert the given node into the tree
    if (!root)
        root = newNode;

    else
        // Check if the parent node param is provided, then call the recursive insert method
        parent ? insertChildRecursive(newNode, parent) : insertChildRecursive(newNode, root);
}
void Tree::insertSiblingRecursive(Node *newNode, Node *sibling)
{
    // If the current node has a sibling, traverse to the next sibling
    if (sibling->nextSibling)
        insertSiblingRecursive(newNode, sibling->nextSibling);
    else
        // If the current node does not have a sibling, insert the new node as its sibling
        sibling->nextSibling = newNode;
}

void Tree::inserSibling(Node *newNode, Node *sibling)
{
    // Check that the sibling node exists and doesn't equal the root,
    // because the root node cannot has siblings
    if (sibling && sibling != root)
        insertSiblingRecursive(newNode, sibling);
}

void Tree::displayRecursive(Node *current, int depth)
{

    for (int i = 0; i < depth - 1; ++i)
    {
        std::cout << "     "; // Adjust indentation based on node depth
    }

    if (depth != 0)
        cout << "|";

    if (depth != 0)
        std::cout << "_____";

    // print node information
    current->display();

    // Recursively display child nodes
    Node *child = current->firstChild;
    while (child)
    {
        displayRecursive(child, depth + 1);
        child = child->nextSibling;
    }
}

void Tree::display()
{
    if (root)
    {
        std::cout << "Tree Structure:" << std::endl;
        displayRecursive(root, 0);
    }
    else
    {
        std::cout << "Tree is empty." << std::endl;
    }
}
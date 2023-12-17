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
#ifndef TREE_H
#define TREE_H

#include "./node.h"

class Tree
{
    Node *root;
    void insertChildRecursive(Node *newNode, Node *parent);
    void insertSiblingRecursive(Node *newNode, Node *sibling);
    void displayRecursive(Node *current, int depth);

public:
    Tree();
    void insertChild(Node *newNode, Node *parent);
    void inserSibling(Node *newNode, Node *sibling);
    void display();
    ~Tree();
};

#endif

#ifndef TREE_H
#define TREE_H

#include "./node.h"

class Tree{
    Node* root;
    void insertChildRecursive(Node* newNode, Node* parent);
    void insertSiblingRecursive(Node* newNode, Node* sibling);
    
    public:
    Tree();
    void insertChild(Node* newNode, Node* parent);
    void inserSibling(Node* newNode, Node* sibling);
    ~Tree();
};

#endif

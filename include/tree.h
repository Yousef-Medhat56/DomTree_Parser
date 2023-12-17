#ifndef TREE_H
#define TREE_H

#include "./node.h"

class Tree{
    Node* root;
    void insertChildRecursive(Node* newNode, Node* parent);
    
    public:
    Tree();
    void insertChild(Node* newNode, Node* parent);
    ~Tree();
};

#endif

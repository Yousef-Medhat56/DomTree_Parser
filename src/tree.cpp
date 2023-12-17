#include "../include/tree.h"
#include "./node.cpp"

Tree::Tree(){
    root = nullptr;
}

Tree::~Tree(){
    delete root;
}
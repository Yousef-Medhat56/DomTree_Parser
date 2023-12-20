#ifndef DOM_TREE_H
#define DOM_TREE_H

#include "./tree.h"

class DomTree : public Tree
{
    // find the Attribute node, using attribute name and value
    Node *getAttrNode(string attrKey, string attrValue);
    Node *getAttrNodeRecursive(Node *current, string attrKey, string attrValue);

public:
    // get a tag node using its id attribute
    Node *getTagById(const string id);
};

#endif
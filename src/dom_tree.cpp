#include "./tree.cpp"
#include "../include/dom_tree.h"

Node *DomTree::getAttrNodeRecursive(Node *current, string attrKey, string attrValue)
{
    if (current == nullptr)
        return nullptr;

    // check if the node type is Attribute Node
    if (current->type == "attr")
    {
        // check if the attribute name and value are correct
        if (current->getAttrName() == attrKey && current->getAttrVal() == attrValue)
            return current;
    }

    // recurse on the siblings
    Node *found = getAttrNodeRecursive(current->nextSibling, attrKey, attrValue);
    if ((found != nullptr))
        return found;

    // if not found recurse on the children
    return getAttrNodeRecursive(current->firstChild, attrKey, attrValue);

    // If the key is not found in the current subtree, return NULL
    return nullptr;
};

Node *DomTree::getAttrNode(string attrKey, string attrValue)
{
    return getAttrNodeRecursive(root, attrKey, attrValue);
};

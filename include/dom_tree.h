#ifndef DOM_TREE_H
#define DOM_TREE_H

#include "./tree.h"

class DomTree : public Tree
{
public:
    // get a tag node using its id attribute
    TagNode *getTagById(const string id);
};

#endif
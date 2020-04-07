//
// Created by joey on 4/4/20.
//

#ifndef ALGORITHM_BINARY_TREE_DEF_H
#define ALGORITHM_BINARY_TREE_DEF_H

#include <cstddef>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {

    }
};
#endif //ALGORITHM_LINK_LIST_DEF_H

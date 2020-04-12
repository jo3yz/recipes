//
// Created by joey on 4/8/20.
//

#ifndef ALGORITHM_SIMPLE_H
#define ALGORITHM_SIMPLE_H

#include "binarytree/binary_tree_def.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

int binaryTreeHeight(TreeNode *root);
void binaryTreeHeightTest();
bool isBalanced(TreeNode* root);
bool isBalancedBetter(TreeNode* root);
void isBalancedTest();
vector<string> binaryTreePaths(TreeNode* root);

#endif //ALGORITHM_SIMPLE_H

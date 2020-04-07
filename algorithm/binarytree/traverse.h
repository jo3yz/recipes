//
// Created by joey on 4/7/20.
//

#ifndef ALGORITHM_TRAVERSE_H
#define ALGORITHM_TRAVERSE_H

#include "binarytree/binary_tree_def.h"
#include <iostream>
#include <stack>

using std::string;
using std::cout;
using std::endl;
using std::stack;

void postOrder(TreeNode *root);
void nonRecursivePostOrder(TreeNode *root);
void inOrder(TreeNode *root);
void nonRecursiveInOrder(TreeNode *root);
void nonRecursivePreOrder(TreeNode *root);
void preOrder(TreeNode *root);

void preOrderTest();
void inOrderTest();

#endif //ALGORITHM_TRAVERSE_H

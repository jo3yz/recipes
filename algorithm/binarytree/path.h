//
// Created by joey on 4/11/20.
//

#ifndef ALGORITHM_PATH_H
#define ALGORITHM_PATH_H


#include "binary_tree_def.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

vector<string> binaryTreePaths(TreeNode* root);
void DFS(TreeNode* root);

#endif //ALGORITHM_PATH_H

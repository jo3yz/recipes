//
// Created by joey on 4/11/20.
//

#include "binarytree/path.h"

vector<string> ret{};
string path{};

void DFS(TreeNode* root)
{
    if(!root)
        return;

    if(!root->left && !root->right)
    {
        path += std::to_string(root->val);
        ret.push_back(path);
        size_t size = std::to_string(root->val).size();
        while(size--)
            path.erase(--path.end());

        return;
    }

    path += std::to_string(root->val);
    path += "->";
    DFS(root->left);
    DFS(root->right);

    size_t size = std::to_string(root->val).size() + 2;
    while(size--)
        path.erase(--path.end());
}

vector<string> binaryTreePaths(TreeNode* root)
{
    DFS(root);
    return ret;
}
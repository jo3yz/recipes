//
// Created by joey on 4/8/20.
//

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <stack>
#include "binarytree/simple.h"

int binaryTreeHeight(TreeNode *root)
{
    if(!root)
        return 0;

    return std::max(binaryTreeHeight(root->left), binaryTreeHeight(root->right)) + 1;
}

void binaryTreeHeightTest()
{
    TreeNode n6(6);
    TreeNode n5(5);
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n4.left = &n6;

    std::cout<<binaryTreeHeight(&n1)<<std::endl;
}

bool isBalanced(TreeNode* root)
{
    bool ret = true;

    // preorder traverse
    std::stack<TreeNode *> s{};
    s.push(root);
    while(!s.empty())
    {
        TreeNode *cur = s.top();
        if(std::abs(binaryTreeHeight(cur->left) - binaryTreeHeight(cur->right)) > 1)
        {
            ret = false;
            break;
        }

        s.pop();
        if(cur->right)
            s.push(cur->right);
        if(cur->left)
            s.push(cur->left);
    }

    return ret;
}

int dfs(TreeNode* root, bool &balanced){
    if(!root)
        return 0;

    int l = dfs(root->left, balanced);
    int r = dfs(root->right, balanced);
    if(abs(l - r) > 1)
        balanced = false;
    return std::max(l, r) + 1;
}
bool isBalancedBetter(TreeNode* root)
{
    bool balanced = true;
    dfs(root, balanced);
    return balanced;
}

void isBalancedTest()
{
    TreeNode n6(6);
    TreeNode n5(5);
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n4.left = &n6;

    std::cout<<isBalanced(&n1)<<std::endl;
}

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
        path.erase(--path.end());
        return;
    }
    else
    {
        path += std::to_string(root->val);
        path += "->";
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);
    }

    size_t size = std::to_string(root->val).size() + 2;
    while(size--)
        path.erase(--path.end());
}

vector<string> binaryTreePaths(TreeNode* root)
{
    DFS(root);
    return ret;
}
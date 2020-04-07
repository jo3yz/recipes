//
// Created by joey on 4/7/20.
//

#include "binarytree/serialize.h"

string toSequence(TreeNode* root)
{
    string ret{};
    // empty tree
    if(!root)
        return "";

    if(root->left)
    {
        ret += "(" + toSequence(root->left);
    }
    else
    {
        ret += "(";
    }

    if(root->right)
    {
        ret += toSequence(root->right) + ")";
    }
    else
    {
        ret += ")";
    }


    return ret;
}

void toSequenceTest()
{
    TreeNode n5(5);
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;

    cout<<toSequence(&n1);
}

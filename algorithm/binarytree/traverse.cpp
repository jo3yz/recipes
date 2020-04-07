//
// Created by joey on 4/7/20.
//

#include "binarytree/traverse.h"

void postOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<",";
}

void nonRecursivePostOrder(TreeNode *root)
{
    if(!root)
        return;

    stack<TreeNode *> s{};
    stack<TreeNode *> ss{};
    s.push(root);
    while(!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        ss.push(node);

        if(node->left) // first left then right
            s.push(node->right);
        if(node->right)
            s.push(node->left);
    }

    while(!ss.empty())
    {
        TreeNode *n = ss.top();
        cout<<n->val;
        ss.pop();
    }
}

void inOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<<root->val<<",";
    inOrder(root->right);
}

void nonRecursiveInOrder(TreeNode *root)
{
    stack<TreeNode *> s{};
    TreeNode* cur = root;

    while(!s.empty() || cur)
    {
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        // now cur is nullptr which indicate that traverse reaches the most left and bottom position
        if(!s.empty())
        {
            cur = s.top();
            s.pop();
            cout<<cur->val<<",";
            cur = cur->right; // find the right child's the most left and bottom position
        }
    }
}

void nonRecursivePreOrder(TreeNode *root)
{
    if(!root)
        return;

    stack<TreeNode *> s{};
    s.push(root);
    while(!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        cout<<node->val<<",";

        // first right then left
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }
}

void preOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->val<<",";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderTest()
{
    TreeNode n5(5);
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    preOrder(&n1);
    cout<<endl;
    nonRecursivePreOrder(&n1);
}

void inOrderTest()
{
    TreeNode n5(5);
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    inOrder(&n1);
    cout<<endl;
    nonRecursiveInOrder(&n1);
}
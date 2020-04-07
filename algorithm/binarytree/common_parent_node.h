//
// Created by joey on 3/31/20.
//

#ifndef ALGORITHM_COMMON_PARENT_NODE_H
#define ALGORITHM_COMMON_PARENT_NODE_H

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

/*
        1
      / \
     2   3
    / \ / \
    4 5 6 7
  /\ /\ /\ /\
如上图所示，由正整数 1, 2, 3, ...组成了一棵无限大的二叉树。从某一个结点到根结点（编号是1的结点）都有一条唯一的路径，比如从5到根结点的路径是（5, 2, 1），从4到根结点的路径是（4, 2, 1），从根结点1到根结点的路径上只包含一个结点1，因此路径就是（1）。对于两个结点x和y，假设他们到根结点的路径分别是（x1, x2, ... ,1）和（y1, y2,...,1），那么必然存在两个正整数i和j，使得从xi 和yj 开始，有xi = yj，xi + 1 = yj + 1，xi + 2 = yj + 2，...
现在的问题就是，给定x和y，要求他们的公共父节点，即xi（也就是 yj）。

 */
void commomParentNode();

#endif //ALGORITHM_COMMON_PARENT_NODE_H

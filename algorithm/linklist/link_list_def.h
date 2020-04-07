#ifndef ALGORITHM_LINK_LIST_DEF_H
#define ALGORITHM_LINK_LIST_DEF_H

#include <cstddef>
#include <vector>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createList(const std::vector<int>& vals);
void printList(ListNode *head);

#endif //ALGORITHM_LINK_LIST_DEF_H

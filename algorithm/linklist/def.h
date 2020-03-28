#ifndef ALGORITHM_DEF_H
#define ALGORITHM_DEF_H

#include <cstddef>
#include <vector>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createList(const std::vector<int>& vals)
{
    ListNode head(0);
    ListNode *cur = &head;
    for(int v : vals)
    {
        cur->next = new ListNode(v);
        cur = cur->next;
    }

    return head.next;
}

void printList(ListNode *head)
{
    while(head != NULL)
    {
        std::cout<<head->val<<",";
        head = head->next;
    }
    std::cout<<std::endl;
}

#endif //ALGORITHM_DEF_H

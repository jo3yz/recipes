//
// Created by joey on 4/7/20.
//

#include "linklist/link_list_def.h"

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
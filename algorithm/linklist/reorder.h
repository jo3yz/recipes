//
// Created by joey on 3/28/20.
//

#ifndef ALGORITHM_REORDER_H
#define ALGORITHM_REORDER_H

#include "def.h"

//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

void reorderList(ListNode* head)
{
    while(head->next != NULL)
    {
        ListNode *pre = NULL;
        ListNode *cur = head->next;
        ListNode *nxt{};
        while(cur != NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = pre;
        head = head->next;
    }
}

void reorderListTest()
{
    std::vector<int> vi{1,2,3,4,5};
    ListNode *list = createList(vi);
    printList(list);
    reorderList(list);
    printList(list);
}

#endif //ALGORITHM_REORDER_H

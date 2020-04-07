//
// Created by joey on 4/7/20.
//

#include "linklist/sort.h"

ListNode *insertionSortList(ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode *dummyHead = new ListNode(-1); // the REAL head node added by user
    dummyHead->next = head;

    ListNode *prev = head;
    ListNode *cur = head->next;
    while(cur != NULL)
    {
        if(prev->val > cur->val) // cur need to insert
        {
            ListNode *temp = dummyHead;
            for(; temp->next != cur && temp->next->val < cur->val; temp = temp->next);// find insert position
            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            cur = prev->next;
        }
        else
        {
            prev = prev->next;
            cur = cur->next;
        }
    }

    return dummyHead->next;
}


void insertionSortListTest()
{
    ListNode *head = createList({1,2,5,0,9});
    printList(head);

    auto sorted = insertionSortList(head);
    printList(sorted);
}

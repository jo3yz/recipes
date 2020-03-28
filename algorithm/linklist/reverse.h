//
// Created by joey on 3/27/20.
//

#ifndef ALGORITHM_REVERSE_H
#define ALGORITHM_REVERSE_H

#include "def.h"

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(m == n)
        return head;
    if(head == NULL || head->next == NULL)
        return head;

    int count = 1;
    ListNode *start{NULL}, *end{NULL};
    ListNode *temp{};
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *nxt = NULL;

    while(cur != NULL)
    {
        if(count < m - 1 || count > n + 1)
        {
            cur = cur->next;
        }
        if(count == m - 1)
        {
            start = cur;
            cur = cur->next;
        }
        if(count >= m && count <= n)
        {
            nxt = cur->next;
            if(pre == NULL)
            {
                temp = cur;
            }
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        if(count == n + 1)
        {
            end = cur;
            cur = cur->next;
            if(start != NULL)
                start->next = pre;
            if(end != NULL)
                temp->next = end;
        }
        ++count;
    }

    if(count == n + 1)
    {
        if(start != NULL)
            start->next = pre;
        if(end != NULL)
            temp->next = end;
    }

    return start != NULL ? head : pre;
}

ListNode *reverse(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *cur = head;
    ListNode *nxt = NULL;

    while(cur != NULL)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

void reverseTest()
{
    std::vector<int> vi{1,2,3,4,5};
    ListNode *list = createList(vi);
    printList(list);
    list = reverseBetween(list,1,3);
    printList(list);
}

#endif //ALGORITHM_REVERSE_H

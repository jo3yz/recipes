//
// Created by joey on 4/7/20.
//

#include "linklist/cycle.h"

bool hasCycle(ListNode *head)
{
    bool ret = false;
    unordered_set<ListNode *> set;
    while(head != NULL)
    {
        if(set.count(head) == 0)
            set.insert(head);
        else
            return true;

        head = head->next;
    }

    return ret;
}

bool hasCycle_twoPointer(ListNode *head)
{
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return false;

    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }

    return false;
}

ListNode *detectCycle(ListNode *head)
{
    unordered_set<ListNode *> set;
    while(head != NULL)
    {
        if(set.count(head) == 0)
            set.insert(head);
        else
            return head;

        head = head->next;
    }

    return NULL;
}

ListNode *detectCycle_twoPointer(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            fast = head;
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }

    return NULL;
}
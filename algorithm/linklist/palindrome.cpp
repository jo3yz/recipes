//
// Created by joey on 4/7/20.
//

#include "linklist/palindrome.h"

// use fast/slow pointer
// time O(n) space O(1)
bool isPalindrome(ListNode* head)
{
    if(head == NULL)
        return true;
    if(head->next == NULL)
        return true;
    if(head->next->next == NULL)
        return head->next->val == head->val;

    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next)
    {
        // reverse the second half to compare
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        ListNode *nxt = NULL;
        while(cur != NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // now compare
        slow = head;
        while(pre != NULL)
        {
            if(pre->val != slow->val)
                return false;

            pre = pre->next;
            slow = slow->next;
        }
    }
    else
    {
        // reverse the second half to compare
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        ListNode *nxt = NULL;


        while(cur!= NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        slow = head;
        while(pre != NULL)
        {
            if(pre->val != slow->val)
                return false;

            pre = pre->next;
            slow = slow->next;
        }
    }

    return true;
}

bool chkPalindrome(ListNode* A)
{
    if(A == NULL)
        return true;
    if(A->next == NULL)
        return true;
    if(A->next->next == NULL)
        return A->next->val == A->val;

    ListNode *slow = A;
    ListNode *fast = A;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next)
    {
        // reverse the second half to compare
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        ListNode *nxt = NULL;
        while(cur != NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // now compare
        slow = A;
        while(pre != NULL)
        {
            if(pre->val != slow->val)
                return false;

            pre = pre->next;
            slow = slow->next;
        }
    }
    else
    {
        // reverse the second half to compare
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        ListNode *nxt = NULL;


        while(cur!= NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        slow = A;
        while(pre != NULL)
        {
            if(pre->val != slow->val)
                return false;

            pre = pre->next;
            slow = slow->next;
        }
    }

    return true;
}

void isPalindromeTest()
{
    ListNode *head = createList({1,2,3,4,4,3,2,1});
    std::cout<<isPalindrome(head);
}
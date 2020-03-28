//
// Created by joey on 3/28/20.
//

#ifndef ALGORITHM_INTERSECTION_H
#define ALGORITHM_INTERSECTION_H

#include "def.h"
#include <unordered_set>

using std::unordered_set;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA == NULL || headB == NULL)
        return NULL;

    unordered_set<ListNode *> set{0};
    while(headA != NULL)
    {
        set.insert(headA);
        headA = headA->next;
    }
    while(headB != NULL)
    {
        if(set.count(headB) == 1)
            return headB;

        headB = headB->next;
    }
}

ListNode *getIntersectionNode_twoPointer(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    ListNode* countA = headA;
    ListNode* countB = headB;
    int A = 0;
    int B = 0;
    while (countA){
        A++;
        countA = countA->next;
    }
    while (countB){
        B++;
        countB = countB->next;
    }
    while (A < B){
        headB = headB->next;
        B--;
    }
    while (A > B){
        headA = headA->next;
        A--;
    }
    while (A == B){
        if (headA == headB){
            return headA;
        }
        else{
            headA = headA->next;
            headB = headB->next;
        }
    }
    return NULL;
}

#endif //ALGORITHM_INTERSECTION_H

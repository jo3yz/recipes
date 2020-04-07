//
// Created by joey on 3/28/20.
//

#ifndef ALGORITHM_INTERSECTION_H
#define ALGORITHM_INTERSECTION_H

#include "linklist/link_list_def.h"
#include <unordered_set>

using std::unordered_set;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
ListNode *getIntersectionNode_twoPointer(ListNode *headA, ListNode *headB);

#endif //ALGORITHM_INTERSECTION_H

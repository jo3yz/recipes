//
// Created by joey on 3/28/20.
//

#ifndef ALGORITHM_CYCLE_H
#define ALGORITHM_CYCLE_H

#include "linklist/link_list_def.h"
#include <unordered_set>

using std::unordered_set;

bool hasCycle(ListNode *head);
bool hasCycle_twoPointer(ListNode *head);
ListNode *detectCycle(ListNode *head);
ListNode *detectCycle_twoPointer(ListNode *head);

#endif //ALGORITHM_CYCLE_H

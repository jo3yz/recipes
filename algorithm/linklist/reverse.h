//
// Created by joey on 3/27/20.
//

#ifndef ALGORITHM_REVERSE_H
#define ALGORITHM_REVERSE_H

#include "linklist/link_list_def.h"
#include <vector>
using std::vector;

ListNode* reverseBetween(ListNode* head, int m, int n);
ListNode *reverse(ListNode *head);
void reverseTest();
vector<int> reversePrint(ListNode* head);

#endif //ALGORITHM_REVERSE_H

//
// Created by joey on 3/28/20.
//

#ifndef ALGORITHM_REORDER_H
#define ALGORITHM_REORDER_H

#include "linklist/link_list_def.h"

//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

void reorderList(ListNode* head);
void reorderListTest();

#endif //ALGORITHM_REORDER_H

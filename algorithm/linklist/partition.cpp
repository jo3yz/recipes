//
// Created by joey on 4/7/20.
//

//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//你应当保留两个分区中每个节点的初始相对位置。

//输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5

#include "linklist/partition.h"

ListNode* partition(ListNode* head, int x)
{
    ListNode dummyLessHead(-1);
    ListNode *less = &dummyLessHead;

    ListNode dummyHead(-1);
    dummyHead.next = head;
    ListNode *pre = &dummyHead;
    ListNode *cur = head;

    while(cur != NULL)
    {
        if(cur->val < x)
        {
            pre->next = cur->next;
            less->next = cur;
            less = cur;
            cur = less->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

    less->next = dummyHead.next;
    return dummyLessHead.next;
}

void partitionTest()
{
    std::vector<int> vi{1,4,3,2,5,2};
    ListNode *list = createList(vi);
    printList(list);
    list = partition(list, 3);
    printList(list);
}
//
// Created by joey on 4/14/20.
//

#include "linklist/medium.h"

// Leetcode 445
// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
// 
//
// 进阶：如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
// 链接：https://leetcode-cn.com/problems/add-two-numbers-ii

ListNode *reverseList(ListNode *node, int &len)
{
    int l = 0;
    ListNode *pre = NULL;
    ListNode *cur = node;
    ListNode *nxt;
    while(cur)
    {
        ++l;
        nxt= cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    len = l;
    return pre;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int len1, len2;
    l1 = reverseList(l1, len1);
    l2 = reverseList(l2, len2);

    ListNode *lshort = len1 < len2 ? l1 : l2;
    ListNode *llong = len1 < len2 ? l2 : l1;

    ListNode longHead(-1);
    longHead.next = llong;
    ListNode *prelong = &longHead;

    ListNode *originLong = llong;

    int addOn = 0;
    while(lshort != NULL)
    {
        int sum = lshort->val + llong->val + addOn;
        if(sum < 10)
        {
            llong->val = sum;
            addOn = 0;
        }
        else
        {
            llong->val = sum % 10;
            addOn = 1;
        }

        lshort = lshort->next;
        llong = llong->next;
        prelong = prelong->next;
    }

    if(addOn == 1)
    {
        while(llong != NULL && ++llong->val >= 10)
        {
            llong->val = llong->val % 10;
            llong = llong->next;
            prelong = prelong->next;
        }
        if(llong == NULL)
        {
            prelong->next = new ListNode(1);
        }
    }

    int t{};
    return reverseList(originLong, t);
}

void addTwoNumbersTest()
{
    ListNode l1(7), l2(2), l3(4), l4(3);
    ListNode s1(5), s2(6), s3(4);
    l1.next = &l2; l2.next = &l3; l3.next = &l4; l4.next = NULL;
    s1.next = &s2; s2.next = &s3; s3.next = NULL;

    auto res = addTwoNumbers(&l1, &s1);
}

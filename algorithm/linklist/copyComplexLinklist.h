//
// Created by joey on 3/29/20.
//

#ifndef ALGORITHM_COPYCOMPLEXLINKLIST_H
#define ALGORITHM_COPYCOMPLEXLINKLIST_H

#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <cassert>

using std::unordered_map;
using std::unordered_set;
using std::cout;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    Node retHead(-1);
    Node *retHeadPtr = &retHead;
    unordered_map<Node *, int> index_map{}; // value can be repeated so use address instead of value
    unordered_map<int, int> random_map{};

    // init index_map
    Node *ret = NULL;
    Node *cur = head;
    int count = 0;
    while(cur != NULL)
    {
        index_map[cur] = count++;
        cur = cur->next;
    }

    // init random_map and copy the list except random pointer
    cur = head;
    count = 0;
    while(cur != NULL)
    {
        ret = new Node(*cur);
        ret->next = NULL;
        ret->random = NULL;

        // notice that the random pointer maybe NULL
        if(cur->random != NULL)
            random_map[count] = index_map[cur->random];

        // link the node
        retHeadPtr->next = ret;
        retHeadPtr = ret;
        cur = cur->next;
        count++;
    }

    // fill the random pointer
    cur = retHead.next;
    count = 0;
    while(cur != NULL)
    {
        if(random_map.count(count) != 0)
        {
            int index= random_map[count];
            Node *t = retHead.next;
            while(t != NULL)
            {
                if(index == 0)
                    break;

                index--;
                t = t->next;
            }
            cur->random = t;
        }

        cur = cur->next;
        count++;
    }

    return retHead.next;
}

void copyRandomListTest()
{
    //[[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node n4(1);
    Node n3(10);
    Node n2(11);
    Node n1(13);
    Node n0(7);

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    n0.random = NULL;
    n1.random = &n0;
    n2.random = &n4;
    n3.random = &n2;
    n4.random = &n0;

    Node *list = &n0;
    Node *copy = copyRandomList(&n0);
    while(list != NULL && copy != NULL)
    {
        assert(list != copy);
        cout<<list->val<<",";
        cout<<copy->val<<",";
        list = list->next;
        copy = copy->next;
    }
}

#endif //ALGORITHM_COPYCOMPLEXLINKLIST_H

//
// Created by joey on 3/29/20.
//

#ifndef ALGORITHM_COPY_COMPLEX_LINKLIST_H
#define ALGORITHM_COPY_COMPLEX_LINKLIST_H

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

Node* copyRandomList(Node* head);
void copyRandomListTest();
#endif //ALGORITHM_COPY_COMPLEX_LINKLIST_H

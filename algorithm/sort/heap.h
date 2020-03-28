#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <vector>

// build max heap for ASC order sort

template <typename T>
void HeapInsert(std::vector<T> &v, int index)
{
    // size_t cause error here!
    while(v[index] > v[(index - 1) / 2])
    {
        std::swap(v[index], v[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <typename T>
void Heapify(std::vector<T> &v, int index, int size)
{
    int left = 2 * index + 1;
    while(left < size)
    {
        int largest = left + 1 < size && v[left + 1] > v[left] ? left + 1 : left;
        largest = v[index] > v[largest] ? index : largest;
        if(largest == index)
            break;
        std::swap(v[index], v[largest]);
        index = largest;
        left = 2 * index + 1;
    }
}

template <typename T>
void HeapSort(std::vector<T> &v, bool order)
{
    if(v.size() < 2)
        return;
    for(int i = 0; i < v.size(); ++i)
    {
        HeapInsert(v, i);
    }
    int size = v.size();
    std::swap(v[0], v[--size]);
    while(size > 0)
    {
        Heapify(v, 0, size);
        std::swap(v[0], v[--size]);
    }
}

#endif //ALGORITHM_HEAP_H

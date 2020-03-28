#ifndef ALGORITHM_QUICK_H
#define ALGORITHM_QUICK_H

#include <vector>
#include <functional>
#include <checker.h>

template <typename T>
size_t Partition(std::vector<T> &v, size_t begin, size_t end, size_t pivot_index)
{
    size_t current = begin;
    T pivot = v[pivot_index];
    while(current <= end)
    {
        if(v[current] < pivot)
        {
            std::swap(v[current++], v[begin++]);
        }
        else if(v[current] > pivot)
        {
            std::swap(v[current], v[end--]);
        }
        else
        {
            current++;
        }
    }

    return begin;
}

template <typename T>
void QuickSort(std::vector<T> &v, size_t begin, size_t end)
{
    if(begin >= end)
        return;

    size_t mid = Partition(v, begin, end, begin);
    QuickSort(v, begin, mid);
    QuickSort(v, mid + 1, end);
}

template <typename T>
void QuickSort(std::vector<T> &v, bool order)
{
    if(v.size() < 2)
        return;
    QuickSort(v, 0, v.size() - 1);


    if(order == DES_ORDER)
        std::reverse(v.begin(), v.end());
}

void QuickTest()
{
    std::function<void(std::vector<int>&, bool)> QuickSortFunc = [](std::vector<int>& v, bool order){
        QuickSort(v, order);
    };

    std::cout << "Quick Sort Check: " << Check(QuickSortFunc) << std::endl;
}

#endif //ALGORITHM_QUICK_H

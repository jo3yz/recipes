#ifndef ALGORITHM_SIMPLE_H
#define ALGORITHM_SIMPLE_H

#include <vector>
#include <functional>
#include "checker.h"

template <typename T>
void BubbleSort(std::vector<T> &v, bool order)
{
    for(auto i = v.size(); i > 1; --i)
    {
        for(auto j = 0; j < i - 1; ++j)
        {
            if(order == ASC_ORDER)
            {
                if(v[j] > v[j+1])
                    std::swap(v[j], v[j+1]);
            }
            else
            {
                if(v[j] < v[j+1])
                    std::swap(v[j], v[j+1]);
            }

        }
    }
}

template <typename T>
void SelectSort(std::vector<T> &v, bool order)
{
    for(auto i = v.size() - 1; i > 0; --i)
    {
        size_t index = 0;
        for(auto j = 0; j <= i; ++j)
        {
            if(order == ASC_ORDER)
            {
                if(v[index] < v[j])
                {
                    index = j;
                }
            }
            else
            {
                if(v[index] > v[j])
                {
                    index = j;
                }
            }
        }
        std::swap(v[index], v[i]);
    }
}

template <typename T>
void InsertSort(std::vector<T> &v, bool order)
{
    for(auto i = 1; i < v.size(); ++i)
    {
        if(order == ASC_ORDER)
        {
            if(v[i] < v[i-1])
            {
                auto j = i;
                while(j > 0 && v[j] < v[j-1])
                {
                    std::swap(v[j], v[j-1]);
                    --j;
                }
            }
        }
        else
        {
            if(v[i] > v[i-1])
            {
                auto j = i;
                while(j > 0 && v[j] > v[j-1])
                {
                    std::swap(v[j], v[j-1]);
                    --j;
                }
            }
        }
    }
}

void SimpleTest()
{
    std::function<void(std::vector<int>&, bool)> InsertSortFunc = [](std::vector<int>& v, bool order){
        InsertSort(v, order);
    };
    std::cout << "Insert Sort Check: " << Check(InsertSortFunc) << std::endl;
    std::function<void(std::vector<int>&, bool)> BubbleSortFunc = [](std::vector<int>& v, bool order){
        BubbleSort(v, order);
    };
    std::cout << "Bubble Sort Check: " << Check(BubbleSortFunc) << std::endl;
    std::function<void(std::vector<int>&, bool)> SelectSortFunc = [](std::vector<int>& v, bool order){
        SelectSort(v, order);
    };
    std::cout << "Select Sort Check: " << Check(SelectSortFunc) << std::endl;
}

#endif //ALGORITHM_SIMPLE_H

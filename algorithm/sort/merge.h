#ifndef ALGORITHM_MERGE_H
#define ALGORITHM_MERGE_H

#include <vector>
#include "checker.h"

template <typename T>
void MergeSort(std::vector<T> &v, bool order)
{
    PostOrder(v, 0, v.size() - 1, order);
}

template <typename T>
void PostOrder(std::vector<T> &v, size_t begin, size_t end, bool order)
{
    // array has been divided
    if(begin == end)
        return;

    size_t mid = begin + (end - begin) / 2;

    PostOrder(v, begin, mid, order);
    PostOrder(v, mid + 1, end, order);

    // 现现the status of each division is now stored in calling stack

    // now merge every small array which is ordered
    Merge(v, begin, mid, end, order);
}

template <typename T>
void Merge(std::vector<T> &v, size_t begin, size_t mid, size_t end, bool order)
{
    std::vector<T> temp{};

    size_t i = begin;
    size_t j = mid + 1;
    while(i <= mid && j <= end)
    {
        if(order == ASC_ORDER)
        {
            if(v[i] < v[j])
            {
                temp.push_back(v[i++]);
            }
            else
            {
                temp.push_back(v[j++]);
            }
        }
        else
        {
            if(v[i] > v[j])
            {
                temp.push_back(v[i++]);
            }
            else
            {
                temp.push_back(v[j++]);
            }
        }
    }
    while(i <= mid)
    {
        temp.push_back(v[i++]);
    }
    while(j <= end)
    {
        temp.push_back(v[j++]);
    }

    for(size_t ii = begin, jj = 0; ii <= end; ++ii, ++jj)
    {
        v[ii] = temp[jj];
    }
}

template <typename T>
void NonRecursive_MergeSort(std::vector<T> &v, bool order)
{
    for(size_t i = 1; i < v.size(); i*=2)
    {
        for(size_t j = 0; ; j += (2 * i))
        {
            bool flag = false;
            size_t begin = j;
            size_t end = j + (2 * i -1);
            if(end > v.size() - 1)
            {
                end = v.size() - 1;
                flag = true;
            }
            size_t mid = (begin + end) / 2;
            Merge(v, begin, mid, end, order);
            if(flag)
                break;
        }
    }
}

int SmallSum_Traverse(std::vector<int> &v)
{
    int sum{0};
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(v[j] < v[i])
                sum += v[j];
        }
    }
    return sum;
}

void SmallSum(std::vector<int> &v, size_t begin, size_t end, int &sum)
{
    if(begin == end)
        return;

    size_t mid = (begin + end) / 2;

    SmallSum(v, begin, mid, sum);
    SmallSum(v, mid+1, end, sum);

    std::vector<int> temp{};
    size_t i = begin;
    size_t j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(v[i] < v[j])
        {
            sum += (v[i] * (end - j + 1));
            temp.push_back(v[i++]);
        }
        else
        {
            temp.push_back(v[j++]);
        }
    }

    while(j <= end)
    {
        temp.push_back(v[j++]);
    }
    while(i <= mid)
    {
        temp.push_back(v[i++]);
    }
}

void ReversePair(std::vector<int> &v, size_t begin, size_t end, int &num)
{
    if(v.size() == 0 || v.size() == 1)
    {
        num = 0;
        return;
    }

    if(begin == end)
        return;

    size_t mid = (begin + end) / 2;

    ReversePair(v, begin, mid, num);
    ReversePair(v, mid+1, end, num);


    std::vector<int> temp{};

    size_t i = begin;
    size_t j = mid + 1;
    while(i <= mid && j <= end)
    {
        if(v[i] <= v[j])
        {
            temp.push_back(v[i++]);
        }
        else
        {
            std::cout<<"i:"<<i<<" j:"<<j<<std::endl;
            num += (mid - i + 1);
            temp.push_back(v[j++]);
        }
    }
    while(i <= mid)
    {
        temp.push_back(v[i++]);
    }
    while(j <= end)
    {
        temp.push_back(v[j++]);
    }

    for(size_t ii = begin, jj = 0; ii <= end; ++ii, ++jj)
    {
        v[ii] = temp[jj];
    }
}

void MergeTest()
{
    std::function<void(std::vector<int>&, bool)> MergeSortFunc = [](std::vector<int>& v, bool order){
        MergeSort(v, order);
    };

    std::cout << "Merge Sort Check: " << Check(MergeSortFunc) << std::endl;
}

void NonRecursive_MergeSortTest()
{
    std::function<void(std::vector<int>&, bool)> NonRecursive_MergeSortFunc = [](std::vector<int>& v, bool order){
        NonRecursive_MergeSort(v, order);
    };

    std::cout << "Non-Recursive Merge Sort Check: " << Check(NonRecursive_MergeSortFunc) << std::endl;
}

#endif //ALGORITHM_MERGE_H

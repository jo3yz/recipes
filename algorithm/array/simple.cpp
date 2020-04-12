//
// Created by joey on 4/12/20.
//

#include "array/simple.h"

int Fibonacci(int n)
{
    int dp[40];
    dp[0] = 0;
    dp[1] = 1;
    if(n == 0 || n == 1)
        return dp[n];
    else
    {
        for(int i = 2; i < 40; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    return dp[n];
}

int findShortestUnordered(std::vector<int> A, int n)
{
    // the begin of the sub-array which is unsorted
    int begin = n-1;
    // the end of the sub-array which is unsorted
    int end = 0;

    int max = A[0], min = A[n-1];
    for(int i = 0; i < n; i++)
    {
        if(max <= A[i])
            max = A[i];
        else
            end = i;
    }
    for(int i = n-1;i >= 0;i--)
    {
        if(min >= A[i])
            min = A[i];
        else
            begin = i;
    }

    return begin < end ? end-begin+1 : 0;
}

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, std::list<int>> m{};
    for(int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]].push_back(i);
    }

    std::sort(nums.begin(), nums.end());

    int i = 0, j = 1;
    while(i < nums.size())
    {
        while(j < nums.size())
        {
            if(nums[i] + nums[j] == target)
            {
                if(nums[i] != nums[j])
                    return {m[nums[i]].front(), m[nums[j]].front()};
                else
                    return {m[nums[i]].front(), m[nums[j]].back()};
            }
            else if(nums[i] + nums[j] > target)
            {
                break;
            }
            else
            {
                ++j;
            }
        }
        ++i;
        j = i + 1;
    }
    return {};
}

void testTwoSum()
{
    std::vector<int> vi{3,2,3};
    auto ret = twoSum(vi, 6);
    std::cout<<ret[0]<<","<<ret[1];
}
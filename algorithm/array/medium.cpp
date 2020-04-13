//
// Created by joey on 4/12/20.
//
#include "array/medium.h"

// offer 56.1
// a^0 = a
// a^a = 0
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
vector<int> singleNumbers(vector<int>& nums)
{
    if(nums.empty())
        return {};

    int a{0}, b{0}, aXorb{0};

    // get aXorb
    for(auto num : nums)
    {
        aXorb = aXorb ^ num;
    }

    // 1. find the lsb positive bit of aXorb which indicate that  a is different with b in this bit
    // 2. assume that a is positive in this bit
    // 3. Xor all number if they have positive bit in same position, the result is a
    int mask = aXorb & (~aXorb + 1);
    for(auto num : nums)
    {
        if(num & mask)
        {
            a = a ^ num;
        }
    }

    // b = a ^ b ^ a = a ^ a ^ b
    b = aXorb ^ a;

    return {a, b};
}

// offer 56.2
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了3次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
int singleNumberHash(vector<int>& nums)
{
    int xorSum{0};
    unordered_multiset<int> s{};
    for(auto num : nums)
    {
        s.insert(num);
        xorSum = xorSum ^ num;
        if(s.count(num) == 3)
            xorSum = xorSum ^ num;
    }

    return xorSum;
}

// offer 56.2
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了3次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
int singleNumber(vector<int>& nums)
{
    int ans{0};
    for(int i = 0; i < 32; ++i)
    {
        int count{0};
        for(auto num : nums)
        {
            if(num & (1 << i))
                ++count;
        }
        if(count % 3 != 0)
            ans = ans | (1 << i);
    }

    return ans;
}
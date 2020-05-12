//
// Created by joey on 4/12/20.
//

//#include <strings.h>
#include <stack>
#include <memory>
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
// pair: value - first_index
std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int,int> numMap{};
    for(int i = 0; i < nums.size(); ++i)
    {
        if(numMap.count(nums[i]) == 0)
            numMap[nums[i]] = i;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        int compliment = target - nums[i];
        if(numMap.count(compliment) != 0)
        {
            int j = numMap[compliment];
            if(i != j)
                return {i, j};
        }
    }

    return {};
}

void testTwoSum()
{
    std::vector<int> vi{3,2,4};
    auto ret = twoSum(vi, 6);
    std::cout<<ret[0]<<","<<ret[1];
}

int climbStairsDFS(int n)
{
    if(n == 1 || n == 0)
        return n;

    int ret = 0;

    std::stack<int> s{};
    s.push(n);
    while(!s.empty())
    {
        auto ans = s.top();
        s.pop();
        if(ans == 0)
            ++ret;

        if((ans - 2) >= 0)
            s.push(ans - 2);
        if((ans - 1) >= 0)
            s.push(ans - 1);
    }

    return ret;
}

int climbStairs(int n)
{
    if(n <= 2)
        return n;

    int dp1 = 1;
    int dp2 = 2;

    for(int i = 3; i <= n; ++i)
    {
        int temp = dp2;
        dp2 = dp1 + dp2;
        dp1= temp;
    }

    return dp2;
}

std::vector<int> shortestToChar(std::string S, char C)
{
    std::vector<int> vi{};
    vi.resize(S.length());

    int lastLeftMin = INT32_MAX;

    for(size_t i = 0; i < S.size(); ++i)
    {
        if(S[i] == C)
        {
            vi[i] = 0;
            lastLeftMin = 0;
            continue;
        }
        else
        {
            int rightMin = S.find_first_of(C, i) - i;
            vi[i] = std::min(rightMin, ++lastLeftMin);
        }
    }

    return vi;
}

void shortestToCharTest()
{
    std::string s{"aaba"};
    auto res = shortestToChar(s, 'b');
}

void moveZeroes(std::vector<int>& nums)
{
    int j = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }

    while(j < nums.size())
    {
        nums[j] = 0;
        ++j;
    }
}

bool isStraight(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    int zeroNum = std::count_if(nums.begin(), nums.end(), [](int &num){
        return num == 0;
    });

    if(zeroNum == 5)
        return true;

    if(zeroNum != 0)
    {
        nums.erase(nums.begin(), nums.begin() + zeroNum);
    }

    int gap = 0;
    for(auto iter = nums.begin(); iter != (nums.end() - 1); ++iter)
    {
        if(*(iter  + 1) == (*iter))
        {
            return false;
        }
        gap += *(iter  + 1) - (*iter) - 1;
    }

    return gap <= zeroNum;
}
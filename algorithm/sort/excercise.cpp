//
// Created by joey on 4/7/20.
//

#include "excercise.h"

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

int findShortestUnorder(std::vector<int> A, int n)
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

int longestPalindrome(std::string s)
{
    int len{0};
    bool oddFlag = false;
    std::array<int, 52> arr{};
    arr.fill(0);
    for(const char &c : s)
    {
        if(std::islower(c))
        {
            arr[c - 'a']++;
        }
        if(std::isupper(c))
        {
            arr[26 + c - 'A']++;
        }
    }
    for(const int &count : arr)
    {
        if(count%2 == 1)
        {
            oddFlag = true;
            len += (count - 1);
        }
        else
        {
            len += count;
        }
    }
    if(oddFlag)
        len += 1;

    return len;
}

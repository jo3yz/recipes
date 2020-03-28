#ifndef ALGORITHM_EXCERCISE_H
#define ALGORITHM_EXCERCISE_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <array>
#include <unordered_map>

class Info
{
public:
    Info() = default;

    // less<T> will call this
    bool operator<(const Info &other) const
    {
        if(score != other.score)
            return score < other.score;
        else
            return index < other.index;
    }

    // greater<T> will call this
    bool operator>(const Info &other) const
    {
        if(score != other.score)
            return score > other.score;
        else
            return index < other.index;
    }
    std::string name;
    int score{};
    int index{};
};

void Test()
{
    int num{};
    int order{};
    std::vector<Info> infos;

    while (std::cin >> num >> order)
    {
        infos.clear();
        infos.resize(num);

        for (int i = 0; i < num; ++i) {
            std::cin >> infos[i].name >> infos[i].score;
            infos[i].index = i;
        }

        if (order == 0)
            std::sort(infos.begin(), infos.end(), std::greater<Info>());
        else
            std::sort(infos.begin(), infos.end(), std::less<Info>());

        for (int i = 0; i < num; ++i) {
            std::cout << infos[i].name << " " << infos[i].score << std::endl;
        }
    }
}

bool Find(int target, std::vector<std::vector<int>> array)
{
    bool exist = false;
    for(const std::vector<int> &v : array)
    {
        if(v.empty())
            return false;
        if(v[0] <= target && v[v.size() - 1] >= target)
        {
            if(std::binary_search(v.begin(), v.end(), target))
            {
                exist = true;
                break;
            }
        }
    }
    return exist;
}


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


#endif //ALGORITHM_EXCERCISE_H

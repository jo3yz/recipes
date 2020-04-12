//
// Created by joey on 4/12/20.
//

#include "string/simple.h"

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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <array/medium.h>
#include <array/simple.h>

bool isStraight(vector<int>& nums)
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

int main()
{
    vector<int> vi{11,0,9,0,0};
    isStraight(vi);
    return 0;
}
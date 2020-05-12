#include <iostream>

#include "array/hard.h"

int main()
{
    vector<int> vi{ 1,3,-1,-3,5,3,6,7 };
    auto r = maxSlidingWindow(vi, 3);

    return 0;
}
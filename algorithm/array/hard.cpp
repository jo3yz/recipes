#include "hard.h"
#include <iostream>
#include <algorithm>

//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 暴力法：把所有的柱子的组合都枚举一次(超时)

// 分治法：每个区间的最大面积是以下三者之一：(超时)
// 1. 最低的高度 * 区间长度
// 2. 左边的最大面积
// 3. 右边的最大面积
int largestAreaHelper(vector<int> &heights, vector<int>::const_iterator left, vector<int>::const_iterator right)
{
    if(left == right)
        return 0;
    if (left + 1 == right)
        return *left;

    auto iter = min_element(left, right);
    int flatArea = *iter * (right - left);
    int leftArea = largestAreaHelper(heights, left, iter);       // [)
    int rightArea = largestAreaHelper(heights, iter + 1, right); // [)

    return max(max(leftArea, rightArea), flatArea);
}

int largestRectangleArea(vector<int> &heights)
{
    if (heights.size() == 0)
        return 0;

    if (heights.size() == 1)
        return heights[0];

    return largestAreaHelper(heights, heights.cbegin(), heights.cend());
}
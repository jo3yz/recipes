#include "hard.h"
#include <iostream>
#include <algorithm>
#include <stack>

//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 暴力法：把所有的柱子的组合都枚举一次(超时)
// O(n*n*n)

// 分治法：每个区间的最大面积是以下三者之一：(超时)
// 1. 最低的高度 * 区间长度
// 2. 左边的最大面积
// 3. 右边的最大面积
// 最好O(nlogn)
// 最坏O(n*n)

int largestAreaCurHelper(vector<int> &heights, vector<int>::const_iterator left, vector<int>::const_iterator right)
{
    if (left == right)
        return 0;
    if (left + 1 == right)
        return *left;

    auto iter = min_element(left, right);
    int flatArea = *iter * (right - left);
    int leftArea = largestAreaCurHelper(heights, left, iter);       // [)
    int rightArea = largestAreaCurHelper(heights, iter + 1, right); // [)

    return max(max(leftArea, rightArea), flatArea);
}

int largestRectangleAreaRecur(vector<int> &heights)
{
    if (heights.size() == 0)
        return 0;

    if (heights.size() == 1)
        return heights[0];

    return largestAreaCurHelper(heights, heights.cbegin(), heights.cend());
}

// 单调栈法

// 如何维护一个单调栈：
// 1. 先入一个最小的Min值，比如-1
// 2. 依次扫描数字
// 3. 如果待加入到栈顶的新数字，使栈内元素连续，就加入它
// 4. 如果待加入到栈顶的新数组，使栈内元素不连续了，就挨个弹栈，直到加入新元素使栈内元素连续

// 单调栈的性质：
// 一个元素从栈顶出栈时：
// 1. 新进的元素是它右边第一个比它小的元素
// 2. 新成为栈顶的元素是左边第一个比它小的元素

// 思路：
// 1. 把每个元素为最低高度的面积都找出来，里面的最大值就是所求的解
// 2. 以某元素为最低高度的面积怎么找？
// 3. 可以用到单调栈的性质，（待加入到堆顶的序号 - 1）就是矩形的右边界，（新栈顶 + 1）就是矩形的左边界
// 4. 矩形的宽 = 右边界 - 左边界 - 1， 矩形的高：就是该元素

int largestRectangleArea(vector<int> &heights)
{
    if (heights.size() == 0)
        return 0;
    if (heights.size() == 1)
        return heights[0];

    int ret = 0;
    int h, l, r;
    std::stack<int> s{}; // stack里面存序号
    heights.push_back(0);

    for (std::size_t i = 0; i < heights.size(); ++i)
    {
        while (!s.empty() && heights[s.top()] > heights[i])
        {
            h = heights[s.top()];
            r = i;

            s.pop();

            l = s.empty() ? -1 : s.top();

            cout << "h: " << h << endl;
            cout << "l: " << l << endl;
            cout << "r: " << r << endl;

            ret = std::max(ret, h * (r - l - 1));
        }

        s.push(i);
    }

    return ret;
}
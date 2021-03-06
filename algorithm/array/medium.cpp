//
// Created by joey on 4/12/20.
//
#include <numeric>
//#include <strings.h>
#include <iostream>
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

// leetcode 542
// 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
// 两个相邻元素间的距离为 1 。
// 给定矩阵的元素个数不超过 10000。
// 给定矩阵中至少有一个元素是 0。
// 矩阵中的元素只在四个方向上相邻: 上、下、左、右。
// 链接：https://leetcode-cn.com/problems/01-matrix

// DFS: stack overflow
// TODO: DP
vector<vector<bool>> visited;
void UpdateMatrixDFS(vector<vector<int>>& matrix, int i, int j)
{
    // find available next position
    vector<pair<int, int>> availPos{};
    if(i >= 0 && j >= 0)
    {
        if(i < matrix.size() && j + 1 < matrix[0].size())
            availPos.emplace_back(i, j + 1);

        if(i < matrix.size() && j - 1 >= 0)
            availPos.emplace_back(i, j - 1);

        if(i + 1 < matrix.size() && j < matrix[0].size())
            availPos.emplace_back(i + 1, j);

        if(i - 1 >= 0 && j < matrix[0].size())
            availPos.emplace_back(i - 1, j);
    }

    for(auto &pos : availPos)
    {
        if(matrix[pos.first][pos.second] == 0)
        {
            matrix[i][j] = 1;
            return;
        }
    }

    bool visitFlag = false;
    int aroundShortestVisited = INT32_MAX - 1;
    for(auto iter = availPos.begin(); iter != availPos.end(); )
    {
        if(visited[iter->first][iter->second] == true)
        {
            visitFlag = true;
            aroundShortestVisited = min(aroundShortestVisited, matrix[iter->first][iter->second]);
            iter = availPos.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    int aroundShortestUnvisited = INT32_MAX - 1;
    for(auto &pos : availPos)
    {
        UpdateMatrixDFS(matrix, pos.first, pos.second);
        visited[pos.first][pos.second] = true;
        aroundShortestUnvisited = min(aroundShortestUnvisited, matrix[pos.first][pos.second]);
    }

    if(visitFlag)
    {
        matrix[i][j] = min(aroundShortestVisited, aroundShortestUnvisited) + 1;
        return;
    }
    else
    {
        matrix[i][j] = aroundShortestUnvisited + 1;
        return;
    }
}
vector<vector<int>> updateMatrixDFS(vector<vector<int>>& matrix)
{
    size_t height = matrix.size();
    size_t width = matrix[0].size();

    visited.resize(height);
    for(auto &vec : visited)
    {
        vec.resize(width);
        vec.assign(vec.size(), false);
    }

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if(matrix[i][j] >= 1 && !visited[i][j])
            {
                UpdateMatrixDFS(matrix, i, j);
            }
        }
    }

    return matrix;
}


void updateMatrixTest()
{
    vector<vector<int>> vvi= {{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
    auto ans =  updateMatrixDFS(vvi);
    int a = 0;
}

vector<int> retTemp{};

void PermuteDFS(vector<vector<int>> &ret, vector<int> availNums)
{
    if(availNums.empty())
    {
        ret.push_back(retTemp);
        retTemp.pop_back();
        return;
    }

    for(auto iter = availNums.begin(); iter != availNums.end(); ++iter)
    {
        retTemp.push_back(*iter);
        vector<int> v(availNums);
        v.erase(v.begin() + (iter - availNums.begin()));
        PermuteDFS(ret, v);
    }

    retTemp.pop_back();
}

long fac(int val)
{
    vector<int> v;
    v.reserve(val);
    for(int i=1;i<=val;++i)
    {
        v.push_back(i);
    }


    return std::accumulate( v.begin(), v.end(), 1, std::multiplies<int>() );

}

// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ret;

    ret.reserve(fac(nums.size()));
    retTemp.reserve(nums.size());

    PermuteDFS(ret, nums);

    return ret;
}

void permuteTest()
{
    vector<int> vv{1,2,3};
    auto ans = permute(vv);
    int a = 0;
}

// LCOF 03
// 2 <= n <= 100000
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof

int findRepeatNumber(vector<int>& nums)
{
    std::unordered_set<int> s{};
    for(auto &num : nums)
    {
        if(s.count(num) != 0 )
            return num;
        else
            s.insert(num);
    }

    return -1;
}

int findRepeatNumberBitmap(vector<int>& nums)
{
    const auto bitmapSize = 100000;
    unsigned char bitmap[bitmapSize / 8 + 1];
    memset(bitmap, 0, sizeof(bitmap));

    for(auto &num : nums)
    {
        unsigned char byte = bitmap[(num / 8)];
        unsigned char mask = 0x80 >> (num % 8);

        if(byte & mask)
            return num;
        else
            bitmap[(num / 8)] |= mask;
    }

    return -1;
}

void findRepeatNumberTest()
{
    vector<int> vi = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    auto ans  = findRepeatNumberBitmap(vi);

    int a = 0;
}

int maxArea(vector<int>& height)
{
    int ret = -1;
    int k = 0;
    for(int i = 0; i < height.size(); )
    {
        int j = height.size() - 1;

        while(i < j)
        {
            // calc
            int area = std::min(height[i], height[j]) * (j - i);
            ret = std::max(ret, area);

            // move j
            for(k = j - 1; i < k; --k)
            {
                if(height[k] > height[j])
                {
                    j = k;
                    break;
                }
            }

            if(k == i)
                break;
        }

        // move i
        for(k = i + 1; k < height.size(); ++k)
        {
            if(height[k] > height[i])
            {
                i = k;
                break;
            }
        }
        if(k == height.size())
            break;
    }

    return ret;
}


//若向内移动短板，水槽的短板 min(h[i], h[j])min(h[i],h[j]) 可能变大，因此水槽面积 S(i, j)S(i,j) 可能增大。
//若向内移动长板，水槽的短板 min(h[i], h[j])min(h[i],h[j]) 不变或变小，下个水槽的面积一定小于当前水槽面积。
//因此，向内收窄短板可以获取面积最大值。
//链接：https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/

int maxAreaBetter(vector<int>& height)
{
    int ret = -1;
    int i = 0, j = height.size() - 1;
    while(i < j)
    {
        int area = std::min(height[i], height[j]) * (j - i);
        ret = std::max(ret, area);

        if(height[i] < height[j])
            ++i;
        else
            --j;
    }

    return ret;
}

void maxAreaTest()
{
    // j = 8 6
    // i
    vector<int> vi{1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(vi) << std::endl;
    std::cout << maxAreaBetter(vi) << std::endl;
}

// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
// 
//
//示例：
//
//给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/3sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ret;
    if(nums.size() < 3)
        return ret;

    if(nums.size() == 3)
    {
        if(nums[0] + nums[1] + nums[2] == 0)
        {
            ret.push_back(nums);
        }
        return ret;
    }

    std::sort(nums.begin(), nums.end());
    for(size_t k = 0; k < nums.size(); ++k)
    {
        if(nums[k] > 0)
            break;
        if(k != 0)
        {
            if(nums[k] == nums[k - 1])
                continue;
        }

        for(size_t i = k + 1, j = nums.size() - 1; i < j; )
        {
            int sum = nums[k] + nums[i] + nums[j];
            if(sum == 0)
            {
                ret.push_back({nums[k], nums[i], nums[j]});

                do{ ++i; }
                while(i < j && nums[i] == nums[i - 1]);
                do{ --j; }
                while(i < j && nums[j] == nums[j + 1]);
            }
            else if(sum < 0)
            {
                do{ ++i; }
                while(i < j && nums[i] == nums[i - 1]);

            }
            else // sum > 0
            {
                do{ --j; }
                while(i < j && nums[j] == nums[j + 1]);
            }
        }
    }

    return ret;
}
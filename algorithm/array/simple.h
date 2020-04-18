//
// Created by joey on 4/12/20.
//

#ifndef ALGORITHM_ARRAY_SIMPLE_H
#define ALGORITHM_ARRAY_SIMPLE_H

#include <vector>
#include <unordered_map>
#include <array>
#include <list>
#include <algorithm>
#include <iostream>


int Fibonacci(int n);
int findShortestUnordered(std::vector<int> A, int n);
std::vector<int> twoSum(std::vector<int>& nums, int target);
void testTwoSum();

// leetcode 70
int climbStairsDFS(int n);
int climbStairs(int n);

// leetcode 821
std::vector<int> shortestToChar(std::string S, char C);
void shortestToCharTest();

// leetcode 283
void moveZeroes(std::vector<int>& nums);

// LCOF 61
bool isStraight(std::vector<int>& nums);

#endif //ALGORITHM_SIMPLE_H

//
// Created by joey on 4/12/20.
//

#ifndef ALGORITHM_MEDIUM_H
#define ALGORITHM_MEDIUM_H

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <algorithm>
#include <unordered_set>

using std::vector;
using std::unordered_multiset;
using std::min;
using std::abs;
using std::pair;
using std::remove;

vector<int> singleNumbers(vector<int>& nums);
int singleNumber(vector<int>& nums);

vector<vector<int>> updateMatrixDFS(vector<vector<int>>& matrix);
void updateMatrixTest();

vector<vector<int>> permute(vector<int>& nums);
void permuteTest();

int findRepeatNumber(vector<int>& nums);
void findRepeatNumberTest();

#endif //ALGORITHM_MEDIUM_H

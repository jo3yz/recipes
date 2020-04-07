#ifndef ALGORITHM_CHECKER_H
#define ALGORITHM_CHECKER_H

#include <algorithm>
#include <functional>
#include <random>
#include <iostream>

enum {
    ASC_ORDER = 0,
    DES_ORDER = 1
};

bool Check(std::function<void(std::vector<int>&, bool)> func);


#endif //ALGORITHM_CHECKER_H

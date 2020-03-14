#ifndef ALGORITHM_CHECKER_H
#define ALGORITHM_CHECKER_H

#include <algorithm>
#include <functional>
#include <random>
#include <iostream>


enum {
    ASC_ORDER = 0, // ÉýÐò
    DES_ORDER = 1  // ½µÐò
};

bool Check(std::function<void(std::vector<int>&, bool)> func)
{
    std::random_device seed_device;
    std::default_random_engine engine(seed_device());
    std::uniform_int_distribution<int> distribution(-10000,10000);

    uint16_t times = 16;
    uint16_t maxLen = 8192;

    while(--times)
    {
        std::vector<int> v1{};
        std::vector<int> v2{};
        for(auto i = maxLen; i > 0; --i)
        {
            int random_val = distribution(engine);
            v1.push_back(random_val);
            v2.push_back(random_val);
        }

        func(v1, ASC_ORDER);
        std::sort(v2.begin(), v2.end(), std::less<int>());
        if(v1 != v2)
        {
            return false;
        }

        func(v1, DES_ORDER);
        std::sort(v2.begin(), v2.end(), std::greater<int>());
        if(v1 != v2)
        {
            return false;
        }
    }

    return true;
}

#endif //ALGORITHM_CHECKER_H

#include <iostream>
#include "factory.h"

namespace gof {
    void ProductA::Print() {
        std::cout << "Product A" << std::endl;
    }

    void ProductB::Print() {
        std::cout << "Product B" << std::endl;
    }

}


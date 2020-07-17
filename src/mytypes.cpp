#include <iostream>
#include "mytypes.h"


void print_vectorint(vectorint& _vec)
{
    vectorint::iterator el_it = _vec.begin();
    vectorint::iterator end_vec = _vec.end();

    std::cout << "[";

    while (el_it != end_vec) {
        std::cout << (*el_it);
        if ((el_it + 1) != end_vec) {
            std::cout << ", ";
        }
        el_it++;
    }

    std::cout << "]";
}


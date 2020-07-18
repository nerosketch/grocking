/* 
 * File:   mytypes.h
 * Author: ns
 *
 * Created on June 14, 2020, 11:40 PM
 */

#ifndef MYTYPES_H
#define MYTYPES_H

#include <vector>
#include <iostream>

typedef std::vector<int> vectorint;


template<class T>
void print_iterable(std::ostream& out, T& _iterable)
{
    auto el_it = _iterable.begin();
    auto end_vec = _iterable.end();

    out << "[";

    while (el_it != end_vec) {
        out << (*el_it);
        el_it++;
        if (el_it != end_vec) {
            out << ", ";
        }
    }

    out << "]";
}

template<class T>
void print_iterable(T& _iterable)
{
    print_iterable(std::cout, _iterable);
}


std::ostream& operator<<(std::ostream& out, vectorint& _vec);


#endif /* MYTYPES_H */


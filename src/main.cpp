/* 
 * File:   main.cpp
 * Author: ns
 *
 * Created on June 14, 2020, 8:39 PM
 */

#include <cstdlib>
#include <iostream>
#include "sort_algs.h"
#include "search_algs.h"
#include "archs.h"

using namespace std;

#define OUT(fun) std::cout << "======================" << std::endl; fun(); std::cout << std::endl;

int main (int argc, char** argv)
{
    OUT(test_sort_pick)
    OUT(test_bin_search)
    OUT(test_sum)
    return 0;
}

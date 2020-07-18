#include <vector>
#include <iostream>
#include "archs.h"
#include "mytypes.h"

using namespace std;


static int recursive_sum(vectorint::iterator it, const vectorint::const_iterator& end_it)
{
    if (it == end_it) {
        return 0;
    }

    return *it + recursive_sum(it + 1, end_it);
}


static int sum(vectorint& vec)
{
    vectorint::size_type vec_size = vec.size();
    if (vec_size == 0) {
        return 0;
    } else if (vec_size == 1) {
        return vec[0];
    }

    return recursive_sum(vec.begin(), vec.end());
}


static void check_arr(vectorint& arr, const int expected_res)
{
    cout << "Исходный массив: " << arr << endl;

    int res = sum(arr);

    cout << "  - Их сумма: " << res << " А должна быть " << expected_res << "!";
    if (res == expected_res)
    {
        cout << " Всё правильно :)";
    } else {
        cout << " Не правильно...";
    }
    cout << endl;
}


void test_sum()
{
    cout << "-=Сумма элементов=-" << endl;

    vectorint arr = {1, 3, 4, 5, 7, 8, 9};
    check_arr(arr, 37);

    arr = {1, 3};
    check_arr(arr, 4);

    arr = {};
    check_arr(arr, 0);

    arr = {3};
    check_arr(arr, 3);

    arr = {5, 6};
    check_arr(arr, 11);
}

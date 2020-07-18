#include <vector>
#include <algorithm>
#include <iostream>
#include "sort_algs.h"
#include "mytypes.h"

using namespace std;


/*
 * Сортировка выбором
 */

static vectorint sort_pick(vectorint& arr)
{
    vectorint new_arr;
    int arr_size = arr.size();

    while (arr_size > 0) {
        auto min_elem_it = min_element(arr.begin(), arr.end());
        //int min_elem_index = distance(arr.begin(), min_elem_it);

        cout << "Нашли самый маленький: " << *min_elem_it << endl;

        new_arr.push_back(
                *min_elem_it
        );
        arr.erase(min_elem_it);
        arr_size--;
    }

    return new_arr;
}


void test_sort_pick()
{
    cout << "-=Сортировка выбором=-" << endl;
    vectorint arr = {5, 2, 8, 3, 6, 1, 9};

    cout << "Исходный массив: " << arr << endl;

    vectorint res = sort_pick(arr);
    cout << "Получилось: " << res << endl;
}


/*
 * Быстрая сортировка
 */

static vectorint myqsort(const vectorint& arr)
{
    const vectorint::size_type arr_size = arr.size();

    // базовый случай
//    cout << "---------myqsort----------" << endl << "arr_size:" << arr_size << endl;
    if (arr_size < 2) {
        return arr;
    }

    const int pivot = arr[0];
    vectorint less;
    less.reserve(arr_size);
    for (const int el : arr) {
        if (el < pivot) {
            less.push_back(el);
        }
    }
    cout << "less:" << less << endl;

    vectorint greater;
    greater.reserve(arr_size);
    for (const int el : arr) {
        if (el > pivot) {
            greater.push_back(el);
        }
    }
    cout << "greater:" << greater << endl;

    vectorint sorted_less_and_res = myqsort(less);
    vectorint sorted_greater = myqsort(greater);

    sorted_less_and_res.reserve(sorted_less_and_res.size() + sorted_greater.size() + 1);
    sorted_less_and_res.insert(sorted_less_and_res.end(), pivot);
    sorted_less_and_res.insert(sorted_less_and_res.end(), sorted_greater.begin(), sorted_greater.end());
    cout << "result:" << sorted_less_and_res << endl;
    return sorted_less_and_res;
}


void test_myqsort()
{
    cout << "-=Быстрая сортировка=-" << endl;

    {
        vectorint arr = {5, 2, 8, 3, 6, 1, 9};

        cout << "Исходный массив: " << arr << endl;

        vectorint res = myqsort(arr);
        cout << "Получилось: " << res << endl;
    }

    {
        vectorint arr = {5, 2, 8, 3, 6, 1, 9, 4, 7, 15, 10, 20, 11, 17, 12, 18, 13, 19, 14, 17, 15, 16};

        cout << "Исходный массив: " << arr << endl;

        vectorint res = myqsort(arr);
        cout << "Получилось: " << res << endl;
    }
}

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "sort_algs.h"
#include "mytypes.h"

using namespace std;


static vectorint sort_pick(vectorint& arr)
{
  vectorint new_arr;
  int arr_size = arr.size();

  while(arr_size > 0)
  {
      vectorint::iterator min_elem_it = min_element(arr.begin (), arr.end());
      //int min_elem_index = distance(arr.begin(), min_elem_it);

      cout << "Found el: " << *min_elem_it << endl;

      new_arr.push_back(
        *min_elem_it
      );
      arr.erase (min_elem_it);
      arr_size --;
  }

  return new_arr;
}


void test_sort_pick()
{
  vectorint arr = {5, 2, 8, 3, 6, 1, 9};

  cout << "Исходный массив: ";
  for(const auto& el : arr)
  {
      cout << el << ", ";
  }
  cout << endl;

  vectorint res = sort_pick(arr);
  cout << "Получилось: ";
  for(const auto& el : res)
  {
      cout << el << ", ";
  }
  cout << endl;
}

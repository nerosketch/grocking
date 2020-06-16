/* 
 * File:   mytypes.h
 * Author: ns
 *
 * Created on June 14, 2020, 11:40 PM
 */

#ifndef MYTYPES_H
#define MYTYPES_H

#include <vector>

typedef std::vector<int> vectorint;

// std::ostream& operator<< (std::ostream& sout, vectorint& _vec)
//{
//  vectorint::iterator end_vec = _vec.end ();
//  for (vectorint::iterator el_it = _vec.begin(); el_it != end_vec; el_it ++)
//  {
//    sout << (*el_it) << ", ";
//  }
//  sout << (*end_vec) << std::endl;
//
//  return sout;
//}


void print_vectorint(vectorint& _vec);


#endif /* MYTYPES_H */


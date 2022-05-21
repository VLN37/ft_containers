//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 20/05/2022

#include <iostream>
#include <exception>
#include <algorithm>
#include <sstream>

#ifdef STD
namespace ft = std;
# include <set>
#else
# include "set.hpp"
# include "pair.hpp"
# include "iterator_funcs.hpp"
# include "algo.hpp"
#endif

#define TIMES 1000000

template<typename Var>
void printvar(Var var) {
  std::cout << var << '\n';
}

template<typename Var>
void printpair(Var pair) {
  std::cout << pair.first << " " << pair.second << "\n";
}

template<typename Var>
void printiterator(Var it) {
  std::cout << *it << "\n";
}

template<typename T>
void print(T const& vec) {
  typename T::const_iterator it1 = vec.begin();
  typename T::const_iterator it2 = vec.end();
  for (; it1 != it2; it1++) {
    std::cout << *it1 << " ";
  }
  std::cout << '\n';
}

int main(void) {
{
  ft::set<int> set1;

  for (int i = 0; i < TIMES; i++)
    set1.insert(i);
  for (int i = TIMES - TIMES / 3; i < TIMES - TIMES / 2; i++)
    set1.erase(i);
}

{
  ft::set<int> set1;

  for (int i = 0; i < TIMES; i++)
    set1.insert(i);
  for (int i = 0; i < TIMES; i++)
    set1.find(i);
  ft::set<int> set2(set1);
  set2.erase(set2.begin(), set2.end());
}


}

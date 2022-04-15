// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 14/04/2022
// Last modified: 14/04/2022

#include <iostream>
#include <algorithm>

#ifdef STD
namespace ft = std;
# include <vector>
#else
# include "iterator.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
#endif

template<typename T>
void out(int var) {
  std::cout << var << ' ';
}

template<typename T>
void print(T& vec) {
  std::for_each(vec.begin(), vec.end(), out<T>);
  std::cout << '\n';
}

template<typename Var>
void printvar(Var var) {
  std::cout << var << '\n';
}

template<typename T>
void reverse_print(T& vec) {
	std::for_each(vec.rbegin(), vec.rend(), out<T>);
	std::cout << '\n';
}

int main(void) {
{
  ft::vector<int> vec;

  std::cout << "resize()\n\n";

  for (int i = 0; i < 11; i++)
    vec.push_back(i);
  print(vec);
  reverse_print(vec);

  vec.resize(15, 42);
  print(vec);
  printvar(vec.size());
  printvar(vec.capacity());

  vec.resize(5, 42);
  print(vec);
  printvar(vec.size());
  printvar(vec.capacity());

  vec.resize(15, 0);
  print(vec);
  printvar(vec.size());
  printvar(vec.capacity());
}

{
  std::cout << "push_back()\n\n";

  ft::vector<int> vec(10);
  for (int i = 0; i < 11; i++)
    vec.push_back(i);
}
  return 0;
}

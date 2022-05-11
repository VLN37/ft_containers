//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 15/04/2022

#include <iostream>
#include <exception>
#include <algorithm>

#ifdef STD
namespace ft = std;
# include <vector>
# include <stack>
#else
# include "iterator_vector.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "algo.hpp"
#endif

void out(int var) {
  std::cout << var << ' ';
}

template<typename T>
void print(T& vec) {
  std::for_each(vec.begin(), vec.end(), out);
  std::cout << '\n';
}

template<typename Var>
void printvar(Var var) {
  std::cout << var << '\n';
}

template<typename T>
void reverse_print(T& vec) {
	std::for_each(vec.rbegin(), vec.rend(), out);
	std::cout << '\n';
}

template<typename T>
bool bool_pred(T const& var1, T const& var2) {
  return var1 == var2;
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

  vec.reserve(25);
  print(vec);
  printvar(vec.size());
  printvar(vec.capacity());
}

{
  std::cout << "[ ELEMENT ACCESS ]\n\n";

  ft::vector<int> vec;
  for (int i = 0; i < 11; i++)
    vec.push_back(i);

  printvar(vec[0]);
  printvar(vec[5]);
  printvar(vec[10]);
  vec[10] = 42;
  printvar(vec[10]);
  vec.push_back(66);
  printvar(vec[11]);
  printvar(vec.back());
  printvar(vec.front());
  printvar(vec.at(11));
  printvar(vec.size());
  vec.pop_back();
  printvar(vec.size());
  try {
    printvar(vec.at(42));
  } catch (...) {
    std::cout << "lulz\n";
  }
  print(vec);
  vec.clear();
  print(vec);
}

{
  std::cout << "[ ITERATORS ]\n\n";

  ft::vector<int> vec;
  ft::vector<int>::iterator it1;
  ft::vector<int>::iterator it2(it1);

  for (int i = 0; i < 11; i++)
    vec.push_back(i);
  it2 = it1;
  it2 = vec.begin() + 5;
  *it2 = 42;
  print(vec);
  printvar(*it2);
  printvar(*++it2);
  printvar(*it2++);
  printvar(*it2);
  it1 = vec.begin();
  it2 = vec.end();
  printvar(it1 != it2);
  printvar(it1 == it2);
  printvar(it1 >= it2);
  printvar(it1 <= it2);
  printvar(it1 < it2);
  printvar(it1 > it2);
  printvar(*(it1 + 5));
  printvar(*(it2 - 5));
  printvar(it1[3]);
  printvar(*(2 + it1 + 2));
}

{
  std::cout << "[ ITERATOR NON MEMBER OVERLOADS ]\n";

  ft::vector<int> vec;
  for (int i = 0; i < 11; i++)
    vec.push_back(i);

  ft::vector<int>::iterator it1(vec.begin());
  ft::vector<int>::const_iterator it2(vec.end() - 3);

  printvar(it1 != it2);
  printvar(it1 == it2);
  printvar(it1 >= it2);
  printvar(it1 <= it2);
  printvar(it1 < it2);
  printvar(it1 > it2);
  printvar(it2 != it1);
  printvar(it2 == it1);
  printvar(it2 >= it1);
  printvar(it2 <= it1);
  printvar(it2 < it1);
  printvar(it2 > it1);
  std::cout << *(it1) << '\n';
  std::cout << *(it2) << '\n';
  printvar(*(it2 - 5));
  printvar(it1[3]);
  printvar(*(2 + it1 + 2));
}

{
  std::cout << "[ MEMBER FUNCTIONS ]\n";

  ft::vector<int> vec1;
  for (int i = 0; i < 11; i++)
    vec1.push_back(i);
  ft::vector<int> vec2(vec1);

  ft::vector<int>::iterator it1 = vec1.begin();

  print(vec1);
  vec1.erase(it1 + 5);
  print(vec1);
  vec1.erase(vec1.begin() + 3, vec1.end());
  print(vec1);
  vec1.clear();
  print(vec1);
  it1 = vec2.begin() + 2;
  vec1.swap(vec2);
  print(vec1);
  printvar(*it1);
  vec1.insert(vec1.begin() + 5, 42);
  print(vec1);
  vec1.insert(vec1.begin() + 1, 5, 21);
  print(vec1);
  vec1.insert(vec1.end(), 5, 42);
  print(vec1);
  vec1.insert(vec1.begin(), 5, 13);
  print(vec1);
  vec1.assign(3, 42);
  print(vec1);
  ft::vector<int> tmp(vec1.begin(), vec1.end());
  vec2 = tmp;
  print(vec1);
  print(vec2);
  vec2.assign(10, 42);
  print(vec2);
  vec1.assign(10, 21);
  print(vec2);
  vec1.assign(vec1.begin(), vec1.end());
  print(vec2);
  vec1.insert(vec1.begin() + 5, vec2.begin(), vec2.end());
  print(vec1);
  print(vec2);
  ft::vector<int> vec3(vec2.begin(), vec2.end());
  print(vec3);
  ft::vector<int> vec4(5, 50);
  print(vec4);
  while (vec4.size()) {
    vec4.pop_back();
    print(vec4);
  }
}

{
  std::cout << "STANDALONE ALGO / DISTANCE / ADVANCE\n\n";
  ft::vector<int> vec1;
  for (int i = 0; i < 30; i++)
    vec1.push_back(i);
  ft::vector<int> vec2;
  for (int i = 0; i < 15; i++)
    vec2.push_back(i);
  ft::vector<int> vec3;
  for (int i = 0; i < 45; i++)
    vec3.push_back(i);
  vec3[10] = 11;
  ft::vector<int> vec4(vec3);
  std::cout << ft::distance(vec1.begin(), vec1.end()) << '\n';
  ft::vector<int>::iterator it1 = vec1.begin();
  ft::advance(it1, 5);
  std::cout << *it1 << '\n';
  vec2.assign(5, 42);
  vec3.assign(10, 42);
  std::cout << ft::lexicographical_compare
    (vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << '\n';
  std::cout << ft::lexicographical_compare
    (vec2.begin(), vec2.end(), vec1.begin(), vec1.end()) << '\n';
  std::cout << ft::equal
    (vec2.begin(), vec2.end(), vec3.begin()) << '\n';
  std::cout << ft::equal
    (vec4.begin(), vec4.end(), vec3.begin()) << '\n';
  std::cout << ft::equal
    (vec2.begin(), vec2.end(), vec3.begin()) << '\n';
  std::cout << ft::equal
    (vec2.begin(), vec2.end(), vec3.begin(), bool_pred<int>) << '\n';
  std::cout << ft::equal
    (vec4.begin(), vec4.end(), vec3.begin(), bool_pred<int>) << '\n';
  std::cout << ft::equal
    (vec2.begin(), vec2.end(), vec3.begin(), bool_pred<int>) << '\n';

  std::cout << "\nVECTOR COMPARISON OPERATORS\n\n";

  std::cout << (vec2 == vec3) << '\n';
  std::cout << (vec2 >= vec3) << '\n';
  std::cout << (vec2 <= vec3) << '\n';
  std::cout << (vec2 != vec3) << '\n';
  std::cout << (vec2 > vec3)  << '\n';
  std::cout << (vec2 < vec3)  << '\n';
}

{
  std::cout << "STACK\n";

  ft::stack<int> stk1;
  std::cout << stk1.empty() << '\n';
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
    std::cout << stk1.top() << " ";
  }
  std::cout << '\n';
  std::cout << stk1.size() << '\n';
  while (stk1.size())
    stk1.pop();
  std::cout << stk1.empty() << " empty\n\n";
  ft::stack<int> stk2(stk1);
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';
  std::cout << (stk1 >= stk2) << '\n';
  std::cout << (stk1 <= stk2) << '\n';
  std::cout << (stk1  < stk2) << '\n';
  std::cout << (stk1  > stk2) << '\n';
}


// {
//   ft::vector<int> vec1;
//   for (int i = 0; i < 100000; i++)
//     vec1.push_back(i);
//   ft::vector<int> vec2;
//   vec2.assign(vec1.begin() + 200, vec1.begin() + 5200);
//   ft::vector<int>::iterator it1 = vec1.begin();
//   for (int i = 0; i < 10000000; i++) {
//     for (; it1 != vec1.end(); it1++)
//       *it1 += 50;
//   }
//   vec1.erase(vec1.begin(), vec1.begin() + 100);
// }

  return 0;
}

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

std::string next_string(bool reset = false) {
  static size_t nbr = 0;
  std::stringstream stream;
  std::string       str;

  if (reset == true) {
    nbr = 0;
    return str;
  }
  stream << "string" << nbr++;
  stream >> str;
  return str;
}

int main(void) {
  std::cout << "this compiles!\n";

{
  // constructors
  ft::set<int> set1;
  int i = 0;
  std::cout << set1.empty() << '\n';
  for (; i < 42; i++)
    set1.insert(i);
  ft::set<int> set2(set1);
  ft::set<int> set3 = set2;
  ft::set<int> set4(set1.begin(), set1.end());
  std::cout << set1.empty() << '\n';
  std::cout << set1.size() << '\n';
  std::cout << (set1 == set2) << '\n';
  std::cout << (set1 == set3) << '\n';
  std::cout << (set1 == set4) << '\n';

  //count
  std::cout << set1.count(42) << '\n';
  std::cout << set1.count(21) << '\n';

  ft::set<int>::iterator it1;
  ft::set<int>::iterator it2;
  it1 = set1.find(12);
  it2 = set1.find(13);

  //key compare && value compare
  ft::set<int>::value_compare val_comp = set1.value_comp();
  ft::set<int>::key_compare key_comp = set1.key_comp();

  std::cout << val_comp(*it1, *it2) << '\n';
  std::cout << val_comp(*it1, *it1) << '\n';
  std::cout << key_comp(*it1, *it2) << '\n';
  std::cout << key_comp(*it1, *it1) << '\n';
}
{
  //iterators
  ft::set<int> set1;
  int i = 0;
  for (; i < 42; i++)
    set1.insert(i);
  ft::set<int>::iterator it1 = set1.begin();
  ft::set<int>::iterator it2 = set1.end();
  for (; it1 != it2; it1++)
    std::cout << *it1 << ' ';
  std::cout << '\n';
  ft::set<int>::const_iterator cit1 = set1.begin();
  ft::set<int>::const_iterator cit2 = set1.end();
  for (; cit1 != cit2; cit1++)
    std::cout << *cit1 << ' ';
  std::cout << '\n';
  ft::set<int>::reverse_iterator rit1 = set1.rbegin();
  ft::set<int>::reverse_iterator rit2 = set1.rend();
  for (; rit1 != rit2; rit1++)
    std::cout << *rit1 << ' ';
  std::cout << '\n';
  ft::set<int>::const_reverse_iterator crit1 = set1.rbegin();
  ft::set<int>::const_reverse_iterator crit2 = set1.rend();
  for (; crit1 != crit2; crit1++)
    std::cout << *crit1 << ' ';
  std::cout << '\n';

  //compare different iterators
  it1 = set1.begin();
  it2 = ++set1.begin();
  cit1 = set1.begin();
  std::cout << (it1 == cit1) << '\n';
  std::cout << (it1 != cit1) << '\n';
  std::cout << (crit1 == rit1) << '\n';
  std::cout << (crit1 != rit1) << '\n';
  next_string(true);
}
{
  //modifiers
  ft::set<int> set1;
  int i = 0;
  for (; i < 42; i++)
    set1.insert(i);

  // upper bound lower bound equal range
  printiterator(set1.upper_bound(21));
  printiterator(set1.upper_bound(0));
  printiterator(set1.lower_bound(21));
  printiterator(set1.lower_bound(0));
  // printiterator(set1.equal_range(21).first);
  // printiterator(set1.equal_range(21).second);
  // printiterator(set1.equal_range(12).first);
  // printiterator(set1.equal_range(12).second);

  //insert position
  set1.insert(set1.upper_bound(500), 500);
  print(set1);
  ft::set<int> map2;
  //insert range
  map2.insert(set1.find(10), set1.find(21));
  print(map2);

  //erase key
  set1.erase(12);
  set1.erase(12);
  print(set1);

  //erase range
  set1.erase(set1.upper_bound(10), set1.upper_bound(21));
  print(set1);

  // relational operators
  std::cout << (set1 == map2) << '\n';
  std::cout << (set1 != map2) << '\n';
  std::cout << (set1 <= map2) << '\n';
  std::cout << (set1 >= map2) << '\n';
  std::cout << (set1 < map2) << '\n';
  std::cout << (set1 > map2) << '\n';
}

}

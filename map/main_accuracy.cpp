//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 20/05/2022

#include <iostream>
#include <exception>
#include <algorithm>
#include <sstream>

#ifdef STD
namespace ft = std;
# include <map>
#else
# include "map.hpp"
# include "pair.hpp"
# include "iterator_funcs.hpp"
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
  std::cout << it->first << " " << it->second << "\n";
}

template<typename T>
void print(T const& vec) {
  typename T::const_iterator it1 = vec.begin();
  typename T::const_iterator it2 = vec.end();
  for (; it1 != it2; it1++) {
    std::cout << it1->first << " ";
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
  ft::map<int, std::string> map1;
  int i = 0;
  std::cout << map1.empty() << '\n';
  for (; i < 42; i++)
    map1.insert(ft::make_pair(i, next_string()));
  ft::map<int, std::string> map2(map1);
  ft::map<int, std::string> map3 = map2;
  ft::map<int, std::string> map4(map1.begin(), map1.end());
  std::cout << map1.empty() << '\n';
  std::cout << map1.size() << '\n';
  std::cout << (map1 == map2) << '\n';
  std::cout << (map1 == map3) << '\n';
  std::cout << (map1 == map4) << '\n';

  //count
  std::cout << map1.count(42) << '\n';
  std::cout << map1.count(21) << '\n';

  //find
  ft::map<int, std::string>::iterator it1;
  ft::map<int, std::string>::iterator it2;
  it1 = map1.find(12);
  it2 = map1.find(13);
  printiterator(it1);
  printiterator(it2);

  //key compare && value compare
  ft::map<int, std::string>::value_compare val_comp = map1.value_comp();
  ft::map<int, std::string>::key_compare key_comp = map1.key_comp();

  std::cout << val_comp(*it1, *it2) << '\n';
  std::cout << val_comp(*it1, *it1) << '\n';
  std::cout << key_comp(it1->first, it2->first) << '\n';
  std::cout << key_comp(it1->first, it1->first) << '\n';
}
{
  //iterators
  ft::map<int, std::string> map1;
  int i = 0;
  for (; i < 42; i++)
    map1.insert(ft::make_pair(i, next_string()));
  ft::map<int, std::string>::iterator it1 = map1.begin();
  ft::map<int, std::string>::iterator it2 = map1.end();
  for (; it1 != it2; it1++)
    std::cout << it1->first << ' ';
  std::cout << '\n';
  ft::map<int, std::string>::const_iterator cit1 = map1.begin();
  ft::map<int, std::string>::const_iterator cit2 = map1.end();
  for (; cit1 != cit2; cit1++)
    std::cout << cit1->first << ' ';
  std::cout << '\n';
  ft::map<int, std::string>::reverse_iterator rit1 = map1.rbegin();
  ft::map<int, std::string>::reverse_iterator rit2 = map1.rend();
  for (; rit1 != rit2; rit1++)
    std::cout << rit1->first << ' ';
  std::cout << '\n';
  ft::map<int, std::string>::const_reverse_iterator crit1 = map1.rbegin();
  ft::map<int, std::string>::const_reverse_iterator crit2 = map1.rend();
  for (; crit1 != crit2; crit1++)
    std::cout << crit1->first << ' ';
  std::cout << '\n';

  //compare different iterators
  it1 = map1.begin();
  it2 = ++map1.begin();
  cit1 = map1.begin();
  std::cout << (it1 == cit1) << '\n';
  std::cout << (it1 != cit1) << '\n';
  std::cout << (crit1 == rit1) << '\n';
  std::cout << (crit1 != rit1) << '\n';
  next_string(true);
}
{
  //modifiers
  ft::map<int, std::string> map1;
  int i = 0;
  for (; i < 42; i++)

  // upper bound lower bound equal range
    map1.insert(ft::make_pair(i, next_string()));
  printiterator(map1.upper_bound(21));
  printiterator(map1.upper_bound(0));
  printiterator(map1.lower_bound(21));
  printiterator(map1.lower_bound(0));
  printiterator(map1.equal_range(21).first);
  printiterator(map1.equal_range(21).second);
  printiterator(map1.equal_range(12).first);
  printiterator(map1.equal_range(12).second);

  // bracket operator
  std::cout << map1[21] << '\n';

  //insert position
  map1.insert(map1.upper_bound(500), ft::make_pair(500, next_string()));
  print(map1);
  ft::map<int, std::string> map2;
  //insert range
  map2.insert(map1.find(10), map1.find(21));
  print(map2);

  //erase key
  map1.erase(12);
  map1.erase(12);
  print(map1);

  //erase range
  map1.erase(map1.upper_bound(10), map1.upper_bound(21));
  print(map1);

  // relational operators
  std::cout << (map1 == map2) << '\n';
  std::cout << (map1 != map2) << '\n';
  std::cout << (map1 <= map2) << '\n';
  std::cout << (map1 >= map2) << '\n';
  std::cout << (map1 < map2) << '\n';
  std::cout << (map1 > map2) << '\n';
}
}

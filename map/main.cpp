//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 11/05/2022

#include <iostream>
#include "map.hpp"
#include "pair.hpp"

int main(void) {
  std::cout << "this compiles!\n";

  ft::map<std::string, int> map1;
  ft::map<std::string, int> map2(map1);
  ft::map<std::string, int> map3 = map2;

  std::cout << "size    : " << map1.size() << '\n';
  std::cout << "empty   : " << map1.empty() << '\n';
  std::cout << "max size: " << map1.max_size() << '\n';
  map1.clear();
  map1.swap(map2);
  std::cout << "DUPLICATE KEY TEST #########################################\n";
  std::cout << map1.insert(ft::pair<std::string, int>("a", 1)).second << '\n';
  std::cout << "size    : " << map1.size() << '\n';
  std::cout << map1.insert(ft::pair<std::string, int>("a", 1)).second << '\n';
  std::cout << "size    : " << map1.size() << '\n';
  std::cout << map1.insert(ft::pair<std::string, int>("a", 1)).second << '\n';
  std::cout << "size    : " << map1.size() << '\n';
  map1.insert(ft::pair<std::string, int>("b", 2));
  map1.insert(ft::pair<std::string, int>("c", 3));
  std::cout << "size    : " << map1.size() << '\n';

  map1.print();
  std::cout << "ITERATOR ###################################################\n";
  ft::map<std::string, int>::iterator it1 = map1.begin();
  ft::map<std::string, int>::iterator ite1 = map1.end();
  for (; it1 != ite1; ++it1)
    std::cout << *it1 << '\n';
  std::cout << "REV ITERATOR ###############################################\n";
  ft::map<std::string, int>::rev_iterator rit1 = map1.rbegin();
  ft::map<std::string, int>::rev_iterator rite1 = map1.rend();
  for (; rit1 != rite1; ++rit1)
    std::cout << *rit1 << '\n';
  std::cout << "CONST ITERATOR #############################################\n";
  ft::map<std::string, int>::const_iterator cit1 = map1.begin();
  ft::map<std::string, int>::const_iterator cite1 = map1.end();
  for (; cit1 != cite1; ++cit1)
    std::cout << *cit1 << '\n';
  std::cout << "CONST REV ITERATOR #########################################\n";
  ft::map<std::string, int>::c_rev_iterator crit1 = map1.rbegin();
  ft::map<std::string, int>::c_rev_iterator crite1 = map1.rend();
  for (; crit1 != crite1; ++crit1)
    std::cout << *crit1 << '\n';

  ft::map<char, int> map5;
  char c = 'a';
  int  i = 0;
  for (; i < 20; ++i, ++c)
    map5.insert(ft::pair<const char, int>(c, i));
  map5.print();
  ft::map<char, int> map6;
  map6.insert(map5.begin(), map5.end());
  map5.print();
  map6.print();
  std::cout << *map5.find('a') << '\n';
  std::cout << *map5.find('d') << '\n';
  std::cout << *map5.find('z') << '\n';
  std::cout << map5.count('z') << ' ' << map5.count('a') << '\n';

}

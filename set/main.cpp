//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 15/05/2022

#include <iostream>
#include <set>
#include "set.hpp"
#include "pair.hpp"
#include "iterator_funcs.hpp"

int main(void) {
  std::cout << "this compiles!\n";

{
  std::cout << "########################################### CONSTRUCTOR TEST\n";
  ft::set<int> set1;
  ft::set<int> set2(set1);
  ft::set<int> set3 = set2;

  std::cout << "size    : " << set1.size() << '\n';
  std::cout << "empty   : " << set1.empty() << '\n';
  std::cout << "max size: " << set1.max_size() << '\n';
  set1.clear();
  set1.swap(set2);
  std::cout << "######################################### DUPLICATE KEY TEST\n";
  std::cout << set1.insert((1)).second << '\n';
  std::cout << "size    : " << set1.size() << '\n';
  std::cout << set1.insert((1)).second << '\n';
  std::cout << "size    : " << set1.size() << '\n';
  std::cout << set1.insert((1)).second << '\n';
  std::cout << "size    : " << set1.size() << '\n';
  std::cout << set1.insert((2)).second << '\n';
  std::cout << "size    : " << set1.size() << '\n';
  std::cout << set1.insert((3)).second << '\n';
  std::cout << "size    : " << set1.size() << '\n';
  set1.print();
  std::cout << "################################################### ITERATOR\n";
  ft::set<int>::iterator it = set1.begin();
  ft::set<int>::iterator ite = set1.end();
  for (; it != ite; ++it)
    std::cout << *it << '\n';
  std::cout << "############################################### REV ITERATOR\n";
  ft::set<int>::reverse_iterator rit1 = set1.rbegin();
  ft::set<int>::reverse_iterator rite1 = set1.rend();
  for (; rit1 != rite1; ++rit1)
    std::cout << *rit1 << '\n';
  std::cout << "############################################# CONST ITERATOR\n";
  ft::set<int>::const_iterator cit1 = set1.begin();
  ft::set<int>::const_iterator cite1 = set1.end();
  for (; cit1 != cite1; ++cit1)
    std::cout << *cit1 << '\n';
  std::cout << "######################################### CONST REV ITERATOR\n";
  ft::set<int>::const_reverse_iterator crit1 = set1.rbegin();
  ft::set<int>::const_reverse_iterator crite1 = set1.rend();
  for (; crit1 != crite1; ++crit1)
    std::cout << *crit1 << '\n';
}

{
  std::cout << "################################################ INSERT TEST\n";
  ft::set<char> set;
  char c = 'a';
  for (; c < 'a' + 20; ++c)
    set.insert(c);
  set.print();
  ft::set<char> set2;
  set2.insert(set.begin(), set.end());
  set.print();
  set2.print();
  std::cout << *set.find('a') << '\n';
  std::cout << *set.find('d') << '\n';
  std::cout << *set.find('z') << '\n';
  std::cout << set.count('z') << ' ' << set.count('a') << '\n';
}

}


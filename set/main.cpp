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

{
  std::cout << "########################################### INSERT WITH HINT\n";
  ft::set<char> set;
  ft::set<char>::iterator it1;
  ft::set<char>::iterator it2;
  char c = 'a';
  for (; c < 'a' + 20; ++c)
    set.insert(c);
  set.print();
  it1 = set.begin();
  it2 = set.begin(); it2++;
  set.insert(it2, ++c);
  set.insert(set.find('z'), ++c);
  set.print();
  it1 = set.begin();
  it2 = set.end();
  std::cout << "############################################# ERASE ITERATOR\n";
  set.erase(it1);
  set.print();
  for (char ch = 'b'; ch < 'r'; ch++)
    set.erase(ch);
  set.print();
}

{
  std::cout << "################################################ ERASE RANGE\n";
  ft::set<char> set;
  ft::set<char>::iterator it1;
  ft::set<char>::iterator it2;
  char c = 'a';
  for (; c < 'a' + 20; ++c)
    set.insert(c);
  set.print();
  set.erase(set.begin(), set.end());
  set.print();
}

{
  std::cout << "###################################### KEY COMPARE ASSESSORS\n";
  ft::set<char> set;
  ft::set<char>::iterator it1;
  ft::set<char>::iterator it2;
  char c = 'a';
  for (; c < 'a' + 20; ++c)
    set.insert(c);
  set.print();
  it1 = set.begin();
  it2 = set.begin();
  ft::set<char>::key_compare   key_comp = set.key_comp();
  ft::set<char>::value_compare val_comp = set.value_comp();
  std::cout << key_comp(*it1, *it2) << '\n';
  std::cout << val_comp(*it1, *it2) << '\n';
  it2++;
  std::cout << key_comp(*it1, *it2) << '\n';
  std::cout << val_comp(*it1, *it2) << '\n';
  std::cout << "################################################ EQuAL RANGE\n";
  std::cout << "find h: " << *set.equal_range('h').first << '\n';
  std::cout << "find b: " << *set.equal_range('b').first << '\n';
  std::cout << "find c: " << *set.equal_range('c').first << '\n';
  std::cout << "################################################ UPPER BOUND\n";
  std::cout << "find h: " << *set.upper_bound('h') << '\n';
  std::cout << "find b: " << *set.upper_bound('b') << '\n';
  std::cout << "find c: " << *set.upper_bound('c') << '\n';
  std::cout << "################################################ LOWER BOUND\n";
  std::cout << "find a: " << *set.lower_bound('a') << '\n';
  set.erase('a');
  std::cout << "find a: " << *set.lower_bound('a') << '\n';
  std::cout << "find b: " << *set.lower_bound('b') << '\n';
}

{
  std::cout << "########################################## RANGE CONSTRUCTOR\n";
  ft::set<char> set;
  ft::set<char>::iterator it1;
  ft::set<char>::iterator it2;
  char c = 'a';
  for (; c < 'a' + 20; ++c)
    set.insert(c);
  set.print();
  it1 = set.upper_bound('g');
  it2 = set.lower_bound('p');
  std::cout << "upper bound: " << *it1 << '\n';
  std::cout << "lower bound: " << *it2 << '\n';
  ft::set<char> set2(it1, it2);
  set.print();
  set2.print();
}

}


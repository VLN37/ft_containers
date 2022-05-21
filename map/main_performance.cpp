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

#define TIMES 1000000

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
{
  ft::map<std::string, int> map1;
  std::stringstream ss;
  std::string str;

  for (int i = 0; i < TIMES; i++) {
    ss << i << " ", ss >> str;
    map1.insert(ft::make_pair(str, i));
  }
}

{
  ft::map<int, std::string> map1;

  for (int i = 0; i < TIMES; i++)
    map1.insert(ft::make_pair(i, next_string()));
  for (int i = TIMES - TIMES / 3; i < TIMES - TIMES / 2; i++)
    map1.erase(i);
}

{
  ft::map<int, std::string> map1;

  for (int i = 0; i < TIMES; i++)
    map1.insert(ft::make_pair(i, next_string()));
  for (int i = 0; i < TIMES; i++)
    map1[i] = i + 1;
  for (int i = 0; i < TIMES; i++)
    map1.find(i);
  ft::map<int, std::string> map2(map1);
  map2.erase(map2.begin(), map2.end());
}

}

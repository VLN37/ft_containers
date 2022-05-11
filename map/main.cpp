//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 11/05/2022

#include <iostream>
#include "map.hpp"

int main(void) {
  std::cout << "this compiles!\n";

  ft::map<std::string, int> map1;
  ft::map<std::string, int> map2(map1);
  ft::map<std::string, int> map3 = map2;

  std::cout << "size    : " << map1.size() << '\n';
  std::cout << "empty   : " << map1.empty() << '\n';
  std::cout << "max size: " << map1.max_size() << '\n';
}

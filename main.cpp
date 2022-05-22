//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 20/05/2022

#include "containers.hpp"

/**
 * This project reimplements several std containers from scratch.
 * you are able to use the following containers and all its functions:
 * map
 * set
 * vector
 * stack
 * namespace is ft
 * performance is comparable to std
**/

int main(void) {
  std::cout << "have fun with containers!\n";

  //example
  ft::map<int, std::string> map;

  map.insert(ft::make_pair(42, std::string("42 is the answer")));
  std::cout << map.find(42)->second << "\n";
}

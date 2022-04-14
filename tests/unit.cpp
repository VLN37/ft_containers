// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 14/04/2022
// Last modified: 14/04/2022

#include <iostream>

#ifdef STD
namespace ft = std;
# include <vector>
#else
# include "iterator.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
#endif

int main(void) {
  ft::vector<int> vec(5, 10);
  // std::cout << vec;
  return 0;
}

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 19/05/2022

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

#define TIMES 10000

int main(void) {

{
  ft::vector<int> vec;

  for (int i = 0; i < TIMES; i++)
    vec.insert(vec.end(), i);
}
}

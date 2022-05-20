//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 19/05/2022

#include <iostream>
#include <exception>
#include <algorithm>
#include <string>

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

#define TIMES 1000000

int main(void) {
{
  ft::stack<int> stk1;
  for (int i = 0; i < TIMES; i++) {
    stk1.push(i);
  }
  for (int i = 0; i < TIMES; i++) {
    stk1.pop();
  }
}
{
  ft::stack<std::string> stk1;
  std::string str("hello");
  for (int i = 0; i < TIMES; i++) {
    stk1.push(str);
  }
  for (int i = 0; i < TIMES; i++) {
    stk1.pop();
  }
}
}

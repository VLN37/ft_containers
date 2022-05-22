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
# include <deque>
# include "iterator_vector.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "algo.hpp"
#endif

int main(void) {
  std::cout << "STACK\n";

  ft::stack<int> stk1;
  std::cout << stk1.empty() << '\n';
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
    std::cout << stk1.top() << " ";
  }
  std::cout << '\n';
  std::cout << stk1.size() << '\n';
  while (stk1.size()) {
    std::cout << stk1.top() << " ";
    stk1.pop();
  }
  std::cout << stk1.empty() << " empty\n\n";
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
  }
  ft::stack<int> stk2(stk1);
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';
  std::cout << (stk1 >= stk2) << '\n';
  std::cout << (stk1 <= stk2) << '\n';
  std::cout << (stk1  < stk2) << '\n';
  std::cout << (stk1  > stk2) << '\n';
  stk2.pop();
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';

  ft::stack<std::string, std::deque<std::string> > stk3;
  std::string str("string");
  for (int i = 0; i < 42; i++)
    stk3.push(str);
  for (int i = 0; i < 42; i++)
    std::cout << stk3.top() << " ";
  std::cout << "\n";
  return 0;
}

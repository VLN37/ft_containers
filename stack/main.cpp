//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 19/05/2022

#include <iostream>
#include <exception>
#include <algorithm>
# include <vector>
# include <stack>
# include <deque>

# include "iterator_vector.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "algo.hpp"

int main(void) {
{
  std::cout << "STACK\n";

  ft::stack<int> stk1;
  std::cout << stk1.empty() << '\n';
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
    std::cout << stk1.top() << " ";
  }
  std::cout << '\n';
  std::cout << stk1.size() << '\n';
  while (stk1.size())
    stk1.pop();
  std::cout << stk1.empty() << " empty\n\n";
  ft::stack<int> stk2(stk1);
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';
  std::cout << (stk1 >= stk2) << '\n';
  std::cout << (stk1 <= stk2) << '\n';
  std::cout << (stk1  < stk2) << '\n';
  std::cout << (stk1  > stk2) << '\n';
}

{
  std::cout << "STACK DEQUE\n";

  ft::stack<int, std::deque<int> > stk1;
  std::cout << stk1.empty() << '\n';
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
    std::cout << stk1.top() << " ";
  }
  std::cout << '\n';
  std::cout << stk1.size() << '\n';
  while (stk1.size())
    stk1.pop();
  std::cout << stk1.empty() << " empty\n\n";
  ft::stack<int, std::deque<int> > stk2(stk1);
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';
  std::cout << (stk1 >= stk2) << '\n';
  std::cout << (stk1 <= stk2) << '\n';
  std::cout << (stk1  < stk2) << '\n';
  std::cout << (stk1  > stk2) << '\n';
}

{
  std::cout << "STACK VECTOR\n";

  ft::stack<int, std::vector<int> > stk1;
  std::cout << stk1.empty() << '\n';
  for (int i = 0; i < 43; i++) {
    stk1.push(i);
    std::cout << stk1.top() << " ";
  }
  std::cout << '\n';
  std::cout << stk1.size() << '\n';
  while (stk1.size())
    stk1.pop();
  std::cout << stk1.empty() << " empty\n\n";
  ft::stack<int, std::vector<int> > stk2(stk1);
  std::cout << (stk1 == stk2) << '\n';
  std::cout << (stk1 != stk2) << '\n';
  std::cout << (stk1 >= stk2) << '\n';
  std::cout << (stk1 <= stk2) << '\n';
  std::cout << (stk1  < stk2) << '\n';
  std::cout << (stk1  > stk2) << '\n';
}
  return 0;
}

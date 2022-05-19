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

#define TIMES 10000

int main(void) {

{
  //insert end
  ft::vector<std::string> vec1;
  ft::vector<std::string> vec2;
  std::string str("asd");
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.end(), str);
  for (int i = 0; i < TIMES; i++)
    vec2.insert(vec2.end(), str);

  //insert fill
  vec1.insert(vec1.end(), TIMES, str);

  //copy constructor

  //insert range
  vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

  // assign fill
  // vec2.assign(TIMES, str);

  // //assign range
  vec2.assign(vec1.begin(), vec1.end());
}

{
  ft::vector<int> vec1;
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.end(), i);
  //assignment operator
  ft::vector<int> vec2 = vec1;
}

{
  //push
  ft::vector<int> vec1;
  for (int i = 0; i < TIMES; i++)
    vec1.push_back(42);
  for (int i = 0; i < TIMES; i++)
    vec1.pop_back();
}

}

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
  ft::vector<int> vec1;
  ft::vector<int> vec2;
  // std::string str("asd");
  // for (int i = 0; i < 600; i++)
    // vec1.insert(vec1.begin(), i);
  // ft::vector<int>::iterator it1(vec1[500]);
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), i);

  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), i);
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), i);
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), i);
}

{
  //insert end
  ft::vector<std::string> vec1;
  ft::vector<std::string> vec2;
  std::string str("asd");
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), str);
  for (int i = 0; i < TIMES; i++)
    vec2.insert(vec2.begin(), str);

  //insert fill
  vec1.insert(vec1.end(), TIMES, str);

  //copy constructor
  for (int i = 0; i < TIMES; i++) {
      ft::vector<std::string> vec3(vec2);
  }

  //insert range
  vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

  for (int i = 0; i < TIMES; i++)
   vec1.insert(vec1.begin(), str);

  vec1.insert(vec1.begin(), TIMES, str);

  // assign fill
  vec2.assign(TIMES, str);

  // //assign range
  vec2.assign(vec1.begin(), vec1.end());

  for (int i = 0; i < 1000; i++)
    vec1.erase(vec1.begin());
}

{
  //insert end
  ft::vector<int> vec1;
  ft::vector<int> vec2;
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.begin(), i);
  for (int i = 0; i < TIMES; i++)
    vec2.insert(vec2.begin(), i);

  //insert fill
  vec1.insert(vec1.begin(), TIMES, 42);

  //insert range
  vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

  for (int i = 0; i < TIMES; i++)
   vec1.insert(vec1.begin(), 42);

  // assign fill
  vec2.assign(TIMES, 42);

  // //assign range
  vec2.assign(vec1.begin(), vec1.end());
}

{
  ft::vector<int> vec1;
  for (int i = 0; i < TIMES; i++)
    vec1.insert(vec1.end(), i);
  //assignment operator
  ft::vector<int> vec2 = vec1;
  // iterators
  ft::vector<int>::iterator it1 = vec1.begin();
  ft::vector<int>::iterator it2 = vec1.end();
  while (it1 != it2)
    it1++;
}

{
  //push
  ft::vector<int> vec1;
  for (int i = 0; i < TIMES; i++)
    vec1.push_back(42);
  for (int i = 0; i < TIMES; i++)
    vec1.pop_back();
}

{
  //erase integral
  ft::vector<int> vec1;
  for (int i = 0; i < TIMES; i++)
    vec1.push_back(42);
  for (int i = 0; i < TIMES; i++)
    vec1.erase(vec1.begin());
  for (int i = 0; i < TIMES * 10; i++)
    vec1.push_back(42);
  vec1.erase(vec1.begin(), vec1.begin() + TIMES);
}

}

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 16/04/2022

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
template<typename T, typename Container = ft::vector<T> >
class stack {
public:
  typedef typename Container::value_type      value_type;
  typedef typename Container::reference       reference;
  typedef typename Container::const_reference const_reference;
  typedef typename Container::size_type       size_type;
  typedef          Container                  container_type;

protected:
  Container _data;

private:

};
} // namespace ft

#endif

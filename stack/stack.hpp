//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 16/04/2022

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
template<typename T, typename Container = ft::vector<T> >
class stack {
private:
  typedef stack const&                        stk_constref;

public:
  typedef typename Container::value_type      value_type;
  typedef typename Container::reference       reference;
  typedef typename Container::const_reference const_reference;
  typedef typename Container::size_type       size_type;
  typedef          Container                  container_type;

protected:
  Container _c;

public:
  explicit stack(Container const& c = Container()) : _c(c) { }
  bool            empty(void) const           { return _c.empty(); }
  size_type       size(void) const            { return _c.size(); }
  reference       top(void)                   { return _c.back(); }
  const_reference top(void) const             { return _c.back(); }
  void            pop(void)                   { _c.pop_back(); }
  void            push(const_reference value) { _c.push_back(value); }

friend bool operator==(stk_constref rhs, stk_constref lhs)
  { return rhs._c == lhs._c; }
friend bool operator!=(stk_constref rhs, stk_constref lhs)
  { return rhs._c != lhs._c; }
friend bool operator>=(stk_constref rhs, stk_constref lhs)
  { return rhs._c >= lhs._c; }
friend bool operator<=(stk_constref rhs, stk_constref lhs)
  { return rhs._c <= lhs._c; }
friend bool operator>(stk_constref rhs,  stk_constref lhs)
  { return rhs._c > lhs._c; }
friend bool operator<(stk_constref rhs,  stk_constref lhs)
  { return rhs._c < lhs._c; }
};
} // namespace ft

#endif

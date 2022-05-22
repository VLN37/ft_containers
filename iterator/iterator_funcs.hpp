//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef FT_ITERATOR_FUNCS_HPP
# define FT_ITERATOR_FUNCS_HPP

#include <iostream>
#include <cstddef>
#include "iterator_base.hpp"

namespace ft {
template<typename IterT>
typename iterator_traits<IterT>::difference_type
distance(IterT first, IterT last) {
  typename iterator_traits<IterT>::difference_type diff = 0;
  for (; first != last; first++, diff++)
    continue;
  return diff;
}

template<typename IterT, typename Distance>
void advance(IterT& it, Distance n) {
  while (n--)
    it++;
}
} // namespace ft
#endif // FT_ITERATOR_FUNCS_HPP

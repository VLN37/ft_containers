//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 21/05/2022

#ifndef MAP_OBSERVERS_TPP
# define MAP_OBSERVERS_TPP

#include "map.hpp"

namespace ft {

template<MAP_TEMPLATE>
typename MAP_TYPE::iterator MAP_TYPE::upper_bound(key_type const& key) {
  iterator it = begin();
  iterator ite = end();
  for (; it != ite && !comp(key, it->first); ++it)
    continue;
  return it;
}

template<MAP_TEMPLATE>
typename MAP_TYPE::const_iterator
  MAP_TYPE::upper_bound(key_type const& key) const
{
  const_iterator it = begin();
  const_iterator ite = end();
  for (; it != ite && !comp(key, it->first); ++it)
    continue;
  return it;
}

template<MAP_TEMPLATE>
typename MAP_TYPE::iterator MAP_TYPE::lower_bound(key_type const& key) {
  iterator it = begin();
  iterator ite = end();
  for (; it != ite && comp(it->first, key); ++it)
    continue;
  return it;
}

template<MAP_TEMPLATE>
typename MAP_TYPE::const_iterator
  MAP_TYPE::lower_bound(key_type const& key) const
{
  const_iterator it = begin();
  const_iterator ite = end();
  for (; it != ite && comp(it->first, key); ++it)
    continue;
  return it;
}
} // namespace ft
#endif // MAP_OBSERVERS_TPP

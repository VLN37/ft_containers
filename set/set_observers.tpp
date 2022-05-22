//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 21/05/2022

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 21/05/2022

#ifndef SET_OBSERVERS_TPP
# define SET_OBSERVERS_TPP

#include "set.hpp"

namespace ft {

template<SET_TEMPLATE>
typename SET_TYPE::iterator SET_TYPE::upper_bound(key_type const& key) {
  iterator it = begin();
  iterator ite = end();
  for (; it != ite && !comp(key, *it); ++it)
    continue;
  return it;
}

template<SET_TEMPLATE>
typename SET_TYPE::const_iterator
  SET_TYPE::upper_bound(key_type const& key) const
{
  const_iterator it = begin();
  const_iterator ite = end();
  for (; it != ite && !comp(key, *it); ++it)
    continue;
  return it;
}

template<SET_TEMPLATE>
typename SET_TYPE::iterator SET_TYPE::lower_bound(key_type const& key) {
  iterator it = begin();
  iterator ite = end();
  for (; it != ite && comp(*it, key); ++it)
    continue;
  return it;
}

template<SET_TEMPLATE>
typename SET_TYPE::const_iterator
  SET_TYPE::lower_bound(key_type const& key) const
{
  const_iterator it = begin();
  const_iterator ite = end();
  for (; it != ite && comp(*it, key); ++it)
    continue;
  return it;
}

} // namespace ft
#endif // SET_OBSERVERS_TPP

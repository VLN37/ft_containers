//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 21/05/2022

#ifndef SET_MODIFIERS_TPP
# define SET_MODIFIERS_TPP

#include "set.hpp"

namespace ft {

template<SET_TEMPLATE>
pair<typename SET_TYPE::iterator, bool>
  SET_TYPE::insert(value_type const& val)
{
  typename _Container::nodeptr ptr;

  ptr = tree.search(KoV()(val));
  if (ptr != tree.getsent() && size())
    return pair<iterator, bool>(iterator(ptr), false);
  tree.insert(val);
  return pair<iterator, bool>(iterator(tree.search(KoV()(val))), true);
}

template<SET_TEMPLATE>
typename SET_TYPE::iterator
  SET_TYPE::insert(iterator position, value_type const& val)
{
  typename _Container::nodeptr ptr;

  ptr = tree.search(KoV()(val));
  if (ptr != tree.getsent() && size())
    return iterator(ptr);
  tree.insert(val, position.base());
  return iterator(tree.search(KoV()(val)));
}

template<SET_TEMPLATE>
template<typename Iter>
void SET_TYPE::insert(Iter first, Iter last) {
  for (; first != last; first++)
    insert(value_type(*first));
}

template<SET_TEMPLATE>
typename SET_TYPE::size_type SET_TYPE::erase(key_type const& key) {
  typename _Container::nodeptr ptr;

  ptr = tree.search(key);
  tree.erase(key);
  return ptr == tree.getsent() ? 0 : 1;
}

template<SET_TEMPLATE>
void SET_TYPE::erase(iterator first, iterator last) {
  iterator next(first);

  next++;
  for (; first != last; next++) {
    tree.erase(KoV()(first.base()->data));
    first = next;
  }
}

} // namespace ft
#endif // SET_MODIFIERS_TPP

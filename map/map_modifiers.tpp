//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 21/05/2022

#ifndef MAP_MODIFIERS_TPP
# define MAP_MODIFIERS_TPP

#include "map.hpp"

namespace ft {

template<MAP_TEMPLATE>
typename MAP_TYPE::mapped_type& MAP_TYPE::operator[](key_type const& key) {
  typename _Container::nodeptr ptr;

  ptr = tree.search(key);
  if (ptr == tree.getsent())
    tree.insert(value_type(key, mapped_type()));
  else
    return ptr->data.second;
  return tree.search(key)->data.second;
}

template<MAP_TEMPLATE>
pair<typename MAP_TYPE::iterator, bool>
  MAP_TYPE::insert(value_type const& val) {
  typename _Container::nodeptr ptr;

  ptr = tree.search(KoV()(val));
  if (ptr != tree.getsent() && size())
    return ft::pair<iterator, bool>(iterator(ptr), false);
  ptr = tree.insert(val);
  return ft::pair<iterator, bool>(iterator(ptr), true);
}

template<MAP_TEMPLATE>
typename MAP_TYPE::iterator
  MAP_TYPE::insert(iterator position, value_type const& val) {
  typename _Container::nodeptr ptr;

  ptr = tree.search(KoV()(val));
  if (ptr != tree.getsent() && size())
    return iterator(ptr);
  ptr = tree.insert(val, position.base());
  return iterator(ptr);
}

template<MAP_TEMPLATE>
template<typename Iter>
void MAP_TYPE::insert(Iter first, Iter last) {
  for (; first != last; first++)
    insert(value_type(*first));
}

template<MAP_TEMPLATE>
typename MAP_TYPE::size_type MAP_TYPE::erase(key_type const& key) {
  typename _Container::nodeptr ptr;
  ptr = tree.search(key);
  tree.erase(key);
  return ptr == tree.getsent() ? 0 : 1;
}

template<MAP_TEMPLATE>
void MAP_TYPE::erase(iterator first, iterator last) {
  if (first.base() == tree.getsent())
    return;
  iterator next(first);
  next++;
  for (; next != last; next++) {
    tree.erase(KoV()(first.base()->data));
    first = next;
  }
  tree.erase(KoV()(first.base()->data));
}

} //namespace ft
#endif // MAP_MODIFIERS_TPP

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 07/04/2022

#include "vector.hpp"
#include <string.h>
#include <algorithm>

namespace ft {

template<VECTOR_TEMPLATE>
size_t VECTOR_TYPE::size(void) const {
  return _size;
}

template<VECTOR_TEMPLATE>
size_t VECTOR_TYPE::max_size(void) const {
  return _alloc.max_size();
}

template<VECTOR_TEMPLATE>
size_t VECTOR_TYPE::capacity(void) const {
  return _capacity;
}

template<VECTOR_TEMPLATE>
void VECTOR_TYPE::resize(size_t n, value_type val) {
  if (n < _size) {
    for (size_t i = _size; i > n; i--)
      _alloc.destroy(_data + i);
    _size = n;
  }
  if (n > _capacity)
    reserve(n);
  if (n > _size) {
    for (size_t i = _size; i < n; i++)
      _alloc.construct(_data + i, val);
    _size = n;
  }
}

//treat capacity = 0 case
template<VECTOR_TEMPLATE>
void VECTOR_TYPE::reserve(size_t n) {
  if (n < _capacity)
    return;
  if (_integral_type()) {
    // value_type is memcopyable
    T*tmp = _alloc.allocate(n);
    std::copy(begin().base(), end().base(), tmp);
    _alloc.deallocate(_data, _capacity);
    _capacity = n;
    _data = tmp;
    return;
  }
  // value_type is complex
  T *tmp;
  tmp = _alloc.allocate(n);
  for (size_type i = 0; i < _size; i++)
    _alloc.construct(tmp + i, *(_data + i));
  for (size_type i = 0; i < _size; i++)
    _alloc.destroy(_data + i);
  _alloc.deallocate(_data, _capacity);
  _capacity = n;
  _data = tmp;
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::iterator VECTOR_TYPE::erase(VECTOR_TYPE::iterator pos) {
  if (end() != begin() && pos == end() - 1) {
    pop_back();
    return end();
  }
  if (_integral_type()) {
    std::copy((pos + 1).base(), end().base(), pos.base());
    --_size;
    return pos;
  }
  _alloc.destroy(pos.base());
  iterator it = pos;
  iterator next = pos + 1;
  while (it != end()) {
    _alloc.construct(it.base(), *next);
    _alloc.destroy(next.base());
    it++;
    next++;
  }
  --_size;
  return pos;
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::iterator
  VECTOR_TYPE::erase(iterator first, iterator last) {
  last--;
  for (; last >= first; last--)
    erase(last);
  return first;
}


template<VECTOR_TEMPLATE>
void VECTOR_TYPE::clear(void) {
  while(_size)
    pop_back();
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::iterator VECTOR_TYPE::begin(void) {
  return iterator(_data);
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::const_iterator VECTOR_TYPE::begin(void) const {
  return const_iterator(_data);
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::iterator VECTOR_TYPE::end(void) {
  return iterator(_data + _size);
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::const_iterator VECTOR_TYPE::end(void) const {
  return const_iterator(_data + _size);
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::reverse_iterator VECTOR_TYPE::rbegin(void) {
  return reverse_iterator(end());
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::const_reverse_iterator
     VECTOR_TYPE::rbegin(void) const {
  return reverse_iterator(end());
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::reverse_iterator VECTOR_TYPE::rend(void) {
  return reverse_iterator(begin());
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::const_reverse_iterator VECTOR_TYPE::rend(void) const {
  return reverse_iterator(begin());
}

template<VECTOR_TEMPLATE>
void VECTOR_TYPE::push_back(value_type const& val) {
  if (_size == _capacity)
    reserve(_size ? _size * 2 : 1);
  _alloc.construct(_data + _size, val);
  _size++;
}

template<VECTOR_TEMPLATE>
void VECTOR_TYPE::pop_back(void) {
  if (_size > 0) {
    _alloc.destroy(_data + _size);
    _size--;
  }
}

template<VECTOR_TEMPLATE>
void VECTOR_TYPE::swap(vector& src) {
  size_type	tmp_size = _size;
  size_type	tmp_cap = _capacity;
  pointer		tmp_data = _data;

  _data = src._data;
  _size = src._size;
  _capacity = src._capacity;
  src._data = tmp_data;
  src._size = tmp_size;
  src._capacity = tmp_cap;
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::iterator
  VECTOR_TYPE::insert(iterator pos, value_type const& val) {
  if (_size == _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (_size == _capacity) {
    size_t diff = ft::distance(begin(), pos);
    reserve(_size ? _size * 2 : 1);
    pos = begin() + diff;
  }
  if (pos == end()) {
    push_back(val);
    return pos;
  _alloc.construct(_data + _size, val);
  }
  if (_integral_type()) {
    // in this case the value_type is integral i.e. - memcopyable
    std::copy_backward(pos.base(), end().base(), (end() + 1).base());
    *pos = val;
    ++_size;
    return pos;
  }
  // in this case the value_type is complex
  iterator it = end() - 1;
  iterator to = end();
  ++_size;
  for (; it >= pos; --it, --to)
    *to = *it;
  *pos = val;

  return pos;
}

template<VECTOR_TEMPLATE>
template<typename Integer>
void VECTOR_TYPE::insert_fill(iterator pos, size_type n, Integer const& val) {
  if (_size + n >= _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (_size + n > _capacity) {
    size_t diff = pos - begin();
    reserve(_size ? (_size + n) * 2 : n);
    pos = begin() + diff;
  }
  if (pos == end()) {
    while (n--)
      push_back(val);
    return;
  }
  for (size_type i = 0; i < n; i++)
    _alloc.construct(_data + _size + i, val);
  _size += n;
  iterator it = end() - n;
  iterator to = end();
  for (; it > pos; --it, --to) {
    *to = *it;
  }
  *to = *it;
  for (; n; --n, ++it)
    *it = val;
}

template<VECTOR_TEMPLATE>
template<typename IterT>
void VECTOR_TYPE::insert_range(iterator pos, IterT first, IterT last) {
  size_t distance = last - first;
  if (first > last)
    throw(std::length_error("range error\n"));
  if (_size + distance >= _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (_size + distance > _capacity) {
    size_t diff = pos - begin();
    reserve(_size ? (_size + distance) * 2 : distance);
    pos = begin() + diff;
  }
  if (pos == end()) {
    for (; first != last; ++first)
      push_back(*first);
    return;
  }
  for (size_type i = 0; i < distance; i++)
    _alloc.construct(_data + _size + i, value_type());
  _size += distance;
  iterator it = end() - distance - 1;
  iterator to = end() - 1;
  for (; it > pos; --it, --to) {
    *to = *it;
  }
  *to = *it;
  for (; first != last; first++, it++)
    *it = *first;
}

template<VECTOR_TEMPLATE>
template<typename Integer>
void VECTOR_TYPE::assign_fill(size_type n, Integer const& val) {
  if (n >= _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (n > _capacity)
    reserve(n);
  for (int i = _size - 1; i >= 0; i--)
    _alloc.destroy(_data + i);
  _size = 0;
  while (n--)
    push_back(val);
}

template<VECTOR_TEMPLATE>
template<typename IterT>
void VECTOR_TYPE::assign_range(IterT first, IterT last) {
  if (first > last)
    throw(std::length_error("range error\n"));
  if (static_cast<size_type>(last - first) > _capacity)
    reserve(last - first);
  for (int i = _size - 1; i >= 0; i--)
    _alloc.destroy(_data + i);
  _size = 0;
  for (; first != last; first++)
    push_back(*first);
}

} // namespace ft

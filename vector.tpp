//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 07/04/2022

#include "vector.hpp"

namespace ft {

template<typename T, typename Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::test(size_t n) {
  return _alloc.allocate(n);
}

template<typename T, typename Alloc>
size_t vector<T, Alloc>::size(void) const {
  return _size;
}

template<typename T, typename Alloc>
size_t vector<T, Alloc>::max_size(void) const {
  return _alloc.max_size();
}

template<typename T, typename Alloc>
size_t vector<T, Alloc>::capacity(void) const {
  return _capacity;
}

template<typename T, typename Alloc>
void vector<T, Alloc>::resize(size_t n, value_type val) {
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
template<typename T, typename Alloc>
void vector<T, Alloc>::reserve(size_t n) {
  if (n < _capacity)
    return;
  T *tmp;
  tmp = _alloc.allocate(n);
  for (size_type i = 0; i < _size; i++)
    _alloc.construct(tmp + i, *(_data + i));
  for (size_type i = 0; i < _capacity; i++)
    _alloc.destroy(_data + i);
  _alloc.deallocate(_data, _capacity);
  _capacity = n;
  _data = tmp;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
  vector<T,Alloc>::erase(vector<T, Alloc>::iterator pos) {
  if (end() != begin() && pos == end() - 1) {
    std::cout << "here\n";
    pop_back();
    return end();
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

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
  vector<T,Alloc>::erase(iterator first, iterator last) {
  for (; last > first; last--)
    erase(last);
  return first;
}


template<typename T, typename Alloc>
void vector<T, Alloc>::clear(void) {
  iterator it = end();
  for (; it != begin(); it--)
    erase(it);
  if (it != end())
    erase(it);
  _size = 0;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reference
  vector<T, Alloc>::at(size_type n) {
  if (n >= _size)
    throw(std::out_of_range("at: index out of range\n"));
  return _data[n];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reference
  vector<T, Alloc>::at(size_type n) const {
  if (n >= _size)
    throw(std::out_of_range("at: index out of range\n"));
  return _data[n];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reference
  vector<T, Alloc>::front(void) {
  return _data[0];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reference
  vector<T, Alloc>::front(void) const {
  return _data[0];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back(void) {
  return _data[_size - 1];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back(void) const {
  return _data[_size - 1];
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin(void) {
  return iterator(_data);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin(void) const {
  return const_iterator(_data);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end(void) {
  return iterator(_data + _size);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end(void) const {
  return const_iterator(_data + _size);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void) {
  return reverse_iterator(end());
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator
     vector<T, Alloc>::rbegin(void) const {
  return reverse_iterator(end());
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void) {
  return reverse_iterator(begin());
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator
     vector<T, Alloc>::rend(void) const {
  return reverse_iterator(begin());
}

template<typename T, typename Alloc>
void vector<T, Alloc>::push_back(value_type const& val) {
  if (_size == _capacity)
    reserve(_size ? _size * 2 : 1);
  _alloc.construct(_data + _size, val);
  _size++;
}

template<typename T, typename Alloc>
void vector<T, Alloc>::pop_back(void) {
  if (_size > 0) {
    _alloc.destroy(_data + _size);
    _size--;
  }
}

template<typename T, typename Alloc>
void vector<T, Alloc>::swap(vector& src) {
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

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
  vector<T, Alloc>::insert(iterator pos, value_type const& val) {
  if (_size == _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (_size == _capacity)
    reserve(_size ? _size * 2 : 1);
  if (pos == end()) {
    push_back(val);
    return pos;
  }
  _alloc.construct(_data + _size, value_type());
  iterator it = end() - 1;
  iterator to = end();
  for (; it > pos; --it, --to)
    *to = *it;
  *to = *it;
  *it = val;
  ++_size;
  return pos;
}

template<typename T, typename Alloc>
template<typename Integer>
void
  vector<T, Alloc>::insert_fill(iterator pos, size_type n, Integer const& val) {
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

template<typename T, typename Alloc>
template<typename IterT>
void vector<T, Alloc>::insert_range(iterator pos, IterT first, IterT last) {
  size_t distance = last - first;
  if (first > last)
    throw(std::length_error("range error\n"));
  if (_size + distance >= _max_size)
    throw(std::length_error("max_size exceeded\n"));
  if (_size + distance > _capacity) {
    std::cout << "reserver\n";
    size_t diff = pos - begin();
    reserve(_size ? (_size + distance) * 2 : distance);
    pos = begin() + diff;
    std::cout << *this;
  }
  if (pos == end()) {
    for (; first != last; ++first)
      push_back(*first);
    return;
  }
  for (size_type i = 0; i < distance; i++)
    _alloc.construct(_data + _size + i, 0);
  _size += distance;
  iterator it = end() - distance;
  iterator to = end();
  for (; it > pos; --it, --to) {
    *to = *it;
  }
  *to = *it;
  for (; first != last; first++, it++)
    *it = *first;
}

template<typename T, typename Alloc>
template<typename Integer>
void vector<T, Alloc>::assign_fill(size_type n, Integer const& val) {
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

template<typename T, typename Alloc>
template<typename IterT>
void vector<T, Alloc>::assign_range(IterT first, IterT last) {
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

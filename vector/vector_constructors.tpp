//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 01/04/2022

#include "vector.hpp"

namespace ft {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const alloc_type& alloc)
: _alloc(alloc) {
  _data = _alloc.allocate(0);
  _size = 0;
  _capacity = 0;
  _max_size = _alloc.max_size();
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector<T, Alloc> const& src)
: _alloc(src.get_allocator()), _size(0) {
  _data = _alloc.allocate(0);
  *this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, value_type val, const alloc_type& alloc)
: _alloc(alloc) {
  _data = _alloc.allocate(n);
  _size = n;
  _capacity = n;
  _max_size = _alloc.max_size();
  for (size_t i = 0; i < _size; i++)
    _alloc.construct(_data + i, val);
}

template<typename T, typename Alloc>
template<typename IterT>
void vector<T, Alloc>::constructor_range(IterT first, IterT last) {
  _data = _alloc.allocate(last - first);
  _size = 0;
  _capacity = last - first;
  _max_size = _alloc.max_size();
  for (; first != last; ++first)
    push_back(*first);
}

template<typename T, typename Alloc>
template<typename Integer>
void vector<T, Alloc>::constructor_fill(size_type n, Integer value) {
  _data = _alloc.allocate(n);
  _size = n;
  _capacity = n;
  _max_size = _alloc.max_size();
  for (size_t i = 0; i < _size; i++)
    _alloc.construct(_data + i, value);
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
  for (size_t i = 0; i < _size; i++)
    _alloc.destroy(_data + i);
  _alloc.deallocate(_data, size_type());
}
} // namespace ft

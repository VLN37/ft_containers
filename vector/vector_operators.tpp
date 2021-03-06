//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 31/03/2022

#include "vector.hpp"

namespace ft {

template<VECTOR_TEMPLATE>
VECTOR_TYPE& VECTOR_TYPE::operator=(vec_constref rhs) {
  for (size_t i = 0; i < _size; i++)
    _alloc.destroy(_data + i);
  _alloc.deallocate(_data, size_type());
  _size = rhs._size;
  _capacity = rhs._capacity;
  _data = _alloc.allocate(_capacity);
  _max_size = rhs._max_size;
  for (size_t i = 0; i < _size; i++)
    _alloc.construct(_data + i, *(rhs._data + i));
  return *this;
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::reference VECTOR_TYPE::operator[](size_type n) {
  return _data[n];
}

template<VECTOR_TEMPLATE>
typename VECTOR_TYPE::const_reference
  VECTOR_TYPE::operator[](size_type n) const {
  return _data[n];
}

} //namespace ft

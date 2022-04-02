// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include "vector.hpp"

namespace ft {

template<typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(vec_constref rhs) {
	std::cout << "vector assignment operator called\n";
	for (size_t i = 0; i < _size; i++)
		_alloc.destroy(_data + i);
	_alloc.deallocate(_data, size_type());
	_size = rhs._size;
	_capacity = rhs._capacity;
	_data = _alloc.allocate(_size);
	data = _data;
	memcpy(_data, data, _size * sizeof(value_type));
	return *this;
}

template<typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator[](size_type n) {
	return _alloc.address(n);
}

template<typename T, typename Alloc>
std::ostream& operator<<(std::ostream& o, vector<T, Alloc> const& rhs) {
	o << *rhs._data;
	return o;
}

} //namespace ft

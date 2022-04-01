// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include "vector.hpp"

namespace ft {

template<typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(vector<T, Alloc> const& rhs) {
	std::cout << "vector assignment operator called\n";
	_alloc.deallocate(_data, size_type());
	_size = rhs._size;
	_capacity = rhs._capacity;
	_data = _alloc.allocate(_size);
	data = _data;
	memcpy(_data, data, _size * sizeof(value_type));
	return *this;
}
} //namepace ft

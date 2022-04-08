// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

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
	for (size_t i = 0; i < _size; i++)
		_alloc.construct(tmp + i, *(_data + i));
	for (size_t i = 0; i < _capacity; i++)
		_alloc.destroy(_data + i);
	_alloc.deallocate(_data, _capacity);
	_capacity = n;
	_data = tmp;
}

template<typename T, typename Alloc>
void vector<T, Alloc>::clear(void) {
	for (size_t i = 0; i < _size; i++)
		_alloc.destroy(_data + i);
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
void vector<T, Alloc>::push_back(value_type const& val) {
	if (_size == _capacity)
		reserve(_size ? _size * 2 : 1);
	_alloc.construct(_data + _size, val);
	_size++;
}

template<typename T, typename Alloc>
void vector<T, Alloc>::pop_back(void) {
	if (_size > 0) {
		_alloc.destroy(data + _size);
		_size--;
	}
}


} // namespace ft

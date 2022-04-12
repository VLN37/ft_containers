// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 01/04/2022
// Last modified: 01/04/2022

#include "vector.hpp"

namespace ft {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const alloc_type& alloc)
: _alloc(alloc) {
	std::cout << "default constructor called\n";
	_data = _alloc.allocate(0);
	_size = 0;
	_capacity = 0;
	_max_size = _alloc.max_size();
}

template<typename T, typename Alloc>
template<typename IterT>
vector<T, Alloc>::vector(IterT first, IterT last, alloc_type const& alloc)
: _alloc(alloc) {
	typedef typename is_integral<IterT>::type _integral;
	_integral() ? std::cout << "true\n" : std::cout << "false\n";
	constructor_dispatch(first, last, _integral());
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector<T, Alloc> const& src, const alloc_type& alloc)
: _alloc(alloc), _size(0) {
	std::cout << "vector copy constructor called\n";
	_data = _alloc.allocate(0);
	*this = src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, value_type val, const alloc_type& alloc)
: _alloc(alloc) {
	std::cout << "size parametric constructor called\n";
	_data = _alloc.allocate(n);
	_size = n;
	_capacity = n;
	_max_size = _alloc.max_size();
	for (size_t i = 0; i < _size; i++)
		_alloc.construct(_data + i, val);
}

template<typename T, typename Alloc>
vector<T, Alloc>::~vector(void) {
	std::cout << "default destructor called\n";
	for (size_t i = 0; i < _size; i++)
		_alloc.destroy(_data + i);
	_alloc.deallocate(_data, size_type());
}
} // namespace ft

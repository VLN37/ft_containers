// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 01/04/2022
// Last modified: 01/04/2022

#include "vector.hpp"

namespace ft {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(void) {
	std::cout << "default constructor called\n";
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(vector<T, Alloc> const& src) {
	std::cout << "vector copy constructor called\n";
	(void)src;
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(size_t n) {
	std::cout << "size parametric constructor called\n";
	(void)n;
}
}

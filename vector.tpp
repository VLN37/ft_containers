// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include "vector.hpp"

template <typename T, typename Alloc>
ft::vector<T, Alloc>::vector(void) {
}

template<typename T, typename Alloc>
int* ft::vector<T, Alloc>::test(size_t n) {
	return _Alloc.allocate(n);
}

template<typename T, typename Alloc>
ft::vector<T, Alloc>::~vector(void) {

}

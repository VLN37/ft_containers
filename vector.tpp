// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include "vector.hpp"

namespace ft {

template<typename T, typename Alloc>
int* vector<T, Alloc>::test(size_t n) {
	return _alloc.allocate(n);
}
} // namespace ft

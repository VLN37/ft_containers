// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include "vector.hpp"

namespace ft {

template<typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(vector<T, Alloc> const& src) {
	(void)src;
	std::cout << "vector assignment operator called\n";
	return *this;
}
} //namepace ft



// template<typename T, typename Alloc>
// ft::vector<T, Alloc>& ft::vector<T, Alloc>::operator=(ft::vector<T, Alloc> const& src) {
// 	(void)src;
// 	std::cout << "vector assignment operator called\n";
// 	return *this;
// }

// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <vector>
#include <iostream>

namespace ft {
template<typename T, typename Alloc = std::allocator<T> >
class vector {
public:
	vector(void);
	~vector(void);
	vector<T, Alloc>& operator=(vector<T, Alloc> const& rhs);

	int* test(size_t n);

	typedef				std::allocator<T>					allocator_type;
	typedef				T									value_type;
	typedef typename	std::allocator<T>::pointer			pointer;
	typedef typename	std::allocator<T>::const_pointer	const_pointer;
	typedef typename	std::allocator<T>::reference		reference;
	typedef typename	std::allocator<T>::const_reference	const_reference;
	typedef typename	ft::vector<T, Alloc>				vector_type;
	allocator_type _Alloc;

private:
	};
#include "vector.tpp"
#include "vector_operators.tpp"
} //namespace ft

#endif //FT_VECTOR_HPP

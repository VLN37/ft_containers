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
	typedef				std::allocator<T>					allocator_type;
	typedef				T									value_type;
	typedef typename	std::allocator<T>::pointer			pointer;
	typedef typename	std::allocator<T>::const_pointer	const_pointer;
	typedef typename	std::allocator<T>::reference		reference;
	typedef typename	std::allocator<T>::const_reference	const_reference;
	typedef				vector<T, Alloc>&					vec_ref;
	typedef				vector<T, Alloc> const&				vec_constref;

	vector(void);
	vector(vec_constref src);
	vector(size_t n);
	~vector(void);
	vec_ref operator=(vec_constref rhs);

	int* test(size_t n);

	allocator_type _Alloc;
	value_type data;

private:
	size_t _size;
	size_t _max_size;
	size_t _capacity;
	};
} //namespace ft
#include "vector.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

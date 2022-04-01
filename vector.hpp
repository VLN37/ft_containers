// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <vector>
#include <iostream>
#include <cstring>

namespace ft {

template<typename T, typename Alloc = std::allocator<T> >
class vector {
public:
	typedef				Alloc								alloc_type;
	typedef				T									value_type;
	typedef typename	std::allocator<T>::pointer			pointer;
	typedef typename	std::allocator<T>::size_type		size_type;
	typedef typename	std::allocator<T>::const_pointer	const_pointer;
	typedef typename	std::allocator<T>::reference		reference;
	typedef typename	std::allocator<T>::const_reference	const_reference;
	typedef				vector<T, Alloc>&					vec_ref;
	typedef				vector<T, Alloc> const&				vec_constref;

	std::allocator<T>	_alloc;
	pointer				data;

	explicit vector(const alloc_type& alloc = alloc_type());
	explicit vector(vec_constref src, const alloc_type& alloc = alloc_type());
	//missing range constructor - depends on iterator class
	explicit vector(size_t n, const alloc_type& alloc = alloc_type());
	~vector(void);
	vec_ref operator=(vec_constref rhs);

	int* test(size_t n);


protected:
	pointer		_data;
	size_type	_size;
	size_type	_max_size;
	size_type	_capacity;

private:
	};
} //namespace ft
#include "vector.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

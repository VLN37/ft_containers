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

	typedef				Alloc								allocator_type;
	typedef				T									value_type;
	typedef typename	std::allocator<T>::pointer			pointer;
	typedef typename	std::allocator<T>::const_pointer	const_pointer;
	typedef typename	std::allocator<T>::reference		reference;
	typedef typename	std::allocator<T>::const_reference	const_reference;

private:
	};
#include "vector.tpp"
}


#endif

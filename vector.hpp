// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <vector>
#include <iostream>
#include <cstring>

#include "iterator.hpp"

namespace ft {

template<typename T, typename Alloc = std::allocator<T> >
class vector {
public:
	typedef Alloc											alloc_type;
	typedef T												value_type;
	typedef typename std::allocator<T>::pointer				pointer;
	typedef typename std::allocator<T>::size_type			size_type;
	typedef typename std::allocator<T>::const_pointer		const_pointer;
	typedef typename std::allocator<T>::reference			reference;
	typedef typename std::allocator<T>::const_reference		const_reference;
	typedef vector<T, Alloc>&								vec_ref;
	typedef vector<T, Alloc> const&							vec_constref;
	typedef random_access_iterator<pointer>					iterator;
	typedef random_access_iterator<const_pointer>			const_iterator;
	// typedef reverse_iterator<iterator>						reverse_iterator;
	// typedef reverse_iterator<const_iterator>				const_reverse_iterator;

	std::allocator<T>	_alloc;
	pointer				data;

	//constructors
	explicit vector(const alloc_type& alloc = alloc_type());
	explicit vector(vec_constref src, const alloc_type& alloc = alloc_type());
	//missing range constructor - depends on iterator class
	explicit vector(size_type n,
		value_type val = value_type(), const alloc_type& alloc = alloc_type());
	~vector(void);

	//operators
	vec_ref			operator=(vec_constref rhs);
	reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;
	// std::ostream& operator<<(std::ostream& o);

	//getters
	pointer	test(size_t n);
	size_t	size(void) const;
	size_t	max_size(void) const;
	size_t	capacity(void) const;

	//member functions
	void			reserve(size_t n);
	void			resize(size_t n, value_type val = value_type());
	reference		at(size_type n);
	const_reference	at(size_type n) const;
	reference		front(void);
	const_reference	front(void) const;
	reference		back(void);
	const_reference	back(void) const;
	void			push_back(value_type const& val);
	void			pop_back(void);
	void			clear(void);
	iterator		begin(void);
	const_iterator	begin(void) const;



protected:
	pointer		_data;
	size_type	_size;
	size_type	_max_size;
	size_type	_capacity;

private:
	};
} //namespace ft

// C 11 variant
// template<typename T, typename Alloc = std::allocator<T> >
// std::ostream& operator<<(std::ostream& o, ft::vector<T, Alloc>& rhs);

#include "vector.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

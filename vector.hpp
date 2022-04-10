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
	typedef Alloc										alloc_type;
	typedef T											value_type;
	typedef typename std::allocator<T>::pointer			pointer;
	typedef typename std::allocator<T>::size_type		size_type;
	typedef typename std::allocator<T>::const_pointer	const_pointer;
	typedef typename std::allocator<T>::reference		reference;
	typedef typename std::allocator<T>::const_reference	const_reference;
	typedef vector<T, Alloc>&							vec_ref;
	typedef vector<T, Alloc> const&						vec_constref;
	typedef random_access_iterator<pointer>				iterator;
	typedef random_access_iterator<const_pointer>		const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

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

	//getters
	pointer	test(size_t n);
	size_t	size(void) const;
	size_t	max_size(void) const;
	size_t	capacity(void) const;

	//element access
	reference		at(size_type n);
	const_reference	at(size_type n) const;
	reference		front(void);
	const_reference	front(void) const;
	reference		back(void);
	const_reference	back(void) const;

	//member functions
	void			reserve(size_t n);
	void			resize(size_t n, value_type val = value_type());
	void			push_back(value_type const& val);
	void			pop_back(void);
	void			clear(void);

	// template <class InputIterator>
	// void assign (InputIterator first, InputIterator last);     // range
	// void assign (size_type n, const value_type& val);          // fill

	//iterator insert (iterator position, const value_type& val); // single elem
	// void insert (iterator position, size_type n, const value_type& val); fill
	// template <class InputIterator>                             // range
	// void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase(iterator position);
	// iterator erase(iterator first, iterator last);

	// void swap (vector& x);


	//iterator support
	iterator				begin(void);
	const_iterator			begin(void) const;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	iterator				end(void);
	const_iterator			end(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

	//debug
	friend std::ostream& operator<<(std::ostream& o, vec_ref rhs) {
		std::cout << "Vector debug\n";
		for (iterator it = rhs.begin(); it != rhs.end(); it++)
			o << *it << " ";
		o << "\n\n";
		return o;
	}

protected:
	pointer		_data;
	size_type	_size;
	size_type	_max_size;
	size_type	_capacity;

private:
	};
} //namespace ft

// C 11 variant
// template<typename T>
// std::ostream& operator<<(std::ostream& o,
//ft::vector<T, std::allocator<T> >& rhs);

#include "vector.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

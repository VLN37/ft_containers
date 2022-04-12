// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <vector>
#include <iostream>

#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {
	typedef integral_constant<bool, false>				false_type;
	typedef integral_constant<bool, true>				true_type;

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

	//constructors
	explicit vector(const alloc_type& alloc = alloc_type());
	explicit vector(vec_constref src, const alloc_type& alloc = alloc_type());
	explicit vector(size_type n,
					value_type val = value_type(),
					const alloc_type& alloc = alloc_type());
	//range / fill constructor disambiguator
	template<typename IterT>
	vector(IterT first, IterT last, alloc_type const& alloc = alloc_type());
	~vector(void);

	//operators
	vec_ref			operator=(vec_constref rhs);
	reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;

	//getters
	pointer		test(size_t n);
	size_t		size(void) const;
	size_t		max_size(void) const;
	size_t		capacity(void) const;
	alloc_type	get_allocator(void) const { return this->_alloc; }

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

	void assign(size_type n, value_type const& val);
	template <class IterT>
	void assign(IterT first, IterT last) {
		typedef typename is_integral<IterT>::type _integral;
		assign_dispatcher(first, last, _integral());
	}

	iterator	insert(iterator pos, value_type const& val);
	iterator	insert(iterator pos, size_type n, const value_type& val)
	{ insert_dispatch(pos, n, val, true_type()); return pos; }
	template <class IterT>                             // range
	void insert(iterator position, IterT first, IterT last) {
		typedef typename is_integral<IterT>::type _integral;
		insert_dispatch(position, first, last, _integral());
	}

	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void	swap(vector& src);


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
	template<typename Integer>
	void constructor_dispatch(Integer n, Integer value, true_type) {
		std::cout << "size parametric constructor called\n";
		_data = _alloc.allocate(n);
		_size = n;
		_capacity = n;
		_max_size = _alloc.max_size();
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(_data + i, value);
	}

	template<typename IterT>
	void constructor_dispatch(IterT first, IterT last, false_type) {
		_data = _alloc.allocate(last - first);
		_size = 0;
		_capacity = last - first;
		_max_size = _alloc.max_size();
		for (; first != last; ++first)
			push_back(*first);
	}

	template<typename IterT>
	void insert_dispatch(iterator pos, IterT first, IterT last, false_type) {
		(void)pos;
		(void)first;
		(void)last;
	}

	template<typename Integer>
	void insert_dispatch(iterator pos, Integer n,
	Integer const& val, true_type) {
		if (_size + n >= _max_size)
			throw(std::length_error("max_size exceeded\n"));
		if (_size + n > _capacity) {
			size_t diff = pos - begin();
			std::cout << "reserver\n";
			reserve(_size ? (_size + n) * 2 : n);
			pos = begin() + diff;
		}
		if (pos == end()) {
			while (n--)
				push_back(val);
			return;
		}
		for (int i = 0; i < n; i++)
			_alloc.construct(_data + _size + i, 42);
		_size += n;
		iterator it = end() - n;
		iterator to = end();
		for (; it > pos; --it, --to) {
			*to = *it;
		}
		*to = *it;
		for(; n; n--)
			*it++ = val;
		// return pos;
	}

	template<typename Integer>
	void assign_dispatcher(size_type n, Integer const& val, true_type) {
		if (n >= _max_size)
			throw(std::length_error("max_size exceeded\n"));
		if (n > _capacity)
			reserve(n);
		for (int i = _size - 1; i >= 0; i--)
			_alloc.destroy(_data + i);
		_size = 0;
		while (n--)
			push_back(val);
	}

	template<typename IterT>
	void assign_dispatcher(IterT first, IterT last, false_type) {
		if (first > last)
			throw(std::length_error("range error\n"));
		if (static_cast<size_type>(last - first) > _capacity)
			reserve(last - first);
		for (int i = _size - 1; i >= 0; i--)
			_alloc.destroy(_data + i);
		_size = 0;
		for (; first != last; first++)
			push_back(*first);
	}
	};
} //namespace ft

#include "vector.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

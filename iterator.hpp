// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 04/04/2022
// Last modified: 04/04/2022

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

#include <iostream>
#include <cstddef>

namespace ft {
template<typename Category,
		 typename T,
		 typename Distance = ptrdiff_t,
		 typename Pointer = T*,
		 typename Reference = T&>
struct iterator {
	typedef	T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
	};

template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template<typename T>
struct iterator_traits<T*> {
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template<typename T>
struct iterator_traits<const T*> {
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template <typename IterT>
class random_access_iterator
: public iterator<std::random_access_iterator_tag, IterT> {
public:
	typedef IterT												iterator_type;
	typedef typename iterator_traits<IterT>::iterator_category	iterator_category;
	typedef typename iterator_traits<IterT>::value_type			value_type;
	typedef typename iterator_traits<IterT>::difference_type	difference_type;
	typedef typename iterator_traits<IterT>::pointer			pointer;
	typedef typename iterator_traits<IterT>::reference			reference;
};

} // namespace ft

#endif
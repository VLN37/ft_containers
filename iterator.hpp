// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 04/04/2022
// Last modified: 04/04/2022

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include "iterator_base.hpp"

namespace ft {

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

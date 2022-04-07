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
private:
	typedef iterator_traits<iterator<std::random_access_iterator_tag, IterT> >
		iter_traits;

protected:
	IterT current;

public:
	typedef IterT									iterator_type;
	typedef typename iter_traits::iterator_category	iterator_category;
	typedef typename iter_traits::value_type		value_type;
	typedef typename iter_traits::difference_type	difference_type;
	typedef typename iter_traits::pointer			pointer;
	typedef typename iter_traits::reference			reference;


	random_access_iterator(void) { };
	random_access_iterator(iterator_type const& src) {
		std::cout << "rai copy constructor called\n";
		this->current = src;
	};
	~random_access_iterator(void) { };

	iterator_type& operator=(iterator_type const& rhs){
		std::cout << "rai assignemnt operator called\n";
		return this->current = rhs;
	};


};

} // namespace ft

#endif

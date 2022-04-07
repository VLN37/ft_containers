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
	typedef const random_access_iterator&						rai_constref;
	typedef random_access_iterator&								rai_ref;
	typedef random_access_iterator								rai;

protected:
	IterT current;

public:
	typedef IterT												iterator_type;
	typedef typename iterator_traits<IterT>::iterator_category	iterator_category;
	typedef typename iterator_traits<IterT>::value_type			value_type;
	typedef typename iterator_traits<IterT>::difference_type	difference_type;
	typedef typename iterator_traits<IterT>::pointer			pointer;
	typedef typename iterator_traits<IterT>::reference			reference;


	random_access_iterator(void) { };
	explicit random_access_iterator(pointer src) {
		std::cout << "rai copy constructor called\n";
		this->current = src;
	};
	~random_access_iterator(void) { };

	random_access_iterator& operator=(random_access_iterator<IterT> const& rhs){
		std::cout << "rai assignment operator called\n";
		this->current = rhs.current;
		return *this;
	};

	reference operator*(void) {
		std::cout << "rai dereference operator called\n";
		return *current;
	}

	rai_ref operator++(void)	{ current++; return *this; };
	rai_ref	operator++(int)		{ rai tmp(*this); ++current; return *this; }
	rai_ref operator--(void)	{ current--; return *this; };
	rai_ref	operator--(int)		{ rai tmp(*this); --current; return *this; }
	pointer	operator->(void) const { return &(operator*()); }
	bool	operator==(rai_constref rhs) const { return current == rhs.current; }
	bool	operator!=(rai_constref rhs) const { return !(current == rhs.current);}
	bool	operator>(rai_constref rhs) const { return current > rhs.current; }
	bool	operator<(rai_constref rhs) const { return current < rhs.current; }
	bool	operator<=(rai_constref rhs) const { return current <= rhs.current; }
	bool	operator>=(rai_constref rhs) const { return current >= rhs.current; }
	rai_ref	operator+=(difference_type n)	{ current += n; return *this; }
	rai_ref	operator-=(difference_type n)	{ current -= n; return *this; }
	rai		operator+(difference_type n) const { return rai(current + n); }
	rai		operator-(difference_type n) const { return rai(current - n); }
	rai		operator[](difference_type n) const { return rai(current + n); }
};

//           SFINAE ????????

	// template<typename IterT>
	// random_access_iterator<IterT> operator+(
	// typename random_access_iterator<IterT>::difference_type n,
	// typename random_access_iterator<IterT>::rai_constref rhs) {
	// 	return rai(rhs.current + n);
	// }

} // namespace ft

#endif

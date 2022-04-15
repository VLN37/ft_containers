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
  typedef const random_access_iterator& rai_constref;
  typedef random_access_iterator&       rai_ref;
  typedef random_access_iterator        rai;

protected:
  IterT current;

public:
  typedef IterT                                               iterator_type;
  typedef typename iterator_traits<IterT>::iterator_category  iterator_category;
  typedef typename iterator_traits<IterT>::value_type         value_type;
  typedef typename iterator_traits<IterT>::difference_type    difference_type;
  typedef typename iterator_traits<IterT>::pointer            pointer;
  typedef typename iterator_traits<IterT>::reference          reference;


  random_access_iterator(void): current(NULL) { };
  explicit random_access_iterator(iterator_type src) : current(src) { }
  random_access_iterator(rai_constref src): current(src.current) { }
  ~random_access_iterator(void) { }

  template<typename Iter>
  random_access_iterator(random_access_iterator<Iter> src)
    : current(src.base()) { }

  template<typename Iter>
  rai_ref operator=(random_access_iterator<Iter> const& rhs) {
    this->current = rhs.base();
    return *this;
}

  iterator_type base(void) const  { return current; }
  reference operator*(void) { return *current; }
  rai_ref operator++(void)  { current++; return *this; }
  rai     operator++(int)   { rai tmp(*this); ++current; return tmp; }
  rai_ref operator--(void)  { current--; return *this; };
  rai     operator--(int)   { rai tmp(*this); --current; return tmp; }
  pointer operator->(void) const { return &(operator*()); }
  bool    operator!=(rai_constref rhs) const  { return current != rhs.current; }
  bool    operator==(rai_constref rhs) const  { return current == rhs.current; }
  bool    operator<=(rai_constref rhs) const  { return current <= rhs.current; }
  bool    operator>=(rai_constref rhs) const  { return current >= rhs.current; }
  bool    operator>(rai_constref rhs) const   { return current > rhs.current; }
  bool    operator<(rai_constref rhs) const   { return current < rhs.current; }
  rai_ref	operator+=(difference_type n)       { current += n; return *this; }
  rai_ref	operator-=(difference_type n)       { current -= n; return *this; }
  rai     operator+(difference_type n) const  { return rai(current + n); }
  rai     operator-(difference_type n) const  { return rai(current - n); }
  reference operator[](difference_type n) const { return current[n]; }

  friend rai operator+(difference_type n, rai_constref rhs) {
    return rai(rhs.current + n);
  }
  friend rai operator-(difference_type n, rai_constref rhs) {
    return rai(rhs.current - n);
  }
};

template<typename IteratorL, typename IteratorR>
bool operator==(random_access_iterator<IteratorL> const& rhs,
                random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() == lhs.base(); }

template<typename IteratorL, typename IteratorR>
bool operator!=(random_access_iterator<IteratorL> const& rhs,
                random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() != lhs.base(); }

template<typename IteratorL, typename IteratorR>
bool operator<=(random_access_iterator<IteratorL> const& rhs,
                random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() <= lhs.base(); }

template<typename IteratorL, typename IteratorR>
bool operator>=(random_access_iterator<IteratorL> const& rhs,
                random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() >= lhs.base(); }

template<typename IteratorL, typename IteratorR>
bool operator<(random_access_iterator<IteratorL> const& rhs,
               random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() < lhs.base(); }

template<typename IteratorL, typename IteratorR>
bool operator>(random_access_iterator<IteratorL> const& rhs,
               random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() > lhs.base(); }

template<typename IteratorL, typename IteratorR>
typename random_access_iterator<IteratorL>::difference_type
  operator-(random_access_iterator<IteratorL> const& rhs,
            random_access_iterator<IteratorR> const& lhs)
{ return rhs.base() - lhs.base(); }

template <typename IterT>
class reverse_iterator
: public iterator<std::random_access_iterator_tag, IterT> {
private:
  typedef reverse_iterator const& rev_constref;
  typedef reverse_iterator&       rev_ref;
  typedef reverse_iterator        rev;

protected:
  IterT current;

public:
  typedef IterT                                               iterator_type;
  typedef typename iterator_traits<IterT>::iterator_category  iterator_category;
  typedef typename iterator_traits<IterT>::value_type         value_type;
  typedef typename iterator_traits<IterT>::difference_type    difference_type;
  typedef typename iterator_traits<IterT>::pointer            pointer;
  typedef typename iterator_traits<IterT>::reference          reference;

  reverse_iterator(void): current(NULL) { }
  explicit reverse_iterator(iterator_type src) : current(src) { }
  reverse_iterator(rev_constref src) : current(src.current) { }
  ~reverse_iterator(void) { }

  template<typename Iter>
  reverse_iterator(reverse_iterator<Iter> const& src) : current(src.base()) { }

  template<typename Iter>
  rev_ref operator=(reverse_iterator<Iter> const& rhs) {
    this->current = rhs.base();
    return *this;
  }

  iterator_type base(void) const  { return current; }
  reference operator*(void)       { IterT tmp = current; return *--tmp; }
  rev_ref operator++(void)        { --current; return *this; }
  rev     operator++(int)         { rev tmp(*this); --current; return tmp; }
  rev_ref operator--(void)        { ++current; return *this; }
  rev     operator--(int)         { rev tmp(*this); ++current; return tmp; }
  pointer operator->(void) const              { return &(operator*()); }
  bool    operator==(rev_constref rhs) const  { return current == rhs.current; }
  bool    operator!=(rev_constref rhs) const  { return current != rhs.current; }
  bool    operator<=(rev_constref rhs) const  { return current <= rhs.current; }
  bool    operator>=(rev_constref rhs) const  { return current >= rhs.current; }
  bool    operator>(rev_constref rhs) const   { return current > rhs.current; }
  bool    operator<(rev_constref rhs) const   { return current < rhs.current; }
  rev_ref operator+=(difference_type n)       { current -= n; return *this; }
  rev_ref operator-=(difference_type n)       { current += n; return *this; }
  rev     operator+(difference_type n) const  { return rev(current - n); }
  rev     operator-(difference_type n) const  { return rev(current + n); }
  reference operator[](difference_type n) const { return *(*this + n); }

  friend rev operator+(difference_type n, rev_constref rhs) {
    return rai(rhs.current - n);
  }
  friend rev operator-(difference_type n, rev_constref rhs) {
    return rai(rhs.current + n);
  }
};

template<typename Iter>
bool operator==(reverse_iterator<Iter> const& rhs,
                reverse_iterator<Iter> const& lhs)
{ return rhs.base() == lhs.base(); }

template<typename Iter>
bool operator!=(reverse_iterator<Iter> const& rhs,
                reverse_iterator<Iter> const& lhs)
{ return rhs.base() != lhs.base(); }

template<typename Iter>
bool operator<=(reverse_iterator<Iter> const& rhs,
                reverse_iterator<Iter> const& lhs)
{ return rhs.base() <= lhs.base(); }

template<typename Iter>
bool operator>=(reverse_iterator<Iter> const& rhs,
                reverse_iterator<Iter> const& lhs)
{ return rhs.base() >= lhs.base(); }

template<typename Iter>
bool operator<(reverse_iterator<Iter> const& rhs,
               reverse_iterator<Iter> const& lhs)
{ return rhs.base() < lhs.base(); }

template<typename Iter>
bool operator>(reverse_iterator<Iter> const& rhs,
               reverse_iterator<Iter> const& lhs)
{ return rhs.base() > lhs.base(); }

template<typename Iter>
typename reverse_iterator<Iter>::difference_type
  operator-(reverse_iterator<Iter> const& rhs,
            reverse_iterator<Iter> const& lhs)
{ return lhs.base() - rhs.base(); }



} // namespace ft

#endif

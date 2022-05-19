//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 07/04/2022

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator_vector.hpp"
#include "type_traits.hpp"
#include "algo.hpp"

namespace ft {
  typedef integral_constant<bool, false>              false_type;
  typedef integral_constant<bool, true>               true_type;

template<typename T, typename Alloc = std::allocator<T> >
class vector {
  // ###########################################################################
  // #                               TYPEDEFS                                  #
  // ###########################################################################
public:
  typedef Alloc                                       alloc_type;
  typedef T                                           value_type;
  typedef typename std::allocator<T>::pointer         pointer;
  typedef typename std::allocator<T>::size_type       size_type;
  typedef typename std::allocator<T>::const_pointer   const_pointer;
  typedef typename std::allocator<T>::reference       reference;
  typedef typename std::allocator<T>::const_reference const_reference;
  typedef ft::vector<T, Alloc>&                       vec_ref;
  typedef ft::vector<T, Alloc> const&                 vec_constref;
  typedef random_access_iterator<pointer>             iterator;
  typedef random_access_iterator<const_pointer>       const_iterator;
  typedef ft::reverse_iterator<iterator>              reverse_iterator;
  typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

  // ###########################################################################
  // #                            INTERVAL VARIABLES                           #
  // ###########################################################################
protected:
  std::allocator<T> _alloc;
  pointer           _data;
  size_type         _size;
  size_type         _max_size;
  size_type         _capacity;

public:
  // ###########################################################################
  // #                              CONSTRUCTORS                               #
  // ###########################################################################
  explicit vector(const alloc_type& alloc = alloc_type());
  explicit vector(size_type n,
                  value_type val = value_type(),
                  const alloc_type& alloc = alloc_type());
  vector(vec_constref src);
  //range / fill constructor disambiguator
  template<typename IterT>
  vector(IterT first, IterT last, alloc_type const& alloc = alloc_type())
  : _alloc(alloc) {
    typedef typename is_integral<IterT>::type _integral;
    constructor_dispatch(first, last, _integral());
  }
  ~vector(void);

  //operators
  vec_ref         operator=(vec_constref rhs);
  reference       operator[](size_type n);
  const_reference operator[](size_type n) const;

  // ###########################################################################
  // #                                ASSESSORS                                #
  // ###########################################################################
  size_t          size(void) const;
  size_t          max_size(void) const;
  size_t          capacity(void) const;
  alloc_type      get_allocator(void) const { return this->_alloc; }

  // ###########################################################################
  // #                              ELEMENT ACCESS                             #
  // ###########################################################################
  reference       at(size_type n)
  { if (n >= _size) throw(std::range_error("range error\n")); return _data[n]; }
  const_reference at(size_type n) const
  { if (n >= _size) throw(std::range_error("range error\n")); return _data[n]; }
  reference       front(void)             { return _data[0]; }
  const_reference front(void) const       { return _data[0]; }
  reference       back(void)              { return _data[_size - 1]; }
  const_reference back(void) const        { return _data[_size - 1]; }
  bool             empty(void) const      { return !_size; }

  // ###########################################################################
  // #                            MEMBER FUNCTIONS                             #
  // ###########################################################################
  void            reserve(size_t n);
  void            resize(size_t n, value_type val = value_type());
  void            push_back(value_type const& val);
  void            pop_back(void);
  void            clear(void);

  void assign(size_type n, value_type const& val)
  { assign_dispatch(n, val, true_type()); };
  template <class IterT>
  void assign(IterT first, IterT last) {
    typedef typename is_integral<IterT>::type _integral;
    assign_dispatch(first, last, _integral());
  }

  iterator  insert(iterator pos, value_type const& val);
  iterator  insert(iterator pos, size_type n, const value_type& val)
  { insert_dispatch(pos, n, val, true_type()); return pos; }

  template <class IterT>                             // range
  void insert(iterator position, IterT first, IterT last) {
    typedef typename is_integral<IterT>::type _integral;
    insert_dispatch(position, first, last, _integral());
  }

  iterator  erase(iterator position);
  iterator  erase(iterator first, iterator last);
  void      swap(vector& src);


  // ###########################################################################
  // #                            ITERATOR SUPPORT                             #
  // ###########################################################################
  iterator                 begin(void);
  const_iterator           begin(void) const;
  reverse_iterator         rbegin(void);
  const_reverse_iterator   rbegin(void) const;
  iterator                 end(void);
  const_iterator           end(void) const;
  reverse_iterator         rend(void);
  const_reverse_iterator   rend(void) const;

  // ###########################################################################
  // #                                 DEBUG                                   #
  // ###########################################################################
  friend std::ostream& operator<<(std::ostream& o, vec_ref rhs) {
    std::cout << "Vector debug\n";
    for (iterator it = rhs.begin(); it != rhs.end(); it++)
      o << *it << " ";
    o << "\n\n";
    return o;
  }

  // ###########################################################################
  // #                           RELATIONAL OPERATORS                          #
  // ###########################################################################
  friend bool operator==(vec_constref lhs, vec_constref rhs) {
    if (lhs.size() != rhs.size())
      return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
  }
  friend bool operator<(vec_constref lhs, vec_constref rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                       rhs.begin(), rhs.end());
  }
  friend bool operator!=(vec_constref lhs, vec_constref rhs)
  { return !(lhs == rhs); }
  friend bool operator>(vec_constref lhs, vec_constref rhs)
  { return (rhs < lhs); }
  friend bool operator>=(vec_constref lhs, vec_constref rhs)
  { return lhs > rhs || lhs == rhs; }
  friend bool operator<=(vec_constref lhs, vec_constref rhs)
  { return lhs < rhs || lhs == rhs; }

  // ###########################################################################
  // #                                DISPATCHERS                              #
  // ###########################################################################
private:
  template<typename Integer>
  void constructor_fill(size_type n, Integer value);
  template<typename Integer>
  void constructor_dispatch(Integer n, Integer value, true_type) {
    constructor_fill(static_cast<size_t>(n), value);
  }

  template<typename IterT>
  void constructor_range(IterT first, IterT last);
  template<typename IterT>
  void constructor_dispatch(IterT first, IterT last, false_type) {
    constructor_range(first, last);
  }

  template<typename Integer>
  void insert_fill(iterator pos, size_type n, Integer const& val);
  template<typename Integer>
  void insert_dispatch(iterator pos, size_type n,
Integer const& val, true_type) {
    insert_fill(pos, n, val);
  }

  template<typename IterT>
  void insert_range(iterator pos, IterT first, IterT last);
  template<typename IterT>
  void insert_dispatch(iterator pos, IterT first, IterT last, false_type) {
    insert_range(pos, first, last);
  }

  template<typename Integer>
  void assign_fill(size_type n, Integer const& val);
  template<typename Integer>
  void assign_dispatch(size_type n, Integer const& val, true_type) {
    assign_fill(n, val);
  }

  template<typename IterT>
  void assign_range(IterT first, IterT last);
  template<typename IterT>
  void assign_dispatch(IterT first, IterT last, false_type) {
    assign_range(first, last);
  }
};

} //namespace ft

#include "vector_members.tpp"
#include "vector_operators.tpp"
#include "vector_constructors.tpp"

#endif //FT_VECTOR_HPP

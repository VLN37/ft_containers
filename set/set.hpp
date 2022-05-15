//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 15/05/2022

#ifndef SET_HPP
# define SET_HPP

#include<memory>
#include <functional>
#include "rbtree.hpp"
#include "iterator_tree.hpp"
#include "rbtree_node.hpp"
#include "pair.hpp"

namespace ft {
template<typename T,
         typename Compare = std::less<T>,
         typename Alloc = std::allocator<T> >
class set {
struct KoV {
  T const& operator()(T const& src) {
    return src;
  }
};

class value_compare: Compare { };

// #############################################################################
// #                               TYPEDEFS                                    #
// #############################################################################

public:
  typedef T                                             key_type;
  typedef T                                             value_type;
  typedef Compare                                       key_compare;
  typedef Alloc                                         allocator_type;
  typedef typename Alloc::reference                     reference;
  typedef typename Alloc::const_reference               const_reference;
  typedef typename Alloc::pointer                       pointer;
  typedef typename Alloc::const_pointer                 const_pointer;
  typedef rbtree<const T, const T, KoV, Compare, Alloc> _Container;
  typedef ptrdiff_t                                     difference_type;
  typedef typename _Container::iterator                 iterator;
  typedef typename _Container::const_iterator           const_iterator;
  typedef typename _Container::reverse_iterator         reverse_iterator;
  typedef typename _Container::const_reverse_iterator   const_reverse_iterator;

private:
  typedef typename _Container::reverse_iterator         rev_iterator;
  typedef typename _Container::const_reverse_iterator   c_rev_iterator;

protected:
  _Container    tree;
  key_compare   comp;
  value_compare val_comp;

}; // SET_HPP
} // namespace ft

#endif

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 11/05/2022

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <functional>
#include "rbtree.hpp"
#include "iterator_tree.hpp"
#include "rbtree_node.hpp"
#include "pair.hpp"

namespace ft {
template <typename Key,
          typename Val,
          typename Compare = std::less<Key>,
          typename Alloc   = std::allocator<ft::pair<const Key, Val> > >
class map {
struct KoV {
  Key operator()(ft::pair<const Key, Val> src) {
    return src.first;
  }
};

// #############################################################################
// #                               TYPEDEFS                                    #
// #############################################################################
public:
  typedef Key                                                 key_type;
  typedef Val                                                 mapped_type;
  typedef ft::pair<const Key, Val>                            value_type;
  typedef Compare                                             key_compare;
  typedef Alloc                                               allocator_type;
  typedef typename std::allocator<Val>::reference             reference;
  typedef typename std::allocator<Val>::const_reference       const_reference;
  typedef typename std::allocator<Val>::pointer               pointer;
  typedef typename std::allocator<Val>::const_pointer         const_pointer;
  typedef typename std::allocator<Val>::size_type             size_type;
  typedef rbtree<value_type, Val, KoV, Compare, Alloc>        _storage;

protected:
  rbtree<value_type, Val, KoV, Compare, Alloc> tree;

private:
  typedef typename _Container::iterator                       iterator;
  typedef typename _Container::const_iterator                 const_iterator;
  typedef typename _Container::rev_iterator                   rev_iterator;
  typedef typename _Container::c_rev_iterator                 c_rev_iterator;
  typedef ptrdiff_t                                           difference_type;

};

} // namespace ft
#endif // MAP_HPP

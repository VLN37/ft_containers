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
          typename Compare = std::less<const Key>,
          typename Alloc   = std::allocator<ft::pair<const Key, Val> > >
class map {
struct KoV {
  Key const& operator()(ft::pair<const Key, Val> const& src) {
    return src.first;
  }
};

// #############################################################################
// #                               TYPEDEFS                                    #
// #############################################################################
public:
  typedef Key                                                  key_type;
  typedef Val                                                  mapped_type;
  typedef ft::pair<const Key, Val>                             value_type;
  typedef Compare                                              key_compare;
  typedef Alloc                                                allocator_type;
  typedef typename std::allocator<value_type>::reference       reference;
  typedef typename std::allocator<value_type>::const_reference const_reference;
  typedef typename std::allocator<value_type>::pointer         pointer;
  typedef typename std::allocator<value_type>::const_pointer   const_pointer;
  typedef typename std::allocator<value_type>::size_type       size_type;
  typedef rbtree<const Key, value_type, KoV, Compare, Alloc>   _Container;
  typedef typename _Container::iterator                        iterator;
  typedef typename _Container::const_iterator                  const_iterator;
  typedef typename _Container::rev_iterator                    rev_iterator;
  typedef typename _Container::c_rev_iterator                  c_rev_iterator;
  typedef ptrdiff_t                                            difference_type;

class value_compare {
  protected:
    //this is probably a ValueOfValue struct
    Compare comp;
  public:
    value_compare(Compare c): comp(c) { }
    typedef bool result_type;
    bool operator()(value_type const& x, value_type const& y) const {
      return comp(x.first, y.first);
  }
};

protected:
  rbtree<const Key, value_type, KoV, Compare, Alloc> tree;

// #############################################################################
// #                              CONSTRUCTORS                                 #
// #############################################################################

public:
  explicit map(key_compare const     = key_compare(),
               allocator_type const& = allocator_type()) { };
  map(map const& src) { tree = src.tree; }
  map& operator=(map const& src) { tree = src.tree; return *this; }

// #############################################################################
// #                                CAPACITY                                   #
// #############################################################################

  size_type size(void) const           { return tree.size(); }
  bool      empty(void) const          { return !tree.size(); }
  size_type max_size(void) const       { return tree.max_size(); }

// #############################################################################
// #                               ASSESSORS                                   #
// #############################################################################

  allocator_type get_allocator() const { return allocator_type(); }

// #############################################################################
// #                            ITERATOR SUPPORT                               #
// #############################################################################

  iterator       begin(void)         { return tree.begin(); }
  const_iterator begin(void)  const  { return tree.begin(); }
  iterator       end(void)           { return tree.end(); }
  const_iterator end(void)    const  { return tree.end(); }
  rev_iterator   rbegin(void)        { return tree.rbegin(); }
  c_rev_iterator rbegin(void) const  { return tree.rbegin(); }
  rev_iterator   rend(void)          { return tree.rend(); }
  c_rev_iterator rend(void)   const  { return tree.rend(); }

// #############################################################################
// #                               OPERATIONS                                  #
// #############################################################################

//to do - const correctness on rbtree to work here
  iterator  find(Key const& key) { return iterator(tree.search(key)); }
  size_type count(Key const& key)
  { return tree.search(key) == tree.getsent() ?  0 : 1; }

// #############################################################################
// #                               MODIFIERS                                   #
// #############################################################################

  void clear(void)      { tree.recurse_delete(tree.getroot()); }
  void swap(map& other) { tree.swap(other.tree); }

  ft::pair<iterator, bool> insert(value_type const& val)
  {
    typename _Container::nodeptr ptr;

    ptr = tree.search(KoV()(val));
    if (ptr != tree.getsent() && size())
      return ft::pair<iterator, bool>(iterator(ptr), false);
    tree.insert(val);
    return ft::pair<iterator, bool>(iterator(tree.search(KoV()(val))), true);
  }

  iterator insert(iterator position, value_type const& val)
  {
    typename _Container::nodeptr ptr;

    ptr = tree.search(KoV()(val));
    if (ptr != tree.getsent() && size())
      return iterator(ptr);
    tree.insert(val, position.base());
    return iterator(tree.search(KoV()(val)));
  }

  template<typename Iter>
  void insert(Iter first, Iter last)
  {
    for (; first != last; first++)
      insert(value_type(*first));
  }

  void erase(iterator position)
  {
    tree.erase(KoV()(position.base()->data));
  }

  size_type erase(key_type const& key)
  {
    typename _Container::nodeptr ptr;
    ptr = tree.search(key);
    tree.erase(key);
    return ptr == tree.getsent() ? 0 : 1;
  }

  void erase(iterator first, iterator last)
  {
    iterator next(first);
    next++;
    for (; first != last; next++) {
      tree.erase(KoV()(first.base()->data));
      first = next;
    }
  }

// #############################################################################
// #                                 DEBUG                                     #
// #############################################################################

  void print(void) { tree.print(); }
};

} // namespace ft
#endif // MAP_HPP

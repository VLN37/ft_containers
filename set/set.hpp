//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 15/05/2022

#ifndef SET_HPP
# define SET_HPP

#include <memory>
#include <functional>
#include "rbtree.hpp"
#include "iterator_tree.hpp"
#include "rbtree_node.hpp"
#include "algo.hpp"
#include "pair.hpp"

#define SET_TEMPLATE typename T, typename Compare, typename Alloc
#define SET_TYPE set<T, Compare, Alloc>

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

// #############################################################################
// #                               TYPEDEFS                                    #
// #############################################################################

public:
  typedef const T                                       key_type;
  typedef T                                             value_type;
  typedef Compare                                       key_compare;
  typedef Alloc                                         allocator_type;
  typedef typename Alloc::reference                     reference;
  typedef typename Alloc::const_reference               const_reference;
  typedef typename Alloc::pointer                       pointer;
  typedef typename Alloc::const_pointer                 const_pointer;
  typedef typename Alloc::size_type                     size_type;
  typedef rbtree<const T, T, KoV, Compare, Alloc>       _Container;
  typedef ptrdiff_t                                     difference_type;
  typedef typename _Container::iterator                 iterator;
  typedef typename _Container::const_iterator           const_iterator;
  typedef typename _Container::reverse_iterator         reverse_iterator;
  typedef typename _Container::const_reverse_iterator   const_reverse_iterator;

private:
  typedef typename _Container::reverse_iterator         rev_iterator;
  typedef typename _Container::const_reverse_iterator   c_rev_iterator;

// #############################################################################
// #                          INTERNAL VARIABLES                               #
// #############################################################################

public:
class value_compare {
  protected:
    Compare comp;
  public:
    value_compare(Compare c): comp(c) { }
    bool operator()(key_type const& x, key_type const& y) const {
      return comp(x, y);
  }
};

protected:
  _Container    tree;
  key_compare   comp;
  value_compare val_comp;

// #############################################################################
// #                              CONSTRUCTORS                                 #
// #############################################################################

public:
  set(void): comp(key_compare()), val_comp(value_compare(key_compare())) { }
  template<typename Iter>
  set(Iter first, Iter last)
  : comp(key_compare()), val_comp(value_compare(key_compare()))
  {
    for (; first != last; first++)
      tree.insert(*first);
  }
  set(set const& src)
  : comp(key_compare()), val_comp(value_compare(key_compare()))
  { tree = src.tree; }
  set& operator=(set const& src) {
    tree = src.tree;
    comp = src.key_comp();
    val_comp = src.value_comp();
    return *this;
  }

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
  key_compare    key_comp() const      { return key_compare(); }
  value_compare  value_comp() const    { return value_compare(key_comp()); }

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
// #                                OBSERVERS                                  #
// #############################################################################

//to do - const correctness on rbtree to work here
  iterator  find(value_type const& val)
  { return iterator(tree.search(val)); }
  size_type count(value_type const& val)
  { return tree.search(val) == tree.getsent() ?  0 : 1; }

  iterator       upper_bound(key_type const& key);
  const_iterator upper_bound(key_type const& key) const;
  iterator       lower_bound(key_type const& key);
  const_iterator lower_bound(key_type const& key) const;
  pair<const_iterator, const_iterator> equal_range(key_type const& k) const
  { return ft::make_pair(lower_bound(k), upper_bound(k)); }
  pair<iterator, iterator>             equal_range(key_type const& k)
  { return ft::make_pair(lower_bound(k), upper_bound(k)); }

// #############################################################################
// #                               MODIFIERS                                   #
// #############################################################################

  void clear(void)      { tree.recurse_delete(tree.getroot()); }
  void swap(set& other) { tree.swap(other.tree); }

  template<typename Iter>
  void                 insert(Iter first, Iter last);
  pair<iterator, bool> insert(value_type const& val);
  iterator             insert(iterator position, value_type const& val);
  size_type            erase(key_type const& key);
  void                 erase(iterator first, iterator last);
  void                 erase(iterator position)
  { tree.erase(KoV()(position.base()->data)); }

// #############################################################################
// #                          RELATIONAL OPERATORS                             #
// #############################################################################

friend bool operator==(set const& lhs, set const& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
friend bool operator<(set const& lhs, set const& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                     rhs.begin(), rhs.end());
}
friend bool operator!=(set const& lhs, set const& rhs)
{ return !(lhs == rhs); }
friend bool operator>(set const& lhs, set const& rhs)
{ return !(lhs < rhs); }
friend bool operator>=(set const& lhs, set const& rhs)
{ return lhs > rhs || lhs == rhs; }
friend bool operator<=(set const& lhs, set const& rhs)
{ return lhs < rhs || lhs == rhs; }

// #############################################################################
// #                                 DEBUG                                     #
// #############################################################################

  void print(void) { tree.print(); }
};
} // namespace ft

#include "set_modifiers.tpp"
#include "set_observers.tpp"
#endif // SET_HPP

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
#include "algo.hpp"

#define MAP_TEMPLATE typename Key, \
                     typename Val, \
                     typename Compare, \
                     typename Alloc
#define MAP_TYPE map<Key, Val, Compare, Alloc>

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
  typedef Key                                            key_type;
  typedef Val                                            mapped_type;
  typedef ft::pair<const Key, Val>                       value_type;
  typedef Compare                                        key_compare;
  typedef Alloc                                          allocator_type;
  typedef typename Alloc::reference                      reference;
  typedef typename Alloc::const_reference                const_reference;
  typedef rbtree<const Key, value_type, KoV, Compare, Alloc> _Container;
  typedef typename Alloc::pointer                        pointer;
  typedef typename Alloc::const_pointer                  const_pointer;
  typedef typename Alloc::size_type                      size_type;
  typedef ptrdiff_t                                      difference_type;
  typedef typename _Container::iterator                  iterator;
  typedef typename _Container::const_iterator            const_iterator;
  typedef typename _Container::reverse_iterator          reverse_iterator;
  typedef typename _Container::const_reverse_iterator    const_reverse_iterator;

private:
  typedef typename _Container::reverse_iterator          rev_iterator;
  typedef typename _Container::const_reverse_iterator    c_rev_iterator;

// #############################################################################
// #                          INTERNAL VARIABLES                               #
// #############################################################################

public:
class value_compare {
  protected:
    Compare comp;
  public:
    value_compare(Compare c): comp(c) { }
    bool operator()(value_type const& x, value_type const& y) const {
      return comp(x.first, y.first);
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
  map(void): comp(key_compare()), val_comp(value_compare(key_compare())) { };
  template<typename Iter>
  map(Iter first, Iter last)
  :comp(key_compare()), val_comp(value_compare(key_compare()))
  {
    for (; first != last; first++)
      tree.insert(ft::pair<const Key, Val>(*first));
  }
  map(map const& s)
  : comp(s.key_comp()), val_comp(s.value_comp()) { tree = s.tree; }
  map& operator=(map const& src) {
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
// #                               OBSERVERS                                   #
// #############################################################################

//to do - const correctness on rbtree to work here
  iterator  find(Key const& key) { return iterator(tree.search(key)); }
  size_type count(Key const& key)
{ return tree.search(key) == tree.getsent() ?  0 : 1; }

  iterator       upper_bound(key_type const& key);
  const_iterator upper_bound(key_type const& key) const;
  iterator       lower_bound(key_type const& key);
  const_iterator lower_bound(key_type const& key) const;
  ft::pair<const_iterator, const_iterator> equal_range(key_type const& k) const
  { return ft::make_pair(lower_bound(k), upper_bound(k)); }
  ft::pair<iterator, iterator> equal_range(key_type const& k)
  { return ft::make_pair(lower_bound(k), upper_bound(k)); }

// #############################################################################
// #                               MODIFIERS                                   #
// #############################################################################

  void  clear(void)      { tree.recurse_delete(tree.getroot()); }
  void  swap(map& other) { tree.swap(other.tree); }

  template<typename Iter>
  void                     insert(Iter first, Iter last);
  ft::pair<iterator, bool> insert(value_type const& val);
  iterator                 insert(iterator position, value_type const& val);
  void                     erase(iterator first, iterator last);
  size_type                erase(key_type const& key);
  void                     erase(iterator position)
  {  tree.erase(KoV()(position.base()->data)); }
  mapped_type&             operator[](key_type const& key);


// #############################################################################
// #                          RELATIONAL OPERATORS                             #
// #############################################################################

friend bool operator==(map const& lhs, map const& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
friend bool operator<(map const& lhs, map const& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                     rhs.begin(), rhs.end());
}
friend bool operator!=(map const& lhs, map const& rhs)
{ return !(lhs == rhs); }
friend bool operator>(map const& lhs, map const& rhs)
{ return !(lhs < rhs); }
friend bool operator>=(map const& lhs, map const& rhs)
{ return lhs > rhs || lhs == rhs; }
friend bool operator<=(map const& lhs, map const& rhs)
{ return lhs < rhs || lhs == rhs; }


// #############################################################################
// #                                 DEBUG                                     #
// #############################################################################

  void print(void) { tree.print(); }
};

} // namespace ft
#include "map_observers.tpp"
#include "map_modifiers.tpp"
#endif // MAP_HPP

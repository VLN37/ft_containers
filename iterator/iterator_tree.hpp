//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 08/05/2022

#ifndef ITERATOR_TREE_HPP
# define ITERATOR_TREE_HPP

#include "iterator_base.hpp"
#include "../rbtree/rbtree.hpp"
#include "../rbtree/rbtree_node.hpp"

namespace ft {

template<typename IterT, typename _Container>
class tree_iterator
: public iterator<std::bidirectional_iterator_tag, IterT> {
public:
  typedef IterT                                            iterator_type;
  typedef typename iterator_traits<IterT>::value_type      value_type;
  typedef typename iterator_traits<IterT>::difference_type difference_type;
  typedef typename iterator_traits<IterT>::pointer         pointer;
  typedef typename iterator_traits<IterT>::reference       reference;

private:
  typedef tree_iterator                                    iter;
  typedef ft::iterator_traits<IterT>                       my_traits;
  typedef Node<value_type>*                                nodeptr;

protected:

public:
  Node<value_type>* current;
  tree_iterator(void): current(NULL) { }
  explicit tree_iterator(nodeptr node): current(node) { }

  template <typename Iter2>
  tree_iterator(tree_iterator<Iter2, _Container> const& iterator)
  : current(iterator.base()) { }

  iter& operator=(nodeptr rhs) { current = rhs; return *this; }
  template<typename Iter2>
  iter& operator=(tree_iterator<Iter2, _Container> const& rhs) {
    current = rhs.base();
    return *this;
  }


  nodeptr        base(void) const       { return current; }
  reference      operator*(void) const  { return current->data; }
  pointer        operator->(void) const { return &operator*(); }
  iter&          operator++(void)
  { current = _Container::sucessor(current); return *this; }
  iter&          operator--(void)
  { current = _Container::predecessor(current); return *this; }
  iter           operator++(int) {
    iter tmp(current);
    current = _Container::sucessor(current);
    return tmp;
  }
  iter           operator--(int) {
    iter tmp(current);
    current = _Container::predecessor(current);
    return tmp;
  }
  bool operator==(iter const& rhs) const { return current == rhs.current; }
  bool operator!=(iter const& rhs) const { return current != rhs.current; }
};

template<typename IterA, typename IterB, typename _Container>
bool operator==(tree_iterator<IterA, _Container> const& lhs,
                tree_iterator<IterB, _Container> const& rhs)
  { return (lhs.base() == rhs.base()); }

template<typename IterA, typename IterB, typename _Container>
bool operator!=(tree_iterator<IterA, _Container> const& lhs,
                tree_iterator<IterB, _Container> const& rhs)
  { return (lhs.base() != rhs.base()); }

template<typename IterT, typename _Container>
class tree_rev_iterator
: public iterator<std::bidirectional_iterator_tag, IterT> {
private:
  typedef tree_rev_iterator<IterT, _Container>                rev;
  typedef tree_rev_iterator<IterT, _Container>&               rev_ref;
  typedef tree_rev_iterator<IterT, _Container> const&         rev_constref;


public:
  typedef IterT                                               iterator_type;
  typedef typename iterator_traits<IterT>::iterator_category  iterator_category;
  typedef typename iterator_traits<IterT>::value_type         value_type;
  typedef typename iterator_traits<IterT>::difference_type    difference_type;
  typedef typename iterator_traits<IterT>::pointer            pointer;
  typedef typename iterator_traits<IterT>::reference          reference;
  typedef Node<value_type>*                          nodeptr;

protected:
  Node<value_type>* current;

public:
  tree_rev_iterator(void): current(NULL) { }
  //parameter is a pair, investigate if this is being called or if it even works
  tree_rev_iterator(iterator_type src): current(src) { }
  tree_rev_iterator(nodeptr src): current(src) { }
  tree_rev_iterator(rev const& src): current(src.current) { }
  ~tree_rev_iterator(void) { }

  template<typename Iter>
  rev& operator=(tree_rev_iterator<Iter, _Container> const& rhs)
  { current = rhs.base(); return *this; }

  nodeptr    base(void) const { return current; }
  reference  operator*(void) const { return current->data; }
  pointer    operator->(void) const { return &operator*(); }
  rev&       operator++(void)
  { current =  _Container::predecessor(current); return *this; }
  rev&       operator--(void)
  { current =  _Container::sucessor(current); return *this; }
  rev        operator++(int) {
    rev tmp(current);
    current = _Container::predecessor(current);
    return tmp;
  }
  rev        operator--(int) {
    rev tmp(current);
    current = _Container::sucessor(current);
    return tmp;
  }
  bool operator==(rev const& rhs) const { return current == rhs.current; }
  bool operator!=(rev const& rhs) const { return current != rhs.current; }
};

template<typename IterA, typename IterB, typename _Container>
bool operator==(tree_rev_iterator<IterA, _Container> const& lhs,
                tree_rev_iterator<IterB, _Container> const& rhs)
  { return (lhs.base() == rhs.base()); }

template<typename IterA, typename IterB, typename _Container>
bool operator!=(tree_rev_iterator<IterA, _Container> const& lhs,
                tree_rev_iterator<IterB, _Container> const& rhs)
  { return (lhs.base() != rhs.base()); }

}

#endif

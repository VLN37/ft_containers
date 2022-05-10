//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 08/05/2022

#ifndef ITERATOR_TREE_HPP
# define ITERATOR_TREE_HPP

#include <iostream>
#include "rbtree.hpp"
#include "iterator_base.hpp"
#include "iterator_funcs.hpp"
#include "rbtree_node.hpp"

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
bool operator==(tree_iterator<IterA, _Container> lhs,
                tree_iterator<IterB, _Container> rhs)
  { return (lhs.base() == rhs.base()); }

template<typename IterA, typename IterB, typename _Container>
bool operator!=(tree_iterator<IterA, _Container> lhs,
                tree_iterator<IterB, _Container> rhs)
  { return (lhs.base() != rhs.base()); }

template<typename IterT, typename _Container>
class tree_rev_iterator
: public iterator<std::bidirectional_iterator_tag, IterT> {
protected:
  int randomgarbage;
};

}

#endif

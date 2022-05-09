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
  typedef ft::iterator_traits<IterT>                       my_traits;
  typedef IterT                                            iterator_type;
  typedef typename iterator_traits<IterT>::value_type      value_type;
  typedef Node<value_type>*                                nodeptr;
  typedef typename iterator_traits<IterT>::difference_type difference_type;
  typedef typename iterator_traits<IterT>::pointer         pointer;
  typedef typename iterator_traits<IterT>::reference       reference;

protected:

public:
  Node<value_type>* current;
  tree_iterator(void): current(NULL) { }
  explicit tree_iterator(pointer src): current(src) { }
  tree_iterator(nodeptr node): current(node) { }
  template <typename Iterator>
    tree_iterator(Iterator const& iterator): current(iterator.current) { }

  reference   operator*(void) const { return current->data; }
  pointer     operator->(void) const { return &operator*(); }
  tree_iterator& operator++(void)
  { current = _Container::sucessor(current); return *this; }
  tree_iterator operator++(int) {
    tree_iterator tmp(current);
    current = _Container::sucessor(current);
    return tmp;
  }

};

}

#endif

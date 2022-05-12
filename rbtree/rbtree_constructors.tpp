//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_CONSTRUCTORS_TPP
# define RBTREE_CONSTRUCTORS_TPP

#include "rbtree.hpp"

namespace ft {

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::init_node(Val value) {
  nodeptr node = _nodealloc.allocate(1);
  _nodealloc.construct(node, Node<Val>(value));
  node->parent = SENT;
  // node->data = value;
  node->right = SENT;
  node->left = SENT;
  node->color = RED;
  return node;
}

template <TREE_TEMPLATE>
TREE_TYPE& TREE_TYPE::operator=(rbtree const& src) {
  recurse_delete(root);
  rbtree::iterator it = src.begin();
  rbtree::iterator ite = src.end();
  for (; it != ite; ++it)
    insert(*it);
  _size = src._size;
  return *this;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::SENT =
         reinterpret_cast<Node<Val>*>(&ft::SENTRY);

} // namespace ft
#endif // RBTREE_CONSTRUCTORS_TPP

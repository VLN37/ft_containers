//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_STATIC_TPP
# define RBTREE_STATIC_TPP

#include "rbtree.hpp"

namespace ft {

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::sucessor(nodeptr x) {
  if (x->right != SENT)
    return minimum(x->right);

  nodeptr y = x->parent;
  while (y != SENT && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::predecessor(nodeptr x) {
  if (x->left != SENT)
    return maximum(x->left);

  nodeptr y = x->parent;
  while (y != SENT && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::minimum(nodeptr node) {
  if (node == SENT)
    return node;
  while (node->left != SENT)
    node = node->left;
  return node;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::maximum(nodeptr node) {
  if (node == SENT)
    return node;
  while (node->right != SENT)
    node = node->right;
  return node;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::relative_root(nodeptr node) {
  while (node->parent != SENT)
    node = node->parent;
  return node;
}

} // namespace ft
#endif // RBTREE_STATIC_TPP

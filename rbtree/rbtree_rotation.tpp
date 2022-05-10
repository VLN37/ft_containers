//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_ROTATION_TPP
# define RBTREE_ROTATION_TPP

namespace ft {

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::left_rotate(nodeptr node) {
  nodeptr tmp = node->right;
  node->right = tmp->left;
  if (tmp->left != SENT) {
    tmp->left->parent = node;
  }
  tmp->parent = node->parent;
  if (node->parent == SENT)
    root = tmp;
  else if (node == node->parent->left)
    node->parent->left = tmp;
  else
    node->parent->right = tmp;
  tmp->left  = node;
  node->parent = tmp;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::right_rotate(nodeptr node) {
  nodeptr tmp = node->left;
  node->left = tmp->right;
  if (tmp->right != SENT)
    tmp->right->parent = node;
  tmp->parent = node->parent;
  if (node->parent == SENT)
    this->root = tmp;
  else if (node == node->parent->right)
    node->parent->right = tmp;
  else
    node->parent->left = tmp;
  tmp->right = node;
  node->parent = tmp;
}

}
#endif // RBTREE_ROTATION_TPP

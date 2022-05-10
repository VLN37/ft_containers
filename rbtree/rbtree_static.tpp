//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_STATIC_TPP
# define RBTREE_STATIC_TPP

namespace ft {

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::sucessor(nodeptr x) {
  if (x->right != SENT)
    return minimum(x->right);

  nodeptr y = x->parent;
  while (y != SENT && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::predecessor(nodeptr x) {
  if (x->left != SENT)
    return maximum(x->left);

  nodeptr y = x->parent;
  while (y != SENT && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::minimum(nodeptr node) {
  if (node == SENT)
    return node;
  while (node->left != SENT)
    node = node->left;
  return node;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::maximum(nodeptr node) {
  if (node == SENT)
    return node;
  while (node->right != SENT)
    node = node->right;
  return node;
}

} // namespace ft
#endif // RBTREE_STATIC_TPP

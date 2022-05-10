//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_CONSTRUCTORS_TPP
# define RBTREE_CONSTRUCTORS_TPP

namespace ft {

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::init_node(Val value) {
  nodeptr node = _nodealloc.allocate(1);
  _nodealloc.construct(node, Node<Val>(RED));
  node->parent = SENT;
  node->data = value;
  node->right = SENT;
  node->left = SENT;
  node->color = RED;
  return node;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc >
rbtree<Key, Val, KeyOfValue, Compare, Alloc>&
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::operator=(rbtree const& src) {
  recurse_delete(root);
  rbtree::iterator it = src.begin();
  rbtree::iterator ite = src.end();
  for (; it != ite; ++it)
    insert(*it);
  return *this;
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc >
typename ft::rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
 ft::rbtree<Key, Val, KeyOfValue, Compare, Alloc>::SENT
= reinterpret_cast<Node<Val>*>(&ft::SENTRY);

} // namespace ft
#endif // RBTREE_CONSTRUCTORS_TPP

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 11/05/2022

#ifndef RBTREE_UTILS_HPP
# define RBTREE_UTILS_HPP

namespace ft {

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::swap(tree_type& src) {
  nodeptr tmp = root;
  root = src.getroot();
  src.setroot(tmp);
}

} // namespace ft
#endif // RBTREE_UTILS_HPP

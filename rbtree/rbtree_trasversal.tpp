//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_TRASVERSAL_TPP
# define RBTREE_TRASVERSAL_TPP

namespace ft {

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::recurse_delete(nodeptr node) {
  if (node != SENT) {
    recurse_delete(node->left);
    recurse_delete(node->right);
    _nodealloc.destroy(node);
    _nodealloc.deallocate(node, 1);
  }
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
typename rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
rbtree<Key, Val, KeyOfValue, Compare, Alloc>::
searchHelper(nodeptr node, Key key) {
  if (node == SENT || (!Compare()(KeyOfValue()(node->data), key)
                    &&  !Compare()(key, KeyOfValue()(node->data))))
    return node;
  if (Compare()(key, KeyOfValue()(node->data)))
    return searchHelper(node->left, key);
  else
    return searchHelper(node->right, key);
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::preOrderHelper(nodeptr node) {
  if (node != SENT) {
    std::cout << node->data << " ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
  }
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::inOrderHelper(nodeptr node) {
  if (node != SENT) {
    inOrderHelper(node->left);
    std::cout << node->data << " ";
    inOrderHelper(node->right);
  }
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::postOrderHelper(nodeptr node) {
  if (node != SENT) {
    postOrderHelper(node->left);
    postOrderHelper(node->right);
    std::cout << node->data << " ";
  }
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::print(void) {
  std::cout << "***************************\n";
  if (root) {
    printHelper(this->root, "", true);
  }
  std::cout << "***************************\n";
}

template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::
printHelper(nodeptr node, std::string indent, bool last) {
  if (node != SENT) {
    std::cout << indent;
    if (last) {
      std::cout << "R---- ";
      indent += "     ";
    } else {
      std::cout << "L---- ";
      indent += "|    ";
    }
    std::string sColor = node->color ? "RED" : "BLACK";
    std::cout << node->data << "(" << sColor << ")\n";
    printHelper(node->left, indent, false);
    printHelper(node->right, indent, true);
  }
}
} //namespace ft
#endif

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_INSERT_TPP
# define RBTREE_INSERT_TPP

namespace ft {

/**
 * cases:
 * 1 - tree is empty - newnode is black
 * 2 - tree is not empty - newnode is red
 * 3 - parent of newnode is black - exit
 */
template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::insert(Val value) {
  nodeptr node = search(KeyOfValue()(value));
  nodeptr prev = NULL;
  nodeptr curr = root;

  if (node != SENT)
    delete_node(KeyOfValue()(value));
  node = init_node(value);
  while (curr != SENT) {
    prev = curr;
    if (Compare()(KeyOfValue()(node->data), KeyOfValue()(curr->data)))
      curr = curr->left;
    else
      curr = curr->right;
  }
  node->parent = prev;
  if (prev == NULL)
    root = node;
  else if (Compare()(KeyOfValue()(node->data), KeyOfValue()(prev->data)))
    prev->left = node;
  else
    prev->right = node;

  //case 1
  if (node->parent == NULL) {
    node->color = BLACK;
    return;
  }
  //determine if this is the second node
  if (node->parent->parent == NULL)
    return;
  fix_insert(node);
}

/**
 * 4 - rebalance if parent's brother is red (parent->parent->left/right)
 * 5 - decide rotation rules
 * 5.1 - LEFT rotate
 * 5.2 - RIGHT LEFT rotate
 * 5.3 - RIGHT rotate
 * 5.4 - LEFT RIGHT rotate
 */
template <typename Key, typename Val, typename KeyOfValue,
          typename Compare, typename Alloc>
void rbtree<Key, Val, KeyOfValue, Compare, Alloc>::fix_insert(nodeptr node) {
    nodeptr uncle;
    while (node->parent->color == RED) {
      if (node->parent == node->parent->parent->right) {
        uncle = node->parent->parent->left;
        if (uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        }
        else {
          if (node == node->parent->left) {
            node = node->parent;
            right_rotate(node);                               // 5.2
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          left_rotate(node->parent->parent);                  // 5.1 or 5.2
        }
      }
      else {
        uncle = node->parent->parent->right;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;
        }
        else {
          if (node == node->parent->right) {
            node = node->parent;
            left_rotate(node);                               // 5.4
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          right_rotate(node->parent->parent);                // 5.3 or 5.4
        }
      }
    if (node == root)
      break;
    }
  root->color = BLACK;
  }

}


#endif // RBTREE_INSERT_TPP

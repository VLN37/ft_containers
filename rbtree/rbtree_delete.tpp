//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_DELETE_TPP
# define RBTREE_DELETE_TPP

#include "rbtree.hpp"

namespace ft {

template <TREE_TEMPLATE>
void TREE_TYPE::erase(Key key) {
  nodeptr z = SENT;
  nodeptr x, y;
  e_color y_backup;

  z = search(key);
  if (z == SENT) //key not found
    return;
  _size--;
  y = z;
  y_backup = y->color;
  if (z->left == SENT) {
    x = z->right; // x = tmp?
    transplant_tree(z, z->right);
  }
  else if (z->right == SENT) {
    x = z->left;
    transplant_tree(z, z->left);
  }
  else {
    y = minimum(z->right);
    y_backup = y->color;
    x = y->right;
    if (y->parent == z) {
      x->parent = y;
    }
    else {
      transplant_tree(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant_tree(z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  _nodealloc.destroy(z);
  _nodealloc.deallocate(z, 1);
  if (y_backup == BLACK) {
    fix_delete(x);
  }
}

//s == sibling - x == deleted node
template <TREE_TEMPLATE>
void TREE_TYPE::fix_delete(nodeptr x) {
  nodeptr s;

  while (x != root && x->color == BLACK) {
    if (x == x->parent->left) {
      s = x->parent->right;
      //sibling of deleted node is red
      if (s->color == RED) {
        s->color = BLACK;
        x->parent->color = RED;
        left_rotate(x->parent);
        s = x->parent->right;
      }
      //sibling and children are black
      if (s->left->color == BLACK && s->right->color == BLACK) {
        s->color = RED;
        x = x->parent;
      }
      else {
        if (s->right->color == BLACK) {
          s->left->color = BLACK;
          s->color = RED;
          right_rotate(s);
          s = x->parent->right;
        }
        s->color = x->parent->color;
        x->parent->color = BLACK;
        s->right->color = BLACK;
        left_rotate(x->parent);
        x = root;
      }
    }
    else {
      s = x->parent->left;
      if (s->color == RED) {
        s->color = BLACK;
        x->parent->color = RED;
        right_rotate(x->parent);
        s = x->parent->left;
      }
      if (s->right->color == BLACK && s->left->color == BLACK) { //investigate
        s->color = RED;
        x = x->parent;
      }
      else {
        if (s->left->color == BLACK) {
          s->right->color = BLACK;
          s->color = RED;
          left_rotate(s);
          s = x->parent->left;
        }
        s->color = x->parent->color;
        x->parent->color = BLACK;
        s->left->color = BLACK;
        right_rotate(x->parent);
        x = root;
      }
    }
  }
  x->color = BLACK;
}

template <TREE_TEMPLATE>
void TREE_TYPE::transplant_tree(nodeptr u, nodeptr v) {
  if (u->parent == SENT)
    root = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  v->parent = u->parent; //lose reference of children?
}

} // namespace ft
#endif // RBTREE_DELETE_TPP

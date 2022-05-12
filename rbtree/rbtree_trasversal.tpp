//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_TRASVERSAL_TPP
# define RBTREE_TRASVERSAL_TPP

#include "rbtree.hpp"

namespace ft {

template <TREE_TEMPLATE>
void TREE_TYPE::recurse_delete(nodeptr node) {
  if (node != SENT) {
    recurse_delete(node->left);
    recurse_delete(node->right);
    _nodealloc.destroy(node);
    _nodealloc.deallocate(node, 1);
  }
  root = SENT;
}

template <TREE_TEMPLATE>
typename TREE_TYPE::nodeptr TREE_TYPE::searchHelper(nodeptr node, Key key) {
  if (node == SENT || (!Compare()(KeyOfValue()(node->data), key)
                   &&  !Compare()(key, KeyOfValue()(node->data))))
    return node;
  if (Compare()(key, KeyOfValue()(node->data)))
    return searchHelper(node->left, key);
  else
    return searchHelper(node->right, key);
}

template <TREE_TEMPLATE>
void TREE_TYPE::preOrderHelper(nodeptr node) {
  if (node != SENT) {
    std::cout << node->data << " ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
  }
}

template <TREE_TEMPLATE>
void TREE_TYPE::inOrderHelper(nodeptr node) {
  if (node != SENT) {
    inOrderHelper(node->left);
    std::cout << node->data << " ";
    inOrderHelper(node->right);
  }
}

template <TREE_TEMPLATE>
void TREE_TYPE::postOrderHelper(nodeptr node) {
  if (node != SENT) {
    postOrderHelper(node->left);
    postOrderHelper(node->right);
    std::cout << node->data << " ";
  }
}

template <TREE_TEMPLATE>
void TREE_TYPE::print(void) {
  std::cout << "***************************\n";
  if (root) {
    printHelper(this->root, "", true);
  }
  std::cout << "***************************\n";
}

template <TREE_TEMPLATE>
void TREE_TYPE::printHelper(nodeptr node, std::string indent, bool last) {
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
#endif // RB_TREE_TRASVERSAL

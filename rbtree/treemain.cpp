//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#include <iostream>
#include "rbtree.hpp"

int main(void) {
  std::cout << "this compiles!\n";
  ft::rbtree tree;
  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }
  tree.print();
  tree.inorder();
  tree.preorder();
  tree.postorder();
  std::cout << "hello darkness my old friend\n";
  tree.print();
  tree.delete_node(3);
  tree.print();
  tree.delete_node(4);
  tree.print();
  tree.delete_node(5);
  tree.print();
  // tree.delete_node(1);
  // tree.delete_node(2);
  // tree.print();
  // tree.delete_node(0);
  // tree.delete_node(7);
  // tree.delete_node(8);
  // tree.print();
  // tree.delete_node(9);
}

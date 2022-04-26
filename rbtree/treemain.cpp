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
}

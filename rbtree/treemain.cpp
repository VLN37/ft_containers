//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#include <iostream>
#include "rbtree.hpp"

int main(void) {
  std::cout << "this compiles!\n";
  ft::rbtree tree;
  tree.insert(40);
  tree.insert(20);
  tree.insert(60);
  tree.insert(50);
  tree.insert(30);
  tree.print();
  tree.inorder();
  tree.preorder();
  tree.postorder();
}

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#include <iostream>
#include "rbtree.hpp"
#include "pair.hpp"

int main(void) {
  std::cout << "this compiles!\n";
  ft::rbtree< std::string,
              ft::pair<std::string, int>,
              ft::KeyOfValue<ft::pair<std::string, int> > > tree;
  tree.insert(ft::pair<std::string, int>("a", 1));
  // for (int i = 0; i < 10; i++) {
  //   tree.insert(i);
  // }
  // tree.print();
  // tree.inorder();
  // tree.preorder();
  // tree.postorder();
  // std::cout << "hello darkness my old friend\n";
  // tree.print();
  // tree.delete_node(3);
  // tree.print();
  // tree.delete_node(4);
  // tree.print();
  // tree.delete_node(5);
  // tree.print();

  // tree.delete_node(1);
  // tree.delete_node(2);
  // tree.print();
  // tree.delete_node(0);
  // tree.delete_node(7);
  // tree.delete_node(8);
  // tree.print();
  // tree.delete_node(9);
}

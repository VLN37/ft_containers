//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#include <iostream>
#include "rbtree.hpp"
#include "pair.hpp"

template <typename T>
struct returnint {
  T operator()(T const& src) { return src; };
};

template <typename T>
struct returnstring {
  std::string operator()(T const& src) {
    return (src.first);
  }
};

int main(void) {
  std::cout << "this compiles!\n";
  ft::rbtree< int,
              ft::pair<int, std::string>,
              ft::KeyOfValue<ft::pair<int, std::string> > > tree;
  tree.insert(ft::pair<int, std::string>(1, "tde-cama"));
  tree.insert(ft::pair<int, std::string>(2, "guiga"));
  tree.insert(ft::pair<int, std::string>(3, "iwillens"));
  tree.insert(ft::pair<int, std::string>(4, "adrian"));
  tree.insert(ft::pair<int, std::string>(5, "flavio"));
  tree.insert(ft::pair<int, std::string>(6, "nayran"));
  tree.insert(ft::pair<int, std::string>(7, "paula"));
  tree.insert(ft::pair<int, std::string>(8, "laiz"));
  tree.insert(ft::pair<int, std::string>(9, "welton"));
  tree.insert(ft::pair<int, std::string>(10, "joao"));
  tree.print();
  tree.inorder();

  ft::rbtree<int, int, returnint<int> > tree2;
  tree2.print();
  for (int i = 0; i < 10; i++) {
    tree2.insert(i);
  }
  tree2.print();
  tree2.inorder();
  tree2.preorder();
  tree2.postorder();
  std::cout << "hello darkness my old friend\n";
  tree2.print();
  tree2.delete_node(3);
  tree2.print();
  tree2.delete_node(4);
  tree2.print();
  tree2.delete_node(5);
  tree2.print();

  tree2.delete_node(1);
  tree2.delete_node(2);
  tree2.delete_node(0);
  tree2.delete_node(7);
  tree2.print();
  tree2.delete_node(8);
  tree2.print();
  tree2.delete_node(9);

  std::cout << "this compiles!\n";
  ft::rbtree< std::string,
              ft::pair<std::string, int>,
              returnstring<ft::pair<std::string, int> > > tree3;
  tree3.insert(ft::pair<std::string, int>("a", 8));
  tree3.insert(ft::pair<std::string, int>("b", 18));
  tree3.insert(ft::pair<std::string, int>("c", 5));
  tree3.insert(ft::pair<std::string, int>("d", 15));
  tree3.insert(ft::pair<std::string, int>("e", 17));
  tree3.insert(ft::pair<std::string, int>("f", 25));
  tree3.insert(ft::pair<std::string, int>("g", 40));
  tree3.insert(ft::pair<std::string, int>("h", 80));
  tree3.insert(ft::pair<std::string, int>("i", 1));
  tree3.insert(ft::pair<std::string, int>("i", 15));
  tree3.print();
  tree3.delete_node("h");
  tree3.delete_node("d"); //root case
  tree3.delete_node("g"); //red node case
  tree3.print();
  tree3.inorder();
}

//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#include <iostream>
#include <algorithm>
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

template<typename T, typename V>
void printpair(ft::pair<T, V> pair) {
  std::cout << pair.first << " " << pair.second << "\n";
}

typedef  typename ft::rbtree< std::string,
                  ft::pair<std::string, int>,
                  returnstring<ft::pair<std::string, int> > > STRINT_TREE;

typedef  typename ft::rbtree< std::string,
                  const ft::pair<std::string, int>,
                  returnstring<ft::pair<std::string, int> > > CONST_STRINT_TREE;

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
  tree2.erase(3);
  tree2.print();
  tree2.erase(4);
  tree2.print();
  tree2.erase(5);
  tree2.print();

  tree2.erase(1);
  tree2.erase(2);
  tree2.erase(0);
  tree2.erase(7);
  tree2.print();
  tree2.erase(8);
  tree2.print();
  tree2.erase(9);

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
  // tree3.erase("h");
  // tree3.erase("d"); //root case
  // tree3.erase("g"); //red node case
  // tree3.erase("f"); //red node case
  // tree3.erase("i"); //black node
  // tree3.erase("a"); //black node
  // tree3.erase("b"); //black node
  // tree3.erase("c"); //black node
  // tree3.erase("e"); //black node
  // tree3.print();
  // tree3.inorder();

  STRINT_TREE::nodeptr ptr(tree3.getroot());
  STRINT_TREE::iterator ptr1(tree3.getroot());
  STRINT_TREE::iterator ptr2(ptr1);
  STRINT_TREE::iterator ptr3 = ptr2;
  std::cout << (ptr3 == ptr2) << '\n';
  std::cout << (ptr3 != ptr2) << '\n';
  std::cout << (ptr3 == ++ptr2) << '\n';
  std::cout << *ptr1 << '\n';
  std::cout << *ptr2 << '\n';
  std::cout << *ptr3 << '\n';
  ptr1 = STRINT_TREE::sucessor(ptr);
  std::cout << ptr->data << '\n';
  std::cout << ft::SENTRY.color << '\n';
  STRINT_TREE::iterator it = tree3.begin();
  std::cout << it->first << '\n';
  std::cout << (*it).first << '\n';
  std::cout << *it << '\n';
  std::cout << *++it << '\n';
  std::cout << *it++ << '\n';
  std::cout << *it << '\n';

  STRINT_TREE::iterator it1 = tree3.begin();
  STRINT_TREE::iterator it2 = tree3.end();

  std::cout << &ft::SENTRY << '\n';
  std::cout << tree3.SENT << '\n';
  std::cout << tree3.getroot()->parent <<' '<< tree2.getroot()->parent << '\n';
  std::cout << tree3.getroot() << ' ' << tree2.getroot() << '\n';

  tree3.print();
  for (; it1 != it2; ++it1)
    std::cout << *it1 << '\n';
  for_each(tree3.begin(), tree3.end(), printpair<std::string, int>);

  it1 = tree3.begin();
  ptr = it1.base();
  std::cout << ptr->data << '\n';
  STRINT_TREE::const_iterator itc1 = tree3.begin();
  STRINT_TREE::iterator       itc2 = tree3.begin();
  std::cout << (itc1 == itc2) << '\n';
  std::cout << (itc1 != itc2) << '\n';
  it1 = tree3.end();
  tree3.print();
  // it1++;
  // std::cout << *it1 << '\n';
  ptr = STRINT_TREE::minimum(tree3.getroot());
  std::cout << ptr << '\n';
  ptr = STRINT_TREE::predecessor(ptr);
  std::cout << ptr << '\n';
  std::cout << &ft::SENTRY << '\n';

  STRINT_TREE tree4;
  tree4.insert(ft::pair<std::string, int>("z", 82));
  tree4.insert(ft::pair<std::string, int>("x", 94));
  tree4.insert(ft::pair<std::string, int>("y", 3));
  tree4.insert(ft::pair<std::string, int>("v", 42));
  tree4.insert(ft::pair<std::string, int>("t", 12));

  tree3.print();
  tree4.print();
  tree4 = tree3;
  tree3.print();
  tree4.print();
  STRINT_TREE::nodeptr roottest = tree4.maximum(tree4.getroot());
  std::cout << roottest->data << '\n';
  roottest = STRINT_TREE::relative_root(roottest);
  std::cout << roottest->data << '\n';

  STRINT_TREE::rev_iterator itrev1;
  STRINT_TREE::rev_iterator itrev2(itrev1);
  STRINT_TREE::rev_iterator itrev3(tree4.getroot());
  STRINT_TREE::c_rev_iterator itrevc(tree4.getroot());
  itrev1 = tree4.rbegin();
  itrev2 = tree4.rend();
  std::cout << (itrev1 == itrev2) << '\n';
  std::cout << (itrev1 != itrev2) << '\n';
  for (; itrev1 != itrev2; ++itrev1)
    std::cout << *itrev1 << '\n';
  for_each(tree4.rbegin(), itrev2, printpair<std::string, int>);
  itrev1 = tree4.rbegin();
  std::cout << (itrev1 == itrevc) << '\n';
  std::cout << (itrev1 != itrevc) << '\n';
  STRINT_TREE::rev_iterator itrev4(itc2);
  std::cout << (itrev4 == itc2) << '\n';
  STRINT_TREE::c_rev_iterator itrev5(tree4.begin());
  STRINT_TREE::c_rev_iterator itrev6(tree4.rbegin());
  STRINT_TREE::c_rev_iterator itrev7(tree4.end());
  STRINT_TREE::c_rev_iterator itrev8(tree4.rend());
}

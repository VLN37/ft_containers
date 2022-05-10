//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 09/05/2022

#ifndef RBTREE_NODE_HPP
# define RBTREE_NODE_HPP

namespace ft {
enum e_color { BLACK, RED };

template <typename T>
struct Node {
  typedef Node* nodeptr;

  Node(void) : parent(this), left(this), right(this), color(RED) { }
  explicit Node(ft::e_color i)
  : parent(this), left(this), right(this), color(i) { }

  T       data;
  Node*   parent;
  Node*   left;
  Node*   right;
  e_color color;

  friend std::ostream& operator<<(std::ostream& o, Node& rhs)
  { return o << rhs.data.first; }
};

template <typename T>
struct KeyOfValue {
  int operator()(T const& src) const {
    return (src.first);
  }
};

static Node<int> SENTRY = Node<int>(BLACK);
} // namespace ft


#endif

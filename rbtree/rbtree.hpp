//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef RB_TREE
# define RB_TREE

#include <string>
#include <memory>
#include <functional>
#include "iterator_tree.hpp"

namespace ft {

static Node<int> SENTRY = Node<int>(BLACK);

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Val> >
class rbtree {
public:
  typedef Node<Val>*                                          nodeptr;
  typedef Node<Val>                                           node_type;
  typedef Val                                                 value_type;
  typedef value_type*                                         pointer;
  typedef const pointer                                       const_pointer;
  typedef typename Alloc::template rebind<Node<Val> >::other  Node_allocator;
  typedef rbtree<Key, Val, KeyOfValue, Compare, Alloc>        tree_type;
  typedef tree_iterator<pointer, tree_type>                   iterator;

  // static const nodeptr        SENT = &(Node<Val>());
  static nodeptr SENT;
  nodeptr        root;
  Alloc          _alloc;
  Node_allocator _nodealloc;

  rbtree(void)  { root = SENT; }
  ~rbtree(void) { recurse_delete(root); }
  void recurse_delete(nodeptr node);

  static nodeptr sucessor(nodeptr x);
  static nodeptr predecessor(nodeptr x);
  static nodeptr minimum(nodeptr node);
  static nodeptr maximum(nodeptr node);

  iterator begin(void) { return iterator(minimum(root)); }

  nodeptr searchHelper(nodeptr node, Key key);
  nodeptr search(Key key) { return searchHelper(root, key); }


  nodeptr init_node(Val value) {
    nodeptr node = _nodealloc.allocate(1);
    _nodealloc.construct(node, Node<Val>(RED));
    node->parent = NULL;
    node->data = value;
    node->right = SENT;
    node->left = SENT;
    node->color = RED;
    return node;
  }

  void left_rotate(nodeptr node);
  void right_rotate(nodeptr node);
  void insert(Val value);
  void fix_insert(nodeptr node);
  void delete_node(Key key);
  void fix_delete(nodeptr x);
  void transplant_tree(nodeptr u, nodeptr v);

  //DEBUG
  void preOrderHelper(nodeptr node);
  void inOrderHelper(nodeptr node);
  void postOrderHelper(nodeptr node);
  void print(void);
  void printHelper(nodeptr node, std::string indent, bool last);
	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
  void preorder(void) { preOrderHelper(this->root); std::cout << '\n'; }
  // In-Order traversal
  // Left Subtree -> Node -> Right Subtree
  void inorder() { inOrderHelper(this->root); std::cout << '\n'; }
  // Post-Order traversal
  // Left Subtree -> Right Subtree -> Node
  void postorder() { postOrderHelper(this->root); std::cout << '\n'; }


};

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare,
          typename Alloc >
typename ft::rbtree<Key, Val, KeyOfValue, Compare, Alloc>::nodeptr
 ft::rbtree<Key, Val, KeyOfValue, Compare, Alloc>::SENT
= reinterpret_cast<Node<Val>*>(&ft::SENTRY);


} //namespace ft

#include "rbtree_insert.tpp"
#include "rbtree_delete.tpp"
#include "rbtree_static.tpp"
#include "rbtree_rotation.tpp"
#include "rbtree_trasversal.tpp"

#endif

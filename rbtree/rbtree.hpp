//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef RB_TREE
# define RB_TREE

#include <string>
#include <memory>
#include <functional>
#include "iterator_tree.hpp"

namespace ft {

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Val> >
class rbtree {
public:
  typedef Node<Val>*                                      nodeptr;
  typedef Node<Val>                                       node_type;
  typedef Val                                             value_type;
  typedef value_type*                                     pointer;
  typedef value_type const*                               const_pointer;
  typedef rbtree<Key, Val, KeyOfValue, Compare, Alloc>    tree_type;
  typedef tree_iterator<pointer, tree_type>               iterator;
  typedef tree_iterator<const_pointer, tree_type>         const_iterator;
  typedef tree_rev_iterator<pointer, tree_type>           rev_iterator;
  typedef tree_rev_iterator<const_pointer, tree_type>     const_rev_iterator;
  typedef typename Alloc::template rebind<Node<Val> >::other Node_allocator;

protected:
  nodeptr        root;
  Alloc          _alloc;
  Node_allocator _nodealloc;

public:
  static nodeptr SENT;
  rbtree(void)  { root = SENT; }
  rbtree(rbtree const& src) { *this = src; }
  ~rbtree(void) { recurse_delete(root); }
  rbtree& operator=(rbtree const& src);

  static nodeptr sucessor(nodeptr x);
  static nodeptr predecessor(nodeptr x);
  static nodeptr minimum(nodeptr node);
  static nodeptr maximum(nodeptr node);
  static nodeptr relative_root(nodeptr node);
  nodeptr getroot(void) { return root; }

  void insert(Val value);
  void delete_node(Key key);

  iterator       begin(void)        { return iterator(minimum(root)); }
  const_iterator begin(void) const  { return const_iterator(minimum(root)); }
  iterator       end(void)          { return iterator(SENT); }
  const_iterator end(void) const    { return const_iterator(SENT); }
  rev_iterator   rbegin(void)       { return rev_iterator(maximum(root)); }
  rev_iterator   rend(void)         { return rev_iterator(SENT); }
  const_rev_iterator rbegin(void) const { return rev_iterator(maximum(root)); }
  const_rev_iterator rend(void)   const { return rev_iterator(SENT); }

  //DEBUG
  void print(void);
  // Node         -> Left Subtree -> Right Subtree
  void preorder(void) { preOrderHelper(this->root); std::cout << '\n'; }
  // Left Subtree -> Node         -> Right Subtree
  void inorder() { inOrderHelper(this->root); std::cout << '\n'; }
  // Left Subtree -> Right Subtree -> Node
  void postorder() { postOrderHelper(this->root); std::cout << '\n'; }

private:
  void    recurse_delete(nodeptr node);
  nodeptr init_node(Val value);
  nodeptr searchHelper(nodeptr node, Key key);
  nodeptr search(Key key) { return searchHelper(root, key); }

  void left_rotate(nodeptr node);
  void right_rotate(nodeptr node);
  void fix_insert(nodeptr node);
  void fix_delete(nodeptr x);
  void transplant_tree(nodeptr u, nodeptr v);

  void preOrderHelper(nodeptr node);
  void inOrderHelper(nodeptr node);
  void postOrderHelper(nodeptr node);
  void printHelper(nodeptr node, std::string indent, bool last);
};

} //namespace ft

#include "rbtree_insert.tpp"
#include "rbtree_delete.tpp"
#include "rbtree_static.tpp"
#include "rbtree_rotation.tpp"
#include "rbtree_trasversal.tpp"
#include "rbtree_constructors.tpp"

#endif

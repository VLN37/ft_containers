//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef RB_TREE
# define RB_TREE

#include <string>
#include <memory>
#include <functional>

namespace ft {
enum e_color { BLACK, RED };

// struct tree_base {
//   typedef tree_base*        base_ptr;
//   typedef const tree_base*  const_base_ptr;
// };

// template<typename val>
// struct tree_node : public tree_base {
//   typedef tree_node<val>* node_type;
// };

template <typename T>
struct Node {
  Node(void) : parent(NULL), left(NULL), right(NULL), color(RED) { }
  typedef Node* nodeptr;
  T       data;
  Node*   parent;
  Node*   left;
  Node*   right;
  e_color color;
  friend std::ostream operator<<(std::ostream const& o, Node const& rhs)
  { return o << rhs.data.first; }
};


template <typename T>
struct KeyOfValue {
  int operator()(T const& src) const {
    return (src.first);
  }
};

// template <typename T>
// static Node<T> SENTRY = Node<T>();

template <typename Key,
          typename Val,
          typename KeyOfValue,
          typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Val> >
class rbtree {
public:
  typedef Node<Val>*                                         nodeptr;
  typedef Node<Val>                                          node_type;
  typedef typename Alloc::template rebind<Node<Val> >::other Node_allocator;

  nodeptr        root;
  nodeptr        SENT;
  Alloc          _alloc;
  Node_allocator _nodealloc;

  rbtree(void): SENT(_nodealloc.allocate(1)) {
    _nodealloc.construct(SENT, Node<Val>());
    SENT->right = SENT;
    SENT->left = SENT;
    SENT->parent = NULL;
    SENT->color = BLACK;
    root = SENT;
  }

  ~rbtree(void) {
    recurse_delete(root);
    _nodealloc.destroy(SENT);
    _nodealloc.deallocate(SENT, 1);
  }

  nodeptr get_root(void) {
    return root;
  }

  void recurse_delete(nodeptr node) {
    if (node != SENT) {
      recurse_delete(node->left);
      recurse_delete(node->right);
      _nodealloc.destroy(node);
      _nodealloc.deallocate(node, 1);
    }
  }

  nodeptr searchHelper(nodeptr node, Key key) {
    if (node == SENT || (!Compare()(KeyOfValue()(node->data), key)
                     &&  !Compare()(key, KeyOfValue()(node->data))))
      return node;
    if (Compare()(key, KeyOfValue()(node->data)))
      return searchHelper(node->left, key);
    else
      return searchHelper(node->right, key);
  }

  nodeptr search(Key key) { // chave
    return searchHelper(root, key);
  }

  nodeptr minimum(nodeptr node) {
    if (node == SENT)
      return node;
    while (node->left != SENT)
      node = node->left;
    return node;
  }

  nodeptr maximum(nodeptr node) {
    if (node == SENT)
      return node;
    while (node->right != SENT)
      node = node->right;
    return node;
  }

  nodeptr init_node(Val value) { // val
    nodeptr node = _nodealloc.allocate(1);
    _nodealloc.construct(node, Node<Val>());
    node->parent = NULL;
    node->data = value;
    node->right = SENT;
    node->left = SENT;
    node->color = RED;
    return node;
  }

  void left_rotate(nodeptr node) {
    nodeptr tmp = node->right;
    node->right = tmp->left;
    if (tmp->left != SENT) {
      tmp->left->parent = node;
    }
    tmp->parent = node->parent;
    if (node->parent == NULL)
      root = tmp;
    else if (node == node->parent->left)
      node->parent->left = tmp;
    else
      node->parent->right = tmp;
    tmp->left  = node;
    node->parent = tmp;
  }

  void right_rotate(nodeptr node) {
    nodeptr tmp = node->left;
    node->left = tmp->right;
    if (tmp->right != SENT)
      tmp->right->parent = node;
    tmp->parent = node->parent;
    if (node->parent == NULL)
      this->root = tmp;
    else if (node == node->parent->right)
      node->parent->right = tmp;
    else
      node->parent->left = tmp;
    tmp->right = node;
    node->parent = tmp;
  }

  /**
   * cases:
   * 1 - tree is empty - newnode is black
   * 2 - tree is not empty - newnode is red
   * 3 - parent of newnode is black - exit
   */
  void insert(Val value) { // val
    nodeptr node = init_node(value);
    nodeptr prev = NULL;
    nodeptr curr = root;

    while (curr != SENT) {
      prev = curr;
      if (Compare()(KeyOfValue()(node->data), KeyOfValue()(curr->data)))
        curr = curr->left;
      else
        curr = curr->right;
    }
    node->parent = prev;
    if (prev == NULL)
      root = node;
    else if (Compare()(KeyOfValue()(node->data), KeyOfValue()(prev->data)))
      prev->left = node;
    else
      prev->right = node;

    //case 1
    if (node->parent == NULL) {
      node->color = BLACK;
      return;
    }
    //determine if this is the second node
    if (node->parent->parent == NULL)
      return;
    fix_insert(node);
  }

  /**
   * 4 - rebalance if parent's brother is red (parent->parent->left/right)
   * 5 - decide rotation rules
   * 5.1 - LEFT rotate
   * 5.2 - RIGHT LEFT rotate
   * 5.3 - RIGHT rotate
   * 5.4 - LEFT RIGHT rotate
   */
  void fix_insert(nodeptr node) {
    nodeptr uncle;
    while (node->parent->color == RED) {
      if (node->parent == node->parent->parent->right) {
        uncle = node->parent->parent->left;
        if (uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        }
        else {
          if (node == node->parent->left) {
            node = node->parent;
            right_rotate(node);                               // 5.2
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          left_rotate(node->parent->parent);                  // 5.1 or 5.2
        }
      }
      else {
        uncle = node->parent->parent->right;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;
        }
        else {
          if (node == node->parent->right) {
            node = node->parent;
            left_rotate(node);                               // 5.4
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          right_rotate(node->parent->parent);                // 5.3 or 5.4
        }
      }
    if (node == root)
      break;
    }
  root->color = BLACK;
  }

  void transplant_tree(nodeptr u, nodeptr v) {
    if (u->parent == NULL)
      root = v;
    else if (u == u->parent->left)
      u->parent->left = v;
    else
      u->parent->right = v;
    v->parent = u->parent; //lose reference of children?
  }

  void delete_node(Key key) { // val
    nodeptr z = SENT;
    nodeptr x, y;
    e_color y_backup;

    z = search(key);
    if (z == SENT) //key not found
      return;

    y = z;
    y_backup = y->color;
    if (z->left == SENT) {
      x = z->right; // x = tmp?
      transplant_tree(z, z->right);
    }
    else if (z->right == SENT) {
      x = z->left;
      transplant_tree(z, z->left);
    }
    else {
      y = minimum(z->right);
      y_backup = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      }
      else {
        transplant_tree(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      transplant_tree(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    _nodealloc.destroy(z);
    _nodealloc.deallocate(z, 1);
    if (y_backup == BLACK) {
      fix_delete(x);
    }
  }

  //s == sibling - x == deleted node
  void fix_delete(nodeptr x) {
    nodeptr s;

    while (x != root && x->color == BLACK) {
      if (x == x->parent->left) {
        s = x->parent->right;
        //sibling of deleted node is red
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          left_rotate(x->parent);
          s = x->parent->right;
        }
        //sibling and children are black
        if (s->left->color == BLACK && s->right->color == BLACK) {
          s->color = RED;
          x = x->parent;
        }
        else {
          if (s->right->color == BLACK) {
            s->left->color = BLACK;
            s->color = RED;
            right_rotate(s);
            s = x->parent->right;
          }
          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->right->color = BLACK;
          left_rotate(x->parent);
          x = root;
        }
      }
      else {
        s = x->parent->left;
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          right_rotate(x->parent);
          s = x->parent->left;
        }
        if (s->right->color == BLACK && s->left->color == BLACK) { //investigate
          s->color = RED;
          x = x->parent;
        }
        else {
          if (s->left->color == BLACK) {
            s->right->color = BLACK;
            s->color = RED;
            left_rotate(s);
            s = x->parent->left;
          }
          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->left->color = BLACK;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = BLACK;
  }

  //DEBUG
  void preOrderHelper(nodeptr node) {
    if (node != SENT) {
      std::cout << node->data << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  void inOrderHelper(nodeptr node) {
    if (node != SENT) {
      inOrderHelper(node->left);
      std::cout << node->data << " ";
      inOrderHelper(node->right);
    }
  }

  void postOrderHelper(nodeptr node) {
    if (node != SENT) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      std::cout << node->data << " ";
    }
  }

	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
  void preorder() {
    preOrderHelper(this->root);
    std::cout << '\n';
  }

  // In-Order traversal
  // Left Subtree -> Node -> Right Subtree
  void inorder() {
    inOrderHelper(this->root);
    std::cout << '\n';
  }

  // Post-Order traversal
  // Left Subtree -> Right Subtree -> Node
  void postorder() {
    postOrderHelper(this->root);
    std::cout << '\n';
  }

  void print(void) {
    std::cout << "***************************\n";
    if (root) {
      printHelper(this->root, "", true);
    }
    std::cout << "***************************\n";
  }

  void printHelper(nodeptr node, std::string indent, bool last) {
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
};

} //namespace ft

#endif

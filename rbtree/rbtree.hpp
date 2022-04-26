//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef RB_TREE
# define RB_TREE

#include<string>

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

struct Node {
  int     data;
  Node*   parent;
  Node*   left;
  Node*   right;
  e_color color;
};

typedef Node* nodeptr;

class rbtree {
private:
  nodeptr root;
  nodeptr SENT;

  nodeptr init_node(int value) {
    nodeptr node = new Node;
    node->parent = NULL;
    node->right = SENT;
    node->left = SENT;
    node->color = RED;
    node->data = value;
    return node;
  }

public:
  rbtree(void): SENT(new Node) {
    SENT->color = BLACK;
    SENT->left = NULL;
    SENT->right = NULL;
    root = SENT;
  }

  void insert(int value) {
    nodeptr node = init_node(value);
    nodeptr prev = NULL;
    nodeptr curr = root;

    curr = root;
    while (curr != SENT) {
      prev = curr;
      if (node->data < curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }

    //determine node pointers
    curr->parent = prev;
    if (prev == NULL)
      root = node;
    else if (node->data < prev->data)
      prev->left = node;
    else
      prev->right = node;

    if (node->parent == NULL) {
      node->color = BLACK;
      return;
    }

    if (node->parent->parent == NULL)
      return;
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
      if (root) {
        printHelper(this->root, "", true);
      }
  }

  void printHelper(nodeptr root, std::string indent, bool last) {
    // print the tree structure on the screen
      if (root != SENT) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "     ";
      } else {
        std::cout << "L----";
        indent += "|    ";
      }

      std::string sColor = root->color ? "RED" : "BLACK";
      std::cout << root->data << "(" << sColor << ")\n";
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }
};

} //namespace ft

#endif

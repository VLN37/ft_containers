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

  ~rbtree(void) {
    recurse_delete(root);
    delete SENT;
  }

  void recurse_delete(nodeptr node) {
    if (node != SENT) {
      recurse_delete(node->left);
      recurse_delete(node->right);
      delete node;
    }
  }
  /**
   * cases:
   * 1 - tree is empty - newnode is black
   * 2 - tree is not empty - newnode is red
   * 3 - parent of newnode is black - exit
   */
  void insert(int value) {
    nodeptr node = init_node(value);
    nodeptr prev = NULL;
    nodeptr curr = root;

    while (curr != SENT) {
      prev = curr;
      if (node->data < curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }
    curr->parent = prev;
    if (prev == NULL)
      root = node;
    else if (node->data < prev->data)
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
      if (node->parent == node->parent->parent->right) {    // 5.1 and/or 5.2
        uncle = node->parent->parent->left;
        if (uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = BLACK;
          node = node->parent->parent;
        }
        else {
          if (node == node->parent->left) {                 // 5.2
            node = node->parent;
            //to do right rotate right_rotate(node);
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          //to do left rotate left_rotate(node->parent->parent );
        }
    }
      else {                                                // 5.3 and/or 5.4
        uncle = node->parent->parent->right;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            node->parent->color = BLACK;
            node->parent->parent->color = BLACK;
            node = node->parent->parent;
        }
        else {
          if (node == node->parent->right) {
            node = node->parent;
            //to do left rotate left_rotate(node);              // 5.4
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          //to do right rotate right_rotate(node);
        }
    }
    if (node == root)
      break;
  }
  root->color = BLACK;
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
        std::cout << "R---- ";
        indent += "     ";
      } else {
        std::cout << "L---- ";
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

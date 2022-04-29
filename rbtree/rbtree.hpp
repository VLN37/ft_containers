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
  nodeptr SENT;


public:
  nodeptr root;
  rbtree(void): SENT(new Node) {
    SENT->color = BLACK;
    SENT->parent = NULL;
    SENT->left = NULL;
    SENT->right = NULL;
    root = SENT;
  }

  ~rbtree(void) {
    recurse_delete(root);
    delete SENT;
  }

  nodeptr get_root(void) {
    return root;
  }

  void recurse_delete(nodeptr node) {
    if (node != SENT) {
      recurse_delete(node->left);
      recurse_delete(node->right);
      delete node;
    }
  }

  nodeptr init_node(int value) {
    nodeptr node = new Node;
    node->parent = NULL;
    node->data = value;
    node->right = SENT;
    node->left = SENT;
    node->color = RED;
    return node;
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
    node->parent = prev;
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
    std::cout << "here\n";
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
    if (node->parent == node->parent->parent->right)
          std::cout << "one\n";
    if (node->parent == node->parent->parent->left)
          std::cout << "two\n";
    while (node->parent->color == RED) {
      if (node->parent == node->parent->parent->right) {
        uncle = node->parent->parent->left;
        if (uncle->color == RED) {
          std::cout << "three\n";
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
    root = tmp;
  else if (node == node->parent->right)
    node->parent->right = tmp;
  else
    node->parent->left = tmp;
  tmp->right = node;
  node->parent = tmp;
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

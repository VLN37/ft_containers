//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 11/05/2022

#ifndef RBTREE_UTILS_HPP
# define RBTREE_UTILS_HPP

#include "rbtree.hpp"

namespace ft {

template <TREE_TEMPLATE>
void TREE_TYPE::swap(tree_type& src) {
  nodeptr tmp = root;
  root = src.getroot();
  src.setroot(tmp);
}

} // namespace ft
#endif // RBTREE_UTILS_HPP

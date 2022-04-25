//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef RB_TREE
# define RB_TREE

namespace ft {
enum e_color { BLACK, RED };

struct tree_base {
  typedef tree_base*        base_ptr;
  typedef const tree_base*  const_base_ptr;
};

template<typename val>
struct tree_node : public tree_base {
  typedef tree_node<val>* node_type;
};

} //namespace ft

#endif

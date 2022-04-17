//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 16/04/2022

#ifndef ALGO_HPP
# define ALGO_HPP

namespace ft {

template<typename It1, typename It2>
bool equal(It1 first1, It1 last1, It2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (*first1 != *first2)
      return false;
  }
  return true;
}

template<typename It1, typename It2, typename BinPred>
bool equal(It1 first1, It1 last1, It2 first2, BinPred compare) {
  for (; first1 != last1; ++first1, ++first2) {
    if (compare(*first1, *first2) == false)
      return false;
  }
  return true;
}

template<typename It1, typename It2>
bool lexicographical_compare(It1 first1, It1 last1,
                             It2 first2, It2 last2) {
  for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
    if (*first1 < *first2)
      return true;
    if (*first2 < *first1)
      return false;
  }
  return (first1 == last1) && (first2 != last2);
}

template<typename It1, typename It2, typename BinPred>
bool lexicographical_compare(It1 first1, It1 last1,
                             It2 first2, It2 last2, BinPred compare) {
  for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
    if (compare(*first1, *first2))
      return true;
    if (compare(*first2, *first1))
      return false;
  }
  return (first1 == last1) && (first2 != last2);
}

} // namespace ft

#endif

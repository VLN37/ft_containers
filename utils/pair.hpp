//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 23/04/2022

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
template<typename T1, typename T2>
class pair {
private:
  typedef T1 type_1;
  typedef T2 type_2;

public:
  pair(void): first(T1()), second(T2()) { }
  template<typename _T1, typename _T2>
  pair(pair const& src): first(src.first), second(src.second) { }
  pair(type_1 _first, type_2 _second): first(_first), second(_second) { }

  pair& operator=(pair const& rhs) {
    this->first = rhs.first;
    this->second = rhs.second;
    return *this;
  }

  type_1 first;
  type_2 second;
};

template<typename T1, typename T2>
bool operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs == rhs; }

template<typename T1, typename T2>
bool operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs != rhs; }

template<typename T1, typename T2>
bool operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs <= rhs; }

template<typename T1, typename T2>
bool operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs >= rhs; }

template<typename T1, typename T2>
bool operator>(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs > rhs; }

template<typename T1, typename T2>
bool operator<(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
{ return lhs < rhs; }

} // namespace ft
#endif // PAIR_HPP

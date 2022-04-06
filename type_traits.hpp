// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 06/04/2022
// Last modified: 06/04/2022

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {

// template metaprogramming to create a type only if the following is true
template<bool b, typename T = void>
	struct enable_if { };

template<typename T>
	struct enable_if<true, T> { typedef T type; };

//std compliant helper class for is_integral check
//source: https://en.cppreference.com/w/cpp/types/integral_constant
template <typename T, T v>
struct integral_constant {
	typedef T	value_type;

	static const T value = v;
	operator value_type() const { return value; }
	// constexpr value_type operator()() const noexcept { return value; }
};

//enters here if none of the specializations fit
template<typename T>
struct is_integral
: public integral_constant<bool, false> { };

template<>
struct is_integral<bool>
: public integral_constant<bool, true> { };

template<>
struct is_integral<char>
: public integral_constant<bool, true> { };

template<>
struct is_integral<wchar_t>
: public integral_constant<bool, true> { };

template<>
struct is_integral<signed char>
: public integral_constant<bool, true> { };

template<>
struct is_integral<unsigned char>
: public integral_constant<bool, true> { };

template<>
struct is_integral<short int>
: public integral_constant<bool, true> { };

template<>
struct is_integral<int>
: public integral_constant<bool, true> { };

template<>
struct is_integral<long int>
: public integral_constant<bool, true> { };

// template<>
// struct is_integral<long long int>
// : public integral_constant<bool, true> { };

template<>
struct is_integral<unsigned short int>
: public integral_constant<bool, true> { };

template<>
struct is_integral<unsigned int>
: public integral_constant<bool, true> { };

template<>
struct is_integral<unsigned long int>
: public integral_constant<bool, true> { };

// template<>
// struct is_integral<unsigned long long int>
// : public integral_constant<bool, true> { };

} // namespace ft

#endif

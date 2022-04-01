// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include <vector>
#include "vector.hpp"

int main(void) {
	std::cout << "this compiles!\n";
	ft::vector<int> vec1;
	ft::vector<int> vec2(5, 42);

	int *ptr = vec1.test(50);

	*ptr = 10;
	ptr[1] = 20;
	ptr[2] = 30;
	std::cout << *ptr << '\n';
	std::cout << *(ptr + 1) << '\n';
	std::cout << ptr[2] << '\n';

	vec1 = vec2;
	delete ptr;
	return (0);
}

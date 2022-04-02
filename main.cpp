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

	std::vector<int> vec3;
	ft::vector<int> vec4;

	vec1 = vec2;
	//test resize
	vec3.resize(15, 42);
	vec4.resize(15, 42);

	std::cout << vec3.size() << " size \n";
	std::cout << vec4.size() << " size \n";
	std::cout << vec3.capacity() << " capacity \n";
	std::cout << vec4.capacity() << " capacity \n";
	std::cout << '\n';

	vec3.resize(5, 42);
	vec4.resize(5, 42);

	std::cout << vec3.size() << " size \n";
	std::cout << vec4.size() << " size \n";
	std::cout << vec3.capacity() << " capacity \n";
	std::cout << vec4.capacity() << " capacity \n";
	std::cout << '\n';

	vec3.resize(15, 0);
	vec4.resize(15, 0);

	std::cout << vec3.size() << " size \n";
	std::cout << vec4.size() << " size \n";
	std::cout << vec3.capacity() << " capacity \n";
	std::cout << vec4.capacity() << " capacity \n";
	std::cout << '\n';

	std::cout << vec3[2] << '\n';
	vec3[2] = 21;
	std::cout << vec3[2] << '\n';

	//test resize


	delete ptr;
	return (0);
}

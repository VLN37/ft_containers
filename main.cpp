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

	std::vector<int> stdvec;
	ft::vector<int> ftvec;

	vec1 = vec2;
	//test resize
	stdvec.resize(15, 42);
	ftvec.resize(15, 42);

	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';

	stdvec.resize(5, 42);
	ftvec.resize(5, 42);

	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';

	stdvec.resize(15, 0);
	ftvec.resize(15, 0);

	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';

	std::cout << ftvec[2] << '\n';
	ftvec[2] = 21;
	std::cout << ftvec[2] << '\n';

	//test resize

	std::cout << stdvec.back() << " back\n";
	// std::cout << ftvec.back() << " back\n";
	std::cout << stdvec.front() << " front\n";
	// std::cout << ftvec.front() << " front\n";


	delete ptr;
	return (0);
}

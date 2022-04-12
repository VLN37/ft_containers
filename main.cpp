// Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
// Creation date: 31/03/2022
// Last modified: 31/03/2022

#include <vector>
#include <typeinfo>
#include "vector.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"


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
	//test resize

	//test element access
	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';

	std::cout << "push_back()\n\n";
	stdvec[14] = 42;
	ftvec[14] = 42;
	stdvec.push_back(66);
	ftvec.push_back(66);
	std::cout << stdvec.back() << " stdvec back\n";
	std::cout << ftvec.back() << " ftvec back\n";

	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';

	std::cout << "pop_back()\n\n";
	stdvec.pop_back();
	ftvec.pop_back();
	std::cout << stdvec.back() << " stdvec back\n";
	std::cout << ftvec.back() << " ftvec back\n";

	std::cout << stdvec.size() << " size \n";
	std::cout << ftvec.size() << " size \n";
	std::cout << stdvec.capacity() << " capacity \n";
	std::cout << ftvec.capacity() << " capacity \n";
	std::cout << '\n';



	std::cout << "[] operator\n\n";
	std::cout << ftvec[2] << " ftvec pos 2\n";
	ftvec[2] = 21;
	std::cout << ftvec[2] << " ftvec pos 2\n";
	ftvec[2] = 42;
	std::cout << ftvec.at(2) << " ftvec pos 2\n";
	ftvec[2] = 21;
	std::cout << ftvec.at(2) << " ftvec pos 2\n";
	ftvec[2] = 42;
	try {
		std::cout << ftvec.at(42) << " ftvec pos 2\n";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << '\n';


	std::cout << "back() / front()\n\n";
	std::cout << stdvec.back() << " stdvec back\n";
	std::cout << ftvec.back() << " ftvec back\n";
	std::cout << stdvec.front() << " stdvec front\n";
	std::cout << ftvec.front() << " ftvec front\n";
	std::cout << '\n';
	//test element access
	stdvec.clear();
	ftvec.clear();
{
	ft::iterator<std::input_iterator_tag, int> it1;
	ft::iterator<std::output_iterator_tag, int*> it2;
	ft::iterator<std::random_access_iterator_tag, float> it3;
	ft::iterator<std::random_access_iterator_tag, ft::vector<int> > it4;

	ft::vector<int>::iterator ftit1;
	std::vector<int>::iterator stdit1;


	std::cout << ft::vector<int>::iterator::difference_type() << "here\n";
	// std::cout << ft::vector<int>::iterator::iterator_category() << "here\n";
	// std::cout << ft::vector<int>::iterator::pointer() << "here\n";
	// std::cout << ft::vector<int>::iterator::reference() << "here\n";


	//functions not part of cpp98 - not possible to test the std version
	std::cout << ft::is_integral<int>::value << " is integral <int>\n";
	std::cout << ft::integral_constant<int, 10>::value << '\n';

	(void)ftit1;
	(void)stdit1;
	std::cout << typeid(it1).name() << '\n';
	std::cout << typeid(it2).name() << '\n';
	std::cout << typeid(it3).name() << "\n";
	std::cout << typeid(it4).name() << "\n\n";
}

//testing iterator member overloads
{
	ft::vector<int>::iterator ftit1;
	ft::vector<int>::iterator ftit2(ftit1);

	ftit2 = ftit1;
	std::cout << ftvec[0] << '\n';
	ftit2 = ftvec.begin();
	*ftit2 = 21;
	std::cout << ftvec[0] << '\n';
	ftit2++;
	std::cout << *ftit2 << '\n';
	++ftit2;
	std::cout << *ftit2 << '\n';
	std::cout << (ftit2 == ftit1 ? "true\n" : "false\n");
	ftit2 = ftit1;
	std::cout << (ftit2 == ftit1 ? "true\n" : "false\n");
	std::cout << (ftit2 >= ftit1 ? "true\n" : "false\n");
	std::cout << (ftit2 <= ftit1 ? "true\n" : "false\n");
	std::cout << (ftit2 < ftit1 ? "true\n" : "false\n");
	std::cout << (ftit2 > ftit1 ? "true\n" : "false\n");
	ftit1 = ftvec.begin();
	ftit1 += 2;
	ftvec[0] = 42;
	ftvec[4] = 21;
	std::cout << (*ftit1) << '\n';
	std::cout << (*(ftit1 + 2)) << '\n';
	std::cout << (*(ftit1 - 2)) << '\n';
	std::cout << (ftit1[2]) << '\n';
	ftit2 = 2 + ftit1 + 2;
}
//testing iterator member overloads

//testing iterator non member overloads
{
	ft::vector<int> ftvec2;
	for (int i = 0; i < 50; i++) {
		ftvec2.push_back(i);
	}
	std::vector<int> stdvec2;
	for (int i = 0; i < 50; i++) {
		stdvec2.push_back(i);
	}
	ft::vector<int>::iterator ftit3(ftvec2.begin());
	ft::vector<int>::const_iterator ftit4(ftvec2.begin());
	ft::vector<int>::const_iterator ftit5(ftit3);
	//teste maroto
	// ft::vector<int>::iterator ftit5(ftit4);

	std::vector<int>::iterator stdit3(stdvec2.begin());
	std::vector<int>::const_iterator stdit4(stdvec2.begin());


	stdit3 = stdvec2.begin();
	stdit4 = stdvec2.begin();

	ftit3 = ftvec2.begin();
	ftit4 = ftvec2.begin();

	ftit3 == ftit4 ? std::cout << "true\n" : std::cout << "false\n";
	ftit3 != ftit4 ? std::cout << "true\n" : std::cout << "false\n";
	ftit3 >= ftit4 ? std::cout << "true\n" : std::cout << "false\n";
	ftit3 <= ftit4 ? std::cout << "true\n" : std::cout << "false\n";
	ftit3 > ftit4 ? std::cout << "true\n" : std::cout << "false\n";
	ftit3 < ftit4 ? std::cout << "true\n" : std::cout << "false\n";
}
//testing iterator non member overloads

//testing reverse iterator member overloads
{
	ft::vector<int>ftvec3;
	for (int i = 0; i < 50; i++)
		ftvec3.push_back(i);
	ft::vector<int>::reverse_iterator revit1;
	ft::vector<int>::reverse_iterator revit2(revit1);
	revit1 = revit2;
	revit1 = ftvec3.rbegin();
	revit2 = ftvec3.rend();
	revit1 == revit2 ? std::cout << "true\n" : std::cout << "false\n";
	revit1 != revit2 ? std::cout << "true\n" : std::cout << "false\n";
	revit1 >= revit2 ? std::cout << "true\n" : std::cout << "false\n";
	revit1 <= revit2 ? std::cout << "true\n" : std::cout << "false\n";
	revit1 > revit2 ? std::cout << "true\n" : std::cout << "false\n";
	revit1 < revit2 ? std::cout << "true\n" : std::cout << "false\n";
}
//testing reverse iterator member overloads

//test member functions
{
	ft::vector<int>ftvec3;
	for (int i = 0; i < 50; i++)
		ftvec3.push_back(i);
	ft::vector<int>::iterator ftit3 = ftvec3.begin();
	std::cout << *ftit3 << "\n";
	ftit3 += 5;
	std::cout << *ftit3 << "\n";
	ftit3 = ftvec3.end() - 1;
	std::cout << *ftit3 << "\n";
	ftvec3.erase(ftit3);
	if (ftit3 == ftvec3.end())
		std::cout << "correct erase\n";
}

{
	ft::vector<int>ftvec3;
	for (int i = 0; i < 11; i++)
		ftvec3.push_back(i);
	ft::vector<int>ftvec4(ftvec3);
	std::cout << ftvec3;
	ft::vector<int>::iterator ftit2 = ftvec3.begin();
	ftvec3.erase(ftit2 + 5);
	std::cout << ftvec3;
	ftvec3.erase(ftit2 + 9);
	std::cout << ftvec3;
	ftvec3.erase(ftvec3.begin() + 3, ftvec3.end());
	std::cout << ftvec3;
	ftvec3.clear();
	std::cout << ftvec3;
	ftvec3.clear();
	std::cout << ftvec3;
	ftvec3.swap(ftvec4);
	std::cout << ftvec3;
	ftvec3.insert(ftvec3.begin() + 5, 42);
	std::cout << ftvec3;
	ftvec3.insert(ftvec3.begin() + 1, 5, 21);
	std::cout << ftvec3;
	ftvec3.insert(ftvec3.end(), 5, 42);
	std::cout << ftvec3;
	ftvec3.insert(ftvec3.begin(), 5, 13);
	std::cout << ftvec3;
	ftvec3.assign(3, 42);
	std::cout << ftvec3;
	ft::vector<int>ftvec5(ftvec3.begin(), ftvec3.end());
	std::cout << ftvec3;
	std::cout << ftvec5;
	ft::vector<int>ftvec6(10, 42);
	std::cout << ftvec6;
	ftvec5.clear();
	std::cout << ftvec5;
	ftvec5.assign(ftvec6.begin(), ftvec6.end());
	std::cout << ftvec5;
	ftvec5.clear();
	std::cout << ftvec5;
	ftvec5.assign(10, 21);
	std::cout << ftvec5;
	ftvec5.clear();
	std::cout << ftvec5;

}

	delete ptr;
	return (0);
}

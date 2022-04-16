//Copyright (c) 2022 João Rodriguez A.K.A. VLN37. All rights reserved.
//Creation date: 30/03/2022

#include <vector>
#include <iostream>


int main(void) {
  std::vector<int> vec{1, 2, 3};

  std::cout << "vec max size        : " << vec.max_size() << "\n";
  std::cout << "vec size            : " << vec.size() << "\n";
  std::cout << "vec capacity        : " << vec.capacity() << "\n";

  vec.resize(50);
  std::cout << "vec resize size     : " << vec.size() << "\n";
  std::cout << "vec resize capacity : " << vec.capacity() << "\n";

  vec.reserve(100);
  std::cout << std::endl;
  std::cout << "vec reserve size    : " << vec.size() << "\n";
  std::cout << "vec reserve capacity: " << vec.capacity() << "\n";

  std::cout << "vec.back            : " << vec.back() << "\n";
  std::cout << "vec.lastindex       : " << vec[2] << "\n";

  std::cout << "vec.back            : " << vec.back() << "\n";
  std::cout << "vec.lastindex       : " << vec[15] << "\n";
  std::cout << std::endl;


  vec.resize(15);
  std::cout << std::endl;
  std::cout << "vec shrink size     : " << vec.size() << "\n";
  std::cout << "vec shrink capacity : " << vec.capacity() << "\n";

  std::cout << "vec.back            : " << vec.back() << "\n";
  std::cout << "vec.lastindex       : " << vec[2] << "\n";
  vec.push_back(42);

  std::cout << "vec.back            : " << vec.back() << "\n";
  std::cout << "vec.lastindex       : " << vec[15] << "\n";
  std::cout << std::endl;
}

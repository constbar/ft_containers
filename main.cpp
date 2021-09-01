#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "ranit.hpp"
#include "iter.hpp"


int main() {
	diy::vector<int> lol; // try other type
	diy::vector<int> vec;
	diy::vector<int>::iterator it = vec.begin();
	diy::vector<int>::iterator en = vec.end();
	// vec.clear();
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	// vec.resize(23);
	vec.swap(lol);
	std::cout << lol.back()<< std::endl;
	// std::cout << lol.at(1) << std::endl;
	// std::cout << lol.size() << std::endl;
	// std::cout << lol.capacity() << std::endl;

	// std::vector<int> orig;
	// orig.push_back(111);
	// orig.resize(5);
	// std::cout << orig.size() << std::endl;
	// std::cout << orig.capacity() << std::endl;
	// // std::cout << orig[4] << std::endl;

#if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	// kek.at(200);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
#endif

	return 0;
}

#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "ranit.hpp"
#include "iter.hpp"

#include <iostream> // std::cout
#include <iterator> // std::iterator_traits
#include <typeinfo> // typeid

int main() {

	// std::vector<int>::size_type al;
	// diy::vector<int>::size_type it;
	// std::cout << al << std::endl;

	diy::vector<int> vec;
	diy::vector<int>::iterator it;
	diy::vector<int>::iterator en;
	// vec.reserve(30);
	// vec.realloc(30);
	// std::cout << "emp " << std::boolalpha << vec.empty() << std::endl;
	vec.push_back(10);
	vec.push_back(11);
	// vec.push_back(12);
	// vec.push_back(13);
	// vec.push_back(14);
	// std::cout << "empt " << std::boolalpha << vec.empty() << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;
	// std::cout << "max size " << vec.max_size() << std::endl;
	// std::cout << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	
	std::cout << std::endl;
	it = vec.begin();
	en = vec.end();
	for (; it != en; it++)
		std::cout << *it << std::endl;

	// std::cout << vec.size << std::endl;
	// std::cout << vec.capacity << std::endl;

	// it = vec.end();
	// std::cout << *it << std::endl;
	// it--;
	// std::cout << *it << std::endl;

#if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
#endif

	return 0;
}

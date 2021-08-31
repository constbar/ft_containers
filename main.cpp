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

	diy::vector<int> vec(20);
	// diy::vector<int>::iterator it;
	
	// it = vec.begin();
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;

	return 0;
}

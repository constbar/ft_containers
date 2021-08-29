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

int main()
{
#if 0
	diy::ranit<int>::pointer i;
	std::cout << typeid(i).name() << std::endl;
	int k = 20;
	int q = 40;
	diy::ranit<int> ii(&k);
	ii = &k;
	std::cout << ii.operator*() << std::endl;
	std::cout << ii.operator->() << std::endl;
	ii.operator++();
	std::cout << ii.operator*() << std::endl;
	++ii;
	ii++;
	// std::cout << ii.operator->() << std::endl;
#endif

	diy::vector<int>::iterator kek;


	return 0;
}



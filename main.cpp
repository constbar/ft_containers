#include <iostream>
#include <vector>

#include "vec.hpp"
#include "itr.hpp"

int main() {

	// // this is vector 
	// std::vector<int> kek;
	// kek.push_back(1);
	// std::vector<int>::iterator it;
	// it = kek.begin();

	int i = 122;
	int *pint = &i;
	my::iter<int> p(pint);
	// p = &i;
	// *p = 11;
	// std::cout << i << std::endl;
	std::cout << *p << std::endl;





#if 0
#endif
	return 0;
}
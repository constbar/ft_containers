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


// #if 0
	diy::vector<int> vec;
	// diy::vector<int>::iterator en = vec.end();
	// vec.clear();
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);
	diy::vector<int>::iterator it;
	diy::vector<int>::const_iterator cit;
	it = vec.begin();
	cit = vec.begin();

	it++;
	*it = 12;
	std::cout << *it << std::endl;
	cit++;
	// *cit = 20;
	// ++cit;
	std::cout << *cit << std::endl;


#if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	// kek.at(200);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
#endif // for erase
	// std::vector<int> orig;
	// orig.push_back(12);
	// orig.push_back(13);
	// std::vector<int>::const_iterator p = orig.begin();
	// std::cout << std::endl;
	// // *p = 20;
	// p++;
	// std::cout << *p << std::endl;
	// orig.swap();
	// orig.erase(p);

	return 0;
}


// test iterator and existed func to them
// test vector and existed func to them
// test vector::iterators and existed func to them
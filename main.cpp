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


#if 0
	diy::vector<int> vec;
	diy::vector<int>::iterator it = vec.begin();
	diy::vector<int>::iterator en = vec.end();
	// vec.clear();
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);

	diy::vector<int> lol(vec); // copy
	std::cout << &vec[0] <<	"	" << vec[0] << std::endl;
	std::cout << &lol[0] <<	"	" << lol[0] << std::endl;

// #if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	// kek.at(200);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
#endif
	std::vector<int> orig;
	std::vector<int>::iterator p = orig.begin();
	orig.push_back(12);
	orig.push_back(13);
	// orig.swap();
	orig.erase(p);

	return 0;
}


// test iterator and existed func to them
// test vector and existed func to them
// test vector::iterators and existed func to them
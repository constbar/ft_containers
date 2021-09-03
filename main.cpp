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


#if 1
	diy::vector<int> vec;

	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);

	int ex = 99;
	vec.assign(2, ex);
	std::cout << vec[0] << std::endl; 
	std::cout << vec[1] << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;


	// diy::vector<int>::iterator it;
	// diy::vector<int>::const_iterator cit;

	// it = vec.begin();
	// it++;
	// *it = 12;
	// std::cout << *it << std::endl;

	// cit = vec.begin();
	// cit++;
	// // *cit = 20;
	// ++cit;
	// std::cout << *cit << std::endl;
	// std::cout << vec[3] << std::endl;
#endif


#if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	// kek.at(200);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
#endif // for erase

	// std::string arr[] = {"12", "34"};
	// std::string ex = "ex";
	std::vector<std::string> orig;
	// orig.reserve(100);
	// orig.push_back("99");
	// orig.push_back("99");
	orig.assign(arr, arr + 2);
	// orig.assign(5, ex);

	// std::cout << orig[0] << std::endl;
	// std::cout << orig[1] << std::endl;
	// std::cout << orig[2] << std::endl;
	// std::cout << orig[3] << std::endl;
	// std::cout << orig[4] << std::endl;
	// std::cout << orig[5] << std::endl;
	// std::cout << orig.size() << std::endl;
	// std::cout << orig.capacity() << std::endl;



	return 0;
}


// test iterator and existed func to them
// test vector and existed func to them
// test vector::iterators and existed func to them
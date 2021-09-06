#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stack>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "ranit.hpp"
#include "iter.hpp"

class Man {
	public:
		Man() {
			std::cout << "hola\n";
		};
};

int main() {

	diy::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(1);
	vec1.push_back(1);
	diy::vector<int>::iterator it1;

	diy::vector<int> vec2;
	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(6);
	vec2.push_back(6);
	diy::vector<int>::iterator it2;


	// diy::swap(vec1, vec2);
	// std::cout << vec1[0] << std::endl;
	// std::cout << vec1[1] << std::endl;
	// std::cout << vec1[2] << std::endl;
	// std::cout << std::boolalpha << (it1 == it2) << std::endl;

	diy::vector<int> v;
	diy::vector<int>::iterator f = v.begin();
	diy::vector<int>::iterator l = vec2.end();
	std::cout << std::boolalpha << (f < l) << std::endl;




	return 0;
}

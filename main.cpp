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

	std::vector<int> vec1;
	vec1.push_back(4);
	vec1.push_back(55);
	vec1.push_back(55);
	vec1.push_back(55);
	vec1.push_back(55);
	vec1.push_back(55);
	std::vector<int>::iterator it1 = vec1.begin();
	std::vector<int>::iterator la1 = vec1.end();

	std::vector<int> vec2;
	vec2.push_back(3);
	vec2.push_back(3);
	std::vector<int>::iterator it2 = vec2.begin();
	std::vector<int>::iterator la2 = vec2.end();

	vec1.assign(it2, la2);
	std::cout << vec1[0] << std::endl;
	std::cout << vec1[1] << std::endl;
	// std::cout << vec1[2] << std::endl;

	// std::cout << "asd" << std::endl;

	// bool y = diy::lexicographical_compare(it1, la1, it2, la2);
	// std::cout << std::boolalpha << !y << std::endl;

	// bool y = std::equal();


	return 0;
}

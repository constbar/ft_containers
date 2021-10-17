#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#include <map>
#include <set>

#include "map/map.hpp"
#include "set/set.hpp"
#include "utils/utils.hpp"
#include "stack/stack.hpp"
#include "utils/tests.hpp"
#include "vector/vector.hpp"

int main() {

	std::cout << "diy::vector test" << std::endl;
	diy::vector<std::string> vec1;
	vec1.push_back("vec1");
	vec1.push_back("vec2");
	vec1.push_back("vec3");
	diy::vector<std::string>::iterator vec1_it = vec1.begin();
}

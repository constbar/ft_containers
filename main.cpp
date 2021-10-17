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
	diy::vector<std::string> vec;
	vec.push_back("str1");
	vec.push_back("str2");
	vec.push_back("str3");
	vec.push_back("str4");
	vec.push_back("str5");
	vec.push_back("str6");
	std::cout << "is vec empty? " << std::boolalpha << vec.empty() << std::endl;
	vec.reserve(9);
	std::cout << "new capacity of vector " << vec.capacity() << std::endl;
	diy::vector<std::string>::iterator vec_it1 = vec.begin();
	vec_it1++;
	diy::vector<std::string>::iterator vec_it2 = vec.end();
	vec_it2--;
	vec_it2--;
	vec.erase(vec_it1, vec_it2);
	std::cout << "vec after erase with iters" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	

	std::cout << std::endl;
	std::cout << "diy::stack test" << std::endl;
	diy::stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	while (!stk.empty()) {
		std::cout << stk.top() << std::endl;
		stk.pop();
	}
	std::cout << "is stack empty? " << std::boolalpha << stk.empty() << std::endl;


	std::cout << std::endl;
	std::cout << "diy::map test" << std::endl;
	diy::map<int, std::string> mp;
	mp.insert(diy::make_pair(1, "str1"));
	mp.insert(diy::make_pair(25, "str2"));
	mp.insert(diy::make_pair(4, "str3"));
	mp.insert(diy::make_pair(-30, "str4"));
	mp.insert(diy::make_pair(100, "str5"));
	mp[500] = "500";
	std::cout << "is tree working?" << std::endl;
	diy::map<int, std::string>::iterator mp_it = mp.begin();
	std::cout << mp_it->first << std::endl;
	mp_it++;
	std::cout << mp_it->first << std::endl;
	mp_it++;
	std::cout << mp_it->first << std::endl;
	mp_it++;
	std::cout << mp_it->first << std::endl;
	mp_it++;
	std::cout << mp_it->first << std::endl;
	mp_it++;
	std::cout << mp_it->first << std::endl;


	std::cout << std::endl;
	std::cout << "diy::set test" << std::endl;
	diy::set<std::string> str_set;
	str_set.insert("111");
	str_set.insert("222");
	str_set.insert("333");
	diy::set<std::string>::iterator str_it;
	str_it = str_set.begin();
	std::cout << *str_it << std::endl;
	str_it++;
	std::cout << *str_it << std::endl;
	str_it++;
	std::cout << *str_it << std::endl;
	str_set.clear();
	std::cout << "is set empty after clear? " << std::boolalpha << str_set.empty() << std::endl;

	return 0;
}

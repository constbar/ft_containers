#include <iostream>
#include <queue>
#include <iterator>
#include <vector>
#include <stack>
#include <map>

#include <numeric> // chech it
#include <typeinfo> // typeid

// #include "vector/vector.hpp"
// #include "stack/stack.hpp"
// #include "utils/tests.hpp"


// other dwag
// #include "ch_map/binary_search_tree.hpp"
// #include "ch_map/binary_search_tree_iterator.hpp"
// #include "ch_map/map.hpp"
// #include "ch_map/utils.hpp"


// #include "iter.hpp"
// #include "ranit.hpp"
// #include "bidit.hpp"
// #include "utils.hpp"
// #include "pair.hpp"
// #include "rbtree.hpp"
// #include "node.hpp"
// #include "map.hpp"

// 1. check all valgrind at home
// 2. iterators_traits, nado li ih ispol'zovat'? + !! save them to other file
// 4. std::pair
// 5. std::make_pair, must be reimplemented
// 6. test all pair / make pair / rev traits
// 7. make test from subject
// 8. test all non meber funcs enable if and others (enable if and other)
// 9. wall wextra werr use in check
// 10. in public there is no value_type and other inits of basic params
// 11. check the same in iterator
// 12. check all // (comments)
// 13. make dirs with vector // stack and other .. // or make all in one : vector contains all stuff with working with
// 14. check alll makefile
// 15. check coplience form everywhere
// 16. change standart in make
// 17. bool vector 
// 18. try things what should be implemented in subject
// 19. check all includes in all files, maybe something unnessesary
// 20. send node to other hpp
// final test for eval
// 21. read check list and subj
// 22. check all incudes in files
// 23. make pair add
// 24. make vector beautifull - like . .. ... .... .....
// 25. make typename in iter.hpp
// 26. make it
// 27. make_pair.hpp class -> template

#include "map.hpp"
#include "utils/pair.hpp"
#include "utils/utils.hpp"
// #include "vector/vector.hpp"

// namespace diy {
// 	template <class T1, class T2>
// 	struct pair;
// 	template <class T1, class T2>
// 	pair<T1, T2> make_pair(const T1 &x, const T2 &y);
// }

int main() {  // 146

	diy::pair<int, int> kek;
	kek = diy::make_pair(1,1);

	ft::map<int, int> kke;
	kke.insert(kek);

	kke.insert(diy::make_pair(1, 2111));
	kke.insert(diy::make_pair(1,2111));
	kke.insert(diy::make_pair(2,3333));
	kke.insert(diy::make_pair(4,2123));
	kke.insert(diy::make_pair(111,211));

	ft::map<int, int>::iterator itkke = kke.begin();
	std::cout << "f " << itkke->first << std::endl;
	std::cout << "s " << itkke->second << std::endl;
	itkke++;
	std::cout << "f " << itkke->first << std::endl;
	std::cout << "s " << itkke->second << std::endl;
	itkke++;
	std::cout << "f " << itkke->first << std::endl;
	std::cout << "s " << itkke->second << std::endl;
	std::cout << std::endl;
	// std::cout << itkke->first << std::endl;
	// std::cout << itkke->second << std::endl;
	// std::cout << "clear " << kke.empty() << std::endl;
	// kke.clear();
	// std::cout << "clear " << kke.empty() << std::endl;
	// std::cout << "max " << kke.max_size() << std::endl;
	
	// ft::map<int, std::string>::reverse_Iterator i = kke.rbegin();
	// std::cout << i->second << std::endl;
	// i++;
	// std::cout << i->second << std::endl;	

	// diy::vector<int> asd;
	// asd.push_back(1);
	// asd.push_back(3);
	// asd.push_back(123);
	// asd.push_back(312132);
	// asd.push_back(1232121);
	// diy::vector<int>::iterator it = asd.begin();
	// std::cout << std::endl;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;

	// diy::vector<int>::const_iterator cit;
	// cit = asd.begin();
	// // = asd.begin();


}



	// test_vector test_vec;
	// test_vec.test_const();
	// test_vec.test_copy();
	// test_vec.test_iters();
	// test_vec.test_first();
	// test_vec.test_second();
	// test_vec.test_third();
	// test_vec.test_operators();

	// test_stack test_stk;
	// test_stk.test1();
	// test_stk.test2();







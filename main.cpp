#include <iostream>
#include <iterator>
#include <vector>
#include <list> // need i it?
#include <stack>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "iter.hpp"
#include "ranit.hpp"
#include "tests.hpp"

// 1. check all valgrind
// 2. iterators_traits, nado li ih ispol'zovat'?
// 4. std::pair
// 5. std::make_pair, must be reimplemented
// 6. test all pair / make pair / rev traits
// 7. make test from subject
// 8. test all non meber funcs enable if and others (enable if and other)

int main() {

	test_vector test_vec;
	test_vec.test_const();
	test_vec.test_copy();
	test_vec.test_iters();
	test_vec.test_first();
	test_vec.test_second();
	test_vec.test_third();
	test_vec.test_operators();

	return 0;
}

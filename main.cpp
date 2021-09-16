#include <iostream>
#include <iterator>
#include <vector>
#include <stack>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "stack.hpp"
#include "iter.hpp"
#include "ranit.hpp"
#include "tests.hpp"

// 1. check all valgrind
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

int main() {

	// test_vector test_vec;
	// test_vec.test_const();
	// test_vec.test_copy();
	// test_vec.test_iters();
	// test_vec.test_first();
	// test_vec.test_second();
	// test_vec.test_third();
	// test_vec.test_operators();

	test_stack test_stk;
	test_stk.test1();
	test_stk.test2();



	return 0;
}

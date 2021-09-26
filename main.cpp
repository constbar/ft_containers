#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#include <map>

// // -5. change standart in make and wall wextra werror and name ./a.out
// // -3. how map tree works?
// // -1. test equal range ~720 tests/

#include "map/map.hpp"
#include "utils/utils.hpp"
#include "utils/tests.hpp"
#include "vector/vector.hpp"

int main() {

	test_vector test_vec;
	test_vec.test_const();
	test_vec.test_copy();
	test_vec.test_iters();
	test_vec.test_first();
	test_vec.test_second();
	test_vec.test_third();
	test_vec.test_operators();

	test_stack test_stk;
	test_stk.test1();
	test_stk.test2();

	test_map test_m;
	test_m.test_const();
	
}

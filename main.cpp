#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stack>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "iter.hpp"
#include "ranit.hpp"
#include "tests.hpp"

int main() {

	test_vector test;
	test.test_const();
	test.test_copy();
	test.test_iters();
	test.test_first();
	test.test_second();
	test.test_third();
	test.test_operators();
	
	return 0;
}

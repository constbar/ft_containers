#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "ranit.hpp"
#include "iter.hpp"

/* 
int main() {


#if 1
	diy::vector<int> vec;

	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);

	// int ex = 99;
	// vec.assign(2, ex);
	// std::cout << vec[0] << std::endl; 
	// std::cout << vec[1] << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;


	// diy::vector<int>::iterator it;
	diy::vector<int>::const_iterator cit = vec.begin();

	// it = vec.begin();
	// it++;
	// *it = 12;
	// std::cout << *it << std::endl;

	// cit = vec.begin();
	cit++;
	// *cit = 20;
	++cit;
	std::cout << *cit << std::endl;
	std::cout << vec[3] << std::endl;
#endif


#if 0
	std::cout << "std::vector \n";
	std::vector<int> kek(5);
	// kek.valu
	kek.reserve(30);
	// kek.at(200);
	std::cout << kek.size() << std::endl;
	std::cout << kek.capacity() << std::endl;
// #endif // for erase

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
#endif


	return 0;
}
*/

// #include <type_traits>

// template <class T>
// void foo(T) {
// 	std::cout << "T is signed" << std::endl;
// }

// template <class T,
// class = typename std::enable_if<std::is_member_pointer<T>::value>::type>
// void foo(T) {
// 	std::cout << "T is unsigned " << std::endl;
// }

// int main() {

// 	// foo("12.2");
// 	foo('1');
// 	foo(22222);
// 	return 0;
// }

// struct Bla
// {
// 	template <typename T,
// 		std::enable_if_t<std::is_integral<T>::value, int> = 0>
// 	static void klaf(T t) {
// 		std::cout << "int" << std::endl;
// 	}

// 	template <typename T, 
// 		std::enable_if_t<std::is_floating_point<T>::value, int> = 0>
// 	static void klaf(T t) {
// 		std::cout << "float" << std::endl;
// 	}
// };

// int main()
// {
// 	// Bla::klaf("a");
// 	Bla::klaf(17.5);
// 	Bla::klaf(65);
// }

// template <typename T, typename = std::enable_if_t<!std::is_floating_point<T>::value>>
// bool equals(T f, T s) {

// 	return f == s;
// }

// template <typename T>
// bool equals(T f, T s,
// std::enable_if_t<!std::is_floating_point<T>::value>* = nullptr) {
// 	std::cout << "this is no float" << std::endl;
// 	return f == s;
// }

// template <typename T>
// bool equals(T f, T s,
// std::enable_if_t<std::is_floating_point<T>::value>* = nullptr) {
// 	std::cout << "another one" << std::endl;
// 	return true;
// }

int main() {

	// std::cout << equals(1.f, 1.f) << std::endl;
	// std::cout << equals(1, 1) << std::endl;
	std::string arr[] = {"1","2","3"};
	std::vector<char> kek;
	kek.assign(arr, arr + 4);

	std::cout << kek[0] << std::endl;
	std::cout << kek[1] << std::endl;
	std::cout << kek[2] << std::endl;

	return 0;
}
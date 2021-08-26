#include <iostream>
#include <iterator>
#include <vector>

#include "vec.hpp"
#include "itr.hpp"

template <typename Iterator>
void FooImpl(Iterator first, Iterator last, std::random_access_iterator_tag)
{

}
template <typename Iterator>
void Foo(Iterator first, Iterator last)
{
	typedef typename std::iterator_traits<Iterator>::iterator_category category;
	return FooImpl(first, last, category());
}

int main() {

	// // this is vector 
	std::vector<int> kek;
	kek.push_back(1);
	std::vector<int>::iterator it;
	it = kek.begin();

#if 0
	int i = 77;
	// std::vector<int> arr;
	my::iter<int> kek;
	kek = &i;
	std::cout << *kek << std::endl;

	// std::<int>::iterator it;

	// int *pint = &i;

	// kek = &i;
	// p = &i;
	// *kek = 11;
	// std::cout << i << std::endl;
	// std::cout << *kek << std::endl;
#endif

	// std::vector<int> kek;
	// kek.push_back(2);
	// kek.push_back(1);
	// kek.push_back(3);
	
	// std::vector<int>::iterator i1 = kek.begin();
	// std::vector<int>::iterator i2 = kek.end();
	return 0;
}

// // std::iterator example
// #include <iostream> // std::cout
// #include <iterator> // std::iterator, std::input_iterator_tag

// class MyIterator //: public std::iterator<std::input_iterator_tag, int>
// {
// 	int* p;
// 	public:
// 		MyIterator(int* x) :p(x) {}
// 		MyIterator(const MyIterator& mit) : p(mit.p) {}
// 		MyIterator& operator++() {++p;return *this;}
// 		MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
// 		bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
// 		bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
// 		int& operator*() {return *p;}
// };

// int main () {
// 	int numbers[]={10,20,30,40,50};
// 	MyIterator from(numbers);
// 	MyIterator until(numbers+5);
// 	for (MyIterator it=from; it!=until; it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

//   return 0;
// // }


// // iterator_traits example
// #include <iostream> // std::cout
// #include <iterator> // std::iterator_traits
// #include <typeinfo> // typeid

// int main()
// {
// 	// typedef std::iterator_traits<std::string*> traits;
// 	// if (typeid(traits::iterator_category) == 
// 	// typeid(std::random_access_iterator_tag))
// 	// 	std::cout << "int* is a random-access iterator\n";

// 	// Derived *pd = new Derived;
// 	// Base *pb = pd;
// 	// cout << typeid(pb).name() << endl;	//prints "class Base *"
// 	// cout << typeid(*pb).name() << endl; //prints "class Derived"
// 	// cout << typeid(pd).name() << endl;	//prints "class Derived *"
// 	// my::iter<int> kke;
// 	// std::cout << typeid('1').name() << std::endl; //prints "class Derived"
// 	return 0;
// }
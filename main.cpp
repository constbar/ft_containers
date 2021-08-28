#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include <numeric>
#include <typeinfo> // typeid

#include "vec.hpp"
#include "itr.hpp"

// struct iiterator_traits;
// struct iiterator;

class man {
	public:
		man() {
			std::cout << "ama man!\n";
		}
};
// : public std::iterator<std::random_access_iterator_tag, T>
template<typename _Category, typename _Tp, typename _Distance = std::ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iiterator { // its not an iiterator // rename!! // iiterator <int, int> // typeid(ttt).name() testing just int
      typedef _Category  iterator_category; // 32767 // i								iiterator<int, int>::value_type
      typedef _Tp        value_type;		// 32765 // i
      typedef _Distance  difference_type;	// 140729308496224 // l
      typedef _Pointer   pointer;			// adr // Pi
      typedef _Reference reference;			// 12 // i
	  iiterator() {std::cout << "basic type called\n";} // delete
};

// its a bad idea to implement traits bec of some types require compiler internals
template<typename iiterator>
struct iiterator_traits { // what a name!
      typedef typename iiterator::iterator_category iterator_category; // all works with iiterator_traits<iiterator<int, int>>::value_type lll;
      typedef typename iiterator::value_type        value_type;
      typedef typename iiterator::difference_type   difference_type;
      typedef typename iiterator::pointer           pointer;
      typedef typename iiterator::reference         reference;
};

	// std::iterator_traits<int*>::iterator_category p; // from iter to pointer
	// std::cout << typeid(p).name() << std::endl;


	// iiterator_traits<iiterator<int, int> > ::iterator_category ttt;
	// std::iterator_traits<std::vector<int>::iterator>::iterator_category cati;
	
	// #include <limits>
	// int max1 = std::numeric_limits<int>::max(); // its a trait of this
	// std::cout << max1 << std::endl;
int main() {

	// // iiterator_traits< iiterator<int, int> >::value_type i;
	std::vector<int> kek;
	kek.push_back(11);
	kek.push_back(12);
	kek.push_back(13);
	// std::vector<int>::iterator lol = kek.begin();
	int o = 20;
	int *pp = &o;
	std::iterator_traits<int*>::pointer p;
	std::cout << typeid(p).name() << std::endl;
	// p = &o;
	// std::cout << pp;
	// std::cout << &lol << std::endl;
	// std::cout << lol.base() << std::endl;

	// std::cout << std::advance(lol, 2);
	// back

#if 0
#endif

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

//	return 0;
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



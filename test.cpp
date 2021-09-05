#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>
 
template<class T>
class Iterator;
 
template<class T>
class array {
	public:
		typedef Iterator<T>		iterator; //
		typedef size_t 			size_type;
		typedef T* 				pointer;
		typedef const T*		const_pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef T				value_type;
	
	array():arr_(new T[0]), sz_(0) {}
	array(size_t sz):sz_(sz), arr_(new T[sz]) {
		std::fill(arr_, arr_ + sz_, T()); }
	array(const array& arr)	{
		delete arr_;
		sz_ = arr.sz;
		arr_ = new T[sz_];
		std::copy(arr.arr_, arr.arr_ + sz_, arr_);
	}
	array& operator =(const array& arr)
	{
		array tmp(arr);
		swap(tmp);
		return *this;
	}
	~array()
	{
		delete[] arr_;
	}
	Iterator<T> begin()
	{
		return Iterator<T>(arr_);
	}
	Iterator<T> end()
	{
		return Iterator<T>(arr_ + sz_);
	}
	T& operator [](size_t idx)
	{
		return arr_[idx];
	}
	const T& operator [](size_t idx) const
	{
		return arr_[idx];
	}
	size_t size() const
	{
		return sz_;
	}
private:
	void swap(array& first, array& second)
	{
		std::swap(first.arr_, second.arr_);
		std::swap(first.sz_, second.sz_);
	}
	T* arr_;
	size_t sz_;
};
 
template<class T>
class Iterator {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::forward_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
	
	Iterator(T* curr):current(curr) {}
	
	Iterator& operator =(const Iterator& other) {
		if (this != &other)
			current = other.current;
		return *this; }

	Iterator& operator ++() {
		 ++current;
		 return *this; }

	Iterator operator ++(int i) {
		 Iterator tmp(current);
		 ++current;
		 return tmp; }

	T& operator *() {
		return *current; }
	T* operator ->() {
		return current; }
	bool operator ==(const Iterator& other) {
		return current == other.current; }
	bool operator !=(const Iterator& other) {
		return !(*this == other);}

private:
	T* current;
};
 
int main()
{
	array<int> arr(5);
	for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << *iter << std::endl;
	}
	for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
		*iter = 5;
	}
	for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

// pair example 
/* template <typename t1, typename t2>
void pr(std::pair<t1, t2> &obj)
{

	std::cout << obj.first << "  " << obj.second << std::endl;
}

int main()
{

	std::vector<std::pair<int, std::string>> kek;
	kek.push_back(std::make_pair(1, "asd"));
	std::vector<std::pair<int, std::string>>::iterator k = kek.begin();
	pr(*k);
	// std::cout << *k << std::endl; */

	/* ALLOC WORKING
	std::allocator<int> intAlloc;
	int *intArray = intAlloc.allocate(100);
	intAlloc.deallocate(intArray, 100);

	// string allocator
	std::allocator<std::string> stringAlloc;
	std::string *myString = stringAlloc.allocate(3);

	stringAlloc.construct(myString, "Hello");
	stringAlloc.construct(myString + 1, "World");
	stringAlloc.construct(myString + 2, "!");
	stringAlloc.destroy(myString);
	stringAlloc.destroy(myString + 1);
	stringAlloc.destroy(myString + 2);
	std::cout
		<< myString[0] << " "
		<< myString[1] << " "
		<< myString[2] << std::endl;
	stringAlloc.deallocate(myString, 3); */

	/* 
	// placement new with new
	man *p;
	p = new man();
	std::cout << p << std::endl;
	man &t1 = *p;

	// p = new man();
	new (p) man();
	man &t2 = *p;
	std::cout << p << std::endl;

	std::cout << std::boolalpha << (&t1 == &t2) << std::endl;
	delete p;
	
	// with alloc
	std::allocator<man> all;
	man *pp;
	pp = all.allocate(1);
	all.deallocate(pp, 2);
	// all.destroy(pp);
	pp = all.allocate(2);
	all.construct(pp, man());
	all.deallocate(pp, 2); */

	//woriking whit iterators !
	/* 
	// iiterator_traits<iiterator<int, int> >::iterator_category lll;
	// std::cout << typeid(lll).name() << std::endl;

	// iiterator<int, int>::iterator_category kkk;
	// std::cout << typeid(kkk).name() << std::endl;

	// iiterator_traits<int*>::iterator_category ppp;
	// std::cout << typeid(ppp).name() << std::endl;

	// std::cout << "\nhere without traits" << std::endl;
	// std::list<int> qq; qq.push_back(12); qq.push_back(13);// not need it
	// std::list<int>::iterator www = qq.begin();
	// www++;
	// std::cout << *www << std::endl;
	// www++;
	// std::cout << typeid(www).name() << std::endl;

	// std::cout << "\nhere with traits" << std::endl;
	// std::iterator_traits<std::list<int>::iterator>::iterator_category cati;
	// std::cout << typeid(cati).name() << std::endl; */




	// old description of TRAITS form begin !!!

	/* 
	template<typename _Category, typename _Tp, typename _Distance = std::ptrdiff_t,
			typename _Pointer = _Tp*, typename _Reference = _Tp&>
		struct iiterator { // its shablon // rename!! // iiterator <int, int> // typeid(ttt).name() testing just int
		typedef _Category  iterator_category; 							// 32767 // i			iiterator<int, int>::value_type
		typedef _Tp        value_type;									// 32765 // i
		typedef _Distance  difference_type;								// 140729308496224 // l
		typedef _Pointer   pointer;										// adr // Pi
		typedef _Reference reference;										// 12 // i
		iiterator() {std::cout << "basic type called\n";} // delete
	};

	// its a bad idea to implement traits bec of some types require compiler internals
	template<typename iiterator>
	struct iiterator_traits { // what a name! // iiterator_traits<iiterator<int, int>>::value_type lll;
		typedef typename iiterator::iterator_category iterator_category; // all works with 
		typedef typename iiterator::value_type        value_type;
		typedef typename iiterator::difference_type   difference_type;
		typedef typename iiterator::pointer           pointer;
		typedef typename iiterator::reference         reference;
	};

	template<typename _Tp> // this iterator traits dlya pointers // implement of usual iter_traits with iter_categori
	struct iiterator_traits<_Tp*> { // iiterator_traits<int*>::pointer kek; // it will work as pointer 
		typedef std::random_access_iterator_tag	iterator_category;
		typedef _Tp                         		value_type;
		typedef std::ptrdiff_t                   	difference_type;
		typedef _Tp*                        		pointer;
		typedef _Tp&                        		reference;
	};

	/// Partial specialization for const pointer types.
	template<typename _Tp> // for const type
	struct iiterator_traits<const _Tp*> { // iiterator_traits<const int*>::iterator_category kek;
		typedef std::random_access_iterator_tag iterator_category;
		typedef _Tp                         value_type;
		typedef std::ptrdiff_t                   difference_type;
		typedef const _Tp*                  pointer;
		typedef const _Tp&                  reference;
		};
		// std::iterator_traits<int*>::iterator_category p; // from iter to pointer
		// std::cout << typeid(p).name() << std::endl;


		// iiterator_traits<iiterator<int, int> > ::iterator_category ttt;
		// std::iterator_traits<std::vector<int>::iterator>::iterator_category cati;
		
		// #include <limits>
		// int max1 = std::numeric_limits<int>::max(); // its a trait of this
		// std::cout << max1 << std::endl; */



		// test if categories are the same :
		/*
		std::iterator_traits<std::list<int>::iterator>::iterator_category q;
		std::iterator_traits<std::string *>::iterator_category traits;

		if (typeid(q) == typeid(std::random_access_iterator_tag))
			std::cout << "int* is a random-access iterator\n";
		else
			std::cout << "NINE!\n"; */









// test for erase!
// int main() {

// #if 0 // orginal
// 	std::vector<int> v;
// 	v.push_back(111);
// 	v.push_back(222);
// 	v.push_back(333);
// 	v.push_back(444);
// 	std::vector<int>::iterator it = v.begin();
// 	std::vector<int>::iterator et = v.begin();
// 	et++;
// 	et++;
// 	std::vector<int>::iterator kek = v.erase(it, et);

// 	// std::vector<int>::iterator b = v.begin();
// 	// for (; b != v.end(); b++)
// 		// std::cout << *b << std::endl;

// 	// std::cout << v.at(0) << std::endl;
// 	// std::cout << v.at(1) << std::endl;

// 	std::cout << "* made 	" << *kek << std::endl;
// 	// std::cout << v.at(2) << std::endl;
// 	// std::cout << v.at(3) << std::endl;

// 	// std::cout << v[0] << std::endl;
// 	// std::cout << v[1] << std::endl;
// 	// std::cout << v[2] << std::endl;
// 	// std::cout << v[3] << std::endl;
// 	// std::cout << v[4] << std::endl;
// 	// std::cout << v[5] << std::endl;
// 	// std::cout << v[6] << std::endl;
	
	
// 	// std::cout << *kek << std::endl;
// 	// std::cout << v[0] << std::endl;
// 	// std::cout << v[1] << std::endl;
// 	// std::cout << v[2] << std::endl;
// 	std::cout << "size " << v.size() << std::endl;
// 	std::cout << "caps " << v.capacity() << std::endl;
// #endif

// 	/// my vector
// #if 0
// 	diy::vector<int> vec;
// 	vec.push_back(111);
// 	vec.push_back(222);
// 	vec.push_back(333);
// 	vec.push_back(444);

// 	diy::vector<int>::iterator iter = vec.begin();
// 	diy::vector<int>::iterator eder = vec.begin();
// 	eder++;
// 	eder++;
// 	diy::vector<int>::iterator d;
// 	d = vec.erase(iter, eder);
// 	std::cout << std::endl;
// 	std::cout << "razimenovano " << *d << std::endl;

// 	std::cout << vec.at(0) << std::endl;
// 	std::cout << vec.at(1) << std::endl;
// 	// std::cout << vec.at(2) << std::endl;
// 	std::cout << vec.size() << std::endl;
// 	std::cout << vec.capacity() << std::endl;
// 	// std::cout << vec.at(2) << std::endl;
// 	// std::cout << vec.at(3) << std::endl;
// #endif
// #if 1 // for single erase
// 	diy::vector<int> vec;
// 	vec.push_back(111);
// 	vec.push_back(222);
// 	vec.push_back(333);
// 	vec.push_back(444);

// 	diy::vector<int>::iterator iter = vec.begin();
// 	diy::vector<int>::iterator d;
// 	d = vec.erase(iter);
// 	std::cout << std::endl;
// 	// std::cout << "razimenovano " << *d << std::endl;

// 	std::cout << vec.at(0) << std::endl;
// 	std::cout << vec.at(1) << std::endl;
// 	std::cout << vec.at(2) << std::endl;
// 	// std::cout << vec.at(3) << std::endl;
// 	// std::cout << vec.size() << std::endl;
// #endif
// 	return 0;
// }
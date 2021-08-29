#ifndef RAITR_HPP
#define RAITR_HPP

#include <iterator>
#include "iter.hpp"
// info
// 1. reverse_iterator : public iterator <vse params> PAGE ! 104 ! add base / add RaNit current; 
// ? 2. nuzhno li nasledonie v iterator esli mozhno obozvat' chisto typename with std::random_access_iterator_tag smth ... 
//  : public std::iterator<std::random_access_iterator_tag, T, /* DIST i can add here void void void */>

	// typedef C iterator_category;
	// 	typedef T value_type;
	// 	typedef D difference_type;
	// 	typedef P pointer;
	// 	typedef R reference;



namespace diy {

	template <typename T, typename C = std::random_access_iterator_tag,
		typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
	class ranit {

		public:
			typedef C	category;
			typedef T	val_type;
			typedef D	dif_type;
			typedef P	pointer;
			typedef R	reference;

		private:
			pointer ptr_iter;

		public: // maybe make it protected // make it in one stting later
			ranit() : ptr_iter(NULL) {
				std::cout << "ptr null const" << std::endl; }

			ranit(pointer input) {
				this->ptr_iter = input;
				std::cout << "ptr const with arg" << std::endl; }

			ranit(const ranit &other) {
				this->ptr_iter = other.ptr_iter;
				std::cout << "copy constr" << std::endl; }

			ranit &operator=(const ranit &other) {
				if (this == &other) return *this;
				this->ptr_iter = other.ptr_iter;
				return *this; }

			~ranit() {}

			reference operator*() const {
				std::cout << "oper * in work" << std::endl;
				return *this->ptr_iter; }

			pointer operator->() const {
				std::cout << "-> in work" << std::endl;
				return this->ptr_iter; }

			ranit &operator++() {
				ptr_iter++;
				return *this; }

			ranit operator++(int) {
				ranit tmp_it(*this);
				++(*this);
				return tmp_it;
			}

			ranit &operator--() {
				ptr_iter--;
				return *this; }

			ranit operator--(int) {
				ranit tmp_it(*this);
				--(*this);
				return tmp_it;
			}


	};
}

#endif







// template <typename _Iterator>
// class reverse_iterator
	// : public iterator<typename iterator_traits<_Iterator>::iterator_category,
	// 				  typename iterator_traits<_Iterator>::value_type,
	// 				  typename iterator_traits<_Iterator>::difference_type,
	// 				  typename iterator_traits<_Iterator>::pointer,
	// 				  typename iterator_traits<_Iterator>::reference>
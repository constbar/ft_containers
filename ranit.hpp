#ifndef RAITR_HPP
#define RAITR_HPP

#include <iterator>
#include "iter.hpp"
// info
// 1. reverse_iterator : public iterator <vse params> PAGE ! 104 ! add base / add RaNit current; 
// ? 2. nuzhno li nasledonie v iterator esli mozhno obozvat' chisto typename with std::random_access_iterator_tag smth ... 
//  : public std::iterator<std::random_access_iterator_tag, T, /* DIST i can add here void void void */>
// 3. need i base func?


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
				std::cout << "simple iter\n"; // delete
			}
			ranit(pointer input) { this->ptr_iter = input; }
			ranit(const ranit &other) { this->ptr_iter = other.ptr_iter; }

			ranit &operator=(const ranit &other) {
				if (this == &other) return *this;
				this->ptr_iter = other.ptr_iter;
				return *this; }

			~ranit() {}

			reference operator*() const { return *this->ptr_iter; }
			pointer operator->() const { return this->ptr_iter; }
			ranit &operator++() { ptr_iter++; return *this; }
			ranit &operator--() { ptr_iter--; return *this; }

			ranit operator++(int) {
				ranit tmp_it(*this);
				++(*this);
				return tmp_it; }

			ranit operator--(int) {
				ranit tmp_it(*this);
				--(*this);
				return tmp_it; }

			// maybe incorrect
			bool operator>(ranit &other) const { return this->ptr_iter > other.ptr_iter; }
			bool operator<(ranit &other) const { return this->ptr_iter < other.ptr_iter; }
			bool operator>=(ranit &other) const { return this->ptr_iter >= other.ptr_iter; }
			bool operator<=(ranit &other) const { return this->ptr_iter <= other.ptr_iter; }
			bool operator==(ranit &other) const { return this->ptr_iter == other.ptr_iter; }
			bool operator!=(ranit &other) const { return this->ptr_iter != other.ptr_iter; }

			//maybe incorrect
			ranit operator+(dif_type shift) const { return ranit(this->ptr_iter + shift); }
			ranit operator-(dif_type shift) const { return ranit(this->ptr_iter - shift); }
			ranit &operator+=(dif_type shift) const { this->ptr_iter += shift; return *this; }
			ranit &operator-=(dif_type shift) const { this->ptr_iter -= shift; return *this; }
			reference operator[](dif_type index) const { return this->ptr_iter[index]; }
	};
}


namespace diy {
	template <typename T, typename C = std::random_access_iterator_tag,
		typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
	
	class rev_ranit {
		public:
			typedef C	category;
			typedef T	val_type;
			typedef D	dif_type;
			typedef P	pointer;
			typedef R	reference;

		private:
			pointer ptr_iter;

		public:
			rev_ranit() : ptr_iter(NULL) {}
			rev_ranit(pointer input) { this->ptr_iter = input; }
			rev_ranit(const rev_ranit &other) { this->ptr_iter = other.ptr_iter; }

			rev_ranit &operator=(const rev_ranit &other) {
				if (this == &other) return *this;
				this->ptr_iter = other.ptr_iter;
				return *this; }

			~rev_ranit() {}

			reference operator*() const { return *this->ptr_iter; }
			pointer operator->() const { return this->ptr_iter; }
			rev_ranit &operator++() { ptr_iter--; return *this; }
			rev_ranit &operator--() { ptr_iter++; return *this; }

			rev_ranit operator++(int) {
				rev_ranit tmp_it(*this);
				--(*this);
				return tmp_it; }

			rev_ranit operator--(int) {
				rev_ranit tmp_it(*this);
				++(*this);
				return tmp_it; }

			bool operator>(rev_ranit &other) const { return this->ptr_iter < other.ptr_iter; }
			bool operator<(rev_ranit &other) const { return this->ptr_iter > other.ptr_iter; }
			bool operator>=(rev_ranit &other) const { return this->ptr_iter <= other.ptr_iter; }
			bool operator<=(rev_ranit &other) const { return this->ptr_iter >= other.ptr_iter; }
			bool operator==(rev_ranit &other) const { return this->ptr_iter == other.ptr_iter; }
			bool operator!=(rev_ranit &other) const { return this->ptr_iter != other.ptr_iter; }

			rev_ranit operator+(dif_type shift) const { return rev_ranit(this->ptr_iter - shift); }
			rev_ranit operator-(dif_type shift) const { return rev_ranit(this->ptr_iter + shift); }
			rev_ranit &operator+=(dif_type shift) const { this->ptr_iter -= shift; return *this; }
			rev_ranit &operator-=(dif_type shift) const { this->ptr_iter += shift; return *this; }
			reference operator[](dif_type index) const { return this->ptr_iter[index]; }
	};
}

#endif


// template <typename _Iterator>
// class reverse_iterator
	// : public iterator<typename iterator_traits<_Iterator>::iterator_category,
	// 				  typename iterator_traits<_Iterator>::value_type,
	// 				  typename iterator_traits<_Iterator>::difference_type,
	// 				  typename iterator_traits<_Iterator>::pointer,
					//   typename iterator_traits<_Iterator>::reference>
					//
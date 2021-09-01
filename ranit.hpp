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


// check all type names here!!! bec orig_iterator should call the same
namespace diy {
	// template <typename T>
	template <typename T, typename C = std::random_access_iterator_tag, 
		typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
	
	class ranit { // : std::iterator<std::random_access_iterator_tag, T> {
		public:
			typedef C	category;
			typedef T	val_type;
			typedef D	dif_type;
			typedef P	pointer;
			typedef R	reference;
			

			/* it is about const and non const iterators
 			// pde -back // t_containers / srcs / Iterators / RandomAccessIterator.hpp
			typedef random ac iter<T, T *, T &> it;
			typedef random ac iter<T, const T *, const T &> const_it;
 */
			//ne nado  typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category ita;
			// typedef T		val_type;
			// typedef T&		reference;
			// typedef T*		pointer;
			// typedef typename std::ptrdiff_t						dif_type;
			// typedef typename std::random_access_iterator_tag	category;


		private:
			// typedef ranit<T> it; // i can store it here // need i it at all??
			pointer		ptr_iter;

		public: // maybe make it protected // make it in one stting later
			ranit() : ptr_iter(NULL) {
				// std::cout << "simple iter\n"; // delete
			}
			ranit(pointer input) { this->ptr_iter = input; }
			ranit(const ranit<T> &other) { this->ptr_iter = other.ptr_iter; } // was added <T>

			// it &operator=(const it &other) { // 2 remakes of it
			ranit &operator=(const ranit &other) {
				// should return ranit<T>
				if (this == &other) return *this;
				this->ptr_iter = other.ptr_iter;
				return *this; }

			~ranit() {}
			
			// maybe should returm ranit<T>
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

// remake because of original chenged !!!!!!!!!!!!!!!!!!!!!
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

// this for swap
namespace diy
{
	template <typename T>
	void swap(T &first, T &second) {
		T tmp = first;
		first = second;
		second = tmp;
	}
}

#endif
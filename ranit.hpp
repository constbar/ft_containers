#ifndef RAITR_HPP
#define RAITR_HPP

#include <iterator>
#include "iter.hpp"
// info
// 1. reverse_iterator : public iterator <vse params> PAGE ! 104 ! add base / add RaNit current; 
// ? 2. nuzhno li nasledonie v iterator esli mozhno obozvat' chisto typename with std::random_access_iterator_tag smth ... 
//  : public std::iterator<std::random_access_iterator_tag, T, /* DIST i can add here void void void */>
// 3. need i base func?
// 4. why destructor virtual?

	// typedef C iterator_category;
	// 	typedef T value_type;
	// 	typedef D difference_type;
	// 	typedef P pointer;
	// 	typedef R reference;


// check all type names here!!! bec orig_iterator should call the same
namespace diy {
	// template <typename T, typename C = std::random_access_iterator_tag, 
	// 	typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
	template <typename T, typename Pointer, typename Reference,
		typename Category = std::random_access_iterator_tag > 
	class ranit { // : std::iterator<std::random_access_iterator_tag, T> {
		public:

			// typedef C	category;
			// typedef T	val_type;
			// typedef D	dif_type;
			// typedef P	pointer;
			// typedef R	reference;


			//ne nado  typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category ita;
			// typedef T		val_type;
			// typedef T&		reference;
			// typedef T*		pointer;
			// typedef typename std::ptrdiff_t						dif_type;
			// typedef typename std::random_access_iterator_tag	category;

			typedef Pointer pointer; /// it will be
			typedef Reference reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::random_access_iterator_tag	category;

			typedef ranit<T, Pointer, Reference>	it; // rename this typers // like common iter
			typedef ranit<T, T*, T&>				iterator;
			typedef ranit<T, const T*, const T&>	const_iterator;

		// private:
		public: // make priv
			pointer	ptr;

		public: // maybe make it protected
			ranit() : ptr(NULL) {}
			ranit(T* input) { this->ptr = input; }
			ranit(const iterator &other) { this->ptr = other.ptr; }
				// this->ptr = const_cast<pointer>(other.ptr);

			// ranit &operator=(const ranit &other) {
			// 	if (this == &other)
			// 		return *this;
			// 	this->ptr = other.ptr; // bilo
			// 	// this->ptr = const_cast<pointer>(other.ptr);
			// 	// vozmozhno this-ptr ne good type
			// 	// return other->ptr;
			// 	return *this;
			// }

			//
			it &operator=(const it& other) { // not good!
				this->ptr = other.ptr;
				return *this;
			}
			
			virtual ~ranit() {} // virtual
			
			reference operator*() const { return *this->ptr; }
			pointer operator->() const { return this->ptr; }
			
			it &operator++() { ptr++; return *this; }
			iterator &operator--() { ptr--; return *this; }

			it operator++(int) {
				it tmp_it(*this);
				++(*this);
				return tmp_it; }

			iterator operator--(int) {
				iterator tmp_it(*this);
				--(*this);
				return tmp_it; }

			bool operator>(const iterator &other) const { return this->ptr > other.ptr; }
			bool operator<(const iterator &other) const { return this->ptr < other.ptr; }
			bool operator>=(const iterator &other) const { return this->ptr >= other.ptr; }
			bool operator<=(const iterator &other) const { return this->ptr <= other.ptr; }
			bool operator==(const iterator &other) const { return this->ptr == other.ptr; }
			bool operator!=(const iterator &other) const { return this->ptr != other.ptr; }

			//maybe incorrect
			iterator operator+(dif_type shift) const { return iterator(this->ptr + shift); }
			iterator operator-(dif_type shift) const { return iterator(this->ptr - shift); }
			iterator &operator+=(dif_type shift) const { this->ptr += shift; return *this; }
			iterator &operator-=(dif_type shift) const { this->ptr -= shift; return *this; }
			T& operator[](dif_type index) const { return this->ptr[index]; } //

			dif_type operator-(ranit other) const { return this->ptr - other.ptr; }
			// here should be friendly funcs??
	};
}

// remake because of original chenged !!!!!!!!!!!!!!!!!!!!!
// namespace diy {
// 	template <typename T, typename C = std::random_access_iterator_tag,
// 		typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
	
// 	class rev_ranit {
// 		public: // should i add orig names?
// 			typedef C	category;
// 			typedef T	val_type;
// 			typedef D	dif_type;
// 			typedef P	pointer;
// 			typedef R	reference;

// 		private:
// 			pointer ptr_iter;

// 		public:
// 			rev_ranit() : ptr_iter(NULL) {}
// 			rev_ranit(pointer input) { this->ptr_iter = input; }
// 			rev_ranit(const rev_ranit &other) { this->ptr_iter = other.ptr_iter; }

// 			rev_ranit &operator=(const rev_ranit &other) {
// 				if (this == &other) return *this;
// 				this->ptr_iter = other.ptr_iter;
// 				return *this; }

// 			~rev_ranit() {}

// 			reference operator*() const { return *this->ptr_iter; }
// 			pointer operator->() const { return this->ptr_iter; }
// 			rev_ranit &operator++() { ptr_iter--; return *this; }
// 			rev_ranit &operator--() { ptr_iter++; return *this; }

// 			rev_ranit operator++(int) {
// 				rev_ranit tmp_it(*this);
// 				--(*this);
// 				return tmp_it; }

// 			rev_ranit operator--(int) {
// 				rev_ranit tmp_it(*this);
// 				++(*this);
// 				return tmp_it; }

// 			bool operator>(rev_ranit &other) const { return this->ptr_iter < other.ptr_iter; }
// 			bool operator<(rev_ranit &other) const { return this->ptr_iter > other.ptr_iter; }
// 			bool operator>=(rev_ranit &other) const { return this->ptr_iter <= other.ptr_iter; }
// 			bool operator<=(rev_ranit &other) const { return this->ptr_iter >= other.ptr_iter; }
// 			bool operator==(rev_ranit &other) const { return this->ptr_iter == other.ptr_iter; }
// 			bool operator!=(rev_ranit &other) const { return this->ptr_iter != other.ptr_iter; }

// 			rev_ranit operator+(dif_type shift) const { return rev_ranit(this->ptr_iter - shift); }
// 			rev_ranit operator-(dif_type shift) const { return rev_ranit(this->ptr_iter + shift); }
// 			rev_ranit &operator+=(dif_type shift) const { this->ptr_iter -= shift; return *this; }
// 			rev_ranit &operator-=(dif_type shift) const { this->ptr_iter += shift; return *this; }
// 			reference operator[](dif_type index) const { return this->ptr_iter[index]; }
// 	};
// }










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
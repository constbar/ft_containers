#ifndef RAITR_HPP
#define RAITR_HPP

#include <iterator>
#include "iter.hpp"

// 1. reverse_iterator : public iterator <vse params> PAGE ! 104 ! add base / add RaNit current; 
// ? 2. nuzhno li nasledonie v iterator esli mozhno obozvat' chisto typename with std::random_access_iterator_tag smth ... 
//  : public std::iterator<std::random_access_iterator_tag, T, /* DIST i can add here void void void */>
// 3. need i base func?
// 4. why destructor virtual?
// 5. will you test just iterators
// 6. make list of initilizition
// 7. implement of base/
// 8. wtf of friendly funcs???
// 9. check  "    " instead tabs


	// typedef C iterator_category;
	// 	typedef T value_type;
	// 	typedef D difference_type;
	// 	typedef P pointer;
	// 	typedef R reference;

namespace diy { // ! added = T* and ref = T& // works finially
	template <typename T, typename Pointer = T*, typename Reference = T&,
		typename Category = std::random_access_iterator_tag > 
	class ranit {
		public:

			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::random_access_iterator_tag	category;

			typedef ranit<T, Pointer, Reference>	it;
			typedef ranit<T, T*, T&>				iterator;
			typedef ranit<T, const T*, const T&>	const_iterator;

		public: // make priv
			pointer	ptr;

		public: // maybe make it protected for just iters?
			ranit() : ptr(NULL) {}
			ranit(T* input) { this->ptr = input; } // try it with ewplace T* -> poiter // just name
			ranit(const iterator &other) { this->ptr = other.ptr; }
				// this->ptr = const_cast<pointer>(other.ptr);

			// could be it -- iterator&
			// ranit &operator=(const ranit &other) {
			it &operator=(const it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			
			virtual ~ranit() {} // why virtual?
			
			reference operator*() const { return *this->ptr; }
			pointer operator->() const { return this->ptr; }
			
			it &operator++() { ptr++; return *this; }
			it &operator--() { ptr--; return *this; }

			it operator++(int) {
				it tmp_it(*this);
				++(*this);
				return tmp_it; }

			it operator--(int) {
				it tmp_it(*this);
				--(*this);
				return tmp_it; }

			bool operator>(const it &other) const { return this->ptr > other.ptr; }
			bool operator<(const it &other) const { return this->ptr < other.ptr; }
			bool operator>=(const it &other) const { return this->ptr >= other.ptr; }
			bool operator<=(const it &other) const { return this->ptr <= other.ptr; }
			bool operator==(const it &other) const { return this->ptr == other.ptr; }
			bool operator!=(const it &other) const { return this->ptr != other.ptr; }

			//maybe incorrect
			it operator+(dif_type shift) const { return it(this->ptr + shift); }
			it operator-(dif_type shift) const { return it(this->ptr - shift); }
			it &operator+=(dif_type shift) const { this->ptr += shift; return *this; }
			it &operator-=(dif_type shift) const { this->ptr -= shift; return *this; }
			T& operator[](dif_type index) const { return this->ptr[index]; } //

			dif_type operator-(ranit other) const { return this->ptr - other.ptr; }
			// here should be friendly funcs??
	};
}

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&,
		typename Category = std::random_access_iterator_tag > 
	class rev_ranit {
		public:

			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::random_access_iterator_tag	category;

			typedef rev_ranit<T, Pointer, Reference>	rev_it;
			typedef rev_ranit<T, T*, T&>				iterator;
			typedef rev_ranit<T, const T*, const T&>	const_iterator;

		public: // make priv
			pointer	ptr;

		public: // maybe make it protected for just iters?
			rev_ranit() : ptr(NULL) {}
			rev_ranit(T* input) { this->ptr = input; } // try it with ewplace T* -> poiter // just name
			rev_ranit(const iterator &other) { this->ptr = other.ptr; }
				// this->ptr = const_cast<pointer>(other.ptr);

			// could be it -- iterator&
			// rev_ranit &operator=(const rev_ranit &other) {
			rev_it &operator=(const rev_it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			
			virtual ~rev_ranit() {} // why virtual?
			
			reference operator*() const { return *this->ptr; }
			pointer operator->() const { return this->ptr; }
			
			rev_it &operator++() { ptr--; return *this; }
			rev_it &operator--() { ptr++; return *this; }

			rev_it operator++(int) {
				rev_it tmp_it(*this);
				++(*this);
				return tmp_it; }

			rev_it operator--(int) {
				rev_it tmp_it(*this);
				--(*this);
				return tmp_it; }

			bool operator>(const rev_it &other) const { return this->ptr < other.ptr; }
			bool operator<(const rev_it &other) const { return this->ptr > other.ptr; }
			bool operator>=(const rev_it &other) const { return this->ptr <= other.ptr; }
			bool operator<=(const rev_it &other) const { return this->ptr >= other.ptr; }
			bool operator==(const rev_it &other) const { return this->ptr == other.ptr; }
			bool operator!=(const rev_it &other) const { return this->ptr != other.ptr; }

			//maybe incorrect
			rev_it operator+(dif_type shift) const { return rev_it(this->ptr - shift); }
			rev_it operator-(dif_type shift) const { return rev_it(this->ptr + shift); }
			rev_it &operator+=(dif_type shift) const { this->ptr -= shift; return *this; }
			rev_it &operator-=(dif_type shift) const { this->ptr += shift; return *this; }
			T& operator[](dif_type index) const { return this->ptr[index]; } //

			dif_type operator-(rev_ranit other) const { return this->ptr - other.ptr; }
	};
}


// for iters
namespace diy {

	// distance btw iterators
	template<typename T>
	size_t iter_dist(T first, T last) {
		size_t dist = 0;
		for (dist = 0; first != last; dist++, first++);
		return dist;
	}
}

// for vecs
namespace diy
{
	// swap
	template <typename T>
	void swap(T &first, T &second) {
		T tmp = first;
		first = second;
		second = tmp;
	}

	// enable_if 
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// lexograf compare

}

namespace diy
{
	template <class InputIterator>
	bool	lexicographical_compare(InputIterator first1, InputIterator last1,
		InputIterator first2, InputIterator last2) {
		
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
#ifndef RAITR_HPP
#define RAITR_HPP

#include "iter.hpp" // need i?
#include "utils.hpp"

#include <iterator>

// povtorenit random acsees iterator in diy and in inits??
namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&,
		typename Category = std::random_access_iterator_tag> 
	class ranit {
		public:
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::random_access_iterator_tag	category;
			pointer									ptr;
			typedef ranit<T, Pointer, Reference>	it;
			typedef ranit<T, T*, T&>				iterator;
			typedef ranit<T, const T*, const T&>	const_iterator;

		public:
			ranit() : ptr(NULL) {}
			ranit(pointer input) : ptr(input) {}
			ranit(const iterator &other) { this->ptr = other.ptr; }
			it &operator=(const it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			~ranit() {}

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

			it operator+(dif_type shift) const { return it(this->ptr + shift); }
			it operator-(dif_type shift) const { return it(this->ptr - shift); }
			it &operator+=(dif_type shift) { this->ptr += shift; return *this; }
			it &operator-=(dif_type shift) { this->ptr -= shift; return *this; }
			T& operator[](dif_type index) const { return this->ptr[index]; }
			dif_type operator-(ranit other) const { return this->ptr - other.ptr; }
	};
}

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&,
		typename Category = std::random_access_iterator_tag> 
	class rev_ranit {
		public:

			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::random_access_iterator_tag	category;
			pointer	ptr;
			typedef rev_ranit<T, Pointer, Reference>	rev_it;
			typedef rev_ranit<T, T*, T&>				iterator;
			typedef rev_ranit<T, const T*, const T&>	const_iterator;

		public:
			rev_ranit() : ptr(NULL) {}
			rev_ranit(pointer input) { this->ptr = input; }
			rev_ranit(const iterator &other) { this->ptr = other.ptr; }

			rev_it &operator=(const rev_it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			
			~rev_ranit() {}
			
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

			rev_it operator+(dif_type shift) const { return rev_it(this->ptr - shift); }
			rev_it operator-(dif_type shift) const { return rev_it(this->ptr + shift); }
			rev_it &operator+=(dif_type shift) const { this->ptr -= shift; return *this; }
			rev_it &operator-=(dif_type shift) const { this->ptr += shift; return *this; }
			T& operator[](dif_type index) const { return this->ptr[index]; }
			dif_type operator-(rev_ranit other) const { return this->ptr - other.ptr; }
			iterator base() const { return this->ptr; }
	};
}

#endif

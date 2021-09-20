#ifndef BIDIT_HPP
#define BIDIT_HPP

#include "utils.hpp"

#include <iterator>

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&,
		typename Category = std::random_access_iterator_tag> 
	class bidit {
		public:
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::bidirectional_iterator_tag	category;
			pointer ptr;
			typedef bidit<T, Pointer, Reference>	it;
			typedef bidit<T, T*, T&>				iterator;
			typedef bidit<T, const T*, const T&>	const_iterator;
		
		public:
			bidit() : ptr(NULL) {}
			// bidit(pointer input) : ptr(input) {}



	};

// 		public:
// 			ranit(const iterator &other) { this->ptr = other.ptr; }

// 			it &operator=(const it &other) {
// 				if (this == &other)
// 					return *this;
// 				this->ptr = other.ptr;
// 				return *this;
// 			}
			
// 			~ranit() {}

// 			reference operator*() const { return *this->ptr; }
// 			pointer operator->() const { return this->ptr; }
			
// 			it &operator++() { ptr++; return *this; }
// 			it &operator--() { ptr--; return *this; }

// 			it operator++(int) {
// 				it tmp_it(*this);
// 				++(*this);
// 				return tmp_it; }

// 			it operator--(int) {
// 				it tmp_it(*this);
// 				--(*this);
// 				return tmp_it; }

// 			bool operator>(const it &other) const { return this->ptr > other.ptr; }
// 			bool operator<(const it &other) const { return this->ptr < other.ptr; }
// 			bool operator>=(const it &other) const { return this->ptr >= other.ptr; }
// 			bool operator<=(const it &other) const { return this->ptr <= other.ptr; }
// 			bool operator==(const it &other) const { return this->ptr == other.ptr; }
// 			bool operator!=(const it &other) const { return this->ptr != other.ptr; }

// 			it operator+(dif_type shift) const { return it(this->ptr + shift); }
// 			it operator-(dif_type shift) const { return it(this->ptr - shift); }
// 			it &operator+=(dif_type shift) { this->ptr += shift; return *this; }
// 			it &operator-=(dif_type shift) { this->ptr -= shift; return *this; }
// 			T& operator[](dif_type index) const { return this->ptr[index]; }
// 			dif_type operator-(ranit other) const { return this->ptr - other.ptr; }
// 	};
}

#endif
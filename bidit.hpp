#ifndef BIDIT_HPP
#define BIDIT_HPP

#include <iostream> // need i?

#include "rbtree.hpp"
#include "node.hpp"

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&>
	// typename Category = std::bidirectional_iterator_tag> 
	class bidit {
		public:
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::bidirectional_iterator_tag	category;

			typedef diy::node<T>					nd;
			typedef diy::node<T>*					ptr_nd;
			ptr_nd									ptr;
			typedef bidit<T, Pointer, Reference>	it;
			typedef bidit<T, T*, T&>				iterator;
			typedef bidit<T, const T*, const T&>	const_iterator;
				
		public:
			bidit() : ptr(NULL) {}
			bidit(ptr_nd input_node) : ptr(input_node) {}
			bidit(const bidit &other) { *this = other; }
			it &operator=(const it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			~bidit() {}

			reference operator*() const { return *ptr->value; } // add this
			pointer operator->() const { return ptr->value; } // add this
			pointer node() { return this->ptr; }
			ptr_nd base() const { return this->ptr; }

			it &operator++() {
				ptr_nd tmp;
				if (this->ptr->right) {
					this->ptr = this->ptr->right;
					while (this->ptr->left)
						this->ptr = this->ptr->left;
				} else {
					tmp = this->ptr->parent;
					for (; tmp && this->ptr == tmp->right; tmp = tmp->parent)
						this->ptr = tmp;
					// while(tmp && this->ptr == tmp->right) { // make for loop
					// 	this->ptr = tmp;
					// 	tmp = tmp->parent;
					// }
					this->ptr = this->ptr->parent;
				}
				return *this;
			}

			it operator++(int) {
				it tmp(*this);
				this->operator++();
				return tmp;
			};

			it operator--() {
				ptr_nd tmp;
				if (this->ptr->left) {
					this->ptr = this->ptr->left;
					while (this->ptr->right)
						this->ptr = this->ptr->right;
				} else {
					tmp = this->ptr->parent;
					for (;tmp && this->ptr == tmp->left; tmp = tmp->parent)
						this->ptr = tmp;

					// while (tmp && this->ptr == tmp->left)
					// {
					// 	this->ptr = tmp;
					// 	tmp = tmp->parent;
					// }
					this->ptr = this->ptr->parent;
				}
				return *this;
			}

			it operator--(int) {
				it tmp(*this);
				this->operator--();
				return tmp;
			}

			bool operator==(const it &other) const { return (this->ptr == other.ptr); }
			bool operator!=(const it &other) const { return !(*this == other); }
			bool operator>(const it &other) const { return (this->ptr > other.ptr); }
			bool operator<(const it &other) const {	return (this->ptr < other.ptr); }
			bool operator>=(const it &other) const { return (this->ptr >= other.ptr); }
			bool operator<=(const it &other) const { return (this->ptr <= other.ptr); }
	};
}
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

#endif
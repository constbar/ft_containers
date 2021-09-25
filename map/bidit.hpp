#ifndef BIDIT_HPP
#define BIDIT_HPP

// #include <iostream> // need i?

// #include "rbtree.hpp"
// #include "node.hpp"

// namespace diy {
// 	template <typename T, typename Pointer = T*, typename Reference = T&>
// 	// typename Category = std::bidirectional_iterator_tag> 
// 	class bidit {
// 		public:
// 			typedef Pointer			pointer;
// 			typedef Reference		reference;
// 			typedef typename std::ptrdiff_t						dif_type;
// 			typedef typename std::bidirectional_iterator_tag	category;

// 			typedef diy::node<T>					nd;
// 			typedef diy::node<T>*					ptr_nd;
// 			ptr_nd									ptr;
// 			typedef bidit<T, Pointer, Reference>	it;
// 			typedef bidit<T, T*, T&>				iterator;
// 			typedef bidit<T, const T*, const T&>	const_iterator;
				
// 		public:
// 			bidit() : ptr(NULL) {}
// 			bidit(ptr_nd input_node) : ptr(input_node) {}
// 			bidit(const bidit &other) { *this = other; }
// 			it &operator=(const it &other) {
// 				if (this == &other)
// 					return *this;
// 				this->ptr = other.ptr;
// 				return *this;
// 			}
// 			~bidit() {}

// 			reference operator*() const { return *ptr->value; } // add this
// 			pointer operator->() const { return ptr->value; } // add this
// 			pointer node() { return this->ptr; }
// 			ptr_nd base() const { return this->ptr; }

// 			it &operator++() {
// 				ptr_nd tmp;
// 				if (this->ptr->right) {
// 					this->ptr = this->ptr->right;
// 					while (this->ptr->left)
// 						this->ptr = this->ptr->left;
// 				} else {
// 					tmp = this->ptr->parent;
// 					for (; tmp && this->ptr == tmp->right; tmp = tmp->parent)
// 						this->ptr = tmp;
// 					// while(tmp && this->ptr == tmp->right) { // make for loop
// 					// 	this->ptr = tmp;
// 					// 	tmp = tmp->parent;
// 					// }
// 					this->ptr = this->ptr->parent;
// 				}
// 				return *this;
// 			}

// 			it operator++(int) {
// 				it tmp(*this);
// 				this->operator++();
// 				return tmp;
// 			};

// 			it operator--() {
// 				ptr_nd tmp;
// 				if (this->ptr->left) {
// 					this->ptr = this->ptr->left;
// 					while (this->ptr->right)
// 						this->ptr = this->ptr->right;
// 				} else {
// 					tmp = this->ptr->parent;
// 					for (;tmp && this->ptr == tmp->left; tmp = tmp->parent)
// 						this->ptr = tmp;

// 					// while (tmp && this->ptr == tmp->left)
// 					// {
// 					// 	this->ptr = tmp;
// 					// 	tmp = tmp->parent;
// 					// }
// 					this->ptr = this->ptr->parent;
// 				}
// 				return *this;
// 			}

// 			it operator--(int) {
// 				it tmp(*this);
// 				this->operator--();
// 				return tmp;
// 			}

// 			bool operator==(const it &other) const { return (this->ptr == other.ptr); }
// 			bool operator!=(const it &other) const { return !(*this == other); }
// 			bool operator>(const it &other) const { return (this->ptr > other.ptr); }
// 			bool operator<(const it &other) const {	return (this->ptr < other.ptr); }
// 			bool operator>=(const it &other) const { return (this->ptr >= other.ptr); }
// 			bool operator<=(const it &other) const { return (this->ptr <= other.ptr); }
// 	};
// }

#endif
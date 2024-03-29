#ifndef SETIT_HPP
#define SETIT_HPP

#include "snode.hpp"

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&>
	class setit {
		public:
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::bidirectional_iterator_tag	category;

			typedef diy::set_node<T>				nd;
			typedef diy::set_node<T>*				ptr_nd;
			ptr_nd									ptr;
			typedef setit<T, Pointer, Reference>	it;
			typedef setit<T, T*, T&>				iterator;
			typedef setit<T, const T*, const T&>	const_iterator;

		public:
			setit() : ptr(NULL) {}
			setit(ptr_nd input_node) : ptr(input_node) {}
			setit(const setit &other) { *this = other; }
			it &operator=(const it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			~setit() {}

			pointer set_node() { return this->ptr; }
			ptr_nd base() const { return this->ptr; }
			reference operator*() const { return *ptr->value; }
			pointer operator->() const { return ptr->value; }

			it &operator++() {
				ptr_nd tmp;
				if (this->ptr->right) {
					this->ptr = this->ptr->right;
					while (this->ptr->left)
						this->ptr = this->ptr->left;
				}
				else {
					tmp = this->ptr->parent;
					for (; tmp && this->ptr == tmp->right; tmp = tmp->parent)
						this->ptr = tmp;
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
				}
				else {
					tmp = this->ptr->parent;
					for (;tmp && this->ptr == tmp->left; tmp = tmp->parent)
						this->ptr = tmp;
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

namespace diy {
	template <typename T, typename Pointer = T*, typename Reference = T&>
	class rev_setit {
		public:
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef typename std::ptrdiff_t						dif_type;
			typedef typename std::bidirectional_iterator_tag	category;

			typedef diy::set_node<T>				nd;
			typedef diy::set_node<T>*				ptr_nd;
			ptr_nd									ptr;
			typedef rev_setit<T, Pointer, Reference>	it;
			typedef rev_setit<T, T*, T&>				iterator;
			typedef rev_setit<T, const T*, const T&>	const_iterator;

		public:
			rev_setit() : ptr(NULL) {}
			rev_setit(ptr_nd input_node) : ptr(input_node) {}
			rev_setit(const rev_setit &other) { *this = other; }
			it &operator=(const it &other) {
				if (this == &other)
					return *this;
				this->ptr = other.ptr;
				return *this;
			}
			~rev_setit() {}

			pointer set_node() { return this->ptr; }
			ptr_nd base() const { return this->ptr; }
			reference operator*() const { return *ptr->value; }
			pointer operator->() const { return ptr->value; }


			it operator++(int) {
				it tmp(*this);
				this->operator++();
				return tmp;
			};

			it &operator++() {
				ptr_nd tmp;
				if (this->ptr->left) {
					this->ptr = this->ptr->left;
					while (this->ptr->right)
						this->ptr = this->ptr->right;
				}
				else {
					tmp = this->ptr->parent;
					for (;tmp && this->ptr == tmp->left; tmp = tmp->parent)
						this->ptr = tmp;
					this->ptr = this->ptr->parent;
				}
				return *this;
			}

			it operator--(int) {
				it tmp(*this);
				this->operator--();
				return tmp;
			}

			it &operator--() {
				ptr_nd tmp;
				if (this->ptr->right) {
					this->ptr = this->ptr->right;
					while (this->ptr->left)
						this->ptr = this->ptr->left;
				}
				else {
					tmp = this->ptr->parent;
					for (; tmp && this->ptr == tmp->right; tmp = tmp->parent)
						this->ptr = tmp;
					this->ptr = this->ptr->parent;
				}
				return *this;
			}

			bool operator==(const it &other) const { return (this->ptr == other.ptr); }
			bool operator!=(const it &other) const { return !(*this == other); }
			bool operator>(const it &other) const { return (this->ptr > other.ptr); }
			bool operator<(const it &other) const {	return (this->ptr < other.ptr); }
			bool operator>=(const it &other) const { return (this->ptr >= other.ptr); }
			bool operator<=(const it &other) const { return (this->ptr <= other.ptr); }
	};
}

#endif

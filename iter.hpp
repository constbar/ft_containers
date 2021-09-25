#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

namespace diy {
	template <typename T>
	class bidit {
		public:
			typedef diy::tree_node<T>	node;
			node						*ptr;

		public:
			bidit() : ptr(NULL) {}
			bidit(node *other) { this->ptr = other; }
			bidit(bidit const &other) { *this = other; }
			bidit &operator=(bidit const &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return *this;
			}
			~bidit() {}

			node* get_ptr_iter() const { return this->ptr; }
			
			bool operator==(const bidit &other) const {
				if (other.ptr == this->ptr)
					return true;
				return false;
			}

			bool operator!=(const bidit &other) const { return !operator==(other); }
			T &operator*() { return *this->ptr->value; }
			T *operator->() { return this->ptr->value; }
			const T *operator->() const { return this->ptr->value; }

			bidit operator++() {
				if (this->ptr && this->ptr->next)
					this->ptr = this->ptr->next;
				return *this;
			}

			bidit operator++(int) {
				bidit ret_bidit = *this;
				if (this->ptr && this->ptr->next)
					this->ptr = this->ptr->next;
				return ret_bidit;
			}

			bidit &operator--() {
				if (this->ptr && this->ptr->prev)
					this->ptr = this->ptr->prev;
				return *this;
			}

			bidit operator--(int) {
				bidit ret_bidit = *this;
				if (this->ptr && this->ptr->prev)
					this->ptr = this->ptr->prev;
				return ret_bidit;
			}			
	};
}

namespace diy {
	template <typename T>
	class rev_bidit {
		public:
			typedef diy::tree_node<T>	node;
			node 						*ptr;

		public:
			rev_bidit() : ptr(NULL) {}
			rev_bidit(node *other) { this->ptr = other; }
			rev_bidit(rev_bidit const &other) { *this = other; }
			rev_bidit &operator=( rev_bidit const &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return *this;
			}
			~rev_bidit() {}

			bool operator==(const rev_bidit &other) const {
				if (other.ptr == this->ptr)
					return true;
				return false;
			}

			node *get_ptr_iter() const { return this->ptr; }
			T &operator*() { return (*this->ptr->value); }
			T *operator->() { return (this->ptr->value); }
			const T *operator->() const { return (this->ptr->value); }
			bool operator!=(const rev_bidit &other) const { return (!operator==(other)); }

			rev_bidit operator++() {
				if (this->ptr && this->ptr->prev)
					this->ptr = this->ptr->prev;
				return *this;
			}

			rev_bidit operator++(int) {
				rev_bidit ret_iter = *this;
				if (this->ptr && this->ptr->prev)
					this->ptr = this->ptr->prev;
				return ret_iter;
			}

			rev_bidit &operator--() {
				if (this->ptr && this->ptr->next)
					this->ptr = this->ptr->next;
				return *this;
			}

			rev_bidit operator--(int) {
				rev_bidit ret_iter = *this;
				if (this->ptr && this->ptr->next)
					this->ptr = this->ptr->next;
				return ret_iter;
			}
	};
}

#endif
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
			reference operator*() const { return *ptr->value; } // add this
			pointer operator->() const { return ptr->value; } // add this

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
			reference operator*() const { return *ptr->value; } // add this
			pointer operator->() const { return ptr->value; } // add this


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
				} else {
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
				} else {
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




// #include <iterator>
// #include <iostream>

// namespace diy {
// 	template <typename iterator, typename Pointer = iterator*, typename Reference = iterator&>
// 	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, iterator> {
// 	public:
// 		typedef iterator														iterator_type;
// 		typedef std::ptrdiff_t											difference_type;
// 		typedef iterator *pointer;
// 		typedef iterator &reference;
// 		// typedef typename diy::iterator_traits<iterator>::iterator_category		iterator_category;
// 		// typedef typename diy::iterator_traits<iterator>::value_type				value_type;
// 		// typedef typename diy::iterator_traits<iterator>::difference_type		difference_type;
// 		// typedef typename diy::iterator_traits<iterator>::pointer				pointer;
// 		// typedef typename diy::iterator_traits<iterator>::reference				reference;

// 		reverse_iterator() { this->_it = 0; }

// 		explicit reverse_iterator (iterator_type it) { this->_it = it; }

// 		template <class Iter>
// 		reverse_iterator(const reverse_iterator<Iter>& rev_it) { this->_it = rev_it; }

// 		template< class U > 
// 		reverse_iterator& operator=( const reverse_iterator<U>& other ) {
// 			if (*this != other)
// 				this->_it = other.getIterator();
// 			return *this;
// 		}

// 		iterator_type		base() const { return (_it); }
		
// 		reference 			operator*() { return *(--base()); }
// 		pointer 			operator->() {return &(operator*()); }

// 		reference 			operator[]( difference_type n ) const { return this->_it[n]; };
		
// 		reverse_iterator&	operator++() { --this->_it; return *this; }
// 		reverse_iterator&	operator--() { ++this->_it; return *this; }
// 		reverse_iterator	operator++(int) {reverse_iterator it(*this); --this->_it; return it; }
// 		reverse_iterator	operator--(int) {reverse_iterator it(*this); ++this->_it; return it; }
// 		reverse_iterator	operator+( difference_type n ) const { return reverse_iterator(this->_it - n); }
// 		reverse_iterator	operator-( difference_type n ) const { return reverse_iterator(this->_it + n); }
// 		reverse_iterator&	operator+=( difference_type n ) { return reverse_iterator(this->_it -= n); }
// 		reverse_iterator&	operator-=( difference_type n ) { return reverse_iterator(this->_it += n); }

// 		iterator_type		getIterator() const { return this->_it; }

// 	private:
// 		iterator_type _it;

// 	};

// 	template< class Iterator1, class Iterator2 >
// 	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs == rhs;
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs.base() != rhs.base();
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs.base() > rhs.base();
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs.base() >= rhs.base();
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs.base() < rhs.base();
// 	}

// 	template< class Iterator1, class Iterator2 >
// 	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
// 		return lhs.base() <= rhs.base();
// 	}

// 	template< class Iter > 
// 	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, 
// 	const reverse_iterator<Iter>& it ) {
// 		return reverse_iterator<Iter>(it - n);
// 	}

// 	template< class Iter > 
// 	reverse_iterator<Iter> operator-( typename reverse_iterator<Iter>::difference_type n, 
// 	const reverse_iterator<Iter>& it ) {
// 		return reverse_iterator<Iter>(it + n);
// 	}
// }

#endif

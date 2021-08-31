#ifndef VECTOR_HPP
#define VECTOR_HPP

// template <class T, class Allocator = std::allocator<T>>
// how to make const iter
// can make it faster with list prisvaivaniya
// 1. why vector is always explisit


#include "ranit.hpp"
#include <iostream>

namespace diy {
	template <typename T>
	class vector {

		public:

		public:
			typedef T					value_type;
			typedef T*					pointer;
			typedef T&					reference;
 			typedef std::ptrdiff_t		difference_type;
			typedef size_t				size_type;

			typedef typename diy::ranit<value_type>		iterator;
			typedef typename std::allocator<value_type>	allocator_type;

			// typedef const value_type &const_reference;
			// typedef const value_type *const_pointer;
			// typedef RandomAccessIterator<T, T *, T &> iterator;
			// typedef RandomAccessIterator<T, const T *, const T &> const_iterator;
			// typedef ReverseRAI<iterator> reverse_iterator;
			// typedef ReverseRAI<const_iterator> const_reverse_iterator;

		// private:
		public: // make it private
			pointer			ptr;
			size_type		size;
			size_type		capacity;
			allocator_type 	allocator;

		public:
 			vector(const allocator_type &alloc = allocator_type() ) {
				this->ptr = NULL; this->size = 0;
				this->capacity = 0;

				this->ptr = allocator.allocate(1); // del .allocate(0)
				this->allocator.construct(ptr, 12); // del
			}

			vector(size_t num, const T& val = T(),
				const allocator_type& alloc = allocator_type()) {
				this->ptr = NULL;
				this->size = num;
				this->capacity = num;
				this->allocator = alloc;


				// this->ptr = allocator.allocate(capacity);	
			}

			~vector() {
				// if (this->allocator)
					// this->allocator.deallocate(1);
					this->allocator.destroy(ptr);
					this->allocator.deallocate(this->ptr, 1);
			}

			// iterator begin() { return iterator(_vector); }
			iterator begin() {
				return iterator(ptr); // it was just return ar
			}

		// 	vector(size_t n, const value_type &val = value_type()) {
		// 		sz = 0;
		// 		cp = 0;
		// 		ar = NULL;
		// 	}

		// 	void reserve(size_t n) {

		// 		if (n < this->cp)
		// 			return;

		// 		T* newarr = new T[n];
		// 		for (size_t i = 0; i < this->sz; i++)
		// 			newarr[i] = this->ar[i];

		// 		delete [] this->ar;
		// 		this->ar = newarr;
		// 		this->cp = n;
		// 	}

		// 	void resize(size_t n, const T &value = T()) {

		// 		if (n > this->cp)
		// 			reserve(n);
				
		// 		for (size_t i = this->sz; i < n; i++)
		// 			this->ar[i] = value;

		// 		if (n < this->sz)
		// 			this->sz = n;
		// 	};

		// 	void push_back(const T &value) {
				
		// 		if (this->cp == this->sz)
		// 			reserve(2 * sz);
				
		// 		this->ar[sz] = value;
		// 		sz++;
		// 	}

		// 	void pop_back() {

		// 		this->sz--;
		// 	}

		// 	size_t size() const {

		// 		return this->sz;
		// 	}

		// 	size_t capacity() {

		// 		return this->cp;
		// 	}


			// my::iter ret() {

		// 	// 	return my::iter;
		// 	// }

		// 	// virtual	~Base();
	};

}

#endif

#ifndef VEC_HPP
#define VEC_HPP

// template <class T, class Allocator = std::allocator<T>>
// class vector;

/* 
	1. realise all methods
*/

#include "itr.hpp"
#include <iostream>


// namespace ft {
// 	template <class T>
// 	class random_access_iterator : 
// 	public std::iterator<ft::random_access_iterator_tag, T> {
// };
// }


namespace diy {
	
	template<typename T> // dont need it all
	class vector {

		private:
			T		*arr;
			size_t	sz;
			size_t	cp;

		public:
			
			vector() { // this

				sz = 0;
				cp = 0;
				arr = NULL;
			};

			void reserve(size_t n) {

				if (n < this->cp)
					return;

				T* newarr = new T[n];
				for (size_t i = 0; i < this->sz; i++)
					newarr[i] = this->arr[i];

				delete [] this->arr;
				this->arr = newarr;
				this->cp = n;
			}

			void resize(size_t n, const T &value = T()) {

				if (n > this->cp)
					reserve(n);
				
				for (size_t i = this->sz; i < n; i++)
					this->arr[i] = value;

				if (n < this->sz)
					this->sz = n;
			};

			void push_back(const T &value) {
				
				if (this->cp == this->sz)
					reserve(2 * sz);
				
				this->arr[sz] = value;
				sz++;
			}

			void pop_back() {

				this->sz--;
			}

			size_t size() const {

				return this->sz;
			}

			size_t capacity() {

				return this->cp;
			}

			// my::iter ret() {

			// 	return my::iter;
			// }

			// virtual	~Base();
	};

}

#endif

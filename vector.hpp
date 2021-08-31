#ifndef VECTOR_HPP
#define VECTOR_HPP

// template <class T, class Allocator = std::allocator<T>>
// how to make const iter
// can make it faster with list prisvaivaniya
// 1. why vector is always explisit


/**
    *
    * - Coplien form:
    * operator=:            Assign vector
    *	copy 
	* 
    * - Iterators:
    * rbegin:               Return reverse iterator to reverse beginning
    * rend:                 Return reverse iterator to reverse end
    * - Element access:
    * operator[]:           Access element
    * at:                   Access element
    * front:                Access first element
    * back:                 Access last element
    *
    * - Modifiers:
    * assign:               Assign vector content
    * insert:               Insert elements
    * erase:                Erase elements
    * swap:                 Swap content
    * clear:                Clear content
    *
    * - Non-member function overloads:
    * relational operators: Relational operators for vector
    * swap:                 Exchange contents of two vectors
    * ------------------------------------------------------------- *
    */


#include "ranit.hpp"
#include <iostream>

namespace diy {
	template <typename T>
	class vector {

		public:

		public:
			// typedef T					value_type;
			typedef T*					pointer;
			typedef T&					reference;
 			typedef std::ptrdiff_t		difference_type;
			// typedef size_t				size_type; // i dont need it 

			typedef typename diy::ranit<T>		iterator;
			typedef typename std::allocator<T>	allocator_type;

			// typedef const value_type &const_reference;
			// typedef const value_type *const_pointer;
			// typedef RandomAccessIterator<T, T *, T &> iterator;
			// typedef RandomAccessIterator<T, const T *, const T &> const_iterator;
			// typedef ReverseRAI<iterator> reverse_iterator;
			// typedef ReverseRAI<const_iterator> const_reverse_iterator;

		// private:
		public: // make it private
			pointer			v_ptr;
			size_t			v_size;
			size_t			v_capacity;
			allocator_type 	v_allocator;

		public:
			// invalid func
 			vector(const allocator_type &alloc = allocator_type() ) {
				this->v_ptr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;

				this->v_ptr = v_allocator.allocate(1); // del .allocate(0)
				this->v_allocator.construct(v_ptr, 12); // del
			}

			vector(const size_t input_num, const T &intput_val = T(),
				const allocator_type &alloc = allocator_type()) {
				
				this->v_ptr = NULL;
				this->v_size = input_num;
				this->v_capacity = input_num;

				this->v_allocator = alloc;
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);

				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&this->v_ptr[i], intput_val);
			}

			// idk what is it
			// here Range constructor, creates a vector with a size equal

			~vector() {

				for (size_t i = 0; i > this->v_size; i++) // was till capacity
					this->v_allocator.destroy(&this->v_ptr[i]);
				this->v_allocator.deallocate(this->v_ptr, this->v_capacity);
			}

			iterator begin() { return iterator(this->v_ptr); }
			// const begin
			iterator end() { return iterator(this->v_ptr + this->v_size); }
			// const end

			// make it private // i didnt test it yet
			void realloc(const size_t new_capacity) { // reserve? // added const
				
				pointer tmp = this->v_allocator.allocate(new_capacity); // can add here try catch 
				
				size_t old_size = this->v_size; //
				if (new_capacity < this->v_size) //
					this->v_size = new_capacity; //

				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&tmp[i], this->v_ptr[i]);

				// this->~vector();
				
				for (size_t i = 0; i < old_size; i++) //
					this->v_allocator.destroy(&this->v_ptr[i]); //
				this->v_allocator.deallocate(this->v_ptr, this->v_capacity); //

				this->v_capacity = new_capacity;
				this->v_ptr = tmp;
			}

			void reserve(const size_t input_num) { // added const

				if (input_num <= this->v_capacity)
					return;
				size_t m = std::max(input_num, this->v_capacity * 2);
				realloc(m);
			}
			
			void push_back(const T &input_val) {
				// maybe size + 1 > capacity or here maybe reserve instead realloc
				if (this->v_size == this->v_capacity) {
					if (!this->v_size)
						realloc(1);
					else
						realloc(this->v_capacity * 2);
				}
				this->v_allocator.construct(&this->v_ptr[this->v_size], input_val);
				this->v_size++;
			}

			size_t size() const { return this->v_size; }
			size_t capacity() const { return this->v_capacity; }
			bool empty() const { return !this->v_size; }
			size_t max_size() const { return this->v_allocator.max_size(); }
			
			void pop_back() {
				if (this->v_size) {
					this->v_allocator.destroy(&this->v_ptr[this->v_size - 1]);
					this->v_size--;
				}
			}

			void resize(const size_t num, T input_val = T()) { // added const
				// MAKE IT
			}
	};

}

#endif

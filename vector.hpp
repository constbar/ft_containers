#ifndef VECTOR_HPP
#define VECTOR_HPP

// template <class T, class Allocator = std::allocator<T>>
// how to make const iter
// can make it faster with list prisvaivaniya
// 1. why vector is always explisit
// 2. sprosit' pro try and catch
// 3. try and catchi before allocs
// 4. swap can live here
// 5. expicit for what

#include "ranit.hpp"
#include <iostream>

namespace diy {
	template <typename T>
	class vector {

		public:

		public:
			typedef T*				pointer;
			typedef T&				reference;
			typedef const T*		const_pointer;
			typedef const T&		const_reference;

 			typedef std::ptrdiff_t	difference_type;

			typedef typename std::allocator<T>					allocator_type;
			typedef typename diy::ranit<T, pointer, reference>	iterator;
			typedef typename diy::ranit<T, const T*, const T&>	const_iterator;
			// add reverse const and non-c

		public: // make it private
			pointer			v_ptr;
			size_t			v_size;
			size_t			v_capacity;
			allocator_type 	v_allocator;

		public:
			// invalid func
 			vector(const allocator_type &alloc = allocator_type()) {

				this->v_ptr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;
				this->v_allocator = alloc;
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
			// here Range construcor, creates a vector with a size equal

			~vector() {

				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.destroy(&this->v_ptr[i]);
				this->v_allocator.deallocate(this->v_ptr, this->v_capacity);
				this->v_ptr = NULL;
			}

			/// end of copliens form

			iterator begin() { 
				std::cout << "usual begin?\n";
				return iterator(this->v_ptr); }

			const_iterator begin() const { // unused
				std::cout << "const begin\n";
				return const_iterator(this->v_ptr); }

			iterator end() { return iterator(this->v_ptr + this->v_size); }
			const_iterator end() const { return const_iterator(this->v_ptr + this->v_size); }

			// make it private //
			void realloc(const size_t new_capacity) {
				
				pointer tmp = this->v_allocator.allocate(new_capacity); // can add here try catch 
				
				size_t old_size = this->v_size; //
				if (new_capacity < this->v_size) //
					this->v_size = new_capacity; //

				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&tmp[i], this->v_ptr[i]);

				// this->~vector(); // it was here but i dont belive in ~
				
				for (size_t i = 0; i < old_size; i++) //
					this->v_allocator.destroy(&this->v_ptr[i]); //
				this->v_allocator.deallocate(this->v_ptr, this->v_capacity); //

				this->v_capacity = new_capacity;
				this->v_ptr = tmp;
			}

			void reserve(size_t input_num) {

				if (input_num <= this->v_capacity)
					return;
				size_t m = std::max(input_num, this->v_capacity * 2);
				realloc(m);
			}
			
			void push_back(const T &input_val) {
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

			void resize(size_t input_num, T input_val = T()) {
				
				while (this->v_size > input_num)
					pop_back();
				if (input_num > this->v_capacity)
					reserve(input_num);
				while (input_num > this->v_size)
					push_back(input_val);
			}

			void clear() {
				while(this->v_size)
					pop_back();
			}
			
			void swap(vector &other) {
				diy::swap(this->v_ptr, other.v_ptr);
				diy::swap(this->v_size, other.v_size);
				diy::swap(this->v_capacity, other.v_capacity);
				diy::swap(this->v_allocator, other.v_allocator); }

			reference operator[] (size_t index) { return this->v_ptr[index]; }
			const_reference operator[] (size_t index) const { return this->v_ptr[index]; }

			reference at(size_t index) {
				if (index >= this->v_size)
					throw std::out_of_range("out of vector");
				return *(this->v_ptr + index); }

			const_reference at(size_t index) const {
				if (index >= this->v_size)
					throw std::out_of_range("out of vector");
				return *(this->v_ptr + index); }

			reference front() { return this->v_ptr[0]; }
			const_reference front() const { return this->v_ptr[0]; }

			reference back() { return this->v_ptr[this->v_size - 1]; }
			const_reference back() const { return this->v_ptr[this->v_size - 1]; }

			vector &operator=(const vector &other) {
				
				if (this == &other)
					return *this;

				this->~vector();

				// eto uslovie nichego ne vikinet
				try { this->v_ptr = this->v_allocator.allocate(other.v_capacity); }
				catch (std::exception &e) { throw std::length_error("no alloc"); }
				
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				
				for (size_t i = 0; i < this->v_size; ++i)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
				
				return *this;
			}

			vector (const vector &other) {
				
				this->v_ptr = NULL;
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				this->v_allocator = other.v_allocator;

				// need i this tryes?
				try { this->v_ptr = this->v_allocator.allocate(this->v_capacity); }
				catch(const std::exception &e) // make it cleaner
				{
					throw std::length_error("no alloc");
					std::cerr << e.what() << '\n'; // to del
				}
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
			}

			void assign(size_t input_num, const T &input_val) {
				clear();
				while(input_num) {
					push_back(input_val);
					input_num--; }}

			// iterator erase(const_iterator __position) {}
			// iterator erase const_iterator __first, const_iterator __last
	};
}

#endif

    // * rbegin:               
    // * rend:             


    // * assign:             
    // * insert:            
    // * erase:              
    // *
    // * relational operators?? wtf???: Relational operators for vector

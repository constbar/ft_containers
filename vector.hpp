#ifndef VECTOR_HPP
#define VECTOR_HPP

// can make it faster with list prisvaivaniya
// 1. why vector is always explisit
// 4. swap can live here
// 5. expicit for what
// 6. should iter be only with <1 param>
// 7. ENABLE IF
// 8. check all stuff with valgrind
// 9. you should implement iterator traits - where shold i use it?
// 10. make all funcs from subj - implement
// 11. need i push front

#include "ranit.hpp"
#include <iostream>
#include <iterator> // to del

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

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename diy::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = 0) {

				this->v_ptr = NULL;
				this->v_size = 0;
				this->v_capacity = 0;
				this->v_allocator = alloc;

				this->v_size = this->v_capacity = diy::iter_dist(first, last);
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);
				
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(this->v_ptr + i, *(first + i));
			}

			vector(const vector &other) { // copy?
				
				this->v_ptr = NULL;
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				this->v_allocator = other.v_allocator;

				// i deleted try here by the way
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);
				
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
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
				// std::cout << "usual begin?\n"; // to del
				return iterator(this->v_ptr); }

			const_iterator begin() const { // unused
				std::cout << "const begin\n";
				return const_iterator(this->v_ptr); }

			iterator end() { return iterator(this->v_ptr + this->v_size); }
			const_iterator end() const { return const_iterator(this->v_ptr + this->v_size); }

			// make it private //
			void realloc(const size_t new_capacity) {
				
				pointer tmp = this->v_allocator.allocate(new_capacity);
				
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

				// here was try and catch
				this->v_ptr = this->v_allocator.allocate(other.v_capacity);
				
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				
				for (size_t i = 0; i < this->v_size; ++i)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
				
				return *this;
			}

			void assign(size_t input_num, const T &input_val) {
				clear();
				while(input_num) {
					push_back(input_val);
					input_num--; }}
			
			
			//  assign with ENABLE IF!

			iterator erase(iterator first, iterator last) {
				
   				if (first == end())
					return first;
				if (first == last)
					return first;

				iterator tmp_it(last);
				size_t dist = diy::iter_dist(first, last);
				size_t i = 0;

				for (i = 0; last != this->end(); first++, last++, i++) { // del here
					// std::cout << v_ptr[i] << " it is adr of dest and constr " << &this->v_ptr[i];
					this->v_allocator.destroy(&this->v_ptr[i]);
					this->v_allocator.construct(&this->v_ptr[i], *last);
					// std::cout << " added instead " << v_ptr[i] << " val after";
					// std::cout << std::endl;
				}

				for (; i < this->v_size; i++) { // del here
					// std::cout << "val " << v_ptr[i] << " adr pure destroy " << &this->v_ptr[i] << std::endl;
					this->v_allocator.destroy(&this->v_ptr[i]);
				}

				this->v_size = this->v_size - dist;
				// std::cout << "	 		 " << this->v_ptr + dist + 1 << std::endl;
				// return this->v_ptr + dist;
				return tmp_it;
			}

			iterator erase(iterator input) {

				iterator tmp_it(input);
				size_t i = 0;
				for (i = 0; input != this->end() - 1; input++, i++) { // added this
					// std::cout << v_ptr[i] << " it is adr of dest and constr " << &this->v_ptr[i];
					this->v_allocator.destroy(&this->v_ptr[i]);
					this->v_allocator.construct(&this->v_ptr[i], this->v_ptr[i + 1]);
					// std::cout << " added instead " << v_ptr[i] << " val after";
					// std::cout << std::endl;
				}
				// std::cout << "at the end i deleted	 	 " << &v_ptr[i] << " and value " << v_ptr[i] << std::endl;
				this->v_allocator.destroy(&this->v_ptr[i]);
				this->v_size--;
				return tmp_it;
			}


			// iterator insert(iterator input_it, const T &input_value) {
			// 	iterator tmp_it(input_it);

				
			// 	// 1. realloc
			// 	// 2.  
			// }

				
			void insert(iterator input_it, size_t input_num, const T &input_value) {
				
				size_t		gap = diy::iter_dist(input_it, this->end());
				vector		tmp_vec(input_it, this->end());
				iterator	tmp_it = tmp_vec.begin();

				// std::cout << gap << std::endl;

				// test // good
				// for (diy::vector<int>::iterator it = tmp_vec.begin(); it != tmp_vec.end(); it++)
				// 	std::cout << "this is inside tmp " << *it << std::endl;

				this->v_size = this->v_size - gap;
				std::cout << "this->size " << this->v_size << std::endl;

				while (input_num) { // check it in comparison of orig vector
					this->v_allocator.destroy(&this->v_ptr[this->v_size]);
					// std::cout << "ind of val " << v_size << std::endl; // to del
					this->push_back(input_value);
					input_num--;

					// vvesti size_t i-toe
				}
				// + proshlij size 

				for (; tmp_it != tmp_vec.end(); tmp_it++)
					this->push_back(*tmp_it); // add destroy
				
				// i v etom cikle delitit' poka bil starij SIZE
			}
	};
}

#endif

	// * rbegin:			   
	// * rend:			 


	// * assign:			 
	// * insert:			
	// *
	// * relational operators?? wtf???: Relational operators for vector

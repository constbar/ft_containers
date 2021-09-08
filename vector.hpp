#ifndef VECTOR_HPP
#define VECTOR_HPP

// 1. why vector is always explisit
// 5. expicit for what
// 6. should iter be only with <1 param>
// 8. check all stuff with valgrind
// 10. make all funcs from subj - implement
// 12. make list of initilizition
// 13. relational operators?? wtf???: Relational operators for vector || non member funcs overload
// 14. iterators_traits, nado li ih ispol'zovat'?
// 15. reverse_iterator
// 17. is_integral // in TEmplate use plz craft func
// 19. std::pair 
// 20. std::make_pair, must be reimplemented
// 21. test all pair / make pair / rev traits
// 22. alloc inside of friendly funcs?
// 23. test if all funcs the same std::vector and diy::vector??
// 24. make list of initilizition
// 25. make test from subject
// 26. test all non meber funcs enable if and others

#include "ranit.hpp"
#include "utils.hpp"

#include <iostream>
// #include <iterator> // to del

namespace diy {
	template <typename T> // class Alloc = std::allocator<T> // add it in friendly funcs
	class vector {

		public:
			typedef T*				pointer;
			typedef T&				reference;
			typedef const T*		const_pointer;
			typedef const T&		const_reference;

 			typedef std::ptrdiff_t	difference_type;

			typedef typename std::allocator<T>						allocator_type;
			typedef typename diy::ranit<T, pointer, reference>		iterator;
			typedef typename diy::ranit<T, const T*, const T&>		const_iterator;
			typedef typename diy::rev_ranit<T, pointer, reference>	reverse_iterator;
			typedef typename diy::rev_ranit<T, const T*, const T&>	const_reverse_iterator;

		private:
			pointer			v_ptr;
			size_t			v_size;
			size_t			v_capacity;
			allocator_type 	v_allocator;

		public:
			// invalid func
 			explicit vector(const allocator_type &alloc = allocator_type()) :
				v_ptr(NULL),
				v_size(0),
				v_capacity(0),
				v_allocator(alloc) {}

			explicit vector(const size_t input_num, const T &intput_val = T(),
				const allocator_type &alloc = allocator_type()) : 
				v_ptr(NULL),
				v_size(input_num),
				v_capacity(input_num),
				v_allocator(alloc) {
				
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&this->v_ptr[i], intput_val);
			}

			template <typename InpIt>
			vector(InpIt first, InpIt last, const allocator_type &alloc = allocator_type(),
				typename diy::enable_if<!std::is_integral<InpIt>::value, InpIt>::type = 0) :
				v_ptr(NULL),
				v_size(0),
				v_capacity(0),
				v_allocator(alloc) {

				this->v_size = this->v_capacity = diy::iter_dist(first, last);
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(this->v_ptr + i, *(first + i));
			}

			vector(const vector &other) {
				this->v_ptr = NULL;
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				this->v_allocator = other.v_allocator;
				this->v_ptr = this->v_allocator.allocate(this->v_capacity);
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
			}

			vector &operator=(const vector &other) {
				if (this == &other)
					return *this;
				this->~vector();
				this->v_ptr = this->v_allocator.allocate(other.v_capacity);
				this->v_size = other.v_size;
				this->v_capacity = other.v_capacity;
				for (size_t i = 0; i < this->v_size; ++i)
					this->v_allocator.construct(&this->v_ptr[i], *(other.v_ptr + i));
				return *this;
			}

			~vector() {
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.destroy(&this->v_ptr[i]);
				this->v_allocator.deallocate(this->v_ptr, this->v_capacity);
				this->v_ptr = NULL;
			}

			iterator begin() { return iterator(this->v_ptr); } // works only this
			const_iterator begin() const { return const_iterator(this->v_ptr); }
			iterator end() { return iterator(this->v_ptr + this->v_size); }
			const_iterator end() const { return const_iterator(this->v_ptr + this->v_size); }

			reverse_iterator rbegin() { return reverse_iterator(this->v_ptr + this->v_size - 1); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->v_ptr + this->v_size - 1); }
			reverse_iterator rend() { return reverse_iterator(this->v_ptr - 1); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->v_ptr - 1); }
		
			reference front() { return this->v_ptr[0]; }
			const_reference front() const { return this->v_ptr[0]; }
			reference back() { return this->v_ptr[this->v_size - 1]; }
			const_reference back() const { return this->v_ptr[this->v_size - 1]; }

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

			void pop_back() {
				if (this->v_size) {
					this->v_allocator.destroy(&this->v_ptr[this->v_size - 1]);
					this->v_size--;
				}
			}

			size_t size() const { return this->v_size; }
			size_t capacity() const { return this->v_capacity; }
			bool empty() const { return !this->v_size; }
			size_t max_size() const { return this->v_allocator.max_size(); }
			
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

			void assign(size_t input_num, const T &input_val) {
				clear();
				while(input_num) {
					push_back(input_val);
					input_num--; }}
			
			template <typename InpIt>
			void assign(InpIt first, InpIt last,
				typename diy::enable_if<!std::is_integral<InpIt>::value >::type* = 0) {
			
				size_t dist = diy::iter_dist(first, last);	
				for (size_t i = 0; i < this->v_size; i++)
					this->v_allocator.destroy(this->v_ptr + i);
				if (dist > this->v_capacity) {
					this->v_allocator.deallocate(this->v_ptr, this->v_capacity);
					this->v_ptr = this->v_allocator.allocate(dist);
					this->v_capacity = dist;
				}
				for (size_t i = 0; i < dist; i++)
					this->v_allocator.construct(this->v_ptr + i, *(first + i));
				this->v_size = dist;
			}

			iterator erase(iterator first, iterator last) {
   				if (first == this->end())
					return first;
				if (first == last)
					return first;

				iterator tmp_it(last);
				size_t start_id = this->v_size - diy::iter_dist(first, this->end());
				
				size_t dist = diy::iter_dist(first, last);
				// std::cout << "dist f to l " << dist << std::endl;

				size_t i = start_id;
				for (; last != this->end(); first++, last++, i++) { // del here
				// 	// std::cout << v_ptr[i] << " it is adr of dest and constr " << &this->v_ptr[i];
					this->v_allocator.destroy(&this->v_ptr[i]);
					this->v_allocator.construct(&this->v_ptr[i], *last);
				// 	// std::cout << " added instead " << v_ptr[i] << " val after";
				// 	// std::cout << std::endl;
				}
				size_t last_id =  i + start_id;
				// std::cout << "index of last " << last_id << std::endl;
				// std::cout << "how much shoul i move till end " << this->v_size - last_id << std::endl;
				
				for (; last_id < this->size(); last_id++) { // del here
					std::cout << "val and id " << last_id << " " << v_ptr[last_id] << " adr pure destroy " << &this->v_ptr[last_id] << std::endl;
					this->v_allocator.destroy(&this->v_ptr[last_id]);
				}

				this->v_size = this->v_size - dist;
				// // std::cout << "	 		 " << this->v_ptr + dist + 1 << std::endl;
				// // return this->v_ptr + dist;
				return tmp_it;
			}

			iterator erase(iterator input) { return erase(input, input + 1); }

			void insert(iterator input_it, size_t input_num, const T &input_value) {

				size_t		dist = diy::iter_dist(input_it, this->end());
				vector		tmp_vc(input_it, this->end());
				iterator	tmp_it = tmp_vc.begin();

				// std::cout << "size of DIST-begin to end\t" << dist << std::endl; // to del

				// // test // good // inside tmp
				// for (diy::vector<int>::iterator it = tmp_vc.begin(); it != tmp_vc.end(); it++)
				// 	std::cout << "this is inside tmp " << *it << std::endl;

				size_t indx_of_begin = this->v_size = this->v_size - dist;

				// std::cout << "this->size " << this->v_size << std::endl; // to del
				// std::cout << "dist size " << dist << std::endl; // to del
				// std::cout << "index of begggiiiiiin\t\t" << indx_of_begin << std::endl; // to del

				// // destroy dolzhen bit' s nachala this->ptr + sdig do kona vsego massiva
				// std::cout << "\n";
				for (size_t i = 0; i < dist; i++) {
					// std::cout << "adr of destr " << &this->v_ptr[indx_of_begin + i]; // del test
					// std::cout << " and val  " << this->v_ptr[indx_of_begin + i] << std::endl; // del test
					this->v_allocator.destroy(&this->v_ptr[indx_of_begin + i]);
				}

				while (input_num) {
					// std::cout << "ind of val " << v_size << std::endl; // to del
					this->push_back(input_value);
					input_num--;
				}

				for (; tmp_it != tmp_vc.end(); tmp_it++)
					this->push_back(*tmp_it);
				// return; // here leak
			}

			iterator insert(iterator input_it, const T &input_value) {
			
				difference_type ind = input_it - this->begin();
				// std::cout << "its a ind " << ind << std::endl;
				insert(input_it, 1, input_value);
				iterator tmp_it(&this->v_ptr[ind]);
				return tmp_it;
			}

			template <typename InpIt> // remade this integral
			void insert(iterator pos, InpIt first, InpIt last,
				typename diy::enable_if<!std::is_integral<InpIt>::value >::type* = 0) {
				
				vector		tmp_vc(pos, this->end());
				iterator	tmp_it = tmp_vc.begin();
				
				size_t dist_dst = diy::iter_dist(pos, this->end());
				// std::cout << "dist_dst till end " << dist_dst << std::endl; //  !! neceseaary

				size_t indx = this->v_size - dist_dst;
				// std::cout << "index of pos " << indx << std::endl;

				this->v_size = this->v_size - dist_dst;

				// std::cout << "\nneed to clean:" << std::endl;
				for (size_t i = 0; i < dist_dst; i++) {
					// std::cout << "val of delete " << this->v_ptr[indx + i]  << " and adrr ";
					// std::cout << &this->v_ptr[indx + i] << std::endl;
					this->v_allocator.destroy(&this->v_ptr[indx + i]);
				}

				for (; first != last; first++)
					this->push_back(*first);

				for (; tmp_it != tmp_vc.end(); tmp_it++)
					this->push_back(*tmp_it);
			}

		private:
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
	};
}

namespace diy {
	
	template <typename T>
	void swap(const diy::vector<T> &lv, const diy::vector<T> &rv) { lv.swap(rv); }

	template <typename T>
	bool operator==(const diy::vector<T> &lv, const diy::vector<T> &rv) {
		return lv.size() == rv.size() && diy::equal(lv.begin(), lv.end(), rv.begin());
	}

	template <typename T>
	bool operator<(const diy::vector<T> &lv, const diy::vector<T> &rv) {
		return diy::lexicographical_compare(lv.begin(), lv.end(), rv.begin(), rv.end());
	}
	
	template <typename T>
	bool operator!=(const diy::vector<T> &lv, const diy::vector<T> &rv) { return !(lv == rv); }

	template <typename T>
	bool operator>=(const diy::vector<T> &lv, const diy::vector<T> &rv) { return !(lv < rv); }

	template <typename T>
	bool operator<=(const diy::vector<T> &lv, const diy::vector<T> &rv) { return !(rv < lv); }

	template <typename T>
	bool operator>(const diy::vector<T> &lv, const diy::vector<T> &rv) { return rv < lv; }
}

#endif

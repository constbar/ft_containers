#ifndef ITR_HPP
#define ITR_HPP

#include <iterator>

namespace diy {

	// template <class Category, class T, class Distance = ptrdiff_t,
			//   class Pointer = T *, class Reference = T &>
	template <typename T, typename pointer = T*, // vse deault paramets should be at the end // vse ok // NINE!! we could not refer by the ::
		typename reference = T&> // maybe will be error because v nasledovanii est' opredelennaya posledovatel'nost' v structure
	//  : public std::iterator<std::random_access_iterator_tag, T> // hotya mi v template oboznachaem, a peredaem v nasledovanii
	class iter { //ranit

		private:
			pointer ptr_iter; // rename

		public:
			// typedef T *pointer;
			// typedef T &reference;

			iter() : ptr_iter(NULL) { // speed of exec
				std::cout << "ptr null const" << std::endl; }

			iter(pointer input) {
				this->ptr_iter = input;
				std::cout << "ptr const with arg" << std::endl; }

			iter(const iter &other) {
				this->ptr_iter = other.ptr_iter;
				std::cout << "copy constr" << std::endl; }

			iter &operator=(const iter &other) {
				if (this == &other) return *this;
				this->ptr_iter = other.ptr_iter;
				return *this; }

			~iter() {} // virtual

			reference operator*() const {
				std::cout << "ref in work" << std::endl;
				return *this->ptr_iter; }

	};
}

#endif

// template <typename _Iterator>
// class reverse_iterator
	// : public iterator<typename iterator_traits<_Iterator>::iterator_category,
	// 				  typename iterator_traits<_Iterator>::value_type,
	// 				  typename iterator_traits<_Iterator>::difference_type,
	// 				  typename iterator_traits<_Iterator>::pointer,
	// 				  typename iterator_traits<_Iterator>::reference>
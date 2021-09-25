#ifndef ITER_HPP
#define ITER_HPP

#include <iterator>
#include <iostream>

namespace diy {

	// class ranit_tag {}; //random access iterator // or struct

	// template < typename C, typename T,
	// 	typename D = std::ptrdiff_t,
	// 	typename P = T*, typename R = T& >
	// struct iterator {
	// 	typedef C iterator_category;
	// 	typedef T value_type;
	// 	typedef D difference_type;
	// 	typedef P pointer;
	// 	typedef R reference;
	// };

	// template <typename iiterator>
	// struct iterator_traits {
	// 	typedef typename iiterator::iterator_category	iterator_category;
	// 	typedef typename iiterator::value_type			value_type;
	// 	typedef typename iiterator::difference_type		difference_type;
	// 	typedef typename iiterator::pointer				pointer;
	// 	typedef typename iiterator::reference			reference;
	// };

// template <typename _Tp> // this iterator traits dlya pointers // implement of usual iter_traits with iter_categori
// struct iiterator_traits<_Tp *>
// { // iiterator_traits<int*>::pointer kek; // it will work as pointer
// 	typedef std::random_access_iterator_tag		iterator_category;
// 	typedef _Tp 								value_type;
// 	typedef std::ptrdiff_t 						difference_type;
// 	typedef _Tp *								pointer;
// 	typedef _Tp &								reference;
// };

// /// Partial specialization for const pointer types.
// template <typename _Tp> // for const type
// struct iiterator_traits<const _Tp *>
// { // iiterator_traits<const int*>::iterator_category kek;
// 	typedef std::random_access_iterator_tag		iterator_category;
// 	typedef _Tp									value_type;
// 	typedef std::ptrdiff_t						difference_type;
// 	typedef const _Tp *							pointer;
// 	typedef const _Tp &							reference;
// };
}
#endif
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace diy {
	template<typename T>
	size_t iter_dist(T first, T last) {
		size_t dist = 0;
		for (dist = 0; first != last; dist++, first++);
		return dist;
	}
}

namespace diy {
	template <typename T>
	void swap(T &first, T &second) {
		T tmp = first;
		first = second;
		second = tmp;
	}
}

namespace diy {
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

namespace diy {
	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2) {
		
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
}

namespace diy {
	template <typename InputIterator1, typename InputIterator2>
		bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
			while (first1 != last1) {
				if (!(*first1 == *first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}
}

namespace diy {
	template <typename T>
	struct is_integral {
		static const bool value;
		typedef std::integral_constant<bool, value> type;
	};
}

namespace diy {
	template <typename Arg1, typename Arg2, typename Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <typename T>
	struct less : binary_function<T, T, bool> {
		bool operator()(const T &x, const T &y) const {
			return (x < y);
		}
	};

	template <typename iterator>
	class iterator_traits {
		public:
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;
	};

	template <typename T>
	class iterator_traits<T*> {
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	class iterator_traits<const T *> {
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
}


namespace diy {
	template <typename T1, typename T2>
	class pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() :
				first(),
				second() {}

			template <typename U, typename V>
			pair(const pair<U, V> &pr) :
				first(pr.first),
				second(pr.second) {}

			pair(const first_type &a, const second_type &b) :
				first(a),
				second(b) {}

			pair &operator=(const pair &pr) {
				if (*this == pr)
					return (*this);
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			}
	};

	template <typename T1, typename T2>
	bool operator==(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T1, typename T2>
	bool operator!=(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator>(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return (rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>=(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}

	template <typename T1, typename T2>
	bool operator<(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <typename T1, typename T2>
	bool operator<=(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <typename T1, typename T2>
	diy::pair<T1, T2> make_pair(T1 x, T2 y) {
		return diy::pair<T1, T2>(x, y);
	}
}

#endif
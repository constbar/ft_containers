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

namespace diy { // std::less
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const {
			return (x < y);
		}
	};
}

#endif
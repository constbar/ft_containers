#ifndef PAIR_HPP
#define PAIR_HPP

#include "utils.hpp"

#include <iostream>

namespace diy {
	template <typename T1, typename T2>
	struct pair {
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
	bool operator<(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <typename T1, typename T2>
	bool operator<=(const diy::pair<T1, T2> &lhs, const diy::pair<T1, T2> &rhs) {
		return !(rhs < lhs);
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
	diy::pair<T1, T2> make_pair(T1 x, T2 y) {
		return diy::pair<T1, T2>(x, y);
	}
}

#endif
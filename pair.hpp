#ifndef PAIR_HPP
#define PAIR_HPP

#include "utils.hpp"

#include <iostream>

namespace diy {
	template <typename T1, typename T2>
	class pair {
		public:
			T1 first;
			T2 second;

		public:
			pair() : first(), second() {}
			pair(const T1 &a, const T2 &b) : first(a), second(b) {}
			~pair() {}

			template <typename U1, typename U2>
			pair(const pair<U1, U2> &input_pair) { *this = input_pair; }

			pair &operator=(const pair &other) {
				if (this == &other)
					return *this;
				this->first = other.first;
				this->second = other.second;
				return *this;
			}
	};

	template <typename T1, typename T2> 
	pair<T1, T2> make_pair(const T1 &a, const T2& b) {
		return pair<T1, T2>(a, b);
	}

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &a, const pair<T1, T2> &b) {
		return a.first == b.first && a.second == b.second;
	}
	
	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &a, const pair<T1, T2> &b) {
		return !(a == b);
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &a, const pair<T1, T2> &b) {
		return (a.first < b.first) || !(b.first < a.first && a.second < b.second);
	}
	
	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2> &a, const pair<T1,T2> &b) {
		return b < a;
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& a, const pair<T1, T2>& b) {
		return !(b < a);
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& a, const pair<T1, T2>& b) {
		return !(a < b);
	}
}

#endif
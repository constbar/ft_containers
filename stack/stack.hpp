#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp" // vidimo ne nado
// #include "../vector/ranit.hpp" // dont need

#include <iostream>
#include <iterator>

namespace diy {
	template <typename T, typename Container = diy::vector<T> >
	class stack {
		private:
			Container c;

		public:
			explicit stack(const Container &input = Container()) { this->c = input; }
			stack(const stack &other) { this->c = other.c; }
			stack &operator=(const stack &other) {
				if (this == &other)
					return *this;
				stack tmp(other);
				diy::swap(this->c, tmp.c);
				return *this;
			}
			~stack(){};
			
			void		push(const T &value) { c.push_back(value); }
			T			&top() { return c.back(); }
			const T		&top() const { return c.back(); }
			void		pop() { c.pop_back(); }
			size_t		size() const { return c.size(); }
			bool		empty() const { return c.empty(); }
			Container	get_c() const { return c; }
	};

	template <typename T>
	bool operator<(const stack<T> &s1, const stack<T> &s2) {return s1.get_c() < s2.get_c(); }

	template <typename T>
	bool operator>(const stack<T> &s1, const stack<T> &s2) {return s1.get_c() > s2.get_c(); }

	template <typename T>
	bool operator<=(const stack<T> &s1, const stack<T> &s2) {return s1.get_c() <= s2.get_c(); }

	template <typename T>
	bool operator>=(const stack<T> &s1, const stack<T> &s2) {return s1.get_c() >= s2.get_c(); }

	template <typename T>
	bool operator==(const stack<T> &s1, const stack<T> &s2) { return s1.get_c() == s2.get_c(); }

	template <typename T>
	bool operator!=(const stack<T> &s1, const stack<T> &s2) { return !(s1.get_c() == s2.get_c()); }
}

#endif
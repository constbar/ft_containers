#ifndef SNODE_HPP
#define SNODE_HPP

namespace diy {
	template <typename T>
	class set_node {
		public:
			char		color;
			T			*value;
			set_node	*left;
			set_node	*right;
			set_node	*parent;

		private:
			set_node() :
				color('r'),
				value(NULL),
				left(NULL),
				right(NULL),
				parent(NULL) {}

		public:
			explicit set_node(T *input_value) :
				color('r'),
				value(input_value),
				left(NULL),
				right(NULL),
				parent(NULL) {}

			set_node(const set_node &other) { *this = other; }

			set_node &operator=(const set_node &other) {
				if (this == &other)
					return *this;
				this->color = other.color;
				this->value = other.value;
				this->left = other.left;
				this->right = other.right;
				this->parent = other.parent;
				return *this;
			}

			~set_node() {}
	};
}

#endif
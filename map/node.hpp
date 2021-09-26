#ifndef NODE_HPP
#define NODE_HPP

namespace diy {
	template <typename T>
	class map_node {
		public:
			map_node	*prev;
			map_node	*next;
			map_node	*left;
			map_node	*right;
			T			*value;
		
		map_node() :
			prev(NULL),
			next(NULL),
			left(NULL),
			right(NULL),
			value(NULL) {}

			map_node(const map_node &other) { *this = other; }

			map_node &operator=(const map_node &other) {
				if (this == &other)
					return *this;
				this->prev = other.prev;
				this->next = other.next;
				this->left = other.left;
				this->right = other.right;
				this->value = other.value;
				return *this;
			}

			~map_node() {}
	};
}

#endif

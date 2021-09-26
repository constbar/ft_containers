#ifndef NODE_HPP
#define NODE_HPP

// #include "rbtree.hpp"
// #include "bidit.hpp"

namespace diy {
	template <typename T>
	struct tree_node {
		public:
			tree_node	*prev;
			tree_node	*next;
			tree_node	*left;
			tree_node	*right;
			T			*value;
		
		tree_node() :
			prev(NULL),
			next(NULL),
			left(NULL),
			right(NULL),
			value(NULL) {}

			tree_node(const tree_node &other) { *this = other; }

			tree_node &operator=(const tree_node &other) {
				if (this == &other)
					return *this;
				this->prev = other.prev;
				this->next = other.next;
				this->left = other.left;
				this->right = other.right;
				this->value = other.value;
				return *this;
			}

			~tree_node() {}
	};
}

#endif

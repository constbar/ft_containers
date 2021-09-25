// #ifndef NODE_HPP
// #define NODE_HPP

// #include <iostream> // need i?

// #include "rbtree.hpp"
// #include "bidit.hpp"

// namespace diy {
// 		template <typename T>
// 		struct node
// 		{
// 			T *value;
// 			bool color;
// 			node *left;
// 			node *right;
// 			node *parent;

// 			node(T *value)
// 			{
// 				this->value = value;
// 				left = right = parent = NULL;
// 				this->color = true;
// 			}
// 		};

// 	// template <typename T>
// 	// class node {
// 	// 	public:
// 	// 		char	color;
// 	// 		T		*value;
// 	// 		node	*left;
// 	// 		node	*right;
// 	// 		node	*parent;

// 	// 	private:
// 	// 		node() :
// 	// 			color('r'),
// 	// 			value(NULL),
// 	// 			left(NULL),
// 	// 			right(NULL),
// 	// 			parent(NULL) {}
		
// 	// 	public:
// 	// 		explicit node(T *input_value) :
// 	// 			color('r'),
// 	// 			value(input_value),
// 	// 			left(NULL),
// 	// 			right(NULL),
// 	// 			parent(NULL) {}
			
// 	// 		node(const node &other) { *this = other; }
			
// 	// 		node &operator=(const node &other) {
// 	// 			if (this == &other)
// 	// 				return *this;
// 	// 			this->color = other.color;
// 	// 			this->value = other.value;
// 	// 			this->left = other.left;
// 	// 			this->right = other.right;
// 	// 			this->parent = other.parent;
// 	// 			return *this;
// 	// 		}

// 	// 		~node() {}
// 	// };
// }

// #endif

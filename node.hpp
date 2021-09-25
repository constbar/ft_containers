#ifndef NODE_HPP
#define NODE_HPP

namespace diy {
	template <class T>
	struct tree_node {
		tree_node *prev;
		tree_node *next;
		tree_node *right;
		tree_node *left;
		T *ptr;
	};

// 	template <typename T>
// 	struct maillon {
// 		T		*value;
// 		bool	color; // char // 
// 		maillon	*left;
// 		maillon	*right;
// 		maillon	*parent;
// 		maillon	*next;
// 		T *ptr; // wtf?
// 		maillon	*prev; // wtf?

// 		maillon(T *input_value) :
// 			value(input_value),
// 			color(true),
// 			left(NULL),
// 			right(NULL),
// 			parent(NULL),
// 			next(NULL) {} // ??
// 	};
}
#endif
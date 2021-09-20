#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>

namespace diy {
	// template <typename T>
	template <typename K, typename V>
	class tree {
			
		class node {
			public:
				char	color;
				K key;
				V val;
				node	*left;
				node	*right;
				node	*parent;

				bool isLeftChild;
				bool black;

			public:
				node(K key, V val) {
					this->key = key;
					this->val = val;
					left = right = parent = NULL; // add this->
					black = false;
					isLeftChild = false;
				}
		};

		public:
			node		*root;
			int			size;

		private:
			void add(node parent, node new_node) {

			}
		public:
			void add(K key, V val) {
				node *n = new node(key, val);
				if (root == NULL) {
					std::cout << "root is null" << std::endl;
					root = n;
					root->black = true;
					this->size++;
					return;
				}
				add(root, n);
				this->size++;
			}


	};
}

#endif
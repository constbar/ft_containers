#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream> // need i?

#include "bidit.hpp"
#include "utils.hpp"
#include "pair.hpp"
#include "node.hpp"
#include "ranit.hpp"

namespace diy {
	template <typename T, typename P, typename Rs>
	class bidit;
}

namespace diy {
	template <typename T>
	class rbtree {
		
		public:
			typedef T*				pointer;
			typedef T&				reference;
			typedef const T*		const_pointer;
			typedef const T&		const_reference;
			typedef std::ptrdiff_t	difference_type;

			typedef diy::node<T>				nd;
			typedef diy::node<T>*				ptr_nd;
			typedef diy::less<T>				comparator;
			typedef typename std::allocator<T>	tree_allocator;
			typedef typename std::allocator<nd>	node_allocator;

			typedef typename diy::bidit<T, pointer, reference>		iterator;
			typedef typename diy::bidit<T, const T*, const T&>		const_iterator;
			typedef typename diy::rev_ranit<T, pointer, reference>	reverse_iterator;
			typedef typename diy::rev_ranit<T, const T*, const T&>	const_reverse_iterator;

		private:
			ptr_nd			root;
			ptr_nd			last;
			size_t			size;
			comparator		comp;
			tree_allocator	talloc;
			node_allocator	nalloc;
	
		public:
			explicit rbtree(const comparator comp = comparator(), // &comp
				const tree_allocator &talloc = tree_allocator(),
				const node_allocator &nalloc = node_allocator()) :
					root(NULL),
					last(NULL),
					size(0),
					comp(comp),
					talloc(talloc),
					nalloc(nalloc) {
				this->last = this->nalloc.allocate(1);
				this->nalloc.construct(this->last, nd(NULL));
			}

			template <class InputIterator>
			rbtree(InputIterator first_iter, InputIterator last_iter,
				const comparator comp = comparator(),
				const tree_allocator &talloc = tree_allocator(),
				const node_allocator &nalloc = node_allocator()) :
					root(NULL),
					last(NULL),
					size(0),
					comp(comp),
					talloc(talloc),
					nalloc(nalloc) {
				this->last = this->nalloc.allocate(1);
				this->nalloc.construct(this->last, nd(NULL));
				insert(first_iter, last_iter);
			}

			rbtree &operator=(const rbtree &other) {
			 	if (this == &other)
				 	return *this;
				this->clear();
				this->root = other.root;
				this->last = other.last;
				this->size = other.size;
				this->comp = other.comp;
				this->talloc = other.talloc;
				this->nalloc = other.nalloc;
				insert(other.begin(), other.end());
				return *this;
			}

			rbtree(const rbtree &other) {
				this->clear();
				this->root = other.root;
				this->last = other.last;
				this->size = other.size;
				this->comp = other.comp;
				this->talloc = other.talloc;
				this->nalloc = other.nalloc;
				this->last = this->nalloc.allocate(1);
				this->nalloc.construct(this->last, nd(NULL));
				insert(other.begin(), other.end());
			}

			~rbtree() {
				if (this->size == 0)
					return;
				this->size = 0;
				destoy_node(this->root);
				this->root = NULL;
			}

			iterator begin() {
				if (this->root == NULL || this->size == 0)
					return iterator(this->last);
				else {
					ptr_nd tmp_ptr = this->root;
					while (tmp_ptr->left)
						tmp_ptr = tmp_ptr->left;
					return iterator(tmp_ptr);
				}
			}

			const_iterator begin() const {
				if (this->root == NULL || this->size == 0)
					return const_iterator(this->last);
				else {
					ptr_nd tmp_ptr = this->root;
					while (tmp_ptr->left)
						tmp_ptr = tmp_ptr->left;
					return const_iterator(tmp_ptr);
				}
			}


			bool empty() const {
				if (this->size == 0)
					return true;
				return false;
			}


			size_t size_tree() const { return this->size; }
			comparator value_comp() const { return this->comp; }
			size_t max_size() const { return this->talloc.max_size(); } // check it!
			tree_allocator get_allocator() const { return this->talloc; }

			iterator		end() { return iterator(this->last); }
			const_iterator	end() const { return const_iterator(this->last); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			diy::pair<iterator, bool> insert(const T &input_value) { // why bool? // adding only 1 val without key?
				if (this->root)
					this->root->parent = NULL;

				// creating node with input_value inside
				pointer new_value = this->talloc.allocate(1);
				this->talloc.construct(new_value, input_value);
				ptr_nd new_node = this->nalloc.allocate(1);
				this->nalloc.construct(new_node, nd(new_value));

				// pointing root to new_node
				if (this->root == NULL) {
					null_root(new_node);
					diy::pair<iterator, bool> ret_it;
					ret_it = diy::make_pair(iterator(this->root), true);
					return ret_it;
				}

				// looking for a place for input_value
				ptr_nd tree_step = this->root;
				ptr_nd val_place = NULL;
				while (tree_step) {
					val_place = tree_step;
					if (this->comp(*tree_step->value, input_value))
						tree_step = val_place->right;
					else
						tree_step = val_place->left;
				}

				// here check if its works with same // using comparators
				if (*val_place->value == input_value) {
					destoy_node(new_node);
					this->root->parent = this->last;
					this->last->left = this->root;
					diy::pair<iterator, bool> ret_d;
					ret_d = diy::make_pair(iterator(val_place), false);
					return ret_d;
				}
				attach_node(val_place, input_value, new_node);
				check_violations(new_node);

				this->root->parent = this->last;
				this->last->left = this->root;
				diy::pair<iterator, bool> ret_end;
				ret_end = diy::make_pair(iterator(new_node), true);
				return ret_end;
			}

			iterator insert(iterator pos, const T &input_value) {
				// (void)pos; 										// remake
				return insert(input_value).first;
			}

			template <class InputIterator> // other
			// typename ft::enable_if<ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) 
			void insert(InputIterator first_iter, InputIterator last_iter) {
				while (first_iter != last_iter) {
					insert(*first_iter);
					first_iter++;
				}
			}

			void erase(iterator pos) { // other
				destoy_node(pos.node());
				this->size--;
			}

			size_t erase(const T &input_value) {
				if (this->root == NULL)
					return 0;
				iterator tmp_iter;
				tmp_iter = find(input_value);
				if (tmp_iter == end())
					return 0;
				if (input_value == *tmp_iter) {
					erase(tmp_iter);
					return 1;
				}
				return 0;
			}

			void erase(iterator first_iter, iterator last_iter) {
				while (first_iter != last_iter)
					erase(first_iter++);
			}

			iterator find(T input_value) {
				ptr_nd tmp_ptr_nd = find_in_tree(input_value);

				if (!this->comp(*tmp_ptr_nd->value, input_value) &&
				!this->comp(input_value, *tmp_ptr_nd->value))
					return (iterator(tmp_ptr_nd));
				return (iterator(this->last));
			}

			const_iterator find(T input_value) const {
				ptr_nd tmp_ptr_nd = find_in_tree(input_value);

				if (!this->comp(*tmp_ptr_nd->value, input_value) &&
				!this->comp(input_value, *tmp_ptr_nd->value))
					return (const_iterator(tmp_ptr_nd));
				return (const_iterator(this->last));
			}

			void clear() {
				if (this->size == 0)
					return;
				this->size = 0;
				destoy_node(this->root);
				this->root = NULL;
			}

			void swap(rbtree &other) {
				diy::swap(this->root, other.root);
				diy::swap(this->last, other.last);
				diy::swap(this->size, other.size);
				diy::swap(this->comp, other.comp);
				diy::swap(this->talloc, other.talloc);
				diy::swap(this->nalloc, other.nalloc);
			}

			size_t count(const T &input_value) const {
				size_t i = 0;
				const_iterator iter = begin();
				while (iter != end()) {
					if (iter->first == input_value)
						i++;
					iter++;
				}
				return i;
			};

		private:
			void null_root(const ptr_nd &new_node) {
				this->size++;
				this->root = new_node;
				this->root->color = 'b';
			}

			void destoy_node(ptr_nd elim) {
				if (elim == NULL) // here can be leak?
					return;
				destoy_node(elim->left);
				destoy_node(elim->right);
				this->talloc.destroy(elim->value);
				this->talloc.deallocate(elim->value, 1);
				this->nalloc.destroy(elim);
				this->nalloc.deallocate(elim, 1);
			}

			void attach_node(ptr_nd &last_node, const T &input_value, ptr_nd &new_node) {
				if (this->comp(*last_node->value, input_value))
					last_node->right = new_node;
				else
					last_node->left = new_node;
				new_node->parent = last_node;
			}

			void check_violations(ptr_nd checking_node) {
				ptr_nd prnt = NULL;
				ptr_nd grnd = NULL;
				ptr_nd aunt = NULL;

				if (checking_node == NULL)
					return;
				while ((checking_node != this->root) &&
					(checking_node->color == 'r') &&
					(checking_node->parent->color == 'r')) {

					prnt = checking_node->parent;
					grnd = checking_node->parent->parent;

					if (prnt == grnd->left) {
						aunt = grnd->right;
						if (aunt && aunt->color == 'r') {
							grnd->color = 'r';
							prnt->color = 'b';
							aunt->color = 'b';
							checking_node = grnd;
						}
						else {
							if (checking_node == prnt->right) {
								left_rotation(prnt);
								checking_node = prnt;
								prnt = checking_node->parent;
							}
							right_rotation(grnd);
							diy::swap(prnt->color, grnd->color);
							checking_node = prnt;
						}
					} else {
						aunt = grnd->left;
						if (aunt && aunt->color == 'r') {
							grnd->color = 'r';
							prnt->color = 'b';
							aunt->color = 'b';
							checking_node = grnd;
						}
						else {
							if (checking_node == prnt->left) {
								right_rotation(prnt);
								checking_node = prnt;
								prnt = checking_node->parent;
							}
							left_rotation(grnd);
							diy::swap(prnt->color, grnd->color);
							checking_node = prnt;
						}
					}
				}
				this->root->color = 'b';
			}

			void left_rotation(ptr_nd x) { // check it
				ptr_nd y = x->right;
				x->right = y->left;
				if (y->left)
					y->left->parent = x;
				y->left = x;
				y->parent = x->parent;
				if (x->parent && x->parent->left == x)
					x->parent->left = y;
				else if (x->parent)
					x->parent->right = y;
				x->parent = y;
				if (y->parent == NULL)
					this->root = y;
			}

			void right_rotation(ptr_nd x) {
				ptr_nd y = x->left;
				x->left = y->right;
				if (y->right)
					y->right->parent = x;
				y->right = x;
				y->parent = x->parent;
				if (x->parent && x->parent->left == x)
					x->parent->left = y;
				else if (x->parent)
					x->parent->right = y;
				x->parent = y;
				if (y->parent == NULL)
					this->root = y;
			}

			ptr_nd find_in_tree(T &input_value) {
				ptr_nd first_node = this->root;
				ptr_nd second_node = NULL;

				while (first_node)
				{
					second_node = first_node;
					if (this->comp(*first_node->value, input_value))
						first_node = second_node->right;
					else if (this->comp(input_value, *first_node->value))
						first_node = second_node->left;
					else // 						need it???
						return second_node;
				}
				return second_node;
			}

			iterator lower_bound(const T &input_val) {// try this // for what?
				iterator iter = this->begin();
				for (; iter != this->end(); iter++) {
					if (!this->comp(iter->first, input_val))
						break;
				}
				return iter;
			}

			const_iterator lower_bound(const T &input_val) const {
				const_iterator iter = this->begin();
				for (; iter != this->end(); iter++) {
					if (!this->_comp(iter->first, input_val))
						break;
				}
				return iter;
			}

			iterator upper_bound(const T &input_val) {
				iterator iter = this->begin();
				for (; iter != this->end(); iter++) {
					if (this->_comp(input_val, iter->first))
						break;
				}
				return iter;
			}

			const_iterator upper_bound(const T &input_val) const {
				const_iterator iter = this->begin();
				for (; iter != this->end(); iter++) {
					if (this->_comp(input_val, iter->first))
						break;
				}
				return iter;
			}

			diy::pair<iterator, iterator> equal_range(const T &input) {
				iterator lower = lower_bound(input);
				iterator upper = upper_bound(input);
				return diy::make_pair(iterator(lower), iterator(upper));
			}

			diy::pair<const_iterator, const_iterator> equal_range(const T &input) const {
				const_iterator lower = lower_bound(input);
				const_iterator upper = upper_bound(input);
				return diy::make_pair(const_iterator(lower), const_iterator(upper));
			}
	};
}

#endif
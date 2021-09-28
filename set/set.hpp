#ifndef SET_HPP
#define SET_HPP

#include "setit.hpp"
#include "snode.hpp"

namespace diy {
	template <typename T, typename P, typename R>
	class setit;
}

namespace diy {
	template <typename T>
	class set {
		public:
			typedef T*				pointer;
			typedef T&				reference;
			typedef const T*		const_pointer;
			typedef const T&		const_reference;

			typedef diy::set_node<T>			nd;
			typedef diy::set_node<T>*			ptr_nd;
			typedef diy::less<T>				comparator;
			typedef typename std::allocator<T>	pair_allocator;
			typedef typename std::allocator<nd>	node_allocator;

			typedef typename diy::setit<T, pointer, reference>		iterator;
			typedef typename diy::setit<T, const T*, const T&>		const_iterator;
			typedef typename diy::rev_setit<T, pointer, reference>	reverse_iterator;
			typedef typename diy::rev_setit<T, const T*, const T&>	const_reverse_iterator;

		private:
			ptr_nd			root;
			ptr_nd			last;
			size_t			size;
			comparator		comp;
			pair_allocator	palloc;
			node_allocator	nalloc;
	
		public:
			explicit set(const comparator &comp = comparator(),
				const pair_allocator &palloc = pair_allocator(),
				const node_allocator &nalloc = node_allocator()) :
					root(NULL),
					last(NULL),
					size(0),
					comp(comp),
					palloc(palloc),
					nalloc(nalloc) {
				this->last = this->nalloc.allocate(1);
				this->nalloc.construct(this->last, nd(NULL));
			}

			template <typename InputIterator>
			set(InputIterator first_iter, InputIterator last_iter,
				const comparator &comp = comparator(),
				const pair_allocator &palloc = pair_allocator(),
				const node_allocator &nalloc = node_allocator()) :
					root(NULL),
					last(NULL),
					size(0),
					comp(comp),
					palloc(palloc),
					nalloc(nalloc) {
				this->last = this->nalloc.allocate(1);
				this->nalloc.construct(this->last, nd(NULL));
				insert(first_iter, last_iter);
			}

			set &operator=(const set &other) {
				if (this == &other)
					return *this;
				this->clear();
				this->root = other.root;
				this->last = other.last;
				this->size = other.size;
				this->comp = other.comp;
				this->palloc = other.palloc;
				this->nalloc = other.nalloc;
				insert(other.begin(), other.end());
				return *this;
			}

			set(const set &other) :
				root(NULL),
				last(NULL),
				size(0),
				comp(other.comp),
				palloc(other.palloc),
				nalloc(other.nalloc) {
					this->last = this->nalloc.allocate(1);
					this->nalloc.construct(this->last, nd(NULL));
					insert(other.begin(), other.end());
				}

			~set() {
				clear();
				nalloc.destroy(last);
				nalloc.deallocate(last, 1);
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

			size_t size_set() const { return this->size; }
			comparator value_comp() const { return this->comp; }
			size_t max_size() const { return this->palloc.max_size(); }
			pair_allocator get_allocator() const { return this->palloc; }

			iterator		end() { return iterator(this->last); }
			const_iterator	end() const { return const_iterator(this->last); }

			reverse_iterator rbegin() {
				reverse_iterator ret_iter(this->last);
				ret_iter++;
				return ret_iter;
			}
			
			const_reverse_iterator rev_begin() const {
				const_reverse_iterator ret_iter(this->last);
				ret_iter++;
				return ret_iter;
			}
			
			reverse_iterator rend() {
				reverse_iterator ret_iter(this->root);
				ret_iter++;
				return ret_iter;
			}

			const_reverse_iterator rev_end() const {
				const_reverse_iterator ret_iter(this->root);
				ret_iter++;
				return ret_iter;
			}

			diy::pair<iterator, bool> insert(const T &input_value) {
				if (this->root)
					this->root->parent = NULL;

				// creating node with input_value inside
				pointer new_value = this->palloc.allocate(1);
				this->palloc.construct(new_value, input_value);
				ptr_nd new_node = this->nalloc.allocate(1);
				this->nalloc.construct(new_node, nd(new_value));

				// pointing root to new_node
				if (this->root == NULL) {
					this->size++;
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

				this->size++;
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
				(void)pos;
				return insert(input_value).first;
			}

			template <class InpIt>
			void insert(InpIt first_iter, InpIt last_iter,
				typename diy::enable_if<!std::is_integral<InpIt>::value, InpIt>::type = 0) {
					while (first_iter != last_iter) {
						insert(*first_iter);
						first_iter++;
					}
				}

			void erase(iterator pos) {
				this->size--;
				this->root->parent = NULL;
				ptr_nd del_node = inner_erase(pos.base());
				check_violations(del_node);
				if (this->root) {
					this->root->parent = this->last;
					this->last->left = this->root;
				}
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
					return iterator(tmp_ptr_nd);
				return iterator(this->last);
			}

			const_iterator find(T input_value) const {
				ptr_nd tmp_ptr_nd = find_in_tree(input_value);

				if (!this->comp(*tmp_ptr_nd->value, input_value) &&
				!this->comp(input_value, *tmp_ptr_nd->value))
					return const_iterator(tmp_ptr_nd);
				return const_iterator(this->last);
			}

			void clear() {
				if (this->size == 0)
					return;
				this->size = 0;
				destoy_node(this->root);
				this->root = NULL;
			}

			void swap(set &other) {
				diy::swap(this->root, other.root);
				diy::swap(this->last, other.last);
				diy::swap(this->size, other.size);
				diy::swap(this->comp, other.comp);
				diy::swap(this->palloc, other.palloc);
				diy::swap(this->nalloc, other.nalloc);
			}

			iterator lower_bound(const T &value) {
				return iterator(lower_rec_bound(value, this->root));
			}

			const_iterator lower_bound(const T &value) const {
				return const_iterator(lower_rec_bound(value, this->root));
			}

			iterator upper_bound(const T &value) {
				return iterator(upper_rec_bound(value, this->root));
			}

			const_iterator upper_bound(const T &value) const {
				return const_iterator(upper_rec_bound(value, root));
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
				this->root = new_node;
				this->root->color = 'b';
			}

			void destoy_node(ptr_nd elim) {
				if (elim == NULL)
					return;
				destoy_node(elim->left);
				destoy_node(elim->right);
				this->palloc.destroy(elim->value);
				this->palloc.deallocate(elim->value, 1);
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
					}
					else {
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

			void left_rotation(ptr_nd x) {
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

				while (first_node) {
					second_node = first_node;
					if (this->comp(*first_node->value, input_value))
						first_node = second_node->right;
					else if (this->comp(input_value, *first_node->value))
						first_node = second_node->left;
					else
						return second_node;
				}
				return second_node;
			}

			ptr_nd inner_erase(ptr_nd input_node) {
				if (!input_node)
					return NULL;
				ptr_nd tmp = NULL;
				if (!input_node->left || !input_node->right) {
					if (!input_node->left && !input_node->right) {
						tmp = input_node->parent;
						if (!tmp)
							this->root = NULL;
						else if (tmp->left == input_node)
							tmp->left = NULL;
						else
							tmp->right = NULL;
					}
					else
						erase_helper(input_node, tmp);
					if (!input_node)
						return NULL;
					palloc.destroy(input_node->value);
					palloc.deallocate(input_node->value, 1);
					nalloc.destroy(input_node);
					nalloc.deallocate(input_node, 1);
					return tmp;
				}
				tmp = input_node->left;
				while (tmp->right)
					tmp = tmp->right;
				this->palloc.destroy(input_node->value);
				this->palloc.construct(input_node->value, *tmp->value);
				return inner_erase(tmp);
			}

			void erase_helper(ptr_nd input_node, ptr_nd tmp) {
				if (!input_node->right)
					tmp = input_node->left;
				else
					tmp = input_node->right;
				if (!input_node->parent) {
					this->root = tmp;
					tmp->parent = NULL;
				}
				else if (input_node->parent->left == input_node) {
					input_node->parent->left = tmp;
					tmp->parent = input_node->parent;
				}
				else {
					input_node->parent->right = tmp;
					tmp->parent = input_node->parent;
				}
			}

			ptr_nd lower_rec_bound(T const &value, ptr_nd node) const {
				if (node == NULL)
					return this->last;
				if (this->comp(*node->value, value))
					return lower_rec_bound(value, node->right);
				else {
					ptr_nd left = lower_rec_bound(value, node->left);
					if (left != this->last)
						return left;
					else
						return node;
				}
			}

			ptr_nd upper_rec_bound(T const &value, ptr_nd node) const {
				if (node == NULL)
					return this->last;
				if (!this->comp(value, *node->value))
					return upper_rec_bound(value, node->right);
				else {
					ptr_nd left = upper_rec_bound(value, node->left);
					if (left != this->last)
						return left;
					else
						return node;
				}
			}
	};
}

#endif
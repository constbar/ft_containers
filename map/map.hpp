#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "node.hpp"
#include "bidit.hpp"
#include "../utils/utils.hpp"

namespace diy {
	template <typename T1, typename T2>
	struct pair;

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1, const T2);
}

namespace diy {
	template <typename Key, typename T,
		typename compare = diy::less<Key> >
		class map {
			public:
				typedef T									mapped_type;
				typedef diy::pair<const Key, T>				value_type;
				typedef diy::map_node<value_type>			node;
				typedef typename std::allocator<value_type>	alloc_pair;
				typedef compare								key_compare;
				typedef alloc_pair							pair_alloc;
				typedef diy::bidit<value_type> 				iterator;
				typedef const iterator						const_iterator;
				typedef size_t								size_type;
				typedef diy::rev_bidit<value_type>			reverse_iterator;
				typedef diy::rev_bidit<const T>				const_reverse_iterator;
				typedef typename std::allocator<diy::map_node<value_type> > node_alloc;

			class value_compare {	
				friend class map;
				protected:
					compare comp;
					value_compare(compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

				bool operator()(const value_type &x, const value_type &y) const {
					return comp(x.first, y.first);
				}
			};

			private:
				node		*begin_pos;
				node		*last_pos;
				size_t		size_tree;
				pair_alloc	palloc;
				node_alloc	nalloc;
				key_compare	comparator;

			public:
				explicit map(const key_compare &comp = key_compare(),
					const pair_alloc &p_alloc = pair_alloc(),
					const node_alloc &n_alloc = node_alloc()) :
						begin_pos(NULL),
						last_pos(NULL),
						size_tree(0),
						palloc(p_alloc),
						nalloc(n_alloc),
						comparator(comp) {}

				template <typename InpIt>
				map(InpIt first_iter, InpIt last_iter,
					const key_compare &comp = key_compare(),
					const pair_alloc &p_alloc = pair_alloc(),
					const node_alloc &n_alloc = node_alloc(),
					typename diy::enable_if<!std::is_integral<InpIt>::value, InpIt>::type = 0) :
						begin_pos(NULL),
						last_pos(NULL),
						size_tree(0), 
						palloc(p_alloc),
						nalloc(n_alloc),
						comparator(comp) {
							insert(first_iter, last_iter);
				}

				map &operator=(const map &other) {
					if (this != &other) {
						this->clear();
						this->begin_pos = NULL;
						this->last_pos = NULL;
						this->size_tree = 0;
						insert(other.begin(), other.end());
						this->size_tree = other.size_tree;
						this->comparator = other.comparator;
					}
					else {
						this->clear();
						this->begin_pos = NULL;
						this->last_pos = NULL;
						this->size_tree = 0;
					}
					this->palloc = other.palloc;
					this->nalloc = other.nalloc;
					return *this;
				}

				map(const map &other) {
					this->begin_pos = NULL;
					this->last_pos = NULL;
					this->size_tree = 0;
					*this = other;
				}

				~map() {
					this->clear();
					this->begin_pos = NULL;
					this->last_pos = NULL;
					this->size_tree = 0;
				}

				iterator begin() {
					if (!this->size_tree)
						return end();
					node *tmp_node = this->begin_pos;
					while (tmp_node && tmp_node->left)
						tmp_node = tmp_node->left;
					return tmp_node;
				}

				const_iterator begin() const {
					if (!this->size_tree)
						return end();
					node *tmp_node = this->begin_pos;
					while (tmp_node && tmp_node->left != NULL)
						tmp_node = tmp_node->left;
					return tmp_node;
				}

				iterator end() { return this->last_pos; }
				const_iterator end() const { return this->last_pos; }
				
				reverse_iterator rbegin() {
					node *tmp_node = this->begin_pos;
					while (tmp_node && tmp_node->right)
						tmp_node = tmp_node->right;
					return tmp_node;
				}

				const_reverse_iterator rbegin() const {
					node *tmp_node = this->begin_pos;
					while (tmp_node && tmp_node->right)
						tmp_node = tmp_node->right;
					return tmp_node;
				}

				size_t size() const {
					if (!this->size_tree)
						return 0;
					return this->size_tree;
				}

				bool empty() const { return this->size_tree <= 1; }
				size_t max_size() const { return this->palloc.max_size(); }
				reverse_iterator rend() { return this->last_pos; }
				const_reverse_iterator rend() const { return this->last_pos; }
				mapped_type &operator[](const Key &input_key) { 
					return ((*((this->insert(diy::make_pair(input_key, mapped_type()))).first)).second);
				}
				size_t count(const Key &input_key) const { return (this->find(input_key) != this->end()); }

				void clear() {
					iterator cpy_it;
					iterator it = this->begin();
					while (it != this->end()) {
						if (it.ptr->value) {
							this->palloc.destroy(it.ptr->value);
							this->palloc.deallocate(it.ptr->value, 1);
							it.ptr->value = NULL;
						}
						cpy_it = it;
						it++;
						this->nalloc.destroy(cpy_it.ptr);
						this->nalloc.deallocate(cpy_it.ptr, 1);
					}
					this->size_tree = 0;
					this->begin_pos = NULL;
					this->nalloc.destroy(this->last_pos);
					this->nalloc.deallocate(this->last_pos, 1);
					this->last_pos = NULL;
				}

				key_compare key_comp() const { return this->comparator; }
				value_compare value_comp() const { return value_compare(this->comparator); }

				iterator find(const Key &input_key) {
					iterator it = this->begin();
					while (this->begin_pos && it != this->end() && it->first != input_key)
						it++;
					return it;
				}
			
				const_iterator find(const Key &input_key) const {
					iterator it = this->begin();
					while (this->begin_pos && it != this->end() && it->first != input_key)
						it++;
					return it;
				}

				diy::pair<iterator, bool> insert(const value_type &input_value) {
					iterator fin_iter;
					if (this->begin_pos != NULL && this->begin_pos->value != NULL &&
					(fin_iter = this->find(input_value.first)) != this->end())
						return diy::make_pair(fin_iter, false);
					fin_iter = insert(this->begin_pos, input_value);
					return diy::make_pair(fin_iter, true);
				}

				void erase(iterator pos) {
					node *tmp_node = pos.ptr;
					iterator iter = this->begin();
					if (!tmp_node->right && !tmp_node->left) {
						iter = this->begin();
						for (; iter != this->end(); iter++) {
							if (iter.ptr->left == tmp_node)
								iter.ptr->left = NULL;
							else if (iter.ptr->right == tmp_node)
								iter.ptr->right = NULL;
						}
						if (tmp_node == this->begin_pos)
							this->begin_pos = this->begin_pos->next;
					}
					else if (tmp_node->right && tmp_node->left) {
						node *if_node = tmp_node->next;
						if (if_node != this->end().ptr) {
							if (if_node->right) {
								iter = this->begin();
								for (; iter != this->end(); iter++) {
									if (iter.ptr->left == if_node)
										iter.ptr->left = if_node->right;
									else if (iter.ptr->right == if_node)
										iter.ptr->right = if_node->right;
								}
							}
							if_node->right = tmp_node->right;
							if_node->left = tmp_node->left;
							iter = this->begin();
							for (; iter != this->end(); iter++) {
								if (iter.ptr->left == tmp_node)
									iter.ptr->left = if_node;
								else if (iter.ptr->right == tmp_node)
									iter.ptr->right = if_node;
							}
						}
						if (tmp_node == this->begin_pos)
							this->begin_pos = if_node;
					}
					else {
						node *else_node;
						if (tmp_node->right)
							else_node = tmp_node->right;
						if (tmp_node->left)
							else_node = tmp_node->left;
						iter = this->begin();
						for (; iter != this->end(); iter++) {
							if (iter.ptr->left == tmp_node)
								iter.ptr->left = else_node;
							else if (iter.ptr->right == tmp_node)
								iter.ptr->right = else_node;
						}
						if (tmp_node == this->begin_pos)
							this->begin_pos = else_node;
					}
					tmp_node->prev->next = tmp_node->next;
					tmp_node->next->prev = tmp_node->prev;
					this->palloc.destroy(tmp_node->value);
					this->palloc.deallocate(tmp_node->value, 1);
					this->nalloc.destroy(tmp_node);
					this->nalloc.deallocate(tmp_node, 1);
					this->size_tree--;
					if (!this->size_tree)
						this->clear();
				}

				size_type erase(const Key &input_key) {
					size_t ret_size = this->size_tree;
					iterator it;
					if ((it = this->find(input_key)) != this->end())
						this->erase(it);
					return ret_size - this->size_tree;
				}

				void erase(iterator first, iterator last) {
					iterator tmp;
					while (first != last) {
						tmp = first;
						first++;
						erase(tmp);
					}
				}

				iterator insert(iterator pos, const value_type &val) {
					if (!this->size_tree) {
						this->begin_pos = this->nalloc.allocate(1);
						this->nalloc.construct(this->begin_pos, node());
						this->begin_pos->value = this->palloc.allocate(1);
						this->palloc.construct(this->begin_pos->value, val);
						this->last_pos = this->nalloc.allocate(1);
						this->nalloc.construct(this->last_pos, node());
						this->begin_pos->prev = this->last_pos;
						this->begin_pos->next = this->last_pos;
						this->last_pos->prev = this->begin_pos;
						this->last_pos->next = this->begin_pos;
						this->size_tree = 1;
						pos = this->begin_pos;
					}
					else {
						node *new_node = this->nalloc.allocate(1);
						this->nalloc.construct(new_node, node());
						new_node->value = this->palloc.allocate(1);
						this->palloc.construct(new_node->value, val);
						this->size_tree++;
						node *copy_node = this->begin().ptr;
						if ((*copy_node->value).first < (*new_node->value).first) {
							while (copy_node != this->last_pos &&
							(*copy_node->value).first < (*new_node->value).first)
								copy_node = copy_node->next;
							new_node->prev = copy_node->prev;
							new_node->next = copy_node;
							copy_node->prev->next = new_node;
							copy_node->prev = new_node;
						}
						else {
							new_node->prev = this->last_pos;
							new_node->next = copy_node;
							copy_node->prev = new_node;
							this->last_pos->next = new_node;
						}
						put_node(new_node);
						pos = new_node;
					}
					return pos;
				}

				template <typename InpIt>
				void insert(InpIt first, InpIt last, 
					typename diy::enable_if<!std::is_integral<InpIt>::value, InpIt>::type = 0) {
						while (first != last) {
							insert(*first);
							first++;
						}
				}

				void swap(map &other) {
					diy::swap(this->begin_pos, other.begin_pos);
					diy::swap(this->last_pos, other.last_pos);
					diy::swap(this->size_tree, other.size_tree);
					diy::swap(this->palloc, other.palloc);
					diy::swap(this->nalloc, other.nalloc);
					diy::swap(this->comparator, other.comparator);
				}
							
				iterator lower_bound(const Key &input_key) {
					iterator it = begin();
					for (; it != end(); ++it)
						if (!comparator(it->first, input_key))
							break;
					return it;
				}

				const_iterator lower_bound(const Key &input_key) const {
					iterator it = begin();
					for (; it != end(); it++)
						if (!comparator(it->first, input_key))
							break;
					return it;
				}

				iterator upper_bound(const Key &input_key) {
					iterator it = begin();
					for (; it != end(); it++)
						if (this->comparator(input_key, it->first))
							break;
					return it;
				}

				const_iterator upper_bound(const Key &input_key) const {
					iterator it = begin();
					for (; it != end(); ++it)
						if (this->comparator(input_key, it->first))
							break;
					return it;
				}

				diy::pair<const_iterator, const_iterator> equal_range(const Key &input_key) const { return this->equal_range(input_key); }
			
				diy::pair<iterator, iterator> equal_range(const Key &input_key) {
					iterator it = upper_bound(input_key);
					if (it != begin()) {
						it--;
						if (comparator(it->first, input_key) || comparator(input_key, it->first))
							it++;
					}
					iterator next(it);
					if (it != end())
						next++;
					return make_pair<iterator, iterator>(it, next);
				}
			
			private:
				void put_node(node *new_node) {
					node *cpyTree = this->begin_pos;
					while (cpyTree->right != new_node && cpyTree->left != new_node) {
						if ((*cpyTree->value).first < (*new_node->value).first) {
							if (cpyTree->right == NULL)
								cpyTree->right = new_node;
							else
								cpyTree = cpyTree->right;
						}
						else if ((*cpyTree->value).first > (*new_node->value).first) {
							if (cpyTree->left == NULL)
								cpyTree->left = new_node;
							else
								cpyTree = cpyTree->left;
						}
					}
				}
	};

}
#endif

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <cmath>
#include <string.h>
#include "node.hpp"
#include "iter.hpp"
#include "utils/utils.hpp"

namespace diy {
	template <typename T1, typename T2>
	struct pair;

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1, const T2);
}

namespace diy {
	template <typename Key, typename T,
		typename Compare = diy::less<Key>,
		typename Alloc = std::allocator<diy::pair<const Key, T> > >
		class map {
			public:
				typedef T							mapped_type;
				typedef diy::pair<const Key, T>		value_type;
				typedef diy::tree_node<value_type>	node;
				typedef Compare						key_compare;
				typedef Alloc						alloc_type;
				typedef diy::bidit<value_type> 		iterator;
				typedef const iterator				const_iterator;
				typedef size_t						size_type;
				typedef diy::rev_bidit<value_type>	reverse_iterator;
				typedef diy::rev_bidit<const T>		const_reverse_iterator;

			class value_compare {	
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

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
				alloc_type	talloc;
				key_compare	comparator;

			public:
				explicit map(const key_compare &comp = key_compare(),
					const alloc_type &alloc = alloc_type()) :
						begin_pos(NULL),
						last_pos(NULL),
						size_tree(0),
						talloc(alloc),
						comparator(comp) {}

				template <typename InpIt>
				map(InpIt first_iter, InpIt last_iter,
					const key_compare &comp = key_compare(),
					const alloc_type &alloc = alloc_type()) :
						talloc(alloc),
						comparator(comp),
						begin_pos(NULL),
						last_pos(NULL),
						size_tree(0) {
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
					return this->size_tree - 1;
				}

				bool empty() const { return this->size_tree <= 1; }
				size_t max_size() const { return this->talloc.max_size(); }
				reverse_iterator rend() { return this->last_pos; }
				const_reverse_iterator rend() const { return this->last_pos; }
				mapped_type &operator[](const Key &k) { 
					return ((*((this->insert(diy::make_pair(k, mapped_type()))).first)).second);
				}
				size_t count(const Key &input_key) const { return (this->find(input_key) != this->end()); }

								void clear() {
					iterator cpy; // tmp cpy
					iterator it = this->begin();
					while (it != this->end()) {
						if (it.get_ptr_iter()->value) {
							this->talloc.deallocate(it.get_ptr_iter()->value, 1);
							it.get_ptr_iter()->value = NULL;
						}
						cpy = it;
						it++;
						delete cpy.get_ptr_iter(); // delete
					}
					this->begin_pos = NULL;
					this->size_tree = 0;
					delete this->last_pos; // DELETE ??
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
						return (diy::make_pair(fin_iter, false));
					fin_iter = insert(this->begin_pos, input_value);
					return diy::make_pair(fin_iter, true);
				}

				void erase(iterator position) {
					node *replaced = position.get_ptr_iter();

					//arbre
					if (!replaced->right && !replaced->left)
					{
						for (iterator ite = this->begin(); ite != this->end(); ite++)
						{
							if (ite.get_ptr_iter()->left == replaced)
								ite.get_ptr_iter()->left = NULL;
							else if (ite.get_ptr_iter()->right == replaced)
								ite.get_ptr_iter()->right = NULL;
						}
						if (replaced == this->begin_pos)
							this->begin_pos = this->begin_pos->next;
					}
					else if (replaced->right && replaced->left)
					{
						node *tmp = replaced->next;
						if (tmp != this->end().get_ptr_iter())
						{
							if (tmp->right)
							{
								for (iterator ite = this->begin(); ite != this->end(); ite++)
								{
									if (ite.get_ptr_iter()->left == tmp)
										ite.get_ptr_iter()->left = tmp->right;
									else if (ite.get_ptr_iter()->right == tmp)
										ite.get_ptr_iter()->right = tmp->right;
								}
							}
							tmp->right = replaced->right;
							tmp->left = replaced->left;
							for (iterator ite = this->begin(); ite != this->end(); ite++)
							{
								if (ite.get_ptr_iter()->left == replaced)
									ite.get_ptr_iter()->left = tmp;
								else if (ite.get_ptr_iter()->right == replaced)
									ite.get_ptr_iter()->right = tmp;
							}
						}
						if (replaced == this->begin_pos)
							this->begin_pos = tmp;
					}
					else
					{
						node *value;
						if (replaced->right)
							value = replaced->right;
						if (replaced->left)
							value = replaced->left;
						for (iterator ite = this->begin(); ite != this->end(); ite++)
						{
							if (ite.get_ptr_iter()->left == replaced)
								ite.get_ptr_iter()->left = value;
							else if (ite.get_ptr_iter()->right == replaced)
								ite.get_ptr_iter()->right = value;
						}
						if (replaced == this->begin_pos)
							this->begin_pos = value;
					}

					//Iterator
					replaced->prev->next = replaced->next;
					replaced->next->prev = replaced->prev;

					//Delete
					this->talloc.deallocate(replaced->value, 1);
					replaced->value = NULL;
					delete replaced;
					replaced = NULL;
					this->size_tree -= 1;

					if (!this->size_tree)
						this->clear();
				}

				size_type erase(const Key &k) { // !!!!
					size_t ret_size = this->size_tree;
					iterator it;
					if ((it = this->find(k)) != this->end())
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
					if (this->size_tree == 0) {
						//Creation begin
						this->begin_pos = new node; // make node here // MAKE ALLLOC
						memset(this->begin_pos, 0, sizeof(node)); // DEL MEMSET

						this->begin_pos->value = this->talloc.allocate(1);
						this->talloc.construct(this->begin_pos->value, val);

						//Creation endsize
						this->last_pos = new node;
						memset(this->last_pos, 0, sizeof(node));
						this->last_pos->value = reinterpret_cast<value_type*>(&this->size_tree); // reinpr?

						//pointeurs
						this->begin_pos->prev = this->last_pos; // make other func here
						this->begin_pos->next = this->last_pos;
						this->last_pos->prev = this->begin_pos;
						this->last_pos->next = this->begin_pos;
						this->size_tree = 2;
						pos = this->begin_pos;
					}
					else {
						node *_new = new node; // NEW NODE???
						memset(_new, 0, sizeof(node));
						_new->value = this->talloc.allocate(1);
						this->talloc.construct(_new->value, val);
						this->size_tree += 1;

						//Iterateurs
						node *cpy = this->begin().get_ptr_iter();
						if ((*cpy->value).first > (*_new->value).first) {
							_new->prev = this->last_pos;
							_new->next = cpy;
							cpy->prev = _new;
							this->last_pos->next = _new;
						}
						else {
							while (cpy != this->last_pos && (*cpy->value).first < (*_new->value).first)
								cpy = cpy->next;
							_new->prev = cpy->prev;
							_new->next = cpy;
							cpy->prev->next = _new;
							cpy->prev = _new;
						}

						//arbres
						node *cpyTree = this->begin_pos;
						while (cpyTree->right != _new && cpyTree->left != _new)
						{
							if ((*cpyTree->value).first < (*_new->value).first)
							{
								if (cpyTree->right == NULL)
									cpyTree->right = _new;
								else
									cpyTree = cpyTree->right;
							}
							else if ((*cpyTree->value).first > (*_new->value).first)
							{
								if (cpyTree->left == NULL)
									cpyTree->left = _new;
								else
									cpyTree = cpyTree->left;
							}
						}
						pos = _new;
					}
					return pos;
				}

				template <typename InpIt>
				void insert(InpIt first, InpIt last) {
					while (first != last) {
						insert(*first);
						first++;
					}
				}

				void swap(map &other) {
					diy::swap(this->begin_pos, other.begin_pos);
					diy::swap(this->last_pos, other.last_pos);
					diy::swap(this->size_tree, other.size_tree);
					diy::swap(this->talloc, other.talloc);
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

	};

}
#endif

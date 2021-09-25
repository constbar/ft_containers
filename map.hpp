#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string.h>
#include "node.hpp"
#include "iter.hpp"
#include "utils/utils.hpp"

namespace diy {
	template <class T1, class T2>
	struct pair;

	template <class T1, class T2>
	pair<T1, T2> make_pair(const T1& x, const T2& y);
}

namespace ft {
	template <typename Key, typename T,
		typename Compare = diy::less<Key>,
		typename Alloc = std::allocator<diy::pair<const Key, T> > >
		class map {
			public:
				typedef T 												mapped_type;
				typedef diy::pair<const Key, T> 						value_type;
				typedef Compare 										key_compare;
				typedef Alloc								 			alloc_type;
				typedef bidit<value_type> 								iterator;
				typedef const iterator 									const_iterator;
				typedef T 												&reference;
				typedef const T 										&const_reference;
				typedef T 												*pointer;
				typedef const T 										*const_pointer;
				typedef size_t 											size_type;
				typedef ReverseBidirectionalIterator<value_type> 		reverse_iterator;
				typedef ReverseBidirectionalIterator<const T> 			const_reverse_iterator;
				typedef typename std::ptrdiff_t 						difference_type;

				typedef diy::tree_node<value_type>						node;

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
				node	*begin_pos;
				node	*last_pos;
				size_t		size_tree;
				alloc_type	talloc;
				key_compare comparator;

			public:
			explicit map(const key_compare &comp = key_compare(),
				const alloc_type &alloc = alloc_type()) :
					begin_pos(NULL),
					last_pos(NULL),
					size_tree(0),
					talloc(alloc),
					comparator(comp) {}

			template <class InpIt>
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
				this->clear();
				if (this != &other) {
					insert(other.begin(), other.end());
					this->comparator = other.comparator;
					this->size_tree = other.size_tree;
				}
				return *this;
			}
			
			map(const map &other) {
				this->clear();
				*this = other;
			}

			~map() { this->clear(); }

			iterator begin() {
				if (!this->size_tree)
					return end();			// check it
				node *tmp_node = this->begin_pos;
				while (tmp_node && tmp_node->left)
					tmp_node = tmp_node->left;
				return tmp_node;
			}

			const_iterator begin() const {
				if (!this->size_tree)
					return end();			// check it
				node *tmp_node = this->begin_pos;
				while (tmp_node && tmp_node->left != NULL)
					tmp_node = tmp_node->left;
				return tmp_node;
			}

			iterator end() { return this->last_pos; }
			const_iterator end() const { return this->last_pos; }
			
			reverse_iterator rbegin() {
				node *tmp_node = this->begin_pos;
				while (tmp_node && tmp_node->right) // were null
					tmp_node = tmp_node->right;
				return tmp_node;
			}

			const_reverse_iterator rbegin() const {
				node *tmp_node = this->begin_pos;
				while (tmp_node && tmp_node->right) // were null
					tmp_node = tmp_node->right;
				return tmp_node;
			}

			bool empty() const { return this->size_tree < 2; }
			reverse_iterator rend() { return this->last_pos; }
			const_reverse_iterator rend() const { return this->last_pos; }

			size_t size() const {
				if (!this->size_tree)
					return 0;
				return this->size_tree - 1;
			}

			size_t max_size() const { return this->talloc.max_size(); } //changed

			mapped_type &operator[](const Key &k) {
				return ((*((this->insert(diy::make_pair(k, mapped_type()))).first)).second); // CHANGED ?? HERE!!
				// return insert(diy::make_pair(k, mapped_type())).first->second;
			}
			/// LETS GO FRO MHERE
			diy::pair<iterator, bool> insert(const value_type &val) { ///// /?? ?AS?DAS?/
				iterator it;

				if (this->begin_pos != NULL && this->begin_pos->ptr != NULL && (it = this->find(val.first)) != this->end())
					return (diy::make_pair(it, false));
				it = insert(this->begin_pos, val);

				return (diy::make_pair(it, true));
			}



		iterator insert(iterator position, const value_type &val)
		{
			if (this->size_tree == 0)
			{
				//Creation begin
				this->begin_pos = new node; // make node here
				memset(this->begin_pos, 0, sizeof(node));

				this->begin_pos->ptr = this->talloc.allocate(1);
				this->talloc.construct(this->begin_pos->ptr, val);

				//Creation endsize
				this->last_pos = new node;
				memset(this->last_pos, 0, sizeof(node));
				this->last_pos->ptr = reinterpret_cast<value_type *>(&this->size_tree);

				//pointeurs
				this->begin_pos->prev = this->last_pos;
				this->begin_pos->next = this->last_pos;
				this->last_pos->prev = this->begin_pos;
				this->last_pos->next = this->begin_pos;
				this->size_tree = 2;
				position = this->begin_pos;
			}
			else
			{
				node *_new = new node;
				memset(_new, 0, sizeof(node));
				_new->ptr = this->talloc.allocate(1);
				this->talloc.construct(_new->ptr, val);
				this->size_tree += 1;

				//Iterateurs
				node *cpy = this->begin().get_it();
				if ((*cpy->ptr).first > (*_new->ptr).first)
				{
					_new->prev = this->last_pos;
					_new->next = cpy;
					cpy->prev = _new;
					this->last_pos->next = _new;
				}
				else
				{
					while (cpy != this->last_pos && (*cpy->ptr).first < (*_new->ptr).first)
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
					if ((*cpyTree->ptr).first < (*_new->ptr).first)
					{
						if (cpyTree->right == NULL)
							cpyTree->right = _new;
						else
							cpyTree = cpyTree->right;
					}
					else if ((*cpyTree->ptr).first > (*_new->ptr).first)
					{
						if (cpyTree->left == NULL)
							cpyTree->left = _new;
						else
							cpyTree = cpyTree->left;
					}
				}
				position = _new;
			}
			return (position);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}
		void erase(iterator position)
		{
			node *replaced = position.get_it();

			//arbre
			if (!replaced->right && !replaced->left)
			{
				for (iterator ite = this->begin(); ite != this->end(); ite++)
				{
					if (ite.get_it()->left == replaced)
						ite.get_it()->left = NULL;
					else if (ite.get_it()->right == replaced)
						ite.get_it()->right = NULL;
				}
				if (replaced == this->begin_pos)
					this->begin_pos = this->begin_pos->next;
			}
			else if (replaced->right && replaced->left)
			{
				node *tmp = replaced->next;
				if (tmp != this->end().get_it())
				{
					if (tmp->right)
					{
						for (iterator ite = this->begin(); ite != this->end(); ite++)
						{
							if (ite.get_it()->left == tmp)
								ite.get_it()->left = tmp->right;
							else if (ite.get_it()->right == tmp)
								ite.get_it()->right = tmp->right;
						}
					}
					tmp->right = replaced->right;
					tmp->left = replaced->left;
					for (iterator ite = this->begin(); ite != this->end(); ite++)
					{
						if (ite.get_it()->left == replaced)
							ite.get_it()->left = tmp;
						else if (ite.get_it()->right == replaced)
							ite.get_it()->right = tmp;
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
					if (ite.get_it()->left == replaced)
						ite.get_it()->left = value;
					else if (ite.get_it()->right == replaced)
						ite.get_it()->right = value;
				}
				if (replaced == this->begin_pos)
					this->begin_pos = value;
			}

			//Iterator
			replaced->prev->next = replaced->next;
			replaced->next->prev = replaced->prev;

			//Delete
			this->talloc.deallocate(replaced->ptr, 1);
			replaced->ptr = NULL;
			delete replaced;
			replaced = NULL;
			this->size_tree -= 1;

			if (this->size_tree == 0)
				this->clear();
		}
		size_type erase(const Key &k)
		{
			size_t tmpsize = this->size_tree;
			iterator it;
			if ((it = this->find(k)) != this->end())
				this->erase(it);
			return (tmpsize - this->size_tree);
		}
		void erase(iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		}
		void swap(map &x)
		{
			std::swap(x.begin_pos, this->begin_pos);
			std::swap(x.last_pos, this->last_pos);
			std::swap(x.size_tree, this->size_tree);
			std::swap(x.comparator, this->comparator);
		}
		void clear()
		{
			iterator cpy;
			iterator it = this->begin();
			while (it != this->end())
			{
				if (it.get_it()->ptr)
				{
					this->talloc.deallocate(it.get_it()->ptr, 1);
					it.get_it()->ptr = NULL;
				}
				cpy = it;
				it++;
				delete cpy.get_it();
			}
			this->begin_pos = NULL;
			this->size_tree = 0;
			delete this->last_pos;
			this->last_pos = NULL;
		}

		key_compare key_comp() const { return this->comparator; }
		value_compare value_comp(void) const { return value_compare(this->comparator); }

		iterator find(const Key &k) {
			iterator it = this->begin();

			while (this->begin_pos && it != this->end() && it->first != k)
				it++;
			return (it);
		}
		
		const_iterator find(const Key &k) const {
			iterator it = this->begin();
			while (this->begin_pos && it != this->end() && it->first != k)
				it++;
			return it;
		}
		
		size_t count(const Key &k) const { return (this->find(k) != this->end()); }
		iterator lower_bound(const Key &k)
		{
			iterator it = this->begin();

			while (it->first < k)
			{
				it++;
			}
			return (it);
		}
		const_iterator lower_bound(const Key &k) const
		{
			iterator it = this->begin();

			while (it->first < k)
			{
				it++;
			}
			return (it);
		}
		iterator upper_bound(const Key &k)
		{
			iterator it = this->begin();

			while (it != this->end() && it->first < k)
				it++;
			if (it->first == k)
				it++;
			return (it);
		}
		const_iterator upper_bound(const Key &k) const
		{
			iterator it = this->begin();
			while (it->first < k)
			{
				it++;
			}
			if (it->first == k)
				it++;
			return (it);
		}
		diy::pair<const_iterator, const_iterator> equal_range(const Key &k) const
		{
			return (this->equal_range(k));
		}
		
		diy::pair<iterator, iterator> equal_range(const Key &k) {
			iterator it = this->lower_bound(k);
			iterator ite = this->upper_bound(k);
			return (diy::make_pair(it, ite));
		}
	};

}
#endif

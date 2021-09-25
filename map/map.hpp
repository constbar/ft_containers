// #ifndef MAP_HPP
// #define MAP_HPP
// // sadfhkhjfhkjdhjkdsafhkjdfsahjkfsadhhkjasdfhkfasdjk  	del all
// #include <iostream>

// #include "vector.hpp"
// #include "stack.hpp"
// #include "iter.hpp"
// #include "ranit.hpp"
// #include "bidit.hpp"
// #include "tests.hpp"
// #include "utils.hpp"
// #include "pair.hpp"
// #include "rbtree.hpp"
// #include "node.hpp"
// #include "map.hpp"

// namespace diy {
// 	template <typename Key, typename T, typename Compare = diy::less<Key>,
// 		class Alloc = std::allocator<diy::pair<const Key, T> > >
// 		// class Alloc = std::allocator<diy::pair<Key, T> > > // const
// 	class map {
// 		// friend class rbtree;
// 		public:
// 			typedef Key 						key_type;
// 			typedef T 							mapped_type;
// 			typedef typename diy::pair<key_type, mapped_type> value_type;

// 		private:
// 			class value_compare {
// 				friend class map;

// 			// public:
// 			protected:
// 				Compare _comp;
// 				// value_compare() : _comp(NULL) {} // na vsyakij
// 				value_compare(Compare c) : _comp(c) {
// 					std::cout << "comparator class init\n";
// 				}

// 			public:
// 				typedef bool result_type;
// 				typedef value_type first_argument_type;
// 				typedef value_type second_argument_type;
// 				bool operator()(const value_type &x, const value_type &y) const {
// 					return _comp(x.first, y.first);
// 				}
// 			};

// 			private:
// 					rbtree<value_type> tree; // add diy?
// 					// value_compare asd;	

// 	public:
// 		// typedef std::allocator<diy::node<T> > Nalloc;

// 		typedef Compare key_compare;
// 		typedef Alloc allocator_type;
// 		typedef typename allocator_type::reference reference;
// 		typedef typename allocator_type::const_reference const_reference;
// 		typedef typename allocator_type::pointer pointer;
// 		typedef typename allocator_type::const_pointer const_pointer;

// 		typedef typename diy::bidit<value_type, value_type *, value_type&> iterator;
// 		// typedef typename ft::bidit<value_type, const value_type *, const value_type &> const_iterator;

// 		// typedef typename ft::rev_ranit<iterator> reverse_iterator;
// 		// typedef typename ft::rev_ranit<const_iterator> const_reverse_iterator;

// 		// typedef typename std::size_t size_type;
// 		// typedef typename std::ptrdiff_t difference_type;
		
// 				// value_compare(key_compare());!!! !!
// 			// tree(rbtree<T>(1, key_comparator, alloc)) {

// 		explicit map(const key_compare &key_comparator = key_compare(),
// 			const allocator_type &alloc = allocator_type()) :
// 			tree(rbtree<value_type>()) {}
// 		// 	tree(rbtree<value_type>(key_comparator, alloc)) {}

// 		// template <typename InpIt>
// 		// map(InpIt first_iter, InpIt last_iter,
// 		// 	const key_compare &key_comparator = key_compare(),
// 		// 	const allocator_type &alloc = allocator_type(),
// 		// 	typename diy::enable_if<!std::is_integral<InpIt>::value, InpIt>::type = 0) :
// 		// 		tree(rbtree<Key>(key_comparator, alloc)) {
// 		// 			insert(first_iter, last_iter);
// 		// }

// 		// map &operator=(const map &other) { // need copy constr
// 		// 	this->tree.clear();
// 		// 	this->tree.insert(other.tree.begin(), other.tree.end());
// 		// 	return *this;
// 		// }

// 		iterator begin() { return tree.begin(); }

// 		void insert(const value_type &val) {
// 			tree.insert(val);
// 			std::cout << tree.empty() << std::endl;
// 		}
// 		// pair<iterator,bool>	insert(const value_type &val) {
// 			// return tree.insert(val) ; }



// 	};
// }

// #endif
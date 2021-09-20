#include <iostream>
#include <queue>
#include <iterator>
#include <vector>
#include <stack>
#include <map>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "stack.hpp"
#include "iter.hpp"
#include "ranit.hpp"
#include "bidit.hpp"
#include "tests.hpp"
#include "pair.hpp"
#include "rbtree.hpp"

// 1. check all valgrind
// 2. iterators_traits, nado li ih ispol'zovat'? + !! save them to other file
// 4. std::pair
// 5. std::make_pair, must be reimplemented
// 6. test all pair / make pair / rev traits
// 7. make test from subject
// 8. test all non meber funcs enable if and others (enable if and other)
// 9. wall wextra werr use in check
// 10. in public there is no value_type and other inits of basic params
// 11. check the same in iterator
// 12. check all // (comments)
// 13. make dirs with vector // stack and other .. // or make all in one : vector contains all stuff with working with
// 14. check alll makefile
// 15. check coplience form everywhere
// 16. change standart
// 17. bool vector 

// int main() {

// 	int l = 9999;
// 	int *k = &l;
// 	diy::node<int> s(k);
// 	// std::cout << *s.value << std::endl;

// 	diy::node<int> qqq;
// 	qqq = s;
// 	std::cout << *qqq.value << std::endl;









	// test_vector test_vec;
	// test_vec.test_const();
	// test_vec.test_copy();
	// test_vec.test_iters();
	// test_vec.test_first();
	// test_vec.test_second();
	// test_vec.test_third();
	// test_vec.test_operators();

	// test_stack test_stk;
	// test_stk.test1();
	// test_stk.test2();



// 	return 0;
// }


// test geek for geeks !!!!!!			!!!!!!!				!!!!!!!!


// /** C++ implementation for
// Red-Black Tree Insertion
// This code is adopted from
// the code provided by
// Dinesh Khandelwal in comments **/
// // #include <bits/stdc++.h>
// using namespace std;

// enum Color {REDD, BLACK};

// struct Node
// {
// 	int data;
// 	bool color;
// 	Node *left, *right, *parent;

// 	// Constructor
// 	Node(int data)
// 	{
// 	this->data = data;
// 	left = right = parent = NULL;
// 	this->color = REDD;
// 	}
// };

// // Class to represent Red-Black Tree
// class RBTree
// {
// 	private:
// 		Node *root;
// 	protected:
// 		void rotateLeft(Node *&, Node *&);
// 		void rotateRight(Node *&, Node *&);
// 		void fixViolation(Node *&, Node *&);
// 	public:
// 		// Constructor
// 		RBTree() { root = NULL; }

// 		void insert(const int &n);
// 		void inorder();
// 		void levelOrder();
// };

// // A recursive function to do inorder traversal
// void inorderHelper(Node *root)
// {
// 	if (root == NULL)
// 		return;

// 	inorderHelper(root->left);
// 	cout << root->data << " ";
// 	inorderHelper(root->right);
// }

// /* A utility function to insert
// 	a new node with given key
// in BST */
// Node* BSTInsert(Node* root, Node *pt)
// {
// 	/* If the tree is empty, return a new node */
// 	if (root == NULL)
// 	return pt;

// 	/* Otherwise, recur down the tree */
// 	if (pt->data < root->data)
// 	{
// 		root->left = BSTInsert(root->left, pt);
// 		root->left->parent = root;
// 	}
// 	else if (pt->data > root->data)
// 	{
// 		root->right = BSTInsert(root->right, pt);
// 		root->right->parent = root;
// 	}

// 	/* return the (unchanged) node pointer */
// 	return root;
// }

// // Utility function to do level order traversal
// void levelOrderHelper(Node *root)
// {
// 	if (root == NULL)
// 		return;

// 	std::queue<Node *> q;
// 	q.push(root);

// 	while (!q.empty())
// 	{
// 		Node *temp = q.front();
// 		cout << temp->data << " ";
// 		q.pop();

// 		if (temp->left != NULL)
// 			q.push(temp->left);

// 		if (temp->right != NULL)
// 			q.push(temp->right);
// 	}
// }

// void RBTree::rotateLeft(Node *&root, Node *&pt)
// {
// 	Node *pt_right = pt->right;

// 	pt->right = pt_right->left;

// 	if (pt->right != NULL)
// 		pt->right->parent = pt;

// 	pt_right->parent = pt->parent;

// 	if (pt->parent == NULL)
// 		root = pt_right;

// 	else if (pt == pt->parent->left)
// 		pt->parent->left = pt_right;

// 	else
// 		pt->parent->right = pt_right;

// 	pt_right->left = pt;
// 	pt->parent = pt_right;
// }

// void RBTree::rotateRight(Node *&root, Node *&pt)
// {
// 	Node *pt_left = pt->left;

// 	pt->left = pt_left->right;

// 	if (pt->left != NULL)
// 		pt->left->parent = pt;

// 	pt_left->parent = pt->parent;

// 	if (pt->parent == NULL)
// 		root = pt_left;

// 	else if (pt == pt->parent->left)
// 		pt->parent->left = pt_left;

// 	else
// 		pt->parent->right = pt_left;

// 	pt_left->right = pt;
// 	pt->parent = pt_left;
// }

// // This function fixes violations
// // caused by BST insertion
// void RBTree::fixViolation(Node *&root, Node *&pt)
// {
// 	Node *parent_pt = NULL;
// 	Node *grand_parent_pt = NULL;

// 	while ((pt != root) && (pt->color != BLACK) &&
// 		(pt->parent->color == REDD))
// 	{

// 		parent_pt = pt->parent;
// 		grand_parent_pt = pt->parent->parent;

// 		/* Case : A
// 			Parent of pt is left child
// 			of Grand-parent of pt */
// 		if (parent_pt == grand_parent_pt->left)
// 		{

// 			Node *uncle_pt = grand_parent_pt->right;

// 			/* Case : 1
// 			The uncle of pt is also red
// 			Only Recoloring required */
// 			if (uncle_pt != NULL && uncle_pt->color ==
// 												REDD)
// 			{
// 				grand_parent_pt->color = REDD;
// 				parent_pt->color = BLACK;
// 				uncle_pt->color = BLACK;
// 				pt = grand_parent_pt;
// 			}

// 			else
// 			{
// 				/* Case : 2
// 				pt is right child of its parent
// 				Left-rotation required */
// 				if (pt == parent_pt->right)
// 				{
// 					rotateLeft(root, parent_pt);
// 					pt = parent_pt;
// 					parent_pt = pt->parent;
// 				}

// 				/* Case : 3
// 				pt is left child of its parent
// 				Right-rotation required */
// 				rotateRight(root, grand_parent_pt);
// 				swap(parent_pt->color,
// 						grand_parent_pt->color);
// 				pt = parent_pt;
// 			}
// 		}

// 		/* Case : B
// 		Parent of pt is right child
// 		of Grand-parent of pt */
// 		else
// 		{
// 			Node *uncle_pt = grand_parent_pt->left;

// 			/* Case : 1
// 				The uncle of pt is also red
// 				Only Recoloring required */
// 			if ((uncle_pt != NULL) && (uncle_pt->color ==
// 													REDD))
// 			{
// 				grand_parent_pt->color = REDD;
// 				parent_pt->color = BLACK;
// 				uncle_pt->color = BLACK;
// 				pt = grand_parent_pt;
// 			}
// 			else
// 			{
// 				/* Case : 2
// 				pt is left child of its parent
// 				Right-rotation required */
// 				if (pt == parent_pt->left)
// 				{
// 					rotateRight(root, parent_pt);
// 					pt = parent_pt;
// 					parent_pt = pt->parent;
// 				}

// 				/* Case : 3
// 				pt is right child of its parent
// 				Left-rotation required */
// 				rotateLeft(root, grand_parent_pt);
// 				swap(parent_pt->color,
// 						grand_parent_pt->color);
// 				pt = parent_pt;
// 			}
// 		}
// 	}

// 	root->color = BLACK;
// }

// // Function to insert a new node with given data
// void RBTree::insert(const int &data)
// {
// 	Node *pt = new Node(data);

// 	// Do a normal BST insert
// 	root = BSTInsert(root, pt);

// 	// fix Red Black Tree violations
// 	fixViolation(root, pt);
// }

// // Function to do inorder and level order traversals
// void RBTree::inorder()	 { inorderHelper(root);}
// void RBTree::levelOrder() { levelOrderHelper(root); }

// // Driver Code
// int main()
// {
// 	RBTree tree;

// 	tree.insert(7);
// 	tree.insert(6);
// 	tree.insert(5);
// 	tree.insert(4);
// 	tree.insert(3);
// 	tree.insert(2);
// 	tree.insert(1);

// 	cout << "Inorder Traversal of Created Tree\n";
// 	tree.inorder();

// 	cout << "\n\nLevel Order Traversal of Created Tree\n";
// 	tree.levelOrder();
// 	std::cout << std::endl;

// 	return 0;
// }

int main () {


	diy::tree<int, int> kek;
	kek.add(1,1);
	return 0;
}
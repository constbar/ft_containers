#ifndef TESTS_HPP
#define TESTS_HPP

#include "../vector/vector.hpp"
#include "../stack/stack.hpp"
#include "../map/map.hpp"
#include "../set/set.hpp"
#include "utils.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define END "\033[37m"

class Man {
	public:
		void say_smth() { std::cout << "hola!" << std::endl; }
		// Man() { std::cout << "hola" << std::endl; }
};

class test_vector {
	public:
		void test_const() {

			std::cout << RED;
			std::cout << "diy - green | std - yellow" << std::endl;
			std::cout << END;
			
			// simple
			std::cout << std::endl;
			
			std::cout << "testing base constructor:" << std::endl;
			diy::vector<int> diyvec1;
			std::vector<int> stdvec1;

			std::cout << GRE;
			std::cout << "size " << diyvec1.size() << std::endl;
			std::cout << "capacity " << diyvec1.capacity() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << stdvec1.size() << std::endl;
			std::cout << "capacity " << stdvec1.capacity() << std::endl;
			std::cout << END;

			// with int param
			std::cout << std::endl;
			std::cout << "testing constructor with int 5:" << std::endl;
			diy::vector<int> diyvec2(5);
			std::vector<int> stdvec2(5);
			
			std::cout << GRE;
			std::cout << "size " << diyvec2.size() << std::endl;
			std::cout << "capacity " << diyvec2.capacity() << std::endl;
			std::cout << "1st param " << diyvec2[0] << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << stdvec2.size() << std::endl;
			std::cout << "capacity " << stdvec2.capacity() << std::endl;
			std::cout << "1st param " << stdvec2[0] << std::endl;
			std::cout << END;

			// with iterators
			std::cout << std::endl;
			std::cout << "testing constructor with iters:" << std::endl;
			diy::vector<std::string> dv;
			dv.push_back("qwe1");
			dv.push_back("qwe2");
			dv.push_back("qwe3");
			diy::vector<std::string>::iterator dvit = dv.begin();
			diy::vector<std::string>::iterator dvend = dv.end();
			diy::vector<std::string> diyvec3(dvit, dvend);

			std::vector<std::string> sv;
			sv.push_back("qwe1");
			sv.push_back("qwe2");
			sv.push_back("qwe3");
			std::vector<std::string>::iterator stit = sv.begin();
			std::vector<std::string>::iterator stend = sv.end();
			std::vector<std::string> stdvec3(stit, stend);
			
			for (int i = 0; i < 3; i++)
				std::cout << GRE << diyvec3[i] << END << "\t";
			std::cout << std::endl;
			for (int i = 0; i < 3; i++)
				std::cout << YEL << stdvec3[i] << END << "\t";
			std::cout << std::endl;

			std::cout << GRE;
			std::cout << "size " << diyvec3.size() << std::endl;
			std::cout << "capacity " << diyvec3.capacity() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << stdvec3.size() << std::endl;
			std::cout << "capacity " << stdvec3.capacity() << std::endl;
			std::cout << END;
		}

		void test_copy() {
			
			std::cout << std::endl;
			
			// ()
			std::cout << "testing copy () with double:" << std::endl;
			diy::vector<double> src1;
			src1.push_back(12.1);
			src1.push_back(12.2);
			src1.push_back(12.3);
			src1.push_back(12.4);

			diy::vector<double> dst1(src1);
			for (int i = 0; i < 4 ; i++)
				std::cout << GRE << dst1[i] << END << "\t";
			std::cout << std::endl;

			// =
			std::cout << "testing copy = with class:" << std::endl;
			diy::vector<Man> src2;
			src2.push_back(Man());
			src2.push_back(Man());
			src2.push_back(Man());
			src2.push_back(Man());

			diy::vector<Man> dst2(src2);
			for (int i = 0; i < 4 ; i++)
				dst2[i].say_smth();
		}

		void test_iters() {
			
			std::cout << std::endl;

			diy::vector<int> vec;
			vec.push_back(111);
			vec.push_back(222);
			vec.push_back(333);
			vec.push_back(444);
			vec.push_back(555);
			vec.push_back(666);

			diy::vector<int>::const_iterator c_it = vec.begin();
			diy::vector<int>::const_iterator c_en = vec.end();

			std::cout << "mooving iter" << std::endl;
			c_it++;
			std::cout << *c_it << std::endl;
			++c_it;
			std::cout << *c_it << std::endl;
			// *c_it = 999;
			c_it--;
			std::cout << *c_it << std::endl;
			--c_it;
			std::cout << *c_it << std::endl;

			std::cout << "whats inside my vector with const" << std::endl;
			for (; c_it != c_en; c_it++)
				std::cout << *c_it << std::endl;

			diy::vector<int>::iterator it = vec.begin();
			diy::vector<int>::iterator en = vec.end();
			std::cout << "whats inside my vector with usual it" << std::endl;
			std::cout << "with changing" << std::endl;
			for (int i = 1; it != en; it++, i++) {
				*it = *it + 1;
				std::cout << *it << std::endl;
			}
			
			std::cout << "reeverse iters" << std::endl;
			diy::vector<int>::reverse_iterator r_it = vec.rbegin();
			diy::vector<int>::reverse_iterator r_en = vec.rend();

			std::cout << *r_it << std::endl;
			r_it++;
			std::cout << *r_it << std::endl;
			++r_it;
			std::cout << *r_it << std::endl;
			r_it--;
			std::cout << *r_it << std::endl;
			--r_it;
			std::cout << *r_it << std::endl;
		}

		void test_first() {
			// reserve
			// max_size
			// resize
			// clear
			// empty
			// pop_back
			
			std::cout << RED;
			std::cout << "diy - green | std - yellow" << std::endl;
			std::cout << END;

			// reserve
			diy::vector<int> d_vec;
			d_vec.reserve(100);
			std::vector<int> s_vec;
			s_vec.reserve(100);

			std::cout << "\nreserve:" << std::endl;
			std::cout << GRE;
			std::cout << "size " << d_vec.size() << std::endl;
			std::cout << "capacity " << d_vec.capacity() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << s_vec.size() << std::endl;
			std::cout << "capacity " << s_vec.capacity() << std::endl;
			std::cout << END;

			// max size
			std::cout << "\nmax size:" << std::endl;
			std::cout << GRE;
			std::cout << "size " << d_vec.max_size() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << s_vec.max_size() << std::endl;
			std::cout << END;

			// resize
			d_vec.resize(50);
			s_vec.resize(50);
			std::cout << "\nresize:" << std::endl;
			std::cout << GRE;
			std::cout << "size " << d_vec.size() << std::endl;
			std::cout << "capacity " << d_vec.capacity() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "size " << s_vec.size() << std::endl;
			std::cout << "capacity " << s_vec.capacity() << std::endl;
			std::cout << END;

			// empty
			std::cout << "\nis empty?" << std::endl;
			std::cout << GRE;
			std::cout << std::boolalpha << d_vec.empty() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << std::boolalpha << s_vec.empty() << std::endl;
			std::cout << END;

			// empty
			d_vec.clear();
			s_vec.clear();
			std::cout << "\nis empty after clear?" << std::endl;
			std::cout << GRE;
			std::cout << std::boolalpha << d_vec.empty() << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << std::boolalpha << s_vec.empty() << std::endl;
			std::cout << END;

			// pop back
			d_vec.push_back(12);
			d_vec.push_back(13);
			s_vec.push_back(12);
			s_vec.push_back(13);

			diy::vector<int>::reverse_iterator r_diter = d_vec.rbegin();
			std::vector<int>::reverse_iterator r_siter = s_vec.rbegin();

			std::cout << GRE;
			std::cout << "last elem " << *r_diter << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "last elem " << *r_siter << std::endl;
			std::cout << END;

			d_vec.pop_back();
			s_vec.pop_back();

			r_diter = d_vec.rbegin();
			r_siter = s_vec.rbegin();

			std::cout << "after pop back" << std::endl;
			std::cout << GRE;
			std::cout << "last elem " << *r_diter << std::endl;
			std::cout << END;
			
			std::cout << YEL;
			std::cout << "last elem " << *r_siter << std::endl;
			std::cout << END;
		}

		void test_second() {
			// swap
			// front
			// back
			// at
			// []
			// assign
			// erase

			std::cout << END;
			// swap
			std::cout << "swap testing" << std::endl;
			diy::vector<std::string> vec1;
			vec1.push_back("hey");
			vec1.push_back("there");

			diy::vector<std::string> vec2;
			vec2.reserve(30);
			vec2.push_back("how");
			vec2.push_back("are");
			vec2.push_back("you?");

			vec1.swap(vec2);

			diy::vector<std::string>::iterator b;
			b = vec1.begin();

			for (; b != vec1.end(); b++)
				std::cout << *b << "\t";
			std::cout << std::endl;
			std::cout << "vec1 size " << vec1.size() << std::endl;
			std::cout << "vec1 size " << vec1.capacity() << std::endl;


			b = vec2.begin();
			for (; b != vec2.end(); b++)
				std::cout << *b << "\t";
			std::cout << std::endl;
			std::cout << "vec2 size " << vec2.size() << std::endl;
			std::cout << "vec2 cpty "  << vec2.capacity() << std::endl;
			
			// front and back
			std::cout << "front of vec1 " << vec1.front() << std::endl;
			std::cout << "back of vec2 " << vec2.back() << std::endl;

			// []
			std::cout << "[] of index 1 - " << vec1[1] << std::endl;
			std::cout << "at() of index 2 - " << vec1.at(2) << std::endl;
			try { vec1.at(3); }
			catch(const std::exception& e)
			{
				std::cerr << "exception here: ";
				std::cerr << e.what() << '\n';
			}

			// assign test
			std::cout << "\nsimple assign" << std::endl;
			std::cout << GRE;
			std::cout << "vec1 before assign" << std::endl;
			b = vec1.begin();
			for (; b != vec1.end(); b++)
				std::cout << *b << std::endl;
			
			std::cout << std::endl;
			std::cout << BLU;
			vec1.assign(10, "new string");
			b = vec1.begin();
			std::cout << "vec1 after assign" << std::endl;
			for (; b != vec1.end(); b++)
				std::cout << *b << std::endl;
			std::cout << std::endl;
			std::cout << END;

			std::cout << "\nassign with iters" << std::endl;
			std::cout << GRE;

			b = vec2.begin();
			diy::vector<std::string>::iterator l = vec2.end();
			
			vec1.assign(b, l);
			std::cout << "vec1 after new assign from vec2" << std::endl;
			for (b = vec1.begin(); b != vec1.end(); b++)
				std::cout << *b << std::endl;
			std::cout << std::endl;
			std::cout << END;

			// erase with 2 iterators
			std::cout << "simple erase with 2 iters" << std::endl;
			diy::vector<std::string> vect;
			vect.push_back("at");
			vect.push_back("the");
			vect.push_back("end");
			vect.push_back("it");
			vect.push_back("doesnt");
			vect.push_back("even");
			vect.push_back("matter");
			vect.push_back("...");
			
			diy::vector<std::string>::iterator ers1 = vect.begin();
			ers1 += 1;

			diy::vector<std::string>::iterator ers2 = vect.begin();
			ers2 += 5;
			
			std::cout << "deleting ids 1 to 5" << std::endl;
			vect.erase(ers1, ers2);

			std::cout << "new vect now:" << std::endl;
			std::cout << YEL;
			diy::vector<std::string>::iterator new_iter = vect.begin();
			for (; new_iter != vect.end(); new_iter++)
				std::cout << *new_iter << std::endl;

			std::cout << vect.size() << std::endl;
			std::cout << vect.capacity() << std::endl;

			// erase with 1 iter
			diy::vector<std::string>::iterator simple_new = vect.begin();
			simple_new++;

			vect.erase(simple_new);
		
			std::cout << "\nafter erase with 1 iter:" << std::endl;
			new_iter = vect.begin();
			for (; new_iter != vect.end(); new_iter++)
				std::cout << *new_iter << std::endl;

			std::cout << vect.size() << std::endl;
			std::cout << vect.capacity() << std::endl;
			std::cout << END;
		}

		void test_third() {
			// insert

			std::cout << END;
			// insert with iters
			std::cout << "insert with iters:" << std::endl;

			diy::vector<std::string> vec1;
			vec1.push_back("I've become so numb");
			vec1.push_back("I can't feel you there");
			vec1.push_back("Become so tired");
			vec1.push_back("So much more aware");
			diy::vector<std::string>::iterator begit1 = vec1.begin();
			diy::vector<std::string>::iterator endit1 = vec1.end();

			diy::vector<std::string> vec2;
			vec2.push_back("1");
			vec2.push_back("2");
			vec2.push_back("3");
			vec2.push_back("4");
			vec2.push_back("5");
			vec2.push_back("6");
			vec2.push_back("7");
			vec2.push_back("8");
			vec2.push_back("9");
			diy::vector<std::string>::iterator it2 = vec2.begin();
			it2++;
			it2++;
			it2++; // now it on 4

			vec2.insert(it2, begit1, endit1);
			
			std::cout << GRE;
			diy::vector<std::string>::iterator new_iter = vec2.begin();
			for (; new_iter != vec2.end(); new_iter++)
				std::cout << *new_iter << std::endl;
			std::cout << END;
			std::cout << vec2.size() << std::endl;
			std::cout << vec2.capacity() << std::endl;

			// insert with num
			it2 = vec2.begin();
			it2 += 5;
			std::cout << *it2 << std::endl;
			vec2.insert(it2, "!!!!!!!!!!!");

			std::cout << std::endl;
			std::cout << BLU;
			new_iter = vec2.begin();
			for (; new_iter != vec2.end(); new_iter++)
				std::cout << *new_iter << std::endl;
			std::cout << END;

			// insert with num and value
			vec2.insert(it2, 3, "a	d	d	e	d");
			std::cout << std::endl;
			std::cout << YEL;
			new_iter = vec2.begin();
			for (; new_iter != vec2.end(); new_iter++)
				std::cout << *new_iter << std::endl;
			std::cout << END;
		}

		void test_operators() {
			// = != >= < > ...
	
			diy::vector<int> foo(3,100);	// three ints with a value of 100
			diy::vector<int> bar(2,200);	// two ints with a value of 200

			std::cout << GRE;
			if (foo == bar) std::cout << "foo and bar are equal\n";
			if (foo != bar) std::cout << "foo and bar are not equal\n";
			if (foo <  bar) std::cout << "foo is less than bar\n";
			if (foo >  bar) std::cout << "foo is greater than bar\n";
			if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
			if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
			std::cout << END;
		}
};

class test_stack {
	public:
		void test1() {
			// all tests of constuctors and funcs

			std::cout << "creating stack and fill it" << std::endl;
			diy::stack<std::string> t1;
			std::cout << GRE << "is empty? " << std::boolalpha << t1.empty() << std::endl;
			t1.push("1");
			t1.push("2");
			t1.push("3");
			t1.push("4");
			std::cout << GRE;
			std::cout << "size of stack: " << t1.size() << std::endl;
			std::cout << "top of stack: " << t1.top() << std::endl;
			std::cout << "is empty? " << std::boolalpha << t1.empty() << std::endl;
			
			std::cout << std::endl;
			std::cout << "test of pop()" << std::endl;
			t1.pop();
			std::cout << "size of stack: " << t1.size() << std::endl;
			std::cout << "top of stack: " << t1.top() << std::endl;
			std::cout << "is empty? " << std::boolalpha << t1.empty() << std::endl;
			std::cout << END;

			std::cout << std::endl;
			std::cout << YEL;
			std::cout << "test of const stack with a copy constructor" << std::endl;
			const diy::stack<std::string> t2(t1);
			std::cout << "top of stack: " << t2.top() << std::endl;
			std::cout << std::endl;
			std::cout << END;

			std::cout << std::endl;
			std::cout << GRE;
			std::cout << "test of const stack with a container input" << std::endl;
			diy::vector<int> vect;
			vect.push_back(11);
			vect.push_back(22);
			vect.push_back(33);
			vect.push_back(44);
			diy::stack<int> t3(vect);
			std::cout << "size of stack: " << t3.size() << std::endl;
			std::cout << "top of stack: " << t3.top() << std::endl;

			std::cout << std::endl;
			std::cout << "test of =" << std::endl;
			diy::stack<int> t4;
			t4 = t3;
			std::cout << "top of stack: " << t4.top() << std::endl;
			std::cout << END;
		}

		void test2() {
			
			// test of stk with orig vector
			std::cout << std::endl;
			std::cout << "test of diy stack with std::vector inside" << std::endl;
			diy::stack<int, std::vector<int> > ll;
			ll.push(33);
			ll.push(44);
			ll.push(55);
			ll.push(66);
			std::cout << RED << ll.top() << END << std::endl;

			// tests of operators
			std::cout << std::endl;
			std::cout << YEL;
			std::cout << "test operators" << std::endl;
			diy::stack<int> t1;
			t1.push(777);
			t1.push(888);
			t1.push(999);

			diy::stack<int, diy::vector<int> > t2 = t1;
			std::cout << "== " << std::boolalpha << (t1 == t2) << std::endl;
			std::cout << "!= " << std::boolalpha << (t1 != t2) << std::endl;
			t2.pop();
			std::cout << "!= " << std::boolalpha << (t1 != t2) << std::endl;
			std::cout << "< " << std::boolalpha << (t1 < t2) << std::endl;
			std::cout << "> " << std::boolalpha << (t1 > t2) << std::endl;
			std::cout << ">= " << std::boolalpha << (t1 >= t2) << std::endl;
			std::cout << "<= " << std::boolalpha << (t1 <= t2) << std::endl;
			std::cout << END;
		}
};

class test_map {
	public:
		void test_const() {

			std::cout << std::endl;
			std::cout << "test constructors" << std::endl;
			std::cout << GRE;
			diy::map<int, std::string> my1;
			my1.insert(diy::make_pair(1, "str1"));
			my1.insert(diy::make_pair(25, "str2"));
			my1.insert(diy::make_pair(4, "str3"));
			my1.insert(diy::make_pair(-30, "str4"));
			my1.insert(diy::make_pair(100, "str5"));
			diy::map<int, std::string>::iterator my_it1 = my1.begin();
			std::cout << my_it1->first << std::endl;
			my_it1++;
			std::cout << my_it1->first << std::endl;
			my_it1++;
			std::cout << my_it1->first << std::endl;
			my_it1++;
			std::cout << my_it1->first << std::endl;

			std::cout << BLU;
			std::map<int, std::string> st1;
			st1.insert(std::make_pair(1, "str1"));
			st1.insert(std::make_pair(25, "str2"));
			st1.insert(std::make_pair(4, "str3"));
			st1.insert(std::make_pair(-30, "str4"));
			st1.insert(std::make_pair(100, "str5"));
			std::map<int, std::string>::iterator st_it1 = st1.begin();
			std::cout << st_it1->first << std::endl;
			st_it1++;
			std::cout << st_it1->first << std::endl;
			st_it1++;
			std::cout << st_it1->first << std::endl;
			st_it1++;
			std::cout << st_it1->first << std::endl;

			// reverse iter
			std::cout << RED << "rev iter" << END << std::endl;
			diy::map<int, std::string>::reverse_iterator my_it2 = my1.rbegin();
			std::map<int, std::string>::reverse_iterator st_it2 = st1.rbegin();
			std::cout << GRE << my_it2->first << " ";
			std::cout << GRE << my_it2->second << std::endl;
			std::cout << BLU << st_it2->first << " ";
			std::cout << BLU << st_it2->second << std::endl;
			
			std::cout << GRE << "size: " << my1.size() << std::endl;
			std::cout << BLU << "size: " << st1.size() << std::endl;
			std::cout << GRE << "[25]: " << my1[25] << std::endl;
			std::cout << BLU << "[25]: " << st1[25] << std::endl;
			my1[500] = "500";
			st1[500] = "500";
			std::cout << GRE << "[500]: " << my1[500] << std::endl;
			std::cout << BLU << "[500]: " << st1[500] << std::endl;

			std::cout << RED << "copy constructor" << END << std::endl;
			diy::map<int, std::string> my2 = my1;
			std::map<int, std::string> st2 = st1;
			diy::map<int, std::string>::iterator mit = my2.begin();
			std::map<int, std::string>::iterator sit = st2.begin();
			std::cout << GRE << mit->first << std::endl;
			std::cout << BLU << sit->first << std::endl;
			mit++;
			sit++;
			diy::map<int, std::string> my3(mit, my2.end());
			std::map<int, std::string> st3(sit, st2.end());
			diy::map<int, std::string>::iterator mit4 = my3.begin();
			std::map<int, std::string>::iterator sit4 = st3.begin();

			std::cout << RED << "erase" << END << std::endl;
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			my3.erase(mit4);
			st3.erase(sit4);
			mit4 = my3.begin();
			sit4 = st3.begin();
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			my3.erase(4);
			st3.erase(4);
			mit4 = my3.begin();
			sit4 = st3.begin();
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			mit4 = my3.find(25);
			sit4 = st3.find(25);
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			size_t num1 = my3.count(25);
			size_t num2 = st3.count(25);
			std::cout << GRE << "count " << num1 << std::endl;
			std::cout << BLU << "count " << num2 << std::endl;

			my3.insert(diy::make_pair(123, "123"));
			my3.insert(diy::make_pair(123, "123"));
			my3.insert(diy::make_pair(124, "124"));
			my3.insert(diy::make_pair(125, "125"));
			my3.insert(diy::make_pair(126, "126"));

			st3.insert(std::make_pair(123, "123"));
			st3.insert(std::make_pair(123, "123"));
			st3.insert(std::make_pair(124, "124"));
			st3.insert(std::make_pair(125, "125"));
			st3.insert(std::make_pair(126, "126"));

			std::cout << RED << "bounds" << END << std::endl;
			mit4 = my3.upper_bound(123);
			sit4 = st3.upper_bound(123);
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			mit4 = my3.lower_bound(123);
			sit4 = st3.lower_bound(123);
			std::cout << GRE << mit4->first << std::endl;
			std::cout << BLU << sit4->first << std::endl;
			
			std::cout << GRE << "empty? " << std::boolalpha << my1.empty() << std::endl;
			std::cout << BLU << "empty? " << std::boolalpha << st1.empty() << std::endl;
			my1.clear();
			st1.clear();
			std::cout << GRE << "empty? " << std::boolalpha << my1.empty() << std::endl;
			std::cout << BLU << "empty? " << std::boolalpha << st1.empty() << std::endl;

			std::cout << std::endl;
			std::cout << "test str pair" << std::endl;
			diy::map<std::string, std::string> str_map;
			// str_map.insert(diy::make_pair<std::string, std::string>);
			str_map.insert(diy::make_pair("str1", "str1"));
			str_map.insert(diy::make_pair("str2", "str2"));
			str_map.insert(diy::make_pair("str3", "str3"));
			str_map.insert(diy::make_pair("str4", "str4"));
			diy::map<std::string, std::string>::iterator str_it = str_map.begin();
			std::cout << str_it->first << std::endl;
			str_it++;
			std::cout << str_it->first << std::endl;
			str_it++;
			std::cout << str_it->first << std::endl;
			str_it++;
			std::cout << str_it->first << std::endl;
			std::cout << "tree size " << str_map.size() << std::endl;

			std::cout << END;
		}
};

class test_set {
	public:
		void test() {
			// test constructors

			diy::set<int> s1;
			s1.insert(0);
			s1.insert(1);
			s1.insert(2);
			s1.insert(3);
			s1.insert(4);
			s1.insert(5);
			s1.insert(6);
			diy::set<int> copy1(s1);
			diy::set<int> copy2 = copy1;
			std::cout << GRE << "simple iter" << std::endl;
			diy::set<int>::iterator it1 = copy2.begin();
			std::cout << *it1 << std::endl;
			it1++;
			std::cout << *it1 << std::endl;
			it1++;
			std::cout << *it1 << std::endl;
			it1++;
			std::cout << *it1 << std::endl;
			it1++;
			std::cout << *it1 << std::endl;

			std::cout << "const reverse" << std::endl;
			diy::set<int>::const_reverse_iterator it2;
			it2 = copy2.rev_begin();
			std::cout << *it2 << std::endl;
			++it2;
			std::cout << *it2 << std::endl;
			it2--;
			std::cout << *it2 << std::endl;
			it2++;
			std::cout << *it2 << std::endl;
			it2++;
			std::cout << *it2 << std::endl;

			std::cout << "reverse rend" << std::endl;
			diy::set<int>::reverse_iterator it3;
			it3 = copy2.rend();
			std::cout << *it3 << std::endl;
			it3--;
			std::cout << *it3 << std::endl;
			it3--;
			std::cout << *it3 << std::endl;
			std::cout << "cosnt reverse rend" << std::endl;
			diy::set<int>::const_reverse_iterator it4;
			it4 = copy2.rev_end();
			std::cout << *it4 << std::endl;
			it4--;
			std::cout << *it4 << std::endl;
			std::cout << END << std::endl;

			diy::set<int> s2;
			s2.insert(20);
			s2.insert(40);
			s2.insert(60);
			s2.insert(80);
			s2.insert(100);
			s2.insert(120);
			diy::set<int>::iterator it_s2 = s2.begin();
			s2.erase(it_s2);
			it_s2 = s2.begin();
			std::cout << *it_s2 << std::endl;
			diy::set<int>::iterator it_s3 = s2.begin();
			it_s3++;
			it_s3++;
			// erase by iters
			s2.erase(it_s2, it_s3);
			diy::set<int>::iterator it_s4 = s2.begin();
			std::cout << *it_s4 << std::endl;
			// find
			it_s4 = s2.find(100);
			std::cout << *it_s4 << std::endl;
			it_s4 = s2.lower_bound(60);
			std::cout << *it_s4 << std::endl;
			it_s4 = s2.upper_bound(100);
			std::cout << *it_s4 << std::endl;

			std::cout << "size: " << s2.size_set() << std::endl;
			std::cout << "max size: " << s2.max_size() << std::endl;
			std::cout << "set is empty? " << std::boolalpha << s2.empty() << std::endl;
			s2.clear();
			std::cout << "set is empty? " << std::boolalpha << s2.empty() << std::endl;

			std::cout << YEL;
			diy::set<std::string> str_set;
			str_set.insert("123");
			str_set.insert("1123");
			str_set.insert("12344");
			diy::set<std::string>::iterator str_it;
			str_it = str_set.begin();
			std::cout << *str_it << std::endl;
			str_it++;
			std::cout << *str_it << std::endl;
			str_it++;
			std::cout << *str_it << std::endl;
			std::cout << END;
		}
};

#endif

#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <vector>

#include "vector.hpp"


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

			// erase // test with original std::vector
			std::cout << "\nsimple erase with 1 iter" << std::endl;
			std::cout << YEL;
			diy::vector<std::string> vect;
			vect.push_back("pid"); // at
			
			vect.push_back("the");//
			vect.push_back("end");
			vect.push_back("it");
			vect.push_back("doesnt");

			vect.push_back("even");//
			vect.push_back("matter");
			vect.push_back("...");
			
			diy::vector<std::string>::iterator ers1 = vect.begin();
			ers1 += 1;

			diy::vector<std::string>::iterator ers2 = vect.begin();
			ers2 += 5;
			
			std::cout << "begin from " << *ers1 << std::endl;
			std::cout << "begin from " << *ers2 << std::endl;

			vect.erase(ers1, ers2);


			std::cout << "\nprinting all\n\n";
			diy::vector<std::string>::iterator ite = vect.begin();
			for (; ite != vect.end(); ite++)
				std::cout << *ite << std::endl;

			// simple assign
			// diy::vector<std::string>::iterator ers = vect.begin();
			// ers++;
			// // ers++;
			// // ers++;
			// // std::cout << *ers << std::endl;
			// // ers++;
			// // ers++;
			// // // ers++;

			// vect.erase(ers);
			
			// diy::vector<std::string>::iterator ite = vect.begin();
			// // std::cout << *ite << std::endl;
			// for (; ite != vect.end(); ite++)
			// 	std::cout << *ite << std::endl;
			// end of simple arr
			


			std::cout << END;


		}


};


#endif
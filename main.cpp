#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include <numeric> // chech it
#include <typeinfo> // typeid

#include "vector.hpp"
#include "ranit.hpp"
#include "iter.hpp"

int main() {

#if 0
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);


	std::vector<int>::iterator be = vec.begin();
	be++;
	std::vector<int>::iterator eb = vec.end();
	eb--;


	std::vector<int> n(be, eb);
	std::cout << n[0] << std::endl;
	std::cout << n[1] << std::endl;
	std::cout << n[2] << std::endl;
#endif
#if 0

	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	// std::cout << myvector[0] << std::endl;
	// std::cout << myvector[1] << std::endl;
	// std::cout << myvector[2] << std::endl;
	// std::cout << "size " << myvector.size() << std::endl;
	// std::cout << "capacity " << myvector.capacity() << std::endl;

	it = myvector.begin();
	// it = myvector.insert(it, 200);

	// std::cout << std::endl;
	// for (; it != myvector.end(); it++)
	// 	std::cout << *it << std::endl;

	myvector.insert (it, 2, 300);

	std::cout << std::endl;
	for (std::vector<int>::iterator kk = myvector.begin(); kk != myvector.end(); kk++)
		std::cout << *kk << std::endl;
	
	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// std::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
#endif
#if 1

	diy::vector<int> vc;
	vc.push_back(1);
	vc.push_back(2);
	vc.push_back(3);
	vc.push_back(4);
	vc.push_back(5);
	vc.push_back(6);
	vc.push_back(7);
	vc.push_back(8);

	diy::vector<int>::iterator it = vc.begin();
	it++;
	vc.insert(it, 2, 112);

	diy::vector<int>::iterator fb = vc.begin();
	diy::vector<int>::iterator fe = vc.end();
	for (;fb != fe; fb++)
		std::cout << *fb << std::endl;
	
	// std::cout << &vc << std::endl;
	// std::cout << vc.size() << std::endl;
	// std::cout << vc.capacity() << std::endl;

	




#endif


	
	return 0;
}

#ifndef ITR_HPP
#define ITR_HPP

namespace my {

	template<typename T>
	class iter {

		public:

			typedef T* pointer;
			typedef T& referece;

			iter() : ptr_iter(NULL) {
				std::cout << "ptr null constt" << std::endl; }

			iter(pointer first) : ptr_iter(first) {
				std::cout << "ptr constt" << std::endl; }

		private:
			// T* ptr_iter;
			pointer ptr_iter;
		

	};
}

#endif

#ifndef ITR_HPP
#define ITR_HPP

namespace my {

	template <typename T>
	class iter {

		public:

			typedef T* pointer;
			typedef T& reference;

			iter() : ptr_iter(NULL) {
				std::cout << "ptr null const" << std::endl; }

			iter(pointer first) : ptr_iter(first) {
				std::cout << "ptr const with arg" << std::endl; }

			iter(const iter &op) : ptr_iter(op.ptr_iter) {
				std::cout << "copy constt" << std::endl; }

			reference operator*() const {
				return *this->ptr_iter; }

		private:
			// T* ptr_iter;
			pointer ptr_iter;
		

	};
}

#endif

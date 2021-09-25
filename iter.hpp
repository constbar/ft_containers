#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// rename it
// add const ++

template <typename T>
class InputIterator {
public:
	InputIterator()
	{
		this->it = NULL;
	}
	InputIterator(InputIterator const &other)
	{
		operator=(other);
	}
	InputIterator &operator=(InputIterator const &other)
	{
		if (this != &other)
			this->it = other.it;
		return (*this);
	}
	virtual ~InputIterator(void) {}

	bool operator==(const InputIterator &other) const
	{
		if (other.it == this->it)
			return (true);
		return (false);
	}
	bool operator!=(const InputIterator &other) const
	{
		return (!operator==(other));
	}

	T &operator*(void)
	{
		return (*this->it->ptr);
	}
	T *operator->(void)	{ return (this->it->ptr); }
	const T *operator->(void)	const { return (this->it->ptr); } // del // works

	// HERE


	InputIterator operator++(int) {
		InputIterator I = *this;
		if (this->it && this->it->next)
			this->it = this->it->next;
		return I;
	}

	InputIterator operator++(void) {
		if (this->it && this->it->next)
			this->it = this->it->next;
		return *this;
	}



	diy::tree_node<T> *get_it(void) const { return this->it;}

protected:
	diy::tree_node<T> *it;
};

template <typename T>
struct ForwardIterator : public InputIterator<T> {
	public:
		ForwardIterator() {}
	void kkk() {} // del
};

template <typename T>
class bidit : public ForwardIterator<T> {
public:
	bidit(void) {}
	bidit(bidit const &other) { operator=(other); }
	bidit &operator=(bidit const &other) {
		if (this != &other)
			this->it = other.it;
		return (*this);
	}
	virtual ~bidit(void) {}
	bidit(diy::tree_node<T> *other) { this->it = other; }

	bidit operator--(int) {
		bidit I = *this;
		if (this->it && this->it->prev)
			this->it = this->it->prev;
		return (I);
	}
	bidit &operator--() {
		if (this->it && this->it->prev)
			this->it = this->it->prev;
		return (*this);
	}

	bidit operator++(int) {
		bidit I = *this;
		if (this->it && this->it->next)
			this->it = this->it->next;
		return (I);
	}
	bidit operator++() {
		if (this->it && this->it->next)
			this->it = this->it->next;
		return (*this);
	}
};










































/////////////////////////			reverse!!!

template <typename T>
class ReverseInputIterator {	
	public:
		ReverseInputIterator(){}
		ReverseInputIterator(ReverseInputIterator const &other) {
			operator=(other);
		}
		ReverseInputIterator &	operator=( ReverseInputIterator const &other){
			if (this != &other)
				this->it = other.it;
			return (*this);
		}
		virtual ~ReverseInputIterator(void){}
		
		bool					operator==(const ReverseInputIterator &other) const{
			if (other.it == this->it)
				return (true);
			return (false);
		}
		bool					operator!=(const ReverseInputIterator &other) const{
			return (!operator==(other));
		}

		T							&operator*(void){
			return (*this->it->ptr);
		}
		T *operator->() { return (this->it->ptr); }
		const T *operator->() const { return (this->it->ptr); } // del 

		ReverseInputIterator				operator++(int){
			ReverseInputIterator I = *this;
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (I);
		}
		ReverseInputIterator				operator++(void){
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (*this);
		}
		diy::tree_node<T>						*get_it(void) const{
			return (this->it);
		}
	protected :
		diy::tree_node<T>				*it;
};

template <typename T>
struct ReverseForwardIterator : public ReverseInputIterator<T> {
	public:
		ReverseForwardIterator() {}
};

template <typename T>
class rev_bidit : public ReverseForwardIterator<T> {
	public:
		rev_bidit() {}
		rev_bidit(rev_bidit const &other) { *this = other; }
		rev_bidit &operator=( rev_bidit const &other) {
			if (this != &other)
				this->it = other.it;
			return *this;
		}
		virtual ~rev_bidit() {}
		rev_bidit(diy::tree_node<T> *other) { this->it = other; }

		rev_bidit &operator--(){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}
		rev_bidit operator--(int){
			rev_bidit I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
};

////////////////// END OF NESSSEASARY
























































template <typename T>
class RandomAccessIterator
{
public:
	typedef ptrdiff_t difference_type;

	RandomAccessIterator(void) {}
	RandomAccessIterator(RandomAccessIterator const &other) { operator=(other);	}
	RandomAccessIterator &operator=(RandomAccessIterator const &other) {
		if (this != &other)
			this->_array = other._array;
		return (*this);
	}
		
	virtual ~RandomAccessIterator(void) {}
	RandomAccessIterator(T *other) { this->_array = other; }

	bool operator==(const RandomAccessIterator &other) const {
		if (other._array == this->_array)
			return (true);
		return (false);
	}

	bool operator!=(const RandomAccessIterator &other) const { return (!operator==(other)); }

	T &operator*(void) { return (*this->_array); }
	T *operator->(void) { return (*this->_array); }
	const T *operator->() const { return (*this->_array); } // del

	RandomAccessIterator operator++(int) {
		RandomAccessIterator I = *this;
		++this->_array;
		return (I);
	}

	RandomAccessIterator operator++(void) {
		++this->_array;
		return (*this);
	}
	T *get_it(void) const { return (this->_array); }

	RandomAccessIterator operator--(int)
	{
		RandomAccessIterator I = *this;
		--this->_array;
		return (I);
	}
	RandomAccessIterator &operator--() {
		--this->_array;
		return (*this);
	}

	RandomAccessIterator operator+(int n) { return ( this->_array += n); }
	difference_type operator+(RandomAccessIterator it) { return this->_array + it._array; }
	RandomAccessIterator operator-(int n) { return ( this->_array -= n); }
	difference_type operator-(RandomAccessIterator it) { return (this->_array - it._array); }

	bool operator<(const RandomAccessIterator &rhs) const { return (this->_array < rhs._array);	}
	bool operator>(const RandomAccessIterator &rhs) const { return (this->_array > rhs._array);	}
	bool operator<=(const RandomAccessIterator &rhs) const { return (this->_array <= rhs._array); }
	bool operator>=(const RandomAccessIterator &rhs) const { return (this->_array >= rhs._array); }

	RandomAccessIterator operator+=(difference_type n) {
		this->_array -= n;
		return (*this);
	}
	RandomAccessIterator operator-=(difference_type n) {
		this->_array -= n;
		return (*this);
	}

	RandomAccessIterator operator[](int n) { return (this->_array[n]); }
	RandomAccessIterator operator[](difference_type n) { return *(this->_array + n); }

private:
	T *_array;
};

#endif
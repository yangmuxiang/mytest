#include <iostream>

template<class T> class Pointer;
template<class T> class Array_data;

template<class T> class Array {
	friend class Pointer<T>; 

public:
	Array(unsigned size):
		data(new Array_data<T>(size)) {}
	~Array() {
		if (--data->use == 0) 
			delete data;
	}

	const T& operator[] (unsigned n) const
	{
		return data[n];
	}

	T& operator[] (unsigned n)
	{
		return data[n];
	}

	operator const T*() const
	{
		return data;
	}

	operator const T*()
	{
		return data;
	}

private:
	Array(const Array& a);
	Array& operator=(const Array&);
	Array_data<T>* data;
};

template<class T> class Pointer {
public:
	Pointer(Array<T>& a, unsigned n = 0):
		ap(a.data), sub(n) { ++ap->use;}

	Pointer(): ap(0), sub(0) {}

	Pointer(const Pointer<T>& p): ap(p.ap), sub(p.sub) {
		if (ap)
			++ap->use;
	}
	
	~Pointer(){ if(ap && --ap->use == 0) delete ap;}
	Pointer& operator=(const Pointer<T>& p) {
		if (p.ap)
			++p.ap->use;
		if (ap && --ap->user == 0)
			delete ap;
		ap = p.ap;
		sub = p.sub;
		return *this;
	}

	T& operator*() const {
		if (ap == 0)
			throw "* of unboud Pointer";
		return (*ap) [sub];
	}

private:
	Array_data<T>* ap;
	unsigned sub;
};

template<class T> class Array_data {
	friend class Array<T>;
	friend class Pointer<T>;
	
	Array_data(unsigned size = 0):
		data(new T[size]), sz(size), use(1) {}
	~Array_data() { delete[] data; }

	const T& operator[](unsigned n) const
	{
		if (n >= sz) 
			throw "Array subscript out of range";
		return data[n];
	}

	T& operator[] (unsigned n)
	{
		if (n >= sz) 
			throw "Array subscript out of range";
		return data[n];
	}

	Array_data(const Array_data&);
	Array_data& operator=(const Array_data&);

	T* data;
	unsigned sz;
	int use;
};

int 
main() {
	const int N = 10;

	Array<int>*ap = new Array<int> (N);
	Pointer<int> p(*ap, 5);


	*p = 1234;

	delete ap;

	std::cout << *p << std::endl;
	*p = 42;

	std::cout << *p << std::endl;

}


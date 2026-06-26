#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <class T>
class Array
{
private:
	T *data;
	unsigned int length;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int size()const;

	const T& operator[](int idx)const;
	T& operator[](int idx);
};

#include "Array.tpp"

#endif
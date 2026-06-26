#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<class T>
Array<T>::Array() : data(NULL), length(0) {}

template<class T>
Array<T>::Array(unsigned int n) : data(new T[n]), length(n) {}

template<class T>
Array<T>::Array(const Array<T>& other) : data(new T[other.length]), length(other.length)
{
	for (unsigned int i = 0; i < length; i++)
		data[i] = other.data[i];
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (data)
			delete[]data;
		length = other.length;
		data = new T[length];
		for (unsigned int i = 0; i < length; i++)
			this->data[i] = other.data[i];
	}
	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete[]data;
}

template<class T>
unsigned int Array<T>::size()const
{
	return length;
}

template<class T>
const T& Array<T>::operator[](int idx)const
{
	if (static_cast<unsigned int>(idx) >= length || idx < 0)
		throw std::out_of_range("Index out of bounds");
	return data[idx];
}

template<class T>
T& Array<T>::operator[](int idx)
{
	if (static_cast<unsigned int>(idx) >= length || idx < 0)
		throw std::out_of_range("Index out of bounds");
	return data[idx];
}

#endif
#include <iostream>

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other.size())
{
    _array = new T[other.size()];
    for (unsigned int i = 0; i < other.size(); i++) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return *this;

    if (_array != nullptr)
        delete [] _array;

    _size = other.size();
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }

    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
    if (i >= this->size()  || _array == nullptr) 
        throw Array<T>::OutOfRange();
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;
}

template <typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return "Out of range!";
}

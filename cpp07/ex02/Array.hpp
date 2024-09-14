#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](unsigned int i) const;
        unsigned int size() const;
        class OutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        ~Array();
};

#include "Array.tpp"

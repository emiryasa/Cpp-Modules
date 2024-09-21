#include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    *this = src;
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (this != &src)
        this->c = src.c;
    return *this;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}

template <class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return this->c.rbegin();
}

template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return this->c.rend();
}

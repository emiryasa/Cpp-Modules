#pragma once

#include <iostream>
#include <stack>

template <class T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack &operator=(const MutantStack& src);

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"
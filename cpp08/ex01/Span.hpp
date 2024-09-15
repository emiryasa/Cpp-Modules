#pragma once

#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> _vec;
        unsigned int _size;
    public:
        Span();
        Span(const unsigned int &n);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(int x);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};

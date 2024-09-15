#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int &n): _size(n) {}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(const Span &src) {}

Span::~Span() {}

void Span::addNumber(int x)
{
    _vec.push_back(x);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

}

int Span::shortestSpan()
{
    std::vector<int> tmp = _vec;
    int min;
    std::sort(tmp.begin(), tmp.end());

}

int Span::longestSpan()
{

}

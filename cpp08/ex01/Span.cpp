#include "Span.hpp"
#include <algorithm>

Span::Span() {}

Span::Span(const unsigned int &n): _size(n) {}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _size = src._size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int x)
{
    if (_vec.size() == _size)
        throw VectorIsFullException();

    _vec.push_back(x);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_vec.size() + std::distance(begin, end) > _size)
        throw VectorIsFullException();
    
    _vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan()
{
    if (_vec.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    int minSpan = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_vec.size() < 2) {
        throw NoSpanException();
    }

    int minNum = *std::min_element(_vec.begin(), _vec.end());
    int maxNum = *std::max_element(_vec.begin(), _vec.end());
    
    return maxNum - minNum;
}

const char *Span::VectorIsFullException::what() const throw()
{
    return "Size is full!";
}

const char *Span::NoSpanException::what() const throw()
{
    return "There is no span!";
}

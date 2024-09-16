#include "Span.hpp"

int main()
{
    Span sp = Span(6);

    try {
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);

    std::vector<int> tmp;
    tmp.push_back(5);
    tmp.push_back(2);
    tmp.push_back(-2);
    sp.addNumber(tmp.begin(), tmp.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}

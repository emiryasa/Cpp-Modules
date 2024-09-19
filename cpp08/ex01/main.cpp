#include "Span.hpp"

int main()
{

    Span sp = Span(2);

    std::vector<int> c(2);

    c.push_back(5);
    std::cout << c[0] << std::endl;
    try {
        sp.addNumber(5);
        sp.addNumber(2);
        sp.addNumber(1);
        sp.longestSpan();
        sp.shortestSpan();
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    // Span sp = Span(6);
    // Span se = Span();

    // se.shortestSpan();
    // try {
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);

    // std::vector<int> tmp;
    // tmp.push_back(5);
    // tmp.push_back(2);
    // tmp.push_back(-2);
    // sp.addNumber(tmp.begin(), tmp.end());

    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // }
    // catch (std::exception &err) {
    //     std::cout << err.what() << std::endl;
    // }
    // return 0;
}

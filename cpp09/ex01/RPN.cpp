#include "RPN.hpp"
#include <sstream>
RPN::RPN() {}

RPN::RPN(const std::string &line): _line(line) {}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &src) 
{
    if (this != &src)
    {
        _num = src._num;
        _op = src._op;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::calculate()
{
    std::stringstream fs(_line);
}    

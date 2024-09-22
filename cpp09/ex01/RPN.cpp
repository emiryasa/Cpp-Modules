#include "RPN.hpp"
#include <sstream>
#include <cctype>
RPN::RPN() {}

RPN::RPN(const std::string &line): _line(line) {}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &src) 
{
    if (this != &src)
        _num = src._num;
    return *this;
}

RPN::~RPN() {}

bool RPN::performOperation(char op)
{
    if (_num.size() < 2) {
        std::cout << "Error: not enough operands for operation '" << op << "'." << std::endl;
        return false;
    }
    int b = _num.top();
    _num.pop();
    int a = _num.top();
    _num.pop();

    switch (op) {
        case '+':
            _num.push(a + b);
            break;
        case '-':
            _num.push(a - b);
            break;
        case '*':
            _num.push(a * b);
            break;
        case '/':
            _num.push(a / b);
            break;
        default:
            std::cout << "Error: unknown operator '" << op << "'." << std::endl;
            return false;
        
    }
    return true;
}

bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::calculate()
{
    std::stringstream ss(_line);
    std::string token;
    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (!performOperation(token[0])) {
                return 1;
            }
        }
        else if (token.size() >= 1 && std::isdigit(token[0])) {
            int num = token[0] - '0';
            if (num < 0 || num > 9) {
                std::cerr << "Error: number out of range." << std::endl;
                return 1;
            }
            _num.push(num);
        }
        else {
            std::cout << "Error" << std::endl;
            return 1;
        }
    }

    if (_num.size() != 1) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::cout << _num.top() << std::endl;

    return 0;
}

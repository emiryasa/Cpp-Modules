#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN {
    private:
        const std::string _line;
        std::stack<double> _num;
        std::stack<char> _op;

    public:
        RPN();
        RPN(const std::string &line);
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();
        int calculate();
};

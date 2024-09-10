#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

int ScalarConverter::isValid(std::string str)
{
    if (str.empty())
        return 1;
    if (str[0])
    return 0;
}
void ScalarConverter::convert(std::string str)
{
    if (isValid(str))
        return ;
    if (str.empty())
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: Non displayable" << std::endl;
        std::cout << "float: Non displayable" << std::endl;
        std::cout << "double: Non displayable" << std::endl;
        return ;
    }

}

void ScalarConverter::print()
{

}
#include "ScalarConverter.hpp"

std::string ScalarConverter::_str; 
std::string ScalarConverter::_type;

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

int ScalarConverter::isChar()
{   

    if ((std::isprint(_str[0]) && _str.length() == 1))
        return (_type = "char", castChar(), 1);
    return 0;
}

int ScalarConverter::isInt()
{
    if (_str.length() == 1 && !std::isdigit(_str[0]))
        return 0;
    for (size_t i = 0; i < _str.length(); i++)
    {
        if (!std::isdigit(_str[i]) && _str[i] != '-' && _str[i] != '+') 
            return 0;
    }
    _type = "int";
    castInt();
    return 1;
}

int ScalarConverter::isFloat()
{
    size_t dotCount = 0;
    bool hasF = false;

    if (_str.length() == 1)
        return 0;

    for (size_t i = 0; i < _str.length(); i++)
    {
        if (_str[i] == '.')
            dotCount++;
        else if (_str[i] == 'f' || _str[i] == 'F')
        {
            if (i != _str.length() - 1)
                return 0;
            hasF = true;
        }
        else if (!std::isdigit(_str[i]) && _str[i] != '-' && _str[i] != '+')
            return 0;
    }

    if (dotCount > 1)
        return 0;

    if (hasF)
    {
        _type = "float";
        castFloat();
        return 1;
    }
    
    return 0;
}

int ScalarConverter::isDouble()
{
    size_t dotCount = 0;
    if (_str.length() == 1)
        return 0;
    for (size_t i = 0; i < _str.length(); i++)
    {
        if (_str[i] == '.')
            dotCount++;
        else if (!std::isdigit(_str[i]) && _str[i] != '-' && _str[i] != '+')
            return 0;
    }
    if (dotCount > 1)
        return 0;

    _type = "double";
    castDouble();
    return 1;
}

int ScalarConverter::handlePseudo()
{
    std::string pseudos_float[3] = {"-inff", "+inff", "nanf"};
    std::string pseudos_double[3] = {"-inf", "+inf", "nan"};
    for (size_t i = 0; i < 3; i++)
    {
        if (_str == pseudos_float[i] || _str == pseudos_double[i])
        {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << pseudos_float[i] << std::endl;
            std::cout << "double: " << pseudos_double[i] << std::endl;
            return 1;
        }
    }
    return 0;
}

void ScalarConverter::printChar(char c)
{
    long num = atol(_str.c_str());
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
    {
        std::cout << "char: " << "impossible" << std::endl;
        return ;
    }
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(long num)
{
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
    {
        std::cout << "int: " << "impossible" << std::endl;
        return ;
    }
    std::cout << "int: " << num << std::endl;
}

void ScalarConverter::printFloat(float num)
{
    if (_type == "float" || _type == "double")
    {
        size_t a = 0;
        for (size_t i = 0; i < _str.length(); i++)
        {
            if (_str[i] == '.')
            {
                i++;
                a = 0;
                while (_str[i] && _str[i] != 'f' && _str[i] != 'F')
                {
                    a++;
                    i++;
                }
                if (a == 0)
                    a = 1;
            }
            else
                a = 1;
        }
    std::cout << std::fixed << std::setprecision(a) << "float: " << num << "f" << std::endl;
    }
    else if ((_type == "int" || _type == "char"))
        std::cout << "float: " << num << ".0f" << std::endl;
}

void ScalarConverter::printDouble(double num)
{
    if (_type == "float" || _type == "double")
    {
        std::cout << "double: " << num << std::endl;
    }
    else if ((_type == "int" || _type == "char"))
        std::cout << "double: " << num << ".0" << std::endl;
}

void ScalarConverter::castInt()
{
    long num = atol(_str.c_str());
    printChar(static_cast<char>(num));
    printInt(num);
    printFloat(num);
    printDouble(num);
}

void ScalarConverter::castChar()
{
    char c = _str[0];
    printChar(c);
    printInt(static_cast<long>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::castFloat()
{
    float num = atof(_str.c_str());
    printChar(static_cast<char>(num));
    printInt(static_cast<long>(num));
    printFloat(num);
    printDouble(static_cast<double>(num));
}

void ScalarConverter::castDouble()
{
    double num = atof(_str.c_str());
    printChar(static_cast<char>(num));
    printInt(static_cast<long>(num));
    printFloat(static_cast<float>(num));
    printDouble(num);
}

void ScalarConverter::convert(std::string str)
{
    _str = str;
    if (_str.empty())
    {
        std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << "0" << std::endl;
        std::cout << "float: " << "0.0f" << std::endl;
        std::cout << "double: " << "0.0" << std::endl;
        return ;
    }
    if (handlePseudo())
        return ;
    if (isDouble())
        return ;
    else if (isFloat())
        return ;
    else if (isInt())
        return ;
    else if (isChar())
        return ;
    else
        std::cerr << "Invalid data type!" << std::endl;
}

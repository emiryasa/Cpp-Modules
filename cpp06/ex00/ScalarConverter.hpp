#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    private:
        static std::string _str; 
        static std::string _type;

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

        static int  isChar();
        static int  isInt();
        static int  isFloat();
        static int  isDouble();
        static int  handlePseudo();
        static void castChar();
        static void castInt();
        static void castFloat();
        static void castDouble();
        static void printChar(char c);
        static void printInt(long num);
        static void printFloat(float num);
        static void printDouble(double num);

    public:
        ~ScalarConverter();

        static void convert(std::string str);
};
